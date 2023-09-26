#include <stdio.h>

int main() {
	int Counter = 1, y, playerOne, playerTwo;
	char exit, cell1 = '1', cell2 = '2', cell3 = '3', cell4 = '4', cell5 = '5', cell6 = '6', cell7 = '7', cell8 = '8', cell9 = '9';
	while (Counter<13) {/*13 be in dalil ke shart haye mosavi va reset va quit az bazi be dorosti run shavand*/
		printf("Welcome");
		while (Counter<10) {/*Baraye inke tanha 9 bar adad begirad va jadval ra neshan dahad*/
			printf(" %c  | %c  | %c\n", cell1, cell2, cell3);
			printf("____|____|____\n");
			printf(" %c  |  %c | %c\n", cell4, cell5, cell6);
			printf("____|____|____\n");
			printf(" %c  |  %c | %c\n", cell7, cell8, cell9);
			printf("    |    |\n");/*az player one adad migirad va agar dar mahdode nabod,dobare migirad*/
			printf("Player one's turn\nPlease choose a number between 1 to 9:\n");
			scanf("%d", &playerOne);
			while (playerOne != 1 && playerOne != 2 && playerOne != 3 && playerOne != 4 && playerOne != 5 && playerOne != 6 && playerOne != 7 && playerOne != 8 && playerOne != 9) {
				printf("Invalid Number,Please Enter Between 1 to 9:\n");
				scanf("%d", &playerOne);
			}
			/*shart tekrari nabodan*/
			while ((cell1 == 'X' && playerOne == 1) || (cell1 == 'O' && playerOne == 1) || (cell2 == 'O' && playerOne == 2) || (cell2 == 'X' && playerOne == 2) || (cell3 == 'O' && playerOne == 3) || (cell3 == 'X' && playerOne == 3) || (cell4 == 'O' && playerOne == 4) || (cell4 == 'X' && playerOne == 4) || (cell5 == 'O' && playerOne == 5) || (cell5 == 'X' && playerOne == 5) || (cell6 == 'O' && playerOne == 6) || (cell6 == 'X' && playerOne == 6) || (cell7 == 'O' && playerOne == 7) || (cell7 == 'X' && playerOne == 7) || (cell8 == 'O' && playerOne == 8) || (cell8 == 'X' && playerOne == 8) || (cell9 == 'O' && playerOne == 9) || (cell9 == 'X' && playerOne == 9)) {
				printf("This number was choosen,please enter another number:");
				scanf("%d", &playerOne);
				while (playerOne != 1 && playerOne != 2 && playerOne != 3 && playerOne != 4 && playerOne != 5 && playerOne != 6 && playerOne != 7 && playerOne != 8 && playerOne != 9) {
					printf("Invalid Number,Please Enter Between 1 to 9:\n");
					scanf("%d", &playerOne);
				}
			}
			if (playerOne == 1) {/*har khane az jadval ra ba tavajoh be adad bazikon avval por mikonad */
				cell1 = 'X';
				Counter = Counter + 1;
				playerOne = 0;
			}
			if (playerOne == 2) {
				cell2 = 'X';
				Counter = Counter + 1;
				playerOne = 0;
			}
			if (playerOne == 3) {
				cell3 = 'X';
				Counter = Counter + 1;
				playerOne = 0;
			}
			if (playerOne == 4) {
				cell4 = 'X';
				Counter = Counter + 1;
				playerOne = 0;
			}
			if (playerOne == 5) {
				cell5 = 'X';
				Counter = Counter + 1;
				playerOne = 0;
			}
			if (playerOne == 6) {
				cell6 = 'X';
				Counter = Counter + 1;
				playerOne = 0;
			}
			if (playerOne == 7) {
				cell7 = 'X';
				Counter = Counter + 1;
				playerOne = 0;
			}
			if (playerOne == 8) {
				cell8 = 'X';
				Counter = Counter + 1;
				playerOne = 0;
			}
			if (playerOne == 9) {
				cell9 = 'X';
				Counter = Counter + 1;
				playerOne = 0;
			}
			printf(" %c  | %c  | %c\n", cell1, cell2, cell3);
			printf("____|____|____\n");
			printf(" %c  |  %c | %c\n", cell4, cell5, cell6);
			printf("____|____|____\n");
			printf(" %c  |  %c | %c\n", cell7, cell8, cell9);
			printf("    |    |\n");
			/*Shart haye bord player one*/
			if ((cell1 == cell2 && cell1 == cell3 && cell1 == 'X') || (cell4 == cell5 && cell5 == cell6 && cell4 == 'X') || (cell7 == cell8 && cell8 == cell9 && cell7 == 'X') || (cell1 == cell4 && cell4 == cell7 && cell1 == 'X') || (cell2 == cell5 && cell5 == cell8 && cell2 == 'X') || (cell3 == cell6 && cell6 == cell9 && cell3 == 'X') || (cell1 == cell5 && cell5 == cell9 && cell1 == 'X') || (cell3 == cell5 && cell5 == cell7 && cell3 == 'X')) {
				printf("Congratulations!\nPlayer one has won the game!\n");
				Counter = 12;
			}
			if (Counter != 10 && Counter != 12) {/*in shart baraye in ast ke agar player one naborde ast az player two adad begirad*/
				printf("Player 2's turn\nPlease choose a number between 1 to 9:\n");/*az player two adad migirad va agar dar mahdode nabod dobare migirad*/
				scanf("%d", &playerTwo);
				getchar();
				while (playerTwo != 1 && playerTwo != 2 && playerTwo != 3 && playerTwo != 4 && playerTwo != 5 && playerTwo != 6 && playerTwo != 7 && playerTwo != 8 && playerTwo != 9) {
					printf("Invalid Number,Please Enter Between 1 to 9:\n");
					scanf("%d", &playerTwo);
				}
				/*shart tekrari nabodan*/
				while ((cell1 == 'X' && playerTwo == 1) || (cell1 == 'O' && playerTwo == 1) || (cell2 == 'O' && playerTwo == 2) || (cell2 == 'X' && playerTwo == 2) || (cell3 == 'O' && playerTwo == 3) || (cell3 == 'X' && playerTwo == 3) || (cell4 == 'O' && playerTwo == 4) || (cell4 == 'X' && playerTwo == 4) || (cell5 == 'O' && playerTwo == 5) || (cell5 == 'X' && playerTwo == 5) || (cell6 == 'O' && playerTwo == 6) || (cell6 == 'X' && playerTwo == 6) || (cell7 == 'O' && playerTwo == 7) || (cell7 == 'X' && playerTwo == 7) || (cell8 == 'O' && playerTwo == 8) || (cell8 == 'X' && playerTwo == 8) || (cell9 == 'O' && playerTwo == 9) || (cell9 == 'X' && playerTwo == 9)) {
					printf("This number was choosen,please enter another number:");
					scanf("%d", &playerTwo);
					while (playerTwo != 1 && playerTwo != 2 && playerTwo != 3 && playerTwo != 4 && playerTwo != 5 && playerTwo != 6 && playerTwo != 7 && playerTwo != 8 && playerTwo != 9) {
						printf("Invalid Number,Please Enter Between 1 to 9:\n");
						scanf("%d", &playerTwo);
					}
				}
			}
			if (playerTwo == 1) {/*har khane az jadval ra ba tavajoh be adad player two por mikonad*/
				cell1 = 'O';
				Counter = Counter + 1;
				playerTwo = 0;
			}
			if (playerTwo == 2) {
				cell2 = 'O';
				Counter = Counter + 1;
				playerTwo = 0;
			}
			if (playerTwo == 3) {
				cell3 = 'O';
				Counter = Counter + 1;
				playerTwo = 0;
			}
			if (playerTwo == 4) {
				cell4 = 'O';
				Counter = Counter + 1;
				playerTwo = 0;
			}
			if (playerTwo == 5) {
				cell5 = 'O';
				Counter = Counter + 1;
				playerTwo = 0;
			}
			if (playerTwo == 6) {
				cell6 = 'O';
				Counter = Counter + 1;
				playerTwo = 0;
			}
			if (playerTwo == 7) {
				cell7 = 'O';
				Counter = Counter + 1;
				playerTwo = 0;
			}
			if (playerTwo == 8) {
				cell8 = 'O';
				Counter = Counter + 1;
				playerTwo = 0;
			}
			if (playerTwo == 9) {
				cell9 = 'O';
				Counter = Counter + 1;
				playerTwo = 0;
			}
			/*shart haye bord player two*/
			if ((cell1 == cell2 && cell1 == cell3 && cell1 == 'O') || (cell4 == cell5 && cell5 == cell6 && cell4 == 'O') || (cell7 == cell8 && cell8 == cell9 && cell7 == 'O') || (cell1 == cell4 && cell4 == cell7 && cell1 == 'O') || (cell2 == cell5 && cell5 == cell8 && cell2 == 'O') || (cell3 == cell6 && cell6 == cell9 && cell3 == 'O') || (cell1 == cell5 && cell5 == cell9 && cell1 == 'O') || (cell3 == cell5 && cell5 == cell7 && cell3 == 'O')) {
				printf(" %c  | %c  | %c\n", cell1, cell2, cell3);
				printf("____|____|____\n");
				printf(" %c  |  %c | %c\n", cell4, cell5, cell6);
				printf("____|____|____\n");
				printf(" %c  |  %c | %c\n", cell7, cell8, cell9);
				printf("    |    |\n");
				printf("Congratulations!\nPlayer two has won the game!\n");
				Counter = 12;
			}
		}
		if (Counter == 10) {/*agar p==10 shavad va shart haye bala(bord player one va bord player two)bargharar nabashad,yani bazi mosavi shode ast*/
			printf("The game is over!\nNo one has won the game\n");
		}
		/*exit ya reset bazi*/
		printf("Press 1 if you want to start a new game.Otherwise press 2.\n");
		scanf("%d", &exit);
		while (exit != 1 && exit != 2) {
			printf("Invalid number,please press 1 or 2:\n");
			scanf("%d", &exit);
		}
		if (exit == 1)
			Counter = 1, cell1 = '1', cell2 = '2', cell3 = '3', cell4 = '4', cell5 = '5', cell6 = '6', cell7 = '7', cell8 = '8', cell9 = '9';
		if (exit == 2)
			Counter = 13;
	}
	printf("Goodbye");
}