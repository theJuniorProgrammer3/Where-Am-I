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
	char item[] = {'d', 's', 'b'};
	cond.push_back('0');
	cond.push_back('0');
	for(int i = 0; i < 10; i++) {
		if(disB(gen)) {
			cond.push_back('0');
		} else {
		cond.push_back(item[dis(gen)]);
		}
	}
}//kiri, kanan
std::pair<int, int> findNearestDangerEntity(int curPos) {
	int i = curPos;
	int l = -1;
	int r = -1;
	while(i > 0) {
		i--;
		if(cond[i] == 'd') {
			l = i;
			break;
		}
	}
	i = curPos;
	while(i < cond.size() - 1) {
		i++;
		if(cond[i] == 'd') {
			r = i;
			break;
		}
	}
	return {l, r};
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
	std::pair<int, int> entityStepLoop = {0, 0};
	int energyLoop = 0;
	int energy = 20;
	bool lose = false;
	int every3SecondEnergy = 0;
	int energyLoop2 = 0;
	std::vector<std::string> safeEntityMotivation = {"Even if you have difficulties here, don't give up, there is definitely a way out. Destroy.", "If you meet me, don't be scared, I here for help you.", "If you're running out of energy, don't surrender, I can give it to you.", "Next time don't answer randomly, right?", "If someone approaches you to attack you, but you run out of energy, block him."};
	std::uniform_int_distribution<> disMot(0, safeEntityMotivation.size() - 1);
	while(true) {
		auto it = std::find(cond.begin(), cond.end(), 'c');
		int index = it - cond.begin();
		auto entPos = findNearestDangerEntity(index);
		int ans;
		if(cond[index + 1] == 's') {
			clear();
			printw("Safe Entity: Hello! Nice to meet you, need help?\nn: nope\ne: I need energy\n");
			refresh();
			nodelay(stdscr, FALSE);
			ans = getch();
			if(ans == 'e') {
				printw("Safe Entity: You need energy? Okay, you need every 3 second one energy, or one time thirty energy?\ne: Every Second\no: One time\n");
				refresh();
				ans = getch();
				if(ans == 'e') {
				printw("Safe Entity: Okay, I will give you a power of regeneration for you.\n");
				refresh();
				every3SecondEnergy++;
				napms(2000);
				} else if(ans == 'o'){
					printw("Safe Entity: Okay, I will give you thirty energy\n");
					refresh();
					energy += 30;
					napms(2000);
				} else {
					printw("Safe Entity: That's not valid... Ah! I know, maybe you need motivation! Wait a minute...\n");
					refresh();
						napms(4000);
					printw("Safe Entity: %s\n", safeEntityMotivation[disMot(gen)].c_str());
					refresh();
				}
				printw("Done! You don't need me anymore, right? goodbye!\n");
				refresh();
			} else if (ans == 'n') {
				printw("Safe Entity: Okay, goodbye!\n");
				refresh();
			} else {
				printw("Safe Entity: I assumsed you don't need. goodbye!\n");
				refresh();
				}
			cond[index + 1] = '0';
				napms(3000);
				printw("Safe Entity go away...");
				refresh();
				napms(3000);
				clear();
		}
		nodelay(stdscr, TRUE);
		if(entityStepLoop.first == 10) {
			entityStepLoop.first = 0;
		}
		if(entityStepLoop.second == 10) {
			entityStepLoop.second = 0;
		}
		if(entPos.first != -1 && cond[entPos.first + 1] == '0' && std::abs(index - entPos.first) < 10 && entityStepLoop.first == 0) {
			cond[entPos.first] = '0';
			cond[entPos.first + 1] = 'd';
		}
			entityStepLoop.first++;
		if(entPos.second != -1 && cond[entPos.second - 1] == '0' && std::abs(entPos.second - index) < 10 && entityStepLoop.second == 0) {
			cond[entPos.second] = '0';
			cond[entPos.second - 1] = 'd';
		}
			entityStepLoop.second++;
		
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
			if(bCount != 0 && cond[index + 1] == '0') {
				cond[index + 1] = 'b';
				bCount--;
			}
		} else if(inp == 'o') {
			if(bCount != 0 && cond[index - 1] == '0') {
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
		//itensitas dan warna:
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

		for(int j = (index < 3 ? 0 : index - 3); j <= ([&]() -> int {
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
		if(every3SecondEnergy > 0) {
			if(energyLoop2 == 30) {
				energy++;
				energyLoop2 = 0;
			} else energyLoop2++;
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
