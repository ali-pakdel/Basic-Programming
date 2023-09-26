#include "graphics.h"
#include "graphicfuncs.h"
#include <stdio.h>
#define BOARD_SIZE 8
void drawtable(char board[BOARD_SIZE][BOARD_SIZE], int *turn, int *black_score, int *white_score) {
	int i, j;
	if ((*turn) == 1) {
		for (i = 0; i < 8; i++) {
			for (j = 0; j < 8; j++) {
				board[i][j] = '.';
			}
		}
		board[3][3] = 'W', board[3][4] = 'B', board[4][3] = 'B', board[4][4] = 'W';
	}
	clearviewport();
	setbkcolor(WHITE);
	/*rectangle(0, 0, 608, 720);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(1, 1, WHITE);*/
	setcolor(CYAN);
	rectangle(0, 0, 608, 608);
	setfillstyle(SOLID_FILL, CYAN);
	floodfill(300, 300, CYAN);
	/*setcolor(WHITE);
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL,CYAN);
	floodfill(1, 1, WHITE);*/
	setcolor(LIGHTCYAN);
	rectangle(0, 608, 608, 720);
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	floodfill(320, 680, LIGHTCYAN);
	setcolor(LIGHTCYAN);
	for (int i = 0; i < 8; i++) {
		line(0, 76 * i, 608, 76 * i);
		line(76 * i, 0, 76 * i, 608);
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			if (board[i][j] == 'W') {
				setcolor(WHITE);
				circle(i * 76 + 38, j * 76 + 38, 25);
				setfillstyle(SOLID_FILL, WHITE);
				floodfill(i * 76 + 39, j * 76 + 39, WHITE);
			}
			if (board[i][j] == 'B') {
				setcolor(BLACK);
				circle(i * 76 + 38, j * 76 + 38, 25);
				setfillstyle(SOLID_FILL, BLACK);
				floodfill(i * 76 + 39, j * 76 + 39, BLACK);

			}
		}
	}
	scores(board, black_score, white_score);
}
int input(char board[BOARD_SIZE][BOARD_SIZE], int *x, int *y, int *turn, int *black_score, int *white_score) {
	int left = 28, right = 48, top = 28, bottom = 48;
	setcolor(RED);
	if ((*turn) % 2 == 1)
		setbkcolor(BLACK);
	else
		setbkcolor(WHITE);
	rectangle(left, top, right, bottom);
	setfillstyle(INTERLEAVE_FILL, RED);
	floodfill(40, 40, RED);
	char input = 'x', enter = ' ';
	int flagerror = 0, trashnum = 0;
	char trash;
	while (input != ' ') {
		while (enter != '\n') {
			settextstyle(8, 0, 1);
			if ((*turn) % 2 == 1) {
				setcolor(BLACK);
				setbkcolor(LIGHTCYAN);
				outtextxy(60, 620, "Black player's turn.Choose a cell with space");
			}
			else {
				setcolor(BLACK);
				setbkcolor(LIGHTCYAN);
				outtextxy(60, 620, "White player's turn.Choose a cell with space");
			}
			scanf("%c", &input);
			scanf("%c", &enter);
			if (input == ' ' && enter == '\n')
				break;
			if (input != 'w' && input != 's' && input != 'a' && input != 'd')
				flagerror = 1;	
			if (enter == '\n' && (input == 'w' || input == 's' || input == 'a' || input == 'd')) {
				if (input == 'w' && top != 28) {
					top -= 76;
					bottom -= 76;
				}
				else if (input == 's' && bottom != 580) {
					bottom += 76;
					top += 76;
				}
				else if (input == 'a' && left != 28) {
					left -= 76;
					right -= 76;
				}
				else if (input == 'd' && right != 580) {
					right += 76;
					left += 76;
				}
				else
					flagerror = 1;
			}
			if (enter != '\n') {
				for (int i = 0; i < 100; i++) {
					scanf("%c", &trash);
					trashnum++;
					flagerror = 1;
					if (trash == '\n')
						break;
				}
			}
			if (flagerror == 1) {
				setcolor(WHITE);
				rectangle(0, 608, 608, 650);
				setfillstyle(SOLID_FILL, LIGHTCYAN);
				floodfill(304, 620, WHITE);
				setcolor(RED);
				setbkcolor(LIGHTCYAN);
				settextstyle(8, 0, 1);
				outtextxy(120, 620, "INVALID!Please choose another");
				delay(1500);
				setcolor(LIGHTCYAN);
				line(0, 650, 608, 650);
				enter = ' ', trash = ' ', trashnum = 0, flagerror = 0;
			}
		}
		clearviewport();
		drawtable(board, turn, black_score, white_score);
		setcolor(RED);
		if ((*turn % 2 == 1))
			setbkcolor(BLACK);
		else
			setbkcolor(WHITE);
		rectangle(left, top, right, bottom);
		setfillstyle(INTERLEAVE_FILL, RED);
		floodfill(left + 5, top + 5, RED);
		enter = ' ';
	}
	*x = left, *y = top;
	return 0;
}
int playgame(char board[BOARD_SIZE][BOARD_SIZE], int *x, int *y, int *turn) {
	/*i,j,k,l counter haye komaki hastand*/
	int i = 0, j = 0, k = 0, l = 0, flag = 0, flag2 = 0, counter = 0;
	int int_row, int_col;
	char B_W = '0', W_B = '0';
	if ((*turn) % 2 == 1)
		B_W = 'B', W_B = 'W';
	else 
		B_W = 'W', W_B = 'B';
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if ((i * 76 + 28 == *x) && (j * 76 + 28 == *y)) {
				int_row = i + 1;
				int_col = j + 1;
			}
		}
	}
	/*baresi mikonad ke jaei ke entekhab shode monaseb ast ya na, va agar ok bashad flip hara niz anjam midahad*/
	//rast 
	if (board[int_row - 1][int_col - 1] == '.') {
		if (board[(int_row)-1][int_col] == W_B) {
			for (j = (int_col)+1; j < BOARD_SIZE; j++) {
				int p = 0;
				if (board[(int_row)-1][j] == '.')
					break;
				else if (board[(int_row)-1][j] == B_W)
					flag = 1, p++;
				if (p == 1) {
					for (k = int_col; k <= j; k++)
						board[(int_row)-1][k] = B_W;
					break;
				}
			}
		}
		//chap
		if (board[(int_row)-1][(int_col)-2] == W_B) {
			for (j = (int_col)-3; j >= 0; j--) {
				int p = 0;
				if (board[(int_row)-1][j] == '.')
					break;
				else if (board[(int_row)-1][j] == B_W)
					flag = 1, p++;
				if (p == 1) {
					for (k = (int_col)-2; k >= j; k--)
						board[(int_row)-1][k] = B_W;
					break;
				}
			}
		}
		//bala
		if (board[(int_row)-2][(int_col)-1] == W_B) {
			int p = 0;
			for (i = (int_row)-3; i >= 0; i--) {
				if (board[i][(int_col)-1] == '.')
					break;
				else if (board[i][(int_col)-1] == B_W)
					flag = 1, p++;
				if (p == 1) {
					for (k = (int_row)-2; k >= i; k--)
						board[k][(int_col)-1] = B_W;
					break;
				}
			}
		}
		//paeen
		if (board[int_row][(int_col)-1] == W_B) {
			int p = 0;
			for (i = (int_row)+1; i < BOARD_SIZE; i++) {
				if (board[i][(int_col)-1] == '.')
					break;
				else if (board[i][(int_col)-1] == B_W)
					flag = 1, p++;
				if (p == 1) {
					for (k = int_row; k <= i; k++)
						board[k][(int_col)-1] = B_W;
					break;
				}
			}
		}
		//rastbala
		if (board[(int_row)-2][int_col] == W_B) {
			i = (int_row)-2, j = int_col;
			int p = 0;
			while (i >= 0 && j < BOARD_SIZE) {
				if (board[i][j] == '.')
					break;
				else if (board[i][j] == B_W)
					flag = 1, p++;
				if (p == 1) {
					k = (int_row)-2, l = int_col;
					while (k >= i && l <= j) {
						board[k][l] = B_W;
						k--, l++;
					}
					break;
				}
				i--, j++;
			}
		}
		//chapbala
		if (board[(int_row)-2][(int_col)-2] == W_B) {
			i = (int_row)-2, j = (int_col)-2;
			int p = 0;
			while (i >= 0 && j >= 0) {
				if (board[i][j] == '.')
					break;
				else if (board[i][j] == B_W)
					flag = 1, p++;
				if (p == 1) {
					k = (int_row)-2, l = (int_col)-2;
					while (k >= i && l >= j) {
						board[k][l] = B_W;
						k--, l--;
					}
					break;
				}
				i--, j--;
			}
		}
		//rastpaeen
		if (board[int_row][int_col] == W_B) {
			i = int_row, j = int_col;
			int p = 0;
			while (i < BOARD_SIZE && j < BOARD_SIZE) {
				if (board[i][j] == '.')
					break;
				else if (board[i][j] == B_W)
					flag = 1, p++;
				if (p == 1) {
					k = int_row, l = int_col;
					while (k <= i && l <= j) {
						board[k][l] = B_W;
						k++, l++;
					}
					break;
				}
				i++, j++;
			}
		}
		//chappaeen
		if (board[int_row][(int_col)-2] == W_B) {
			i = int_row, j = (int_col)-2;
			int p = 0;
			while (i < BOARD_SIZE && j >= 0) {
				if (board[i][j] == '.')
					break;
				else if (board[i][j] == B_W)
					flag = 1, p++;
				if (p == 1) {
					k = int_row, l = (int_col)-2;
					while (k <= i, l >= j) {
						board[k][l] = B_W;
						k++, l--;
					}
					break;
				}
				i++, j--;
			}
		}
	}
	//		/*agar ok bashad break mikonad va agar na ekhtar midahad*/
	if (flag == 1) {
		board[(int_row)-1][(int_col)-1] = B_W;
		(*turn)++;
	}
	else {
		setcolor(RED);
		setbkcolor(LIGHTCYAN);
		outtextxy(120, 620, "INVALID!Please choose another");
		delay(1500);
	}
	return 0;
}
int endgame(char board[BOARD_SIZE][BOARD_SIZE], int turn, int black_score, int white_score, int *restart) {
	int i, j, k, l;
	char b_or_w, w_or_b;
	int flag = 0;
	if ((turn) % 2 == 1)
		b_or_w = 'B', w_or_b = 'W';
	else
		b_or_w = 'W', w_or_b = 'B';
	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == '.') {
				/*khane haye khali jadval ra peyda karde va sepas az 8 jahat barresi mishavad ke mitan anja bazi kard ya na*/
				//rast
				if (board[i][j + 1] == w_or_b) {
					for (k = j + 2; k < BOARD_SIZE; k++) {
						if (board[i][k] == '.')
							break;
						else if (board[i][k] == b_or_w) {
							k = BOARD_SIZE, j = BOARD_SIZE, i = BOARD_SIZE;
							flag = 1;
							break;
						}
					}
				}
				//chap
				if (board[i][j - 1] == w_or_b) {
					for (k = j - 2; k >= 0; k--) {
						if (board[i][k] == '.')
							break;
						else if (board[i][k] == b_or_w) {
							k = -1, j = BOARD_SIZE, i = BOARD_SIZE;
							flag = 1;
							break;
						}
					}
				}
				//paeen
				if (board[i + 1][j] == w_or_b) {
					for (k = i + 2; k < BOARD_SIZE; k++) {
						if (board[k][j] == '.')
							break;
						else if (board[k][j] == b_or_w) {
							k = BOARD_SIZE, j = BOARD_SIZE, i = BOARD_SIZE;
							flag = 1;
							break;
						}
					}
				}
				//bala
				if (board[i - 1][j] == w_or_b) {
					for (k = i - 2; k >= 0; k--) {
						if (board[k][j] == '.')
							break;
						if (board[k][j] == b_or_w) {
							k = -1, j = BOARD_SIZE, i = BOARD_SIZE;
							flag = 1;
							break;
						}
					}
				}
				//chapbala
				k = j - 1;
				l = i - 1;
				if (board[i - 1][j - 1] == w_or_b) {
					while (k >= 0 && l >= 0) {
						if (board[l][k] == '.')
							break;
						if (board[l][k] == b_or_w) {
							k = -1, l = -1, j = BOARD_SIZE, i = BOARD_SIZE;
							flag = 1;
							break;
						}
						k--, l--;
					}
				}
				//rastbala
				k = j + 1;
				l = i - 1;
				if (board[i - 1][j + 1] == w_or_b) {
					while (k < BOARD_SIZE && l >= 0) {
						if (board[l][k] == '.')
							break;
						if (board[l][k] == b_or_w) {
							k = BOARD_SIZE, l = -1, j = BOARD_SIZE, i = BOARD_SIZE;
							flag = 1;
							break;
						}
						k++, l--;
					}
				}
				//rastpaeen
				k = j + 1;
				l = i + 1;
				if (board[i + 1][j + 1] == w_or_b) {
					while (k < BOARD_SIZE && l < BOARD_SIZE) {
						if (board[l][k] == '.')
							break;
						if (board[l][k] == b_or_w) {
							k = BOARD_SIZE, l = BOARD_SIZE, j = BOARD_SIZE, i = BOARD_SIZE;
							flag = 1;
							break;
						}
						k++, l++;
					}
				}
				//chappaeen
				k = j - 1;
				l = i + 1;
				if (board[i + 1][j - 1] == w_or_b) {
					while (k >= 0 && l < BOARD_SIZE) {
						if (board[l][k] == '.')
							break;
						if (board[l][k] == b_or_w) {
							l = BOARD_SIZE, k = -1, j = BOARD_SIZE, i = BOARD_SIZE;
							flag = 1;
							break;
						}
						k--, l++;
					}
				}
			}
		}
	}
	if (flag == 0) {
		initwindow(600, 400, "GAME OVER");
		rectangle(0, 0, 600, 400);
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		floodfill(1, 1, WHITE);
		setcolor(RED);
		setbkcolor(LIGHTGRAY);
		settextstyle(8, 0, 2);
		outtextxy(20, 60, "The game is over");
		if ((black_score) > (white_score)) {
			setcolor(BLACK);
			outtextxy(20, 90, "Black player has won the game");
		}
		else if ((black_score) < (white_score)) {
			setcolor(WHITE);
			outtextxy(20, 90, "White player has won the game");
		}
		else
			outtextxy(20, 100, "No on has won the game");
		char Bscore[30], Wscore[30];
		setcolor(BLACK);
		sprintf(Bscore, "Black = %d", black_score);
		outtextxy(40, 230, Bscore);
		setcolor(WHITE);
		sprintf(Wscore, "White = %d", white_score);
		outtextxy(210, 230, Wscore);
		setcolor(BLACK);
		settextstyle(3, 0, 2);
		outtextxy(20, 280, "Press 1 to play again,");
		outtextxy(20, 310, "Press 2 to exit");
		int playagain;
		scanf("%d", &playagain);
		if (playagain == 1) {
			closegraph();
			(*restart) = 1;
			return 1;
		}
		else {
			closegraph();
			(*restart) = 2;
			return 2;
		}
	}
	else
		return 0;
}
int scores(char board[BOARD_SIZE][BOARD_SIZE], int *black_score, int *white_score) {
	int i, j;/*i,j counter haye komaki hastand*/
	char Bscore[30], Wscore[30];
	*black_score = 0;
	*white_score = 0;
	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == 'B')
				(*black_score)++;
			if (board[i][j] == 'W')
				(*white_score)++;
		}
	}
	setbkcolor(LIGHTCYAN);
	setcolor(RED);
	settextstyle(8, 0, 1);
	sprintf(Wscore, "White= %d", *white_score);
	sprintf(Bscore, "Black= %d", *black_score);
	outtextxy(10, 680, Bscore);
	outtextxy(500, 680, Wscore);
	setcolor(BLACK);
	circle(130, 690, 20);
	setfillstyle(SOLID_FILL, BLACK);
	floodfill(131, 691, BLACK);
	setcolor(WHITE);
	circle(470, 690, 20);
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(471, 691, WHITE);
	return 0;
}
void guide() {
	initwindow(600, 600, "Othello");
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	floodfill(300, 300, WHITE);
	settextstyle(5, 0, 5);
	setcolor(COLOR(21, 28, 111));
	setbkcolor(LIGHTGRAY);
	outtextxy(100, 30, "Welcome to Othello");
	settextstyle(3, 0, 2);
	setcolor(BLUE);
	outtextxy(30, 140, "Each player has to move the red square by w,s,a,d keys");
	outtextxy(30, 170, "and choose the right place");
	outtextxy(30, 200, "When there is no move left for a player,the game will be over");
	outtextxy(30, 230, "At the end the player which has more marbles will win the game");
	outtextxy(30, 260, "and if they both have equal marbles,the game will be end in tie");
	setcolor(RED);
	outtextxy(190, 400, "press enter to continue...");
	char close;
	scanf("%c", &close);
	if (close == '\n')
		closegraph();
}