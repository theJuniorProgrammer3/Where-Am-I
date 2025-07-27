#include <ncurses.h>
#include <vector>
#include <algorithm>
#include <random>

std::vector<char> cond = {'b', 'b', '0', 'c', '0', '0', '0', '0', 'b', 'b', 'b', '0', '0', '0', 'd'};

std::pair<int, char> getNearObj(int index) {
	char exist = '0';
	int i = index + 1;
	while(true) {
		if(cond[i] != '0') {
			exist = cond[i];
			break;
		}
		i++;
	}
	return {i - index, exist};
}
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(0, 2);
std::bernoulli_distribution disB(0.8);

void expand() {
	char item[] = {'s', 'b', 'd'};
	cond.push_back('0');
	cond.push_back('0');
	cond.push_back('0');
	for(int i = 0; i < 10; i++) {
		if(disB(gen)) {
			cond.push_back('0');
		} else {
		cond.push_back(item[dis(gen)]);
		}
	}
}

int main() {
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
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	/*printw("Click 'c' to skip cutscene");
	napms(4000);*/
	int bCount = 0;
	int inp;
	noecho();
	std::vector<int> entityStep;
	int energyLoop = 0;
	int energy = 20;
	bool lose = false;
	while(true) {
		auto it = std::find(cond.begin(), cond.end(), 'c');
		int index = it - cond.begin();
		if(cond[index + 1] == 'd') {
			lose = true;
			break;
		}
	bool noStep = true;
		clear();
		inp = getch();
		if(inp == 'q') break;
		if(energy > 0) {
		if(inp == KEY_RIGHT) {
			if(index < cond.size() - 1) {
			if(cond[index + 1] == '0') {
			energy--;
			noStep = false;
			cond[index] = '0';
			cond[index + 1] = 'c';
			}
			} else {
			energy--;
			noStep = false;
			cond[index] = '0';
				cond.push_back('c');
				expand();
			}
		} else if(inp == KEY_LEFT) {
			if(index > 0) {
			if(cond[index - 1] == '0') {
				energy--;
				noStep = false;
			cond[index] = '0';
			cond[index - 1] = 'c';
			}
			}
		} else if(inp == 'b') {
			if(cond[index + 1] == 'b') {
			cond[index + 1] = '0';
			bCount++;
			}
		} else if(inp == 'v') {
			if(cond[index - 1] == 'b') {
			cond[index - 1] = '0';
			bCount++;
			}
		} else if(inp == 'p') {
			if(bCount != 0) {
				cond[index + 1] = 'b';
				bCount--;
			}
		} else if(inp == 'o') {
			if(bCount != 0) {
				cond[index - 1] = 'b';
				bCount--;
			}
		} else if(inp == 'f') {
			if(energy >= 3) {
			energy = energy - 3;
			if(cond[index + 2] == 'd') {
			cond[index + 2] = '0';
			}
			}
			
		}
		}

		it = std::find(cond.begin(), cond.end(), 'c');
		index = it - cond.begin();
		auto nearest = getNearObj(index);
		int id = 0;
		printw("  ");
		//itwnsitas dan warna:
		if(nearest.first <= 8) {
		if(nearest.first <= 2) id += 12;
		else if(nearest.first <= 4) id += 8;
		else if(nearest.first <= 6) id += 4;

		if(nearest.second == 'b') id += 4;
		else if(nearest.second == 'd') id += 1;
		else if(nearest.second == 's') id += 2;
		addch('#'| COLOR_PAIR(id));
		}
		printw("\n");

		for(int j = (index < 3 ? index : index - 3); j <= ([&]() -> int {
				if(index >= cond.size() - 1 - 5) {
				return cond.size() - 1;
				} else {
				return index + 5;
				}
				})(); j++) {
			printw((cond[j] == 'c' ? "[@]" : (cond[j] != '0' ? "[X]" : "[ ]")));
		}
		printw("\nBlock in inventory: %d", bCount);
		printw("\nEnergy: %d", energy);

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
		napms(100);
	}
	if(lose) {
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
	}
	endwin();
}
