#include <stdio.h>
#include "functions.h"
#define size 8
void print_board(char board[size][size], int *black_score, int *white_score) {
	int i, j;/*i,j,k counter haye komaki hastand*/
	printf("\n\n            ");
	for (i = 1; i <= size; i++)
		printf("    %d", i);
	printf("  [B=%d  W=%d]\n", *black_score, *white_score);
	int k = 10;
	printf("\n            %d", k);
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			printf("  %c  ", board[i][j]);
		printf("\n");
		printf("\n");
		k += 10;
		if (k <= (size) * 10)
			printf("            %d", k);
	}
}
/*score har kas ra mohasebe mikonad*/
int scores(char board[size][size], int *black_score, int *white_score) {
	int i, j;/*i,j counter haye komaki hastand*/
	int scoreB = 0, scoreW = 0;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (board[i][j] == 'B')
				scoreB++;
			if (board[i][j] == 'W')
				scoreW++;
		}
	}
	*black_score = scoreB, *white_score = scoreW;
	return 0;
}
int playgame(char board[size][size], int *turn) {
	/*i,j,k,l counter haye komaki hastand*/
	int i = 0, j = 0, k = 0, l = 0, flag = 0, flag2 = 0, counter = 0;
	int int_row, int_col, wrong_counter;
	char row, col, enter, wrong = '0';
	char B_W = '0', W_B = '0';
	if ((*turn) % 2 == 1) {
		B_W = 'B', W_B = 'W';
		printf("Black player's turn:\n");
	}
	else {
		B_W = 'W', W_B = 'B';
		printf("White player's turn:\n");
	}
	while (1) {/*vorodi ra migirad va check mikonad ke dorost bashad*/
		int amount = scanf("%c%c", &row, &col);
		scanf("%c", &enter);
		if (enter == '\n') {
			if (amount == 2) {
				int_row = row - '0', int_col = col - '0';
				if ('0' < row < '9' &&  '0' < col < '9' && board[(int_row)-1][(int_col)-1] == '.')
					flag2 = 1;
			}
			/*baresi mikonad ke jaei ke entekhab shode monaseb ast ya na, va agar ok bashad flip hara niz anjam midahad*/
			//rast 
			if (board[(int_row)-1][int_col] == W_B) {
				for (j = (int_col)+1; j < size; j++) {
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
				for (i = (int_row)+1; i < size; i++) {
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
				while (i >= 0 && j < size) {
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
				while (i < size && j < size) {
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
				while (i < size && j >= 0) {
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
			/*agar ok bashad break mikonad va agar na ekhtar midahad*/
			if (flag == 1 && flag2 == 1)
				break;
			else if (counter == 0) {
				printf("Invalid!\nPlease choose another:");
				counter++;
				amount = 0;
			}
			else
				printf("Invalid!\nPlease choose another:");
		}
		else {/*agar dar sharayet khasi user chandin character vared konad,in kar an hara khali mikonad*/
			printf("Invalid!\nPlease choose another:");
			for (wrong_counter = 0; wrong_counter < 100; wrong_counter++) {
				if (wrong == '\n')
					break;
				scanf("%c", &wrong);
			}
		}
	}
	board[(int_row)-1][(int_col)-1] = B_W;
	return 0;
}
/*barresi inke mitavan bazi kard ya na*/
int endgame(char board[size][size], int *turn, int *black_score, int *white_score) {
	int i, j, k, l;
	char b_or_w, w_or_b;
	int flag = 0;
	if ((*turn) % 2 == 1)
		b_or_w = 'B', w_or_b = 'W';
	else
		b_or_w = 'W', w_or_b = 'B';
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (board[i][j] == '.') {
				/*khane haye khali jadval ra peyda karde va sepas az 8 jahat barresi mishavad ke mitan anja bazi kard ya na*/
				//rast
				if (board[i][j + 1] == w_or_b) {
					for (k = j + 2; k < size; k++) {
						if (board[i][k] == '.')
							break;
						else if (board[i][k] == b_or_w) {
							k = size, j = size, i = size;
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
							k = -1, j = size, i = size;
							flag = 1;
							break;
						}
					}
				}
				//paeen
				if (board[i + 1][j] == w_or_b) {
					for (k = i + 2; k < size; k++) {
						if (board[k][j] == '.')
							break;
						else if (board[k][j] == b_or_w) {
							k = size, j = size, i = size;
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
							k = -1, j = size, i = size;
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
							k = -1, l = -1, j = size, i = size;
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
					while (k < size && l >= 0) {
						if (board[l][k] == '.')
							break;
						if (board[l][k] == b_or_w) {
							k = size, l = -1, j = size, i = size;
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
					while (k < size && l < size) {
						if (board[l][k] == '.')
							break;
						if (board[l][k] == b_or_w) {
							k = size,l = size, j = size, i = size;
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
					while (k >= 0 && l < size) {
						if (board[l][k] == '.')
							break;
						if (board[l][k] == b_or_w) {
							l = size,k = -1, j = size, i = size;
							flag = 1;
							break;
						}
						k--, l++;
					}
				}
			}
		}
	}
	if ((flag) == 0) {
		if ((*turn % 2) == 1) 
			printf("There is no place for black to play!\n");
		else 
			printf("There is no place for white to play!\n");
		printf("The game is over\n");
		if ((*black_score) > (*white_score))
			printf("Black player has won the game\n");
		else if ((*black_score) < (*white_score))
			printf("White player has won the game\n");
		else 
			printf("No on has won the game\n");
		printf("Black score = %d\nWhite score = %d\n", *black_score, *white_score);
		return 0;
	}
	else
		return 1;
}