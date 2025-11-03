
void qa() {
	clear();
	attroff(COLOR_PAIR(18));
	printw("Coming soon...\n");
	printw("Press any key to exit.");
	getch();
}

void menu() {
	bool select = 1; // 'Play'
	int input;
	if(has_colors()) {
		while(true) {
		attroff(COLOR_PAIR(18));
		printw("Where Am I game\n");
		printw("Press 's' to select\n");
		(select ? attron(COLOR_PAIR(18)) : attroff(COLOR_PAIR(18)));
		printw("Play\n");
		(select ? attroff(COLOR_PAIR(18)) : attron(COLOR_PAIR(18)));
		printw("Q&A\n");
		refresh();
		input = getch();
		if(input != 's') {
			select = !select;
		} else {
			if(select) {
				break;
			} else {
				qa();
			}
		}
		clear();
		}
	} else {
		while(true) {
		clear();
		printw("Where Am I game\n");
		printw("Press 's' to select\n");
		printw("Play %s", (select ?  " <\n" : "\n"));
		printw("Q&A %s", (select ?  " \n" : "<\n"));
		refresh();
		input = getch();
		if(input != 's') {
			select = !select;
		} else {
			if(select) {
				break;
			} else {
				qa();
			}
		}
		clear();
		}
	}
	clear();
}

