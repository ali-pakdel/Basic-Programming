#include<stdio.h>
#include "functions.h"
#define size 8
int main() {
	char board[size][size];
	int black_score = 2, white_score = 2, player = 0, turn = 1, flag = 0;
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			board[i][j] = '.';
		}
	}
	board[3][3] = 'W', board[3][4] = 'B', board[4][3] = 'B', board[4][4] = 'W';
	print_board(board, &black_score, &white_score);
	while (1) {
		if (endgame(board, &turn, &black_score, &white_score) == 0)
			break;
		playgame(board, &turn);
		turn++;
		scores(board, &black_score, &white_score);
		print_board(board, &black_score, &white_score);
	}
}
