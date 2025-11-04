void qa() {
	clear();
	attroff(COLOR_PAIR(18));
	printw("Coming soon...\n");
	printw("Press any key to exit.");
	getch();
}

vector<int> load() {
	std::ifstream file(".data.txt");
	vector<int> tmp;
	int tmp2;
	if(file.is_open()) {
		while(file >> tmp2) {
			tmp.push_back(tmp2);
		}
	} else {
		tmp.push_back(0);
	}
	file.close();
	return tmp;
}
void save(vector<int> data) {
	std::ofstream file(".data.txt");
	for(auto piece : data) {
		file << piece << " ";
	}
	file.close();
}

void acv() {
	auto data = load();
	clear();
	attroff(COLOR_PAIR(18));
	if(data[0] == 0) {
		printw("You haven't any achievements.\n");
		printw("Press any key to exit.");
		getch();
	} else {
		std::unordered_map<int, string> itoa {
			{1, "Bad ending"},
			{2, "Good ending"},
			{3, "Bad ending 2"},
			{4, "Truth ending"},
			{5, "Secret ending"}
			// untuk versi ini, hanya ending dulu
			// for this version, only endings are exists
		};
		while(true) {
			clear();
			for(auto i : data) {
				try {
					printw("%s\n", itoa.at(i).c_str());
				} catch(const out_of_range& e) {
					printw("Unknown achievement\n");
				}
			}
			printw("Press 'q' to exit");
			refresh();
			int inp = getch();
			if(inp == 'q') break;
		}
	}
}
// hanya menyimpan dan muat penghargaan
// only save and load achievements

void menu() {
	int select = 0; // 'Play'
	int input;
	if(has_colors()) {
		while(true) {
		attroff(COLOR_PAIR(18));
		printw("Where Am I game\n");
		printw("Press 's' to select\n");
		(select == 0 ? attron(COLOR_PAIR(18)) : attroff(COLOR_PAIR(18)));
		printw("Play\n");
		(select == 1 ? attron(COLOR_PAIR(18)) : attroff(COLOR_PAIR(18)));
		printw("Q&A\n");
		(select == 2 ? attron(COLOR_PAIR(18)) : attroff(COLOR_PAIR(18)));
		printw("Achievements\n");
		refresh();
		input = getch();
		if(input != 's') {
			(select == 2 ? select = 0 : select++);
		} else {
			if(select == 0) {
				break;
			} else if(select == 1) {
				qa();
			} else if(select == 2) {
				acv();
			}
		}
		clear();
		}
	} else {
		while(true) {
		clear();
		printw("Where Am I game\n");
		printw("Press 's' to select\n");
		printw("Play %s", (select  == 0 ?  " <\n" : "\n"));
		printw("Q&A %s", (select  == 1 ?  " <\n" : " \n"));
		printw("Achievements %s", (select  == 2 ?  " <\n" : " \n"));
		refresh();
		input = getch();
		if(input != 's') {
			(select == 2 ? select = 0 : select++);
		} else {
			if(select == 0) {
				break;
			} else if(select == 1) {
				qa();
			} else if(select == 2) {
				acv();
			}
		}
		clear();
		}
	}
	clear();
}

