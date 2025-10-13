#include <ncurses.h>
#include <vector>
#include <algorithm>
#include <random>



std::random_device rd;
std::mt19937 gen(rd());
std::vector<char> cond(16, '0');
std::uniform_int_distribution initPos(0, 15);
std::uniform_int_distribution theBlockCount(1, 8);
std::uniform_int_distribution<> dis(0, 5);
std::bernoulli_distribution disB(0.8);
std::bernoulli_distribution time_to_spawnDE(0.03);
std::uniform_int_distribution<> sDEdis(4, 18);
std::uniform_int_distribution<> quotesIntervalDis(50, 1200);
#include "world.cpp"
#include "cutscenes.cpp"

std::pair<bool, int> detectCollide(std::vector<char> vec, int from, int to) {
	for(int i = from; i < to; (from < to ? i++ : i--)) {
		if(vec[i] != '0') return std::pair<bool, int>(true, i);
	}
	return std::pair<bool, int>(false, 0);
}
	
int main() {
	initWorld();
	initscr();
	start_color();
	init_color(10, 250, 0, 0);
        init_color(11, 0, 250, 0);
        init_color(12, 0, 0, 250);
        init_color(13, 250, 250, 250);
        init_color(14, 500, 0, 0);
        init_color(15, 0, 500, 0);
        init_color(16, 0, 0, 500);
        init_color(17, 500, 500, 500);
        init_color(18, 750, 0, 0);
        init_color(19, 0, 750, 0);
        init_color(20, 0, 0, 750);
        init_color(21, 750, 750, 750);
	for(int i = 10; i <= 21; i++) {
		init_pair(i - 9, i, COLOR_BLACK);
	}
	init_pair(13, COLOR_RED, COLOR_BLACK);
	init_pair(14, COLOR_GREEN, COLOR_BLACK);
	init_pair(15, COLOR_BLUE, COLOR_BLACK);
	init_pair(16, COLOR_WHITE, COLOR_BLACK);
	init_pair(17, COLOR_BLACK, COLOR_RED);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	auto it = std::find(cond.begin(), cond.end(), 'c');
	auto index = it - cond.begin();
		auto theNearest = getNearObj(index);
		int theId = 0;
		printw("  ");
		//itensitas dan warna:
		if(theNearest.first <= 8) {
		if(theNearest.first <= 2) theId += 12;
		else if(theNearest.first <= 4) theId += 8;
		else if(theNearest.first <= 6) theId += 4;

		if(theNearest.second == 'b') theId += 4;
		else if(theNearest.second == 'd') theId += 1;
		else if(theNearest.second == 's') theId += 2;
	printw("Click 'c' to skip cutscene");
	int t;
	t = getch();
	if(t == 'c') goto skip;
		for(int a = 1; a <= 4; a++) {
			clear();
			attron(COLOR_PAIR(16 - ((a - 1) * 4)));
	printw("Click 'c' to skip cutscene");
	int tmp;
	tmp = getch();
	if(tmp == 'c') goto skip;
		attroff(COLOR_PAIR(16 - ((a - 1) * 4)));
		refresh();
		if(a == 1) {
			napms(3000);
		} else {
		napms(500);
		}
		}
	cutscene();
	cutscene2(theId, index);
skip:
	attron(COLOR_PAIR(16));
	int itemCount[] = {0, 0, 0, 0};
	//Block, Apple, caRrot, chIli
	int inp;
	noecho();
	std::pair<int, int> entityStepLoop = {0, 0};
	int energyLoop = 0;
	int energy = 20;
	bool lose = false;
	bool win = false;
	int every3SecondEnergy = 0;
	int energyLoop2 = 0;
	bool expandedVision = false;
	int expandedVisionLoop = 0;
	int health = 100;
	int speed = 1;
	int speedLoop = 0;
	bool truth = false;
	bool phase2 = false;
	int quoteLoop = 0;
	int quoteInterval = 0;
	int curQI;
	std::vector<std::string> profQuotes = {
		"Spirit!"
		, "Don't give up!"
		, "I sure you can do it!"
		, "Ask Safe Entity for help!"
		, "Maintain stamina!"
	};
	std::vector<std::string> profQuotesPhase2 = {
		"Why you can?"
		, "I don't expect you can do it."
		, "Whoa! You're stronger than my expectations!"
		, "Still collecting?"
		, "You still survive? Respect..."
	};
	std::string curQuote;
	std::uniform_int_distribution<> disPQ(0, profQuotes.size() - 1);
	std::uniform_int_distribution<> disPQ2(0, profQuotesPhase2.size() - 1);
	// phase 3 coming soon...
	while(true) {
		if(!phase2 && itemCount[0] == 170) {
			cutscene3();
			phase2 = true;
		} else if(itemCount[0] == 200 && inp == 'e') {
			win = true;
			break;
		} else if(itemCount[0] == 256 && inp == 'e') {
			truth = true;
			break;
		}
		it = std::find(cond.begin(), cond.end(), 'c');
		index = it - cond.begin();
		auto entPos = findNearestDangerEntity(index);
#include "safeEntity.cpp"
#include "move.cpp"

		auto nearest = getNearObj(index);
		int id = 0;
		printw("  ");
		//itensitas dan warna:
		if(nearest.first <= 8) {
		if(nearest.first <= 2) id += 12;
		else if(nearest.first <= 4) id += 8;
		else if(nearest.first <= 6) id += 4;

		if(nearest.second == 'b') id += 4;
		else if(nearest.second == 'd') id += 1;
		else if(nearest.second == 's') id += 2;
		else id += 3; // apple, carrot, and chili (?)
		addch('#'| COLOR_PAIR(id));
		}
		printw("\n");

		for(int j = (index < 3 ? 0 : index - 3); j <= ([&]() -> int {
				if(index >= cond.size() - 1 - (expandedVision ? 15 : 5)) {
				return cond.size() - 1;
				} else {
				return index + (expandedVision ? 15 : 5);
				}
				})(); j++) {
			printw((cond[j] == 'c' ? "[@]" : (cond[j] != '0' ? "[X]" : "[ ]")));
		}
			if(expandedVision) {
			expandedVisionLoop += 1;
			if(expandedVisionLoop == 30001) {
			//setelah 5 menit
			expandedVision = false;
			expandedVisionLoop = 0;
			}
			}
		printw("\nHealth: %d", health);
		printw("\nInventory:");
		printw("\nBlock: %d", itemCount[0]);
		printw("\nApple: %d", itemCount[1]);
		printw("\nCarrot: %d", itemCount[2]);
		printw("\nChili: %d", itemCount[3]);
		printw("\nEnergy: %d", energy);
		if(quoteLoop < 70) {
		if(phase2) {
			if(curQuote == "") curQuote = profQuotesPhase2[disPQ2(gen)];
			printw("\n%s", curQuote.c_str());
			quoteLoop++;
		} else {
			if(curQuote == "") curQuote = profQuotes[disPQ(gen)];
			printw("\n%s", curQuote.c_str());
			quoteLoop++;
		}
		} else {
			curQI = quotesIntervalDis(gen);
			if(quoteInterval < curQI) {
				quoteInterval++;
			} else {
				quoteInterval = 0;
				quoteLoop = 0;
				curQuote = "";
			}
		}

		refresh();
		if(noStep) {
		if(energyLoop == 10) {
			energyLoop = 0;
			energy++;
		} else {
			energyLoop++;
		}
		} else {
			energyLoop = 0;
		}
		if(every3SecondEnergy > 0) {
			if(energyLoop2 == 30) {
				energy += every3SecondEnergy;
				energyLoop2 = 0;
			} else energyLoop2++;
		}
		napms(100);
	}
	if(lose) {
		//animasi fade out
		for(int a = 1; a <= 4; a++) {
			clear();
			attron(COLOR_PAIR(13 - ((a - 1) * 4)));
		printw("AAAAAAAAAAAA\nYou've been ate by entity.");
		attroff(COLOR_PAIR(13 - ((a - 1) * 4)));
		refresh();
		if(a == 1) {
			napms(3000);
		} else {
		napms(500);
		}
		}
		badEnding();
	} else if(win) {
		//animasi fade in
		for(int a = 4; a >= 1; a--) {
			clear();
			attron(COLOR_PAIR(16 - ((a - 1) * 4)));
	printw("Yay! Now you can back into lab!");
		attroff(COLOR_PAIR(16 - ((a - 1) * 4)));
		refresh();
		if(a == 1) {
			napms(3000);
		} else {
		napms(500);
		}
		}
		goodEnding();
		napms(3000);
		credit();
	} else if(truth) {
		clear();
		refresh();
		napms(5000);
		truthEnding();
		napms(3000);
		credit();
	}
		}
	endwin();
 }
