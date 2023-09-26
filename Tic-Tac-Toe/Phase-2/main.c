#include <stdio.h>
#pragma once/*functions*/
void print_board(char cell[]);
int play_game(int player, char cell[], int *Counter);
int win_OR_tie(char cell[], int *counter);
int exit_OR_reset(int exit, char cell[], int *counter);
/*what each function do*/
void print_board(char cell[]) {
	printf(" %c  | %c  | %c\n", cell[0], cell[1], cell[2]);
	printf("____|____|____\n");
	printf(" %c  |  %c | %c\n", cell[3], cell[4], cell[5]);
	printf("____|____|____\n");
	printf(" %c  |  %c | %c\n", cell[6], cell[7], cell[8]);
	printf("    |    |\n");
}
int play_game(int player, char cell[], int *Counter) {/*play X and O*/
	if (*Counter % 2 == 1) {/*this if is for changing turns*/
		printf("Player one's turn\nPlease choose a number between 1 to 9:\n");
		scanf("%d", &player);
		/*number must be between 1 to 9*/
		while (player != 1 && player != 2 && player != 3 && player != 4 && player != 5 && player != 6 && player != 7 && player != 8 && player != 9) {
			printf("Invalid Number!!!\nPlease Enter Between 1 to 9:\n");
			scanf("%d", &player);
		}
		/*choosen numbers*/
		while ((cell[0] == 'X' && player == 1) || (cell[0] == 'O' && player == 1) || (cell[1] == 'O' && player == 2) || (cell[1] == 'X' && player == 2) || (cell[2] == 'O' && player == 3) || (cell[2] == 'X' && player == 3) || (cell[3] == 'O' && player == 4) || (cell[3] == 'X' && player == 4) || (cell[4] == 'O' && player == 5) || (cell[4] == 'X' && player == 5) || (cell[5] == 'O' && player == 6) || (cell[5] == 'X' && player == 6) || (cell[6] == 'O' && player == 7) || (cell[6] == 'X' && player == 7) || (cell[7] == 'O' && player == 8) || (cell[7] == 'X' && player == 8) || (cell[8] == 'O' && player == 9) || (cell[8] == 'X' && player == 9)) {
			printf("This number was choosen!!!\nPlease enter another number:");
			scanf("%d", &player);
			while (player != 1 && player != 2 && player != 3 && player != 4 && player != 5 && player != 6 && player != 7 && player != 8 && player != 9) {
				printf("Invalid Number!!!\nPlease Enter Between 1 to 9:\n");
				scanf("%d", &player);
			}
		}
		cell[player - 1] = 'X';
	}
	if (*Counter % 2 == 0) {
		printf("Player 2's turn\nPlease choose a number between 1 to 9:\n");
		scanf("%d", &player);
		/*Number must be between 1 to 9*/
		while (player != 1 && player != 2 && player != 3 && player != 4 && player != 5 && player != 6 && player != 7 && player != 8 && player != 9) {
			printf("Invalid Number!!!\nPlease Enter Between 1 to 9:\n");
			scanf("%d", &player);
		}
		/*choosen numbers*/
		while ((cell[0] == 'X' && player == 1) || (cell[0] == 'O' && player == 1) || (cell[1] == 'O' && player == 2) || (cell[1] == 'X' && player == 2) || (cell[2] == 'O' && player == 3) || (cell[2] == 'X' && player == 3) || (cell[3] == 'O' && player == 4) || (cell[3] == 'X' && player == 4) || (cell[4] == 'O' && player == 5) || (cell[4] == 'X' && player == 5) || (cell[5] == 'O' && player == 6) || (cell[5] == 'X' && player == 6) || (cell[6] == 'O' && player == 7) || (cell[6] == 'X' && player == 7) || (cell[7] == 'O' && player == 8) || (cell[7] == 'X' && player == 8) || (cell[8] == 'O' && player == 9) || (cell[8] == 'X' && player == 9)) {
			printf("This number was choosen!!!\nPlease enter another number:");
			scanf("%d", &player);
			while (player != 1 && player != 2 && player != 3 && player != 4 && player != 5 && player != 6 && player != 7 && player != 8 && player != 9) {
				printf("Invalid Number!!!\nPlease Enter Between 1 to 9:\n");
				scanf("%d", &player);
			}
		}
		cell[player - 1] = 'O';
	}
	print_board(cell);
}
int win_OR_tie(char cell[], int *Counter) {/*Win or Tie*/
	if (*Counter == 10) {/*Tie*/
		printf("The game is over!\nNo one has won the game\n");
	}/*X wins*/
	if ((cell[0] == cell[1] && cell[0] == cell[2] && cell[0] == 'X') || (cell[3] == cell[4] && cell[4] == cell[5] && cell[3] == 'X') || (cell[6] == cell[7] && cell[7] == cell[8] && cell[6] == 'X') || (cell[0] == cell[3] && cell[3] == cell[6] && cell[0] == 'X') || (cell[1] == cell[4] && cell[4] == cell[7] && cell[1] == 'X') || (cell[2] == cell[5] && cell[5] == cell[8] && cell[2] == 'X') || (cell[0] == cell[4] && cell[4] == cell[8] && cell[0] == 'X') || (cell[2] == cell[4] && cell[4] == cell[6] && cell[2] == 'X')) {
		printf("Congratulations!\nPlayer One has won the game!\n");
		*Counter = 12;
	}/*O wins*/
	if ((cell[0] == cell[1] && cell[0] == cell[2] && cell[0] == 'O') || (cell[3] == cell[4] && cell[4] == cell[5] && cell[3] == 'O') || (cell[6] == cell[7] && cell[7] == cell[8] && cell[6] == 'O') || (cell[0] == cell[3] && cell[3] == cell[6] && cell[0] == 'O') || (cell[1] == cell[4] && cell[4] == cell[7] && cell[1] == 'O') || (cell[2] == cell[5] && cell[5] == cell[8] && cell[2] == 'O') || (cell[0] == cell[4] && cell[4] == cell[8] && cell[0] == 'O') || (cell[2] == cell[4] && cell[4] == cell[6] && cell[2] == 'O')) {
		printf("Congratulations!\nPlayer Two has won the game!\n");
		*Counter = 12;
	}
}
int exit_OR_reset(int exit, char cell[], int *Counter) {/*play again or exit*/
	printf("Press 1 if you want to start a new game.Otherwise press 2.\n");
	scanf("%d", &exit);
	while (exit != 1 && exit != 2) {
		printf("Invalid number!!!\nPlease press 1 or 2:\n");
		scanf("%d", &exit);
	}
	if (exit == 1)
		*Counter = 1, cell[0] = '1', cell[1] = '2', cell[2] = '3', cell[3] = '4', cell[4] = '5', cell[5] = '6', cell[6] = '7', cell[7] = '8', cell[8] = '9';
	if (exit == 2)
		*Counter = 13;
}
int main() {
	int Counter = 1;
	int player = 0;
	char cell[9];
	int exit = 0;
	cell[0] = '1', cell[1] = '2', cell[2] = '3', cell[3] = '4', cell[4] = '5', cell[5] = '6', cell[6] = '7', cell[7] = '8', cell[8] = '9';
	printf("Welcome!\n");
	while (Counter < 13) {
		print_board(cell);
		while (Counter < 10) {
			play_game(player, cell, &Counter);
			Counter++;
			win_OR_tie(cell, &Counter);
			if (Counter != 10 && Counter != 12) {/*in if baraye in ast ke agar X naborde bashad ya mosavi nashode bashad,nafar dovom bazi konad*/
				play_game(player, cell, &Counter);
				Counter++;
				win_OR_tie(cell, &Counter);
			}
		}
		exit_OR_reset(exit, cell, &Counter);
	}
	printf("Goodbye!\n");
	getchar();
}
