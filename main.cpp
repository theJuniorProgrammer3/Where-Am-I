#include <ncurses.h>
#include <vector>
#include <algorithm>

int main() {
	initscr();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	std::vector<char> cond = {'0', 'b', '0', 'c', '0', '0', '0', '0', 'b', 'b', 'b', '0'};
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
		for(auto m : cond) {
			printw((m == 'c' ? "[@]" : (m == 'b' ? "[X]" : "[ ]")));
		}
		printw("\nBlock in inventory: %d", bCount);
		refresh();
		napms(100);
	}
	endwin();
}
