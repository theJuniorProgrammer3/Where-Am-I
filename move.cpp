
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
                        health -= 3;
			if(health <= 0) {
				lose = true;
				break;
			}
                }
        bool noStep = true;
	if(speed != 1) {
		speedLoop++;
	} else if(speedLoop == 3001) {
		speed = 1;
		speedLoop = 0;
	}
                clear();
                inp = getch();
                if(inp == 'q') break;
                if(energy > 0) {
                if(inp == KEY_RIGHT) {
                        if(index < cond.size() - 6) {
                        energy--;
                        noStep = false;
                        cond[index] = '0';
			auto collide = detectCollide(cond, index + 1, index + speed + 1); 
			if(collide.first == true) {
				cond[collide.second - 1] = 'c';
			} else {
                        cond[index + speed] = 'c';
			}
                        } else {
                        energy--;
                        noStep = false;
                        cond[index] = '0';
                                cond[index + speed] = 'c';
                                expand();
                        }
                } else if(inp == KEY_LEFT) {
                        if(index > 0) {
                                energy--;
                                noStep = false;
                        cond[index] = '0';
			auto collide = detectCollide(cond, index + 1, index - speed - 1); 
			if(collide.first == true) {
				cond[collide.second + 1] = 'c';
			} else {
                        cond[index - speed] = 'c';
			}
                        }
                } else if(inp == 'b') {
                        if(cond[index + 1] != '0') {
			switch (cond[index + 1]) {
				case 'b':
                        		itemCount[0]++;
					break;
				case 'a':
					itemCount[1]++;
					break;
				case 'r':
					itemCount[2]++;
					break;
				case 'i':
					itemCount[3]++;
					break;
			}
                        cond[index + 1] = '0';
                        }
                } else if(inp == 'v') {
                        if(cond[index - 1] != '0') {
			switch (cond[index - 1]) {
				case 'b':
                        		itemCount[0]++;
					break;
				case 'a':
					itemCount[1]++;
					break;
				case 'r':
					itemCount[2]++;
					break;
				case 'i':
					itemCount[3]++;
					break;
			}
                        cond[index - 1] = '0';
                        }
                } else if(inp == 'p') {
                        if(itemCount[0] != 0 && cond[index + 1] == '0') {
                                cond[index + 1] = 'b';
                                itemCount[0]--;
                        }
                } else if(inp == 'o') {
                        if(itemCount[0] != 0 && cond[index - 1] == '0') {
                                cond[index - 1] = 'b';
                                itemCount[0]--;
                        }
                } else if(inp == 'f') {
                        if(energy >= 3) {
                        energy = energy - 3;
			if(cond[index + 1] == '0') {
                        if(cond[index + 2] == 'd') {
                        cond[index + 2] = '0';
                        }
			} else if(cond[index + 1] == 'd') {
				cond[index + 1] = '0';
			}
                        }

                } else if(inp == 'd') {
                        if(energy >= 3) {
                        energy = energy - 3;
			if(cond[index - 1] == '0') {
                        if(cond[index - 2] == 'd') {
                        cond[index - 2] = '0';
                        }
			} else if(cond[index - 1] == 'd') {
				cond[index - 1] = '0';
			}
                        }
                } else if(inp == '1') {
			// makan apel: boost energy 10
			if(itemCount[1] > 0) {
			energy += 10;
			itemCount[1]--;
			}
		} else if(inp == '2') {
			// makan wortel: vision lebih luas
			if(itemCount[2] > 0) {
			expandedVision = true;
			itemCount[2]--;
			}
		} else if(inp == '3') {
			//makan cabai: lari lebih cepat dengan konsumsi energi yang sama
			if(itemCount[3] > 0) {
			speed += 2;
			itemCount[3]--;
			}
		}
                }

