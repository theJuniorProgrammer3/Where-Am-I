#include <ncurses.h>
#include <vector>
#include <algorithm>
#include <random>



std::random_device rd;
std::mt19937 gen(rd());
std::vector<char> cond(16, '0');
std::uniform_int_distribution initPos(0, 15);
std::uniform_int_distribution theBlockCount(1, 8);
int blockCount = theBlockCount(gen);
void initWorld() {
cond[initPos(gen)] = 'c';
while(blockCount > 0) {
	int a = initPos(gen);
	if(cond[a] != 'c' && cond[a] != 'b') {
		cond[a] = 'b';
		blockCount--;
	}
}
}

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
std::uniform_int_distribution<> dis(0, 2);
std::bernoulli_distribution disB(0.8);
std::bernoulli_distribution time_to_spawnDE(0.03);
std::uniform_int_distribution<> sDEdis(4, 18);

void expand() {
	char item[] = {'d', 's', 'b'};
	cond.push_back('0');
	cond.push_back('0');
	for(int i = 0; i < 40; i++) {
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
void cutscene() {
	int b;
		for(int a = 4; a >= 1; a--) {
			clear();
			attron(COLOR_PAIR(16 - ((a - 1) * 4)));
	printw("Once a day...");
		attroff(COLOR_PAIR(16 - ((a - 1) * 4)));
		refresh();
		if(a == 1) {
			napms(3000);
		} else {
		napms(500);
		}
		}
		for(int a = 1; a <= 4; a++) {
			clear();
			attron(COLOR_PAIR(16 - ((a - 1) * 4)));
	printw("Once a day...");
		attroff(COLOR_PAIR(16 - ((a - 1) * 4)));
		refresh();
		if(a == 1) {
			napms(3000);
		} else {
		napms(500);
		}
		}
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                 # #\n");
		printw("#                   #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(5000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("##########v##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                 # #\n");
		printw("#                   #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(200);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("##########@##########\n");
		printw("#         v         #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                 # #\n");
		printw("#                   #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(200);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#         @         #\n");
		printw("#         v         #\n");
		printw("#                   #\n");
		printw("#                 # #\n");
		printw("#                   #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(200);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#         @         #\n");
		printw("#         v         #\n");
		printw("#                 # #\n");
		printw("#                   #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(200);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @         #\n");
		printw("#         v       # #\n");
		printw("#                   #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(200);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(2000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("# What's that, prof?#\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(3000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("# A machine to...   #\n");
		printw("#####################\n");
		refresh();
		napms(3000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#   To what, prof?  #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("# A machine to...   #\n");
		printw("#####################\n");
		refresh();
		napms(3000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #<&           #\n");
		printw("#     #           # #\n");
		printw("#to explore 1D world#\n");
		printw("#####################\n");
		refresh();
		napms(4000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("# 1D world? Really? #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(2000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     # <&        # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(200);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #  <&       # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(2000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #   ^         #\n");
		printw("#     #   &       # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(2000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#        ?!?        #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #   ^         #\n");
		printw("#     #   &       # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(2000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #   ^         #\n");
		printw("#     #   &       # #\n");
		printw("# I need guinea pig #\n");
		printw("#####################\n");
		refresh();
		napms(3000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#        So?        #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #   ^         #\n");
		printw("#     #   &       # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(4000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#        So?        #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #   &>      # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(1000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #    &>     # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(1000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #     &>    # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(1000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #      &>   # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(1000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #       &>  # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(1000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #       ^     #\n");
		printw("#     #       &   # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v         #\n");
		printw("#     #       ^   # #\n");
		printw("#     #       &     #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @       # #\n");
		printw("#         v   ^     #\n");
		printw("#     #       &   # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @   ^   # #\n");
		printw("#         v   &     #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#             ^     #\n");
		printw("#         @   &   # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(50);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#         @  <&   # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#     Wait, what?   #\n");
		printw("#         @ <&    # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#     Wait, what?   #\n");
		printw("#         @<&     # #\n");
		printw("#         v         #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#     Wait, what?   #\n");
		printw("#                 # #\n");
		printw("#         @<&       #\n");
		printw("#     #   v       # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#     Wait, what?   #\n");
		printw("#                 # #\n");
		printw("#                   #\n");
		printw("#     #  <@<&     # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#     Wait, what?   #\n");
		printw("#                 # #\n");
		printw("#                   #\n");
		printw("#     # <@<&      # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#     Wait, what?   #\n");
		printw("#                 # #\n");
		printw("#                   #\n");
		printw("#     #<@<&       # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                 # #\n");
		printw("#        NO!!!      #\n");
		printw("#     #@<&        # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(100);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                 # #\n");
		printw("#        NO!!!      #\n");
		printw("#     #<&         # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(3000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                 # #\n");
		printw("#                   #\n");
		printw("#     #<&         # #\n");
		printw("#     #             #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(3000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                 # #\n");
		printw("#                   #\n");
		printw("#     #           # #\n");
		printw("#     #<&           #\n");
		printw("#     #           # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(1000);
		clear();
		b = getch();
		if(b == 'c') return;
		printw("########## ##########\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                   #\n");
		printw("#                 # #\n");
		printw("#                   #\n");
		printw("#     #           # #\n");
		printw("#     #             #\n");
		printw("#     #<&         # #\n");
		printw("#                   #\n");
		printw("#####################\n");
		refresh();
		napms(3000);


}
void cutscene2(int id, int index) {
	clear();
	std::string view = "";
		for(int j = (index < 3 ? 0 : index - 3); j <= ([&]() -> int {
				if(index >= cond.size() - 1 - 5) {
				return cond.size() - 1;
				} else {
				return index + 5;
				}
				})(); j++) {
			view += std::string(cond[j] == 'c' ? "[@]" : (cond[j] != '0' ? "[X]" : "[ ]")) + " ";
		}
		view.pop_back();
	
		napms(2000);
		printw("Me: Where Am I?\n");
		refresh();
		napms(3000);
		printw("Professor: In 1D World\n");
		refresh();
		napms(4000);
		clear();
		printw("Me: Why you threw me here?\n");
		refresh();
		napms(5000);
		printw("Professor: Like I said, I need guinea pig. It's you\n");
		refresh();
		napms(7000);
		clear();
		printw("Me: Why you don't tell me before throw me?\n");
		refresh();
		napms(5000);
		printw("Professor: I too excited, It's first my discovery\n");
		refresh();
		napms(7000);
		clear();
		printw("Me: Why you always say \"first discovery\" every your discovery? Prof, this is the 286th your discovery, not first\n");
		refresh();
		napms(8000);
		printw("Professor: I don't know.\n");
		refresh();
		napms(3000);
		clear();
		printw("Me: You even don't tell me how to survival in this world\n");
		refresh();
		napms(5000);
		printw("Professor: Okay, first, you need to know, your body is actually near me, only your consciousness is put there.\n");
		refresh();
		napms(7000);
		clear();
		printw("Me: If this is not my body, when I killed here, I still alive?\n");
		refresh();
		napms(7000);
		printw("Professor: No, you still die. This is your consciousness, without that, you can't alive. Just fight them, don't be next to that.\n");
		refresh();
		napms(7000);
		clear();
		printw("%s\n", view.c_str());
		napms(1000);
		printw("Me: I see something, what's that?\n");
		refresh();
		napms(5000);
		printw("Professsor: That is your environment.\n");
		refresh();
		napms(5000);
		clear();
		printw("%s\n", view.c_str());
		printw("Me: I don't understand.\n");
		refresh();
		napms(3000);
		printw("Professor: Simply put, it's a map to show you the situation around you.\n");
		refresh();
		napms(8000);
		clear();
		addch('#'| COLOR_PAIR(id));
		printw("\n\n");
		printw("%s\n", view.c_str());
		refresh();
		napms(3000);
		printw("Me: I see something else, what's this?\n");
		refresh();
		napms(5000);
		printw("Professor: It's your right indication. Green mean safe, red mean dabger, white mean you can pick it.\n");
		refresh();
		napms(7000);
		clear();
		addch('#'| COLOR_PAIR(id));
		printw("\n\n");
		printw("%s\n", view.c_str());
		printw("Me: I don't understand\n");
		refresh();
		napms(3000);
		printw("Professor: You'll understand. Your task is collect 200 block\n");
		refresh();
		napms(8000);
		clear();
		printw("Why I have a crazy professor.\n");
		refresh();
		napms(5000);
		clear();
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
	int bCount = 0;
	int inp;
	noecho();
	std::pair<int, int> entityStepLoop = {0, 0};
	int energyLoop = 0;
	int energy = 20;
	bool lose = false;
	bool win = false;
	int every3SecondEnergy = 0;
	int energyLoop2 = 0;
	std::vector<std::string> safeEntityMotivation = {"Even if you have difficulties here, don't give up, there is definitely a way out. Destroy.", "If you meet me, don't be scared, I here for help you.", "If you're running out of energy, don't surrender, I can give it to you.", "Next time don't answer randomly, right?", "If someone approaches you to attack you, but you run out of energy, block him."};
	std::uniform_int_distribution<> disMot(0, safeEntityMotivation.size() - 1);
	while(true) {
		if(bCount == 200) {
			win = true;
			break;
		}
		it = std::find(cond.begin(), cond.end(), 'c');
		index = it - cond.begin();
		auto entPos = findNearestDangerEntity(index);
		if(time_to_spawnDE(gen)) {
			if(disB(gen)) {
				cond[index - sDEdis(gen)] = 'd';
			} else {
				cond[index + sDEdis(gen)] = 'd';
			}
		}
		int ans;
		if(cond[index + 1] == 's') {
			clear();
			printw("Safe Entity: Hello! Nice to meet you, need help?\nn: nope\ne: I need energy\n");
			refresh();
			nodelay(stdscr, FALSE);
			ans = getch();
			if(ans == 'e') {
				printw("Safe Entity: You need energy? Okay, you need every 3 second one energy, or one time thirty energy?\ne: Every 3 Second option\no: One time option\n");
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
		if(entPos.first != -1 && cond[entPos.first + 1] == '0' && std::abs(index - entPos.first) < 20 && entityStepLoop.first == 0) {
			cond[entPos.first] = '0';
			cond[entPos.first + 1] = 'd';
		}
			entityStepLoop.first++;
		if(entPos.second != -1 && cond[entPos.second - 1] == '0' && std::abs(entPos.second - index) < 20 && entityStepLoop.second == 0) {
			cond[entPos.second] = '0';
			cond[entPos.second - 1] = 'd';
		}
			entityStepLoop.second++;
		
		if(cond[index + 1] == 'd' || cond[index - 1] == 'd') {
			lose = true;
			break;
		}
	bool noStep = true;
		clear();
		inp = getch();
		if(inp == 'q') break;
		if(energy > 0) {
		if(inp == KEY_RIGHT) {
			if(index < cond.size() - 6) {
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
			
		} else if(inp == 'd') {
			if(energy >= 3) {
			energy = energy - 3;
			if(cond[index - 2] == 'd') {
			cond[index - 2] = '0';
			}
			}
		}
		}

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
	}
		}
	endwin();
 }
