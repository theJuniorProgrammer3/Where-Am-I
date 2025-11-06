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

vector<pair<string, string>> getAvailableQa() {
	vector<pair<string, string>> tmp = {
		{"What is 'Where Am I'?", "Read README.me please."},
		{"Is there foods?", "Yes, there is one in your fridge."},
		{"Is this game fun?", "The answer depends on the player."}
	};
	auto theAcv = load();
	if(find(theAcv.begin(), theAcv.end(), 1) != theAcv.end()) {
		tmp.push_back({"Why Dangerous Entity eats 'Me'?", "That's its job."});
		tmp.push_back({"Who is Dangerous Entity?", "Its is an Entity (:P)"});
	}
	if(find(theAcv.begin(), theAcv.end(), 2) != theAcv.end()) {
		tmp.push_back({"Why didn't the professor look happy when I came back?", "Something is wrong here."});
		tmp.push_back({"Why did the Dangerous Entity become more aggressive when I collected 170 blocks?", "Someone is disappointed."});
	}
	if(find(theAcv.begin(), theAcv.end(), 3) != theAcv.end()) {
		tmp.push_back({"What happens with the player in Bad Ending 2?", "It dies."});
		tmp.push_back({"SCP-256? What's that?", "Follow the advice from Safe Entity."});
	}
	if(find(theAcv.begin(), theAcv.end(), 4) != theAcv.end()) {
		tmp.push_back({"Why professor can forgot?", "Everyone can forget."});
		tmp.push_back({"What happens with SCP-256 in Truth Ending?", "It was gone from existence."});
	}
	if(find(theAcv.begin(), theAcv.end(), 5) != theAcv.end()) {
		tmp.push_back({"What the Secrect Ending mean?", "I don't know either."});
		tmp.push_back({"1D + 1D = ?","It is equal to 'You play Where Am I twice'."});
	}
	// initial q&a
	return tmp; 
}

void qa() {
	clear();
	attroff(COLOR_PAIR(18));
	auto qa = getAvailableQa();
	int select = 0;
	int input;
	if(has_colors()) {
		while(true) {
		attroff(COLOR_PAIR(18));
		printw("FAQ\n");
		printw("Press 's' to select, 'q' to exit\n\n");
		for(int i = 0; i < qa.size(); i++) {
			if(i == select) attron(COLOR_PAIR(18));
			printw("Q: %s\n", qa[i].first.c_str());
			if(i == select) attroff(COLOR_PAIR(18));
		}
		refresh();
		input = getch();
		if(input == KEY_UP) {
			(select == 0 ? select = qa.size() - 1 : select--);
		} else if(input == KEY_DOWN) {
			(select == qa.size() - 1 ? select = 0 : select++);
		} else if(input == 's') {
			clear();
			printw("Q: %s\n", qa[select].first.c_str());
			printw("A: %s\n", qa[select].second.c_str());
			printw("\nPress any key to exit\n");
			getch();
			refresh();
		} else if(input == 'q') {
			clear();
			break;
		}
		clear();
		}
	} else {
		while(true) {
		printw("FAQ\n");
		printw("Press 's' to select, 'q' to exit\n\n");
		for(int i = 0; i < qa.size(); i++) {
			printw("Q: %s %s\n", qa[i].first.c_str(), (i == select ? "<==" : ""));
		}
		refresh();
		input = getch();
		if(input == KEY_UP) {
			(select == 0 ? select = qa.size() - 1 : select--);
		} else if(input == KEY_DOWN) {
			(select == qa.size() - 1 ? select = 0 : select++);
		} else if(input == 's') {
			clear();
			printw("Q: %s\n", qa[select].first.c_str());
			printw("A: %s\n", qa[select].second.c_str());
			printw("\nPress any key to exit\n");
			getch();
			refresh();
		} else if(input == 'q') {
			clear();
			break;
		}
		clear();
		}
	}
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

