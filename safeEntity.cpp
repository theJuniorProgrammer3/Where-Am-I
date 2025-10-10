
				    std::vector<std::string> safeEntityMotivation = {"Even if you have difficulties here, don't give up, there is definitely a way out. Destroy.", "If you meet me, don't be scared, I here for help you.", "If you're running out of energy, don't surrender, I can give it to you.", "Next time don't answer randomly, right?", "If someone approaches you to attack you, but you run out of energy, block him."};
				std::uniform_int_distribution<> disMot(0, safeEntityMotivation.size() - 1);
				int ans;
if(cond[index + 1] == 's') {
                        clear();
                        printw("Safe Entity: Hello! Nice to meet you, need help?\nn: nope\ny: yes\n");
                        refresh();
                        nodelay(stdscr, FALSE);
                        ans = getch();
                        if(ans == 'y') {
                                printw("Safe Entity: You need help? Okay, you need every 3 second one energy, or one time thirty energy, or even want more health?\ne: Every 3 Second option\no: One time option\nh: health\nm: Motivation\n");
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
                                } else if (ans == 'h') {
				printw("Safe Entity: I will give you 40 health\n");
				refresh();
				napms(3000);
				health += 40;
				printw("Done!\n");
				refresh();
			} else if (ans == 'm') {
				printw("Safe Entity: Motivation, ya? Wait a minute...\n");
				refresh();
				napms(3000);
				printw("Safe Entity: %s\n", safeEntityMotivation[disMot(gen)].c_str());
				refresh();
			} else {
                                        printw("Safe Entity: That's not valid... Ah! I know, maybe you need motivation! Wait a minute...\n");
                                        refresh();
                                                napms(4000);
                                        printw("Safe Entity: %s\n", safeEntityMotivation[disMot(gen)].c_str());
                                        refresh();
                                }
                                printw("Safe Entity: Done! You don't need me anymore, right? goodbye!\n");
                                refresh();
                        } else if (ans == 'n') {
                                printw("Safe Entity: Okay, goodbye!\n");
                                refresh();
                        } else {
                                        printw("Safe Entity: That's not valid... Ah! I know, maybe you need motivation! Wait a minute...\n");
                                        refresh();
                                                napms(4000);
                                        printw("Safe Entity: %s\n", safeEntityMotivation[disMot(gen)].c_str());
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
