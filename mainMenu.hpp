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
		tmp.push_back(0);
	}
	file.close();
	return tmp;
}
void save(vector<int> data, int dies) {
	std::ofstream file(".data.txt");
	for(auto piece : data) {
		file << piece << " ";
	}
	file << "\n" << dies;
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
		tmp.push_back({"Why don't Dangerous Entities just eat foods?", "It's same with you, why you eat bread? Delicious? Not really."});
	}
	if(find(theAcv.begin(), theAcv.end(), 2) != theAcv.end()) {
		tmp.push_back({"Why didn't the professor look happy when I came back?", "Something is wrong here."});
		tmp.push_back({"Why did the Dangerous Entity become more aggressive when I collected 170 blocks?", "Someone is disappointed."});
		tmp.push_back({"Why Safe Entity recomend me to collect 256 block instead of 200?", "Why don't you try it yourself?"});
		tmp.push_back({"Why professor compliments 'Me'?", "How hard to survive on unknown world?!!"});
		tmp.push_back({"Why professor always excited with his discovery?", "I don't know, it's professor's secret, ssh."});
	}
	if(find(theAcv.begin(), theAcv.end(), 3) != theAcv.end()) {
		tmp.push_back({"What happens with the player in Bad Ending 2?", "It dies."});
		tmp.push_back({"SCP-256? What's that?", "Follow the advice from Safe Entity."});
		tmp.push_back({"What did the professor do?", "He is do bloody things to 'Me'."});
		tmp.push_back({"Why professor do that?", "Because something wrong here."});
		tmp.push_back({"'[CENCORED]'? Why?", "Are you want to look that action?"});
	}
	if(find(theAcv.begin(), theAcv.end(), 4) != theAcv.end()) {
		tmp.push_back({"Why professor can forgot?", "Everyone can forget."});
		tmp.push_back({"What happens with SCP-256 in Truth Ending?", "It was gone from existence."});
		tmp.push_back({"Who is SCP-255?", "AHHH! Wait for it."});
		tmp.push_back({"Is professor 'Me''s father?", "Didn't you read the cutscenes?"});
		// not :P
		// ugh, weird: "'Me''s"
		tmp.push_back({"What do professors plan pranks for?", "Everyone wants to joke, right?"});
	}
	if(find(theAcv.begin(), theAcv.end(), 5) != theAcv.end()) {
		tmp.push_back({"What the Secrect Ending mean?", "I don't know either."});
		tmp.push_back({"1D + 1D = ?","It is equal to 'You play Where Am I twice'."});
		tmp.push_back({"Why 'Where Am I?'?", "Because 'There you are.'."});
	}
	if(find(theAcv.begin(), theAcv.end(), 6) != theAcv.end()) {
		tmp.push_back({"Why 'Me' got a lot of dies?", "This is a game, right?"});
		tmp.push_back({"It's hurt when 'Me' eaten by Dangerous Entiy?", "How about you?"});
		tmp.push_back({"Who is professor?", "He is a scientist."});
	};
	if(find(theAcv.begin(), theAcv.end(), 7) != theAcv.end()) {
		tmp.push_back({"Why 'Me' got VERY lot of dies?", "It's EXTREMLY... , y'know."});
		tmp.push_back({"Who is SCP-255?", "Wait for Why Am Here game. I think you bored here. This game even not released yet!"});
		// Saya bahkan belum merencanakan bagaimana gamenya
		// I even don't planning how the game look yet
		tmp.push_back({"Is the player hack save data?", "This is probably YES. But if no.... WOW?!"});
	}
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
	data.pop_back(); // delete dies
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
			{5, "Secret ending"},
			{6, "Hundred dies"},
			{7, "Million dies"}
			// sedang diperbanyak
			// on expanding
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

