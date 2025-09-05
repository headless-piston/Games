#include<cstdio>
#include<time.h>
#include<windows.h>
#include<string>
int none, random;
int ch1, oklog;
int l, yes;
int user[6], num, logging, continueing;
int choose, choose1, choose2;
int change1, change2;
long long hp0[4], xp0[4], lv0[4], cd0[4], hup[4], hp, xp, lv, cd, hg;
int answer;
char p[4][6], pc;
char tryp, trypc;
char green[6]={"green"},yellow[7]={"yellow"},red[4]={"red"},purple[7]={"purple"},gray[5]={"gray"},white[6]={"white"};
struct Users {
	long long hp,xp,lv,ch,hup;
};
void color(char clr[]) {
	if(!strcmp(clr,green)){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	}else if(!strcmp(clr,yellow)){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}else if(!strcmp(clr,red)){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	}else if(!strcmp(clr,purple)){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	}else if(!strcmp(clr,gray)){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}else if(!strcmp(clr,white)){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}
void create() {
	if (choose2 >= 1 && choose2 <= 4 && !user[choose2 - 1]) {
		user[choose2 - 1] = 1;
		printf("set the password(6 words)\n");
		//fflush(stdin);
		for (int i = 0; i < 6;) {
			scanf("%c", &pc);
			if ((pc >= 'a' && pc <= 'z') || (pc >= 'A' && pc <= 'Z') || (pc >= '0' && pc <= '9')) {
				p[choose2 - 1][i] = pc;
				i++;
			}
		}
		printf("successful to create\n");
	} else if (user[choose2 - 1]) {
		printf("this number is already appeared,please change your number\n");
	} else if (choose2 < 1 || choose2 > 4) {
		printf("this number is not in the list\n");
	}
}
void login() {
	if (user[choose1 - 1]) {
		yes=0;
		printf("show the password\n");
		for (int i = 0; i < 6;) {
			scanf("%c", &trypc);
			if ((trypc >= 'a' && trypc <= 'z') || (trypc >= 'A' && trypc <= 'Z') || (trypc >= '0' && trypc <= '9')) {
				tryp = trypc;
				if (tryp == p[choose1 - 1][i]) {
					yes++;
				}
				i++;
			}
		}
		if(yes==6) {
			oklog=1;
		} else {
			oklog=0;
		}
	} else {
		printf("the number is unappeared,please create it or try another one\n");
		oklog = 2;
	}
}
void upgrade() {
	int first=lv0[logging];
	if (xp0[logging] < 20) {
		lv0[logging] = 1;
	}
	if (xp0[logging] >= 20 && xp0[logging] < 100) {
		lv0[logging] = 2;
	}
	if (xp0[logging] >= 100 && xp0[logging] < 200) {
		lv0[logging] = 3;
	}
	if (xp0[logging] >= 200 && xp0[logging] < 500) {
		lv0[logging] = 4;
	}
	if (xp0[logging] >= 500 && xp0[logging] < 1000) {
		lv0[logging] = 5;
	}
	if (xp0[logging] >= 1000 && xp0[logging] < 1500) {
		lv0[logging] = 6;
	}
	if (xp0[logging] >= 1500 && xp0[logging] < 2000) {
		lv0[logging] = 7;
	}
	if (xp0[logging] >= 2000 && xp0[logging] < 3000) {
		lv0[logging] = 8;
	}
	if (xp0[logging] >= 3000 && xp0[logging] < 5000) {
		lv0[logging] = 9;
	}
	if (xp0[logging] >= 5000 && xp0[logging] < 10000) {
		lv0[logging] = 10;
	}
	if (xp0[logging] >= 10000) {
		lv0[logging] = 11;
	}
	if(lv0[logging]>first) {
		color(green);
		printf("\nYou Upgrade %lld Level",lv0[logging]-first);
		if(lv0[logging]-first>1) {
			printf("s");
		}
		printf("!\n\n");
	}
}
void thing() {
	color(gray);
	srand(time(nullptr));
	random = rand() % 2049;
	int ran = random % 19;
	switch (ran) {
		case 0: {
			color(red);
			printf("Nothing happens...But you walk into a deep hole.\n");
			printf("You lost %d hp.\n", random % 10 + 1);
			hp0[logging] -= random % 10 + 1;
			printf("You have hp:%lld\n", hp0[logging]);
			break;
		}
		case 1: {
			printf("You fall into a lake and meet a monster of level:%d.\n", random % 10 + 1);
			if (lv0[logging] >= random % 10 + 1) {
				color(green);
				printf("You win it and get some xp.\n");
				printf("You lost %d hp and get %d xp.\n", random % 5, random % 20 + 10 * (random % 10) + 10);
				hp0[logging] -= random % 5;
				xp0[logging] += random % 20 + 10 * (random % 10) + 10;
				printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
			} else {
				color(red);
				printf("You are lost,and you get little xp.\n");
				printf("You lost %lld hp and get %d xp.\n", random % 15 + random % 10 + 1 - lv0[logging], random % 5 + 5);
				hp0[logging] -= random % 15 + random % 10 + 1 - lv0[logging];
				xp0[logging] += random % 5 + 5;
				printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
			}
			break;
		}
		case 2: {
			printf("You meet an old man.He asks you:");
			if (random % 3 == 0) {
				printf("Do you want to buy this book?(Yes:1,No:0)\n");
				//fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (lv0[logging] > random % 10) {
						color(green);
						printf("You read and understand this book successfully,and you get much xp.\n");
						printf("You get %d xp.\n", random % 50 + 20);
						xp0[logging] += random % 50 + 20;
						printf("You have xp:%lld\n", xp0[logging]);
					} else if (lv0[logging] == random % 10) {
						color(red);
						printf("This book is similar to you!You are mixed,and...you get big hurt!\n");
						printf("You lost %d hp.\n", random % 40 + 10);
						hp0[logging] -= random % 40 + 10;
						printf("You have hp:%lld\n", hp0[logging]);
					} else if (lv0[logging] < random % 10) {
						color(gray);
						printf("You cannot understand this book,and nothing else happens.\n");
					}
				} else if (answer == 0) {
					printf("Nothing else happens.\n");
				}
			}
			if (random % 3 == 1) {
				printf("Can you fight with me for fun?(Yes:1,No:0)\n");
				//fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (lv0[logging] > random % 6) {
						color(green);
						printf("You win.The old man is very happy,and he gives you a notebook.You learn a lot from it.\n");
						printf("You get %d xp.\n", random % 60 + 10);
						xp0[logging] += random % 60 + 10;
						printf("You have xp:%lld\n", xp0[logging]);
					} else if (lv0[logging] <= random % 6) {
						color(red);
						printf("You are lost.The old man laughes,and he tells you do not be sad.But you do not feel much better.\n");
						printf("You lost %d hp and get %d xp.\n", random % 20 + 5, random % 40);
						hp0[logging] -= random % 20 + 5;
						xp0[logging] += random % 40;
						printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens.\n");
				}
			}
			if (random % 3 == 2) {
				printf("Is it your thing?(Yes:1,No:0)\n");
				//fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 2 == 1) {
						color(red);
						printf("The old man take the thing into his clothes.He says:It is my thing.You lied.\n");
						printf("You lost %d xp.\n", random % 20 + 3);
						xp0[logging] -= random % 20 + 3;
						printf("You have xp:%lld\n", xp0[logging]);
					} else if (random % 2 == 0) {
						color(green);
						printf("The old man gives you the axe.He says:Please do not let your things lost.Remember!\n");
						printf("You get %d xp.\n", random % 20);
						xp0[logging] += random % 20;
						printf("You have xp:%lld\n", xp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens.\n");
				}
			}
			break;
		}
		case 3: {
			printf("When you are walking through the forest,you find a");
			if (random % 5 == 0) {
				printf(" monster.\n");
				printf("Will you fight with it?(Yes:1,No:0)\n");
				//fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (lv0[logging] >= random % 12) {
						color(green);
						printf("You win,and you get some xp.\n");
						printf("You lost %d hp and get %d xp.\n", random % 10 + 1, random % 30 + 10);
						hp0[logging] = hp0[logging] - random % 10 - 1;
						xp0[logging] = xp0[logging] + random % 30 + 10;
						printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
					} else if (lv0[logging] < random % 12) {
						color(red);
						printf("You are lost,and you get hurt.\n");
						printf("You lost %d hp and get %d xp.\n", random % 15 + 2, random % 20 + 5);
						hp0[logging] = hp0[logging] - random % 15 - 2;
						xp0[logging] = xp0[logging] + random % 20 + 5;
						printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens.\n");
				}
			}
			if (random % 5 == 1) {
				printf(" peach with a good smell.\n");
				printf("Will you eat it?(Yes:1,No:0)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 3 == 0) {
						color(red);
						printf("This is a trap!You have been poisoned!\n");
						printf("You lost %d hp and %d xp.\n", random % 20 + 5, random % 20 + 3);
						hp0[logging] = hp0[logging] - random % 20 - 5;
						xp0[logging] = xp0[logging] - random % 20 - 3;
						printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
					} else {
						color(green);
						printf("It tastes good and your body become stronger.\n");
						printf("You get %d hp.\n", random % 15 + 3);
						hp0[logging] = hp0[logging] + random % 15 + 3;
						printf("You have hp:%lld\n", hp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens.\n");
				}
			}
			if (random % 5 == 2) {
				printf(" human who are in such a pain.\n");
				printf("Can you help him?(Yes:1,No:0)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 2 == 1) {
						printf("You get into a trouble!He is faking it.When you are getting near him,he suddenly wake up and hit you!\n");
						if (lv0[logging] > random % 8 + 1) {
							color(green);
							printf("You hit him successfully.He runs away.\n");
							printf("You lost %d hp and get %d xp.\n", random % 15 + 2, random % 20 + 10);
							hp0[logging] = hp0[logging] - random % 15 - 2;
							xp0[logging] = xp0[logging] + random % 20 + 10;
							printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
						} else if (lv0[logging] <= random % 8 + 1) {
							color(red);
							printf("He hits you hard,and steal some of your money.\n");
							printf("You lost %d hp and get %d xp.\n", random % 30 + 5, random % 20 + 5);
							hp0[logging] = hp0[logging] - random % 30 - 5;
							xp0[logging] = xp0[logging] + random % 20 + 5;
							printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
						}
					} else if (random % 2 == 0) {
						color(green);
						printf("This man is very thankful to you.He give you something as the gift.\n");
						printf("You get %d xp.\n", random % 30 + 10);
						xp0[logging] = xp0[logging] + random % 30 + 10;
						printf("You have xp:%lld\n", xp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens.\n");
				}
			}
			if (random % 5 == 3) {
				printf(" tree which wood is very good for your body while you taking breaks.\n");
				printf("Do you cut it down?(Yes:1,No:0)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 2 == 1) {
						printf("Oh,the tree is a monster...You have to fight with it!\n");
						if (lv0[logging] > random % 9 + 1) {
							color(green);
							printf("You win,and you get much xp from it.\n");
							printf("You lost %d hp and get %d xp.\n", random % 10 + 2, random % 30 + 5);
							hp0[logging] = hp0[logging] - random % 10 - 2;
							xp0[logging] = xp0[logging] + random % 30 + 5;
						} else if (lv0[logging] <= random % 9 + 1) {
							color(red);
							printf("You lost.The monster gets some of your spirit.You become very weak.\n");
							printf("You lost %d hp and get %d xp.\n", random % 20 + 5, random % 20 + 3);
							hp0[logging] = hp0[logging] - random % 20 - 5;
							xp0[logging] = xp0[logging] + random % 20 + 3;
							printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
						}
					} else if (random % 2 == 0) {
						color(green);
						printf("You cut down the tree smoothly.\n");
						printf("You get %d hp and %d xp.\n", random % 10 + 5, random % 20 + 5);
						hp0[logging] = hp0[logging] + random % 10 + 5;
						xp0[logging] = xp0[logging] + random % 20 + 5;
						printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens...\n");
				}
			}
			if (random % 5 == 4) {
				printf(" butterfly flying in the sky,and it seems letting you go with it.\n");
				printf("Do you run after it?(Yes:1,No:0)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 2 == 1) {
						color(red);
						printf("You seem only look at the butterfly,and do not notice the big hole under your feet...\n");
						printf("You lost %d hp and get %d xp.\n", random % 10 + 5, random % 5 + 5);
						hp0[logging] -= random % 10 + 5;
						xp0[logging] += random % 5 + 5;
						printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
					} else if (random % 2 == 0) {
						color(green);
						printf("The butterfly leads you to a good place to practice your skills.\n");
						printf("You get %d xp.\n", random % 30 + 10);
						xp0[logging] = xp0[logging] + random % 30 + 10;
						printf("You have xp:%lld\n", xp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens...\n");
				}
			}
			break;
		}
		case 4: {
			printf("When you are practicing your skills,you meet a child.He says:");
			if (random % 3 == 0) {
				printf("Can you help me solve this problem?(Yes:1,No:0)\n");
				//fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (lv0[logging] > random % 10 + 1) {
						color(green);
						printf("You solve this,and the child is so happy that he gives you some special candies.\n");
						printf("You get %d xp and %d candy.\n", random % 30 + 5, random % 5 + 1);
						xp0[logging] += random % 30 + 5;
						cd0[logging] += random % 5 + 1;
						printf("You have xp:%lld,cd:%lld\n", xp0[logging], cd0[logging]);
					} else {
						color(red);
						printf("You can not solve this either.The child is unhappy,and you,too.\n");
						printf("You lost %d xp.\n", random % 10 + 5);
						xp0[logging] -= random % 10 + 5;
						printf("You have xp:%lld\n", xp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens...\n");
				}
			}
			if (random % 3 == 1) {
				printf("Can I be your student?(Yes:1,No:0)\n");
				//fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (lv0[logging] > random % 11 + 1) {
						color(green);
						printf("Your skills are great to the child.Both you are happy,so the child give you some candies as the price of learning from you.\n");
						printf("You get %d xp and %d candy.\n", random % 30 + 7, random % 5 + 1);
						xp0[logging] += random % 30 + 7;
						cd0[logging] += random % 5 + 1;
						printf("You have xp:%lld,cd:%lld\n", xp0[logging], cd0[logging]);
					} else {
						color(red);
						printf("You realize that this kid is even stronger than you...\n");
						printf("You lost %d xp.\n", random % 8 + 5);
						xp0[logging] -= random % 8 + 5;
						printf("You have xp:%lld\n", xp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens...\n");
				}
			}
			if (random % 3 == 2) {
				printf("May I send this poor cat to you?(Yes:1,No:0)\n");
				//fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 2 == 1) {
						color(red);
						printf("Although you try your best to save this cat,it is died no long goes.Both you are sad.\n");
						printf("You lost %d xp.\n", random % 20 + 5);
						xp0[logging] -= random % 20 + 5;
						printf("You have xp:%lld\n", xp0[logging]);
					} else {
						color(green);
						printf("You save the cat successfully.You are very happy.The child gives you some candies as his gift for it.\n");
						printf("You get %d xp and %d candy.\n", random % 30 + 10, random % 5 + 1);
						xp0[logging] += random % 30 + 10;
						cd0[logging] += random % 5 + 1;
						printf("You have xp:%lld,cd:%lld\n", xp0[logging], cd0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens...\n");
				}
			}
			break;
		}
		case 5: {
			printf("When you are fishing,");
			if (random % 5 == 0) {
				printf("you find a box floating on the water.Do you open it?(Yes:1,No:0)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 3 == 0) {
						color(green);
						printf("You find a book in it.After reading it,you feel that your body is full of enegry.\n");
						printf("You get %lld xp.\n", random % 50 * lv0[logging]);
						xp0[logging] += random % 50 * lv0[logging];
						printf("You have xp:%lld\n", xp0[logging]);
					} else {
						color(red);
						printf("You find a ghost in it!It gets some of your spirit!\n");
						printf("You lost %lld xp.\n", random % 50 * lv0[logging]);
						xp0[logging] -= random % 50 * lv0[logging];
						printf("You have xp:%lld\n", xp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothinf else happens...\n");
				}
			} else if (random % 5 == 1) {
				printf("you feel that a big fish is on the hook.Will you try to get it?(Yes:1,No:0)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 2 == 1) {
						color(red);
						printf("You pull it out,but...It is a leather boot.\n");
						printf("You lost %d xp.\n", random % 30 + 10);
						xp0[logging] -= random % 30 + 10;
						printf("You have xp:%lld\n", xp0[logging]);
					} else if (random % 2 == 0) {
						if (lv0[logging] >= random % 10 + 1) {
							color(green);
							printf("You pull the big fish out successfully,and after eating it,you become much stronger.\n");
							printf("You get %d hp and %d xp.\n", random % 20 + 5, random % 100 + 30);
							hp0[logging] += random % 20 + 5;
							xp0[logging] += random % 100 + 30;
							printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
						} else if (lv0[logging] < random % 10 + 1) {
							color(red);
							printf("You are failed to catch it,and you fall into the water.\n");
							printf("You lost %d hp and %d xp.\n", random % 6 + 2, random % 20 + 5);
							hp0[logging] -= random % 6 + 2;
							xp0[logging] -= random % 20 + 5;
							printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
						}
					}
				} else if (answer == 0) {
					printf("Nothing else happens.\n");
				}
			} else if (random % 5 == 2) {
				printf("you meet a child shouting 'help' in the water.Do you save him?(Yes:1,No:0)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (lv0[logging] > random % 12) {
						color(green);
						printf("You save the child successflly,and you get some candy from the child.\n");
						printf("You get %lld xp and %d candy.\n", random % 12 + 20 * lv0[logging], random % 4 + 1);
						xp0[logging] += random % 12 + 20 * lv0[logging];
						cd0[logging] += random % 4 + 1;
						printf("You have xp:%lld,cd:%lld\n", xp0[logging], cd0[logging]);
					} else if (lv0[logging] == random % 12) {
						color(red);
						printf("You touch him,but you can't save him successfully.\n");
						printf("You lost %d xp.\n", random % 60 + 10);
						xp0[logging] -= random % 60 + 10;
						printf("You have xp:%lld\n", xp0[logging]);
					} else if (lv0[logging] < random % 12) {
						color(red);
						printf("Oh,no!The water is dangerous to you too!You get hurt!\n");
						printf("You lost %d hp and get %d xp.\n", random % 20 + 5, random % 50 + 10);
						hp0[logging] -= random % 20 + 5;
						xp0[logging] += random % 50 + 10;
						printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens...\n");
				}
			} else if (random % 5 == 3) {
				printf("it rains.Do you want to continue fishing?(Yes:1,No:0)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 2 == 1) {
						printf("Suddenly,a monster appears in the thunderstorm.It runs so fast that you have to face it.\n");
						if (lv0[logging] > random % 9 + 3) {
							color(green);
							printf("You win it.After this,you get many xp.\n");
							printf("You lost %d hp and get %d xp.\n", random % 10 + 5, random % 90 + 20);
							hp0[logging] -= random % 10 + 5;
							xp0[logging] += random % 90 + 20;
							printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
						} else if (lv0[logging] <= random % 9 + 3) {
							color(red);
							printf("You are lost.After this,you get big hurt.\n");
							printf("You lost %d hp and get %d xp.\n", random % 30 + 10, random % 20 + 10);
							hp0[logging] -= random % 30 + 10;
							xp0[logging] += random % 20 + 10;
							printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
						}
					} else if (random % 2 == 0) {
						printf("In the storm,you get something,but you may lose something,too.\n");
						if (random % 3 == 0) {
							color(red);
							printf("You have a cold after this.But you also get some xp.\n");
							printf("You lost %d hp and get %d xp.\n", random % 10 + 5, random % 30 + 10);
							hp0[logging] -= random % 10 + 5;
							xp0[logging] += random % 30 + 10;
							printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
						} else if (random % 3 == 1) {
							color(green);
							printf("You finish this trip smoothly.\n");
							printf("You get %d xp.\n", random % 40 + 5);
							xp0[logging] += random % 40 + 5;
							printf("You have xp:%lld\n", xp0[logging]);
						} else if (random % 3 == 2) {
							color(green);
							printf("On the way home,you fall into a hole.But lukily,you find a box that some candy in it.\n");
							printf("You lost %d hp,get %d xp and %d candy.\n", random % 20 + 3, random % 30 + 5, random % 4 + 1);
							hp0[logging] -= random % 20 + 3;
							xp0[logging] -= random % 30 + 5;
							cd0[logging] += random % 4 + 1;
							printf("You have hp:%lld,xp:%lld,cd:%lld\n", hp0[logging], xp0[logging], cd0[logging]);
						}
					}
				} else if (answer == 0) {
					printf("Nothing else happens.\n");
				}
			} else if (random % 5 == 4) {
				printf("a frog appears.You find that this frog is a frog with golden light.Will you catch?(Yes:1,No:0)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 2 == 1) {
						color(red);
						printf("When you are getting near to it,it jumps away suddenly.It scares you so much that you eat a mouthful of mud.\n");
						printf("You lost %d hp and get %d xp.\n", random % 10 + 5, random % 20 + 10);
						hp0[logging] -= random % 10 + 5;
						xp0[logging] += random % 20 + 10;
						printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
					} else if (random % 2 == 0) {
						color(green);
						printf("You catch it smoothly and quikely.You find that you can get much xp by only being beside it.\n");
						printf("You get %d xp.And you can get 1 hp more each day.\n", random % 60 + 20);
						xp0[logging] += random % 60 + 20;
						hup[logging]++;
						printf("You have xp:%lld,hup:%lld", xp0[logging], hup[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens.");
				}
			}
			break;
		}
		case 6: {
			printf("7\n");
			break;
		}
		case 7: {
			printf("8\n");
			break;
		}
		case 8: {
			printf("9\n");
			break;
		}
		case 9: {
			printf("10\n");
			break;
		}
		case 10: {
			printf("11\n");
			break;
		}
		case 11: {
			printf("12\n");
			break;
		}
		case 12: {
			printf("13\n");
			break;
		}
		case 13: {
			printf("14\n");
			break;
		}
		case 14: {
			printf("15\n");
			break;
		}
		case 15: {
			if (random == 2048) {
				color(green);
				printf("You meet a fairy.You are so lucky!And you get many things from him.\n");
				printf("You get 300 hp,3000 xp and 30 candy.\n");
				hp0[logging] += 300;
				xp0[logging] += 3000;
				cd0[logging] += 30;
				printf("You have hp:%lld,xp:%lld,cd:%lld\n", hp0[logging], xp0[logging], cd0[logging]);
			} else if (random % 3 == 0) {
				printf("You meet a thieve who is stealing things from others' house.But you are surprised that he asks you if you can do it with him.(Yes:1,No:0,Run:2)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 4 == 0) {
						printf("You steal something from this house successfully.\n");
						if (random % 5 == 0) {
							color(green);
							printf("You get %d xp and 1 candy.\n", random % 20 + 3);
							xp0[logging] += random % 20 + 3;
							cd0[logging]++;
							printf("You have xp:%lld,cd:%lld\n", xp0[logging], cd0[logging]);
						} else if (random % 5 == 1) {
							color(green);
							printf("You get %d xp.\n", random % 20 + 3);
							xp0[logging] += random % 20 + 3;
							printf("You have xp:%lld\n", xp0[logging]);
						} else {
							color(red);
							printf("You lost %d xp.\n", random % 30 + 5);
							xp0[logging] -= random % 30 + 5;
							printf("You have xp:%lld\n", xp0[logging]);
						}
					} else {
						printf("Someone finds you.Will you fight with this thieve?(Yes:1,No:0)\n");
						fflush(stdin);
						scanf("%d", &answer);
						if (answer == 1) {
							if (random % 2 == 1) {
								color(red);
								printf("The thieve betray you!He hits you too,and you get big hurt!\n");
								printf("You lost %d hp and %d xp.\n", random % 40 + 10, random % 30 + 5);
								hp0[logging] -= random % 40 + 10;
								xp0[logging] -= random % 30 + 5;
								printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
							} else {
								if (lv0[logging] + 2 > random % 8 + 1) {
									color(green);
									printf("You win.You get more things from the man who finds you.\n");
									printf("You lost %d hp and get %d xp.\n", random % 10 + 2, random % 20 + 1);
									hp0[logging] -= random % 10 + 2;
									xp0[logging] += random % 20 + 1;
									printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
								} else {
									color(red);
									printf("You lost.You are hurt by this man and people who this man calls.\n");
									printf("You lost %d hp and %d xp.\n", random % 20 + 5, random % 30 + 5);
									hp0[logging] -= random % 20 + 5;
									xp0[logging] -= random % 30 + 5;
									printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
								}
							}
						} else if (answer == 0) {
							if (random % 2 == 1) {
								color(red);
								printf("You are failed to run away.You are caught to this house's owner.\n");
								printf("You lost %d xp.\n", random % 100 + 10);
								xp0[logging] -= random % 100 + 10;
								printf("You have xp:%lld\n", xp0[logging]);
							} else {
								color(green);
								printf("You run away successfully.\n");
								printf("You lost %d xp.\n", random % 50 + 20);
								xp0[logging] -= random % 50 + 20;
								printf("You have xp:%lld\n", xp0[logging]);
							}
						}
					}
				} else if (answer == 0) {
					if (lv0[logging] >= random % 10) {
						color(green);
						printf("You hit the thieve away successfully.\n");
						printf("You lost %d hp and get %d xp.\n", random % 10 + 1, random % 50 + 10);
						hp0[logging] -= random % 10 + 1;
						xp0[logging] += random % 50 + 10;
						printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
					} else {
						color(red);
						printf("You are lost.The thieve hits you hard and steal some of your things.\n");
						printf("You lost %d hp and get %d xp.\n", random % 30 + 5, random % 20 + 5);
						hp0[logging] -= random % 30 + 5;
						xp0[logging] += random % 20 + 5;
						printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
					}
				} else if (answer == 2) {
					printf("Nothing else happens.\n");
				}
			} else if (random % 3 == 1) {
				printf("You meet a beautiful woman who is doing chores.She says:Can you help me with this?I can't pull it up.(Yes:1,No:0)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (xp0[logging] > 5 * (random % 1000)) {
						color(green);
						printf("You pull up that successfully.The woman let a child give you some candy.\n");
						printf("You get %d xp and %d candy.\n", random % 50 + 10, random % 5 + 1);
						xp0[logging] += random % 50 + 10;
						cd0[logging] += random % 5 + 1;
						printf("You have xp:%lld,cd:%lld\n", xp0[logging], cd0[logging]);
					} else {
						color(red);
						printf("You can't pull up that either.You are unhappy.\n");
						printf("You lost %d xp.\n", random % 20 + 10);
						xp0[logging] -= random % 20 + 10;
						printf("You have xp:%lld\n", xp0[logging]);
					}
				} else if (answer == 0) {
					printf("Nothing else happens.\n");
				}
			} else if (random % 3 == 2) {
				printf("You meet a man who is reading a book.He asks:Do you want to read it with me?(Yes:1,No:0)\n");
				fflush(stdin);
				scanf("%d", &answer);
				if (answer == 1) {
					if (random % 2 == 1) {
						color(red);
						printf("This man is a bad man...While you are reading this book carefully,he hits you hard and get some of your things.\n");
						printf("You lost %d hp and %d xp.\n", random % 20 + 5, random % 10 + 10);
						hp0[logging] -= random % 20 + 5;
						xp0[logging] -= random % 10 + 10;
						printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
					} else if (random % 2 == 0) {
						if (lv0[logging] >= random % 10) {
							color(green);
							printf("You read this book happily,and you learn much from the book and the man.\n");
							printf("You get %d xp.\n", random % 50 + 20);
							xp0[logging] += random % 50 + 20;
							printf("You have xp:%lld\n", xp0[logging]);
						} else if (lv0[logging] < random % 10) {
							color(red);
							printf("You read this book happily,but...You can't understand it,and the man laughs at you.\n");
							printf("You lost %d xp.\n", random % 30 + 10);
							xp0[logging] -= random % 30 + 10;
							printf("You have xp:%lld\n", xp0[logging]);
						}
					}
				} else if (answer == 0) {
					printf("Nothing else happens.\n");
				}
			}
			break;
		}
		case 16: {
			printf("17\n");
			break;
		}
		case 17: {
			printf("18\n");
			break;
		}
		case 18: {
			printf("19\n");
			break;
		}
	}
}
void candy() {
	if (cd0[logging] > 0) {
		cd0[logging]--;
		printf("Now you have candy:%lld\n", cd0[logging]);
		if (random % 10 == 0 || random % 10 == 4) {
			color(green);
			printf("You feel very comfortable.And in the same time,your body become stronger.\n");
			printf("You get %d hp and %lld xp.\n", random % 20 + 10, random % 50 + 20 + lv0[logging] * 10);
			hp0[logging] += random % 20 + 10;
			xp0[logging] += random % 50 + 20 + lv0[logging] * 10;
			printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
		} else if (random % 10 == 1 || random % 10 == 2 || random % 10 == 3) {
			color(red);
			printf("You feel very uncomfortable!This candy is a bad one!\n");
			printf("You lost %d hp and %lld xp.\n", random % 10 + 3, random % 40 + 10 + lv0[logging] * 25);
			hp0[logging] -= random % 10 + 3;
			xp0[logging] -=random % 40 + 10 + lv0[logging] * 25;
			printf("You have hp:%lld,xp:%lld\n", hp0[logging], xp0[logging]);
		} else {
			printf("You feel very sweet,and not any more special feelings.\n");
		}
	} else {
		printf("You have no candy.Please try to get more.\n");
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		hp0[i] = 100;
		lv0[i] = 1;
	}
	printf("press 1 to begin the game\n");
	scanf("%d", &l);
	while (l == 1 || l == 147369) {
		while (l == 1) {
			system("cls");
			printf("login(1) or create(2)\n");
			//fflush(stdin);
			scanf("%d", &choose);
			if (choose == 1) {
				printf("choose a number to login\n");
				//fflush(stdin);
				scanf("%d", &choose1);
				login();
				if (oklog == 1) {
					logging = choose1 - 1;
					continueing = 1;
					printf("successful to login!\n");
				} else if (!oklog) {
					printf("the number or the password is wrong,please try agian\n");
				}
				//fflush(stdin);
				while (continueing) {
					if (hp0[logging] <= 100 && hp0[logging] + hup[logging] > 100) {
						hp0[logging] = 100;
					} else if(hp0[logging]+hup[logging] <= 100) {
						hp0[logging] += hup[logging];
					}
					color(yellow);
					printf("Now you have:hp:%lld,xp:%lld,level:%lld,candy:%lld,hp+ each day:%lld\n", hp0[logging], xp0[logging], lv0[logging], cd0[logging], hup[logging]);
					color(purple);
					printf("Get into a random conversation(1) or try one candy(2)\n");
					//fflush(stdin);
					scanf("%d", &ch1);
					if (ch1 == 1) {
						system("cls");
						color(gray);
						srand(time(nullptr));
						random = rand() % 2049;
						thing();
						upgrade();
					}
					if (ch1 == 2) {
						system("cls");
						color(gray);
						srand(time(0));
						random = rand() % 2049;
						candy();
						upgrade();
					}
					if (hp0[logging] <= 0) {
						color(red);
						printf("\nYou Died!\n\n");
						hp0[logging] = 100;
						xp0[logging] = 0;
						lv0[logging] = 1;
						cd0[logging] = 0;
					}
					color(white);
					printf("If you want to exit,press 0\n");
					//fflush(stdin);
					scanf("%d", &continueing);
					if (!continueing) {
						system("cls");
					}
				}
			}
			if (choose == 2) {
				printf("choose a number to create(choose 0 to cancel)\n");
				//fflush(stdin);
				scanf("%d", &choose2);
				if (choose2 == '0') {
					printf("it is canceled...\n");
				} else {
					create();
				}
			}
			printf("if you want to continue,please press 1\n");
			fflush(stdin);
			scanf("%d", &l);
			if (l == 1) {
				system("cls");
			}
		}
		while (l == 147369) {
			printf("now you are in the administrator mod...\n");
			printf("choose a number to change,or press '0' to exit\n");
			scanf("%d", &change1);
			if (change1 == 0) {
				printf("press any key to exit...\n");
				return 0;
			}
			change1--;
			printf("choose to delete(0),change the password(1),change the hp(2),change the xp(3),change the lv(4),change the cd(5) or change the hup(6)\n");
			scanf("%d", &change2);
			switch (change2) {
				case 0: {
					user[change1] = 0;
					hp0[change1] = 100;
					xp0[change1] = 0;
					lv0[change1] = 1;
					printf("successful to delete\n");
					break;
				}
				case 1: {
					printf("set the new password(6 words)\n");
					for (int i = 0; i < 6;) {
						scanf("%c", &pc);
						if (((pc >= 'a' && pc <= 'z') || (pc >= 'A' && pc <= 'Z') || (pc >= '0' && pc <= '9'))) {
							p[change1][i] = pc;
							i++;
						}
					}
					printf("successful to change\n");
					break;
				}
				case 2: {
					printf("change it into:");
					scanf("%lld", &hp);
					hp0[change1] = hp;
					printf("successful to change\n");
					break;
				}
				case 3: {
					printf("change it into:");
					scanf("%lld", &xp);
					xp0[change1] = xp;
					printf("successful to change\n");
					break;
				}
				case 4: {
					printf("change it into:");
					scanf("%lld", &lv);
					lv0[change1] = lv;
					printf("successful to change\n");
					break;
				}
				case 5: {
					printf("change it into:");
					scanf("%lld", &cd);
					cd0[change1] = cd;
					printf("successful to change\n");
					break;
				}
				case 6: {
					printf("change it into:");
					scanf("%lld", &hg);
					hup[change1] = hg;
					printf("successful to change\n");
					break;
				}
			}
			printf("if you want to continue,tell the password again,or press 0 to exit\n");
			scanf("%d", &l);
		}
	}
	return 0;
}
