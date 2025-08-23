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

