#include <ncurses.h>
#include <vector>
#include <algorithm>

int main() {
	initscr();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	std::vector<bool> cond = {0, 0, 0, 1, 0, 0, 0};
	/*printw("Click 'c' to skip cutscene");
	napms(4000);*/
	int inp;
	while(true) {
		clear();
		inp = getch();
		if(inp == KEY_RIGHT) {
			auto it = std::find(cond.begin(), cond.end(), 1);
			int index = it - cond.begin();
			cond[index] = 0;
			cond[index + 1] = 1;
		} else if(inp == KEY_LEFT) {
			auto it = std::find(cond.begin(), cond.end(), 1);
			int index = it - cond.begin();
			cond[index] = 0;
			cond[index - 1] = 1;
		} else if(inp == 'q') break;
		for(auto m : cond) {
			printw((m == 1 ? "[@]" : "[ ]"));
		}
		refresh();
		napms(100);
	}
	endwin();
}
