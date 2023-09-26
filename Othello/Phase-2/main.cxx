#include <stdio.h>
#include "graphics.h"
#include "functions.h"
#include "graphicfuncs.h"
#define BOARD_SIZE 8
int main() {
	guide();
	while (int res = 1) {
		char board[BOARD_SIZE][BOARD_SIZE];
		int black_score = 2, white_score = 2, x, y, turn = 1, restart = 0;
		initwindow(608, 720, "Othello");
		while (int play = 1) {
			drawtable(board, &turn, &black_score, &white_score);
			if (endgame(board, turn, black_score, white_score,&restart) != 0)
				break;
			input(board, &x, &y, &turn, &black_score, &white_score);
			playgame(board, &x, &y, &turn);
		}
		if (restart == 2)
			break;
	}
	return 0;
}