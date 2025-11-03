void initWorld() {
int blockCount = theBlockCount(gen);
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

void expand() {
	char item[] = {'d', 's', 'b', 'a', 'r', 'i', 'p'};
	cond.push_back('0');
	cond.push_back('0');
	for(int i = 0; i < 40; i++) {
		if(disB(gen)) {
			cond.push_back('0');
		} else {
			if(disTB(gen)) {
				cond.push_back('b');
			} else {
				cond.push_back(item[dis(gen)]);
			}
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
