#include <ncurses.h>
#include <vector>
#include <algorithm>

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
	while(true) {
		clear();
		inp = getch();
		if(inp == KEY_RIGHT) {
			auto it = std::find(cond.begin(), cond.end(), 'c');
			int index = it - cond.begin();
			if(cond[index + 1] == '0') {
			cond[index] = '0';
			cond[index + 1] = 'c';
			}
		} else if(inp == KEY_LEFT) {
			auto it = std::find(cond.begin(), cond.end(), 'c');
			int index = it - cond.begin();
			if(cond[index - 1] == '0') {
			cond[index] = '0';
			cond[index - 1] = 'c';
			}
		} else if(inp == 'b') {
			auto it = std::find(cond.begin(), cond.end(), 'c');
			int index = it - cond.begin();
			if(cond[index + 1] == 'b') {
			cond[index + 1] = '0';
			bCount++;
			}
		} else if(inp == 'v') {
			auto it = std::find(cond.begin(), cond.end(), 'c');
			int index = it - cond.begin();
			if(cond[index - 1] == 'b') {
			cond[index - 1] = '0';
			bCount++;
			}
		} else if(inp == 'p') {
			auto it = std::find(cond.begin(), cond.end(), 'c');
			int index = it - cond.begin();
			if(bCount != 0) {
				cond[index + 1] = 'b';
				bCount--;
			}
		} else if(inp == 'o') {
			auto it = std::find(cond.begin(), cond.end(), 'c');
			int index = it - cond.begin();
			if(bCount != 0) {
				cond[index - 1] = 'b';
				bCount--;
			}
		} else if(inp == 'q') break;

		auto it = std::find(cond.begin(), cond.end(), 'c');
		int index = it - cond.begin();
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


		for(auto m : cond) {
			printw((m == 'c' ? "[@]" : (m != '0' ? "[X]" : "[ ]")));
		}
		printw("\nBlock in inventory: %d", bCount);
		refresh();
		napms(100);
	}
	endwin();
}
