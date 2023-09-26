#include <stdio.h>
#include <string.h>
#include "functions.h"
int main() {
	int adminaccess = 0, standard_id = 924800, logout = 0, exit = 0;
	user_list *first = head();
	user_list *userNode;
	transAct *firstTrans = transhead();
	read_list(first, &standard_id);
	while (exit == 0) {
		while (adminaccess == 0) {
			userNode = login(first, &adminaccess, &exit);
		}
		while (adminaccess == 1 || adminaccess == 2) {
			exit = command_type(first, userNode, &adminaccess, &standard_id);
			if (exit == 1)
				break;
		}
	}
	write_list(first);
}
