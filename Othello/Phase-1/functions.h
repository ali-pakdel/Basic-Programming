#pragma once
#define size 8
void print_board(char board[size][size], int *black_score, int *white_score);
int scores(char board[size][size], int *black_score, int *white_score);
int playgame(char board[size][size], int *turn);
int endgame(char board[size][size], int *turn, int *black_score, int *white_score);