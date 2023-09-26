#pragma once
#define BOARD_SIZE 8
void drawtable(char board[BOARD_SIZE][BOARD_SIZE], int *turn, int *black_score, int *white_score);
int input(char board[BOARD_SIZE][BOARD_SIZE], int *x, int *y, int *turn, int *black_score, int *white_score);
int playgame(char board[BOARD_SIZE][BOARD_SIZE], int *x, int *y, int *turn);
int endgame(char board[BOARD_SIZE][BOARD_SIZE], int turn, int black_score, int white_score,int *restart);
int scores(char board[BOARD_SIZE][BOARD_SIZE], int *black_score, int *white_score);
void guide();