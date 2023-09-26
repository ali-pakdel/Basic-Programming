#include <stdio.h>
#include <string.h>
#include "functions.h"

void read_list(user_list *head, int *standard_id) {/*read the txt*/
	FILE*banklist = fopen("Bank_list.txt", "a");
	fclose(banklist);
	banklist = fopen("Bank_list.txt", "r");
	user_list* newNode;
	transAct* newTrans;
	char name[15], tempname[15];
	int  i;
	if (banklist == NULL)
		printf("Can't open the file\n");
	else {
		while (1) {
			if (fscanf(banklist, "%s", tempname) == EOF)
				break;
			else {
				strcpy(name, tempname);
				newNode = (user_list*)malloc(sizeof(user_list));/*create a new node*/
				findLastUser(head)->next = newNode;
				newNode->next = NULL;
				fscanf(banklist, " %s %s %ld %lf %d", newNode->password, newNode->phoneNumber, &(newNode->uniq_id), &(newNode->cash), &(newNode->num_of_transaction));
				strcpy(newNode->name, name);
				*standard_id = newNode->uniq_id;
				newNode->trans_head = transhead();
				for (i = 0; i < newNode->num_of_transaction; i++) {
					newTrans = (transAct*)malloc(sizeof(transAct));
					findLastTrans(newNode->trans_head)->next = newTrans;
					newTrans->next = NULL;
					fscanf(banklist, " %s : %lf", newTrans->type, &(newTrans->amount));
				}
			}
		}
	}
	fclose(banklist);
}
void write_list(user_list *head) {/*write the nodes in txt*/
	FILE *banklist = fopen("Bank_list.txt", "w");
	user_list* current = head->next;
	transAct* trans;
	int i;
	if (banklist == NULL)
		printf("Can't open the file\n");
	else {
		while (current != NULL) {
			fprintf(banklist, "%s %s %s %ld %lf %d", current->name, current->password, current->phoneNumber, current->uniq_id, current->cash, current->num_of_transaction);
			if (current->num_of_transaction) {
				trans = current->trans_head->next;
				for (i = 0; i < current->num_of_transaction; i++) {
					while (trans != NULL) {
						fprintf(banklist, " %s : %lf", trans->type, trans->amount);
						trans = trans->next;
					}
				}
			}
			fprintf(banklist, "\n");
			current = current->next;
		}
	}
	free_nodes(head);
}
void free_nodes(user_list* head) {/*free all the nodes exept head(admin) at the end*/
	user_list*current = head->next;
	user_list* temp1;
	transAct* temp2;
	transAct* temp3;
	while (current != NULL) {
		temp1 = current->next;
		if (current->num_of_transaction) {
			temp2 = current->trans_head;
			while (temp2 != NULL) {
				temp3 = temp2->next;
				free(temp2);
				temp2 = temp3;
			}
		}
		free(current);
		current = temp1;
	}
}
user_list* head() {/*Creating head for admin*/
	user_list*head = (user_list*)malloc(sizeof(user_list));
	strcpy(head->name, "admin");
	strcpy(head->password, "123");
	strcpy(head->phoneNumber, "00000000000");
	head->uniq_id = 21209800;
	head->cash = 0;
	head->num_of_transaction = 0;
	head->next = NULL;
	return head;
}
user_list* findLastUser(user_list* head) {/*Finds the last user's node for creating another node for next user*/
	user_list* last = head;
	while (last->next != NULL)
		last = last->next;
	return last;
}
transAct* transhead() {/*Creating head for transaction*/
	transAct* transHead = (transAct*)malloc(sizeof(transAct));
	transHead->next = NULL;
	return transHead;
}
transAct* findLastTrans(transAct* transHead) {/*Find the last transaction's node for creating another node for the next user*/
	transAct* last = transHead;
	while (last->next != NULL)
		last = last->next;
	return last;
}
void add_user(user_list* head, int *adminaccess, int *standard_id) {/*Creating new user*/
	user_list *lastUser = findLastUser(head);
	user_list *newNode;
	user_list *current = head->next;
	transAct* lastTrans;
	char name[15], password[15], phoneNumber[15], enter;
	int same = 0;
	scanf("%s %s %s", name, password, phoneNumber);
	scanf("%c", &enter);
	if (*adminaccess == 2) {/*this command is for admin*/
		while (current != NULL) {
			if (strcmp(name, current->name) == 0) {
				printf("This name already choosen\n");
				return;
			}
			else if (strcmp(phoneNumber, current->phoneNumber) == 0) {
				printf("This phone number already choosen\n");
				return;
			}
			current = current->next;
		}
		newNode = (user_list*)malloc(sizeof(user_list));
		lastUser->next = newNode;
		newNode->next = NULL;
		strcpy(newNode->name, name);
		strcpy(newNode->password, password);
		strcpy(newNode->phoneNumber, phoneNumber);
		newNode->uniq_id = (*standard_id) + 1;
		(*standard_id)++;
		newNode->cash = 0.0;
		newNode->num_of_transaction = 0;
		newNode->trans_head = transhead();
		printf("user added successfully\n");
	}
	else
		printf("You don't have access to this command\n");
}
user_list* login(user_list *head, int *adminaccess, int *exit) {/*Login as admin or normal user*/
	user_list *userNode = head;
	char name[15], password[15];
	printf("Enter username and password:\n");
	printf("login ");
	scanf("%s", name);
	if (strcmp(name, "exit") == 0) {/*if no one logged in and user wants to exit*/
		(*exit) = 1;
		(*adminaccess) = 3;
		return;
	}
	scanf(" %s", password);
	if (strcmp(name, head->name) == 0) {/*logging in as an admin*/
		if (strcmp(password, head->password) == 0) {
			printf("Admin logged in successfully\n");
			(*adminaccess) = 2;
			return head;
		}
		else {
			printf("Password is wrong\n");
			return head;
		}
	}
	while (userNode != NULL) {/*logging in as an normal user*/
		if (strcmp(userNode->name, name) == 0)
			if (strcmp(userNode->password, password) == 0) {
				printf("%s logged in successfully\n", userNode->name);
				(*adminaccess) = 1;
				return userNode;
			}
			else {
				printf("Password is wrong\n");
				return head;
			}
		userNode = userNode->next;
	}
	printf("There is no account for %s\n", name);
}
void view(user_list* head, user_list* userNode, int *adminaccess) {/*view information of an user*/
	user_list* current = head->next;
	transAct* temp;
	int find = 0;
	if (*adminaccess == 2) {/*admin wants to see an user's info*/
		char name[15];
		scanf(" %s", &name);
		while (current != NULL) {
			if (strcmp(current->name, name) == 0) {
				find = 1;
				break;
			}
			current = current->next;
		}
		if (find == 0) {
			printf("There is no account for %s\n", name);
			return;
		}
		printf("Name: %s\nPassword: %s\nPhone number: %s\nID: %ld\nCash: %lf\nNumber of transactions: %d\n", current->name, current->password, current->phoneNumber, current->uniq_id, current->cash, current->num_of_transaction);
		if (current->num_of_transaction) {
			temp = current->trans_head->next;
			while (temp != NULL) {
				printf("%s: %lf\n", temp->type, temp->amount);
				temp = temp->next;
			}
		}
	}
	else {/*user wants to see his info*/
		printf("Name: %s\nPassword: %s\nPhone number: %s\nID: %ld\nCash: %lf\nNumber of transactions: %d\n", userNode->name, userNode->password, userNode->phoneNumber, userNode->uniq_id, userNode->cash, userNode->num_of_transaction);
		if (userNode->num_of_transaction) {
			temp = userNode->trans_head->next;
			while (temp != NULL) {
				printf("%s: %lf\n", temp->type, temp->amount);
				temp = temp->next;
			}
		}
	}
}
void logout(int *adminaccess) {
	(*adminaccess) = 0;
}
void transfer(user_list *head, user_list *userNode, int *adminaccess) {/*transfer money*/
	user_list *current = head;
	transAct* userTrans = userNode->trans_head;
	transAct* newTrans;
	transAct* lastTrans1 = findLastTrans(userTrans);
	transAct* lastTrans2;
	char name[15];
	double cash;
	scanf(" %s %lf", name, &cash);
	if (*adminaccess == 2) {/*just normal user can use this command*/
		printf("You can't do that\n");
		return;
	}
	if (strcmp(name, userNode->name) == 0) {
		printf("You can't do that\n");
		return;
	}
	if (cash > userNode->cash) {/*not enough money to send*/
		printf("You don't have enough money\n");
		return;
	}
	if (cash <= 0) {/*value of money must be positive*/
		printf("Transfer value must be greather than zero\n");
		return;
	}
	while (current != NULL) {
		if (strcmp(name, current->name) == 0) {
			current->cash += cash;
			current->num_of_transaction++;
			userNode->cash -= cash;
			userNode->num_of_transaction++;
			newTrans = (transAct*)malloc(sizeof(transAct));
			lastTrans1->next = newTrans;
			newTrans->next = NULL;
			strcpy(newTrans->type, "Transfer_Out");
			newTrans->amount = cash;
			lastTrans2 = findLastTrans(current->trans_head);
			newTrans = (transAct*)malloc(sizeof(transAct));
			lastTrans2->next = newTrans;
			newTrans->next = NULL;
			strcpy(newTrans->type, "Transfer_In");
			newTrans->amount = cash;
			printf("Transfer was successfull\n");
			break;
		}
		current = current->next;
	}
}
void deposit(user_list* head, int *adminaccess) {/*deposit money to an user*/
	user_list* current = head->next;
	transAct* lastTrans;
	transAct* newTrans;
	char name[15];
	double cash;
	scanf(" %s %lf", name, &cash);
	getchar();
	if (*adminaccess != 2) {/*just admin can use this command*/
		printf("You don't have access to this command!\n");
		return;
	}
	if (cash <= 0) {/*value must be positive*/
		printf("Deposit value must be greater than zero\n");
		return;
	}
	else {
		while (current != NULL) {
			if (strcmp(name, current->name) == 0) {
				lastTrans = findLastTrans(current->trans_head);
				current->cash += cash;
				newTrans = (transAct*)malloc(sizeof(transAct));
				lastTrans->next = newTrans;
				newTrans->next = NULL;
				strcpy(newTrans->type, "Deposit");
				newTrans->amount = cash;
				current->num_of_transaction++;
				printf("Deposit was successfull\n");
				break;
			}
			current = current->next;
		}
	}
}
void withdraw(user_list* head, int *adminaccess) {/*withdraw money form an user*/
	user_list* current = head->next;
	transAct* lastTrans;
	transAct* newTrans;
	char name[15];
	double cash;
	scanf(" %s %lf", name, &cash);
	getchar();
	if (*adminaccess != 2) {/*only admin can use this command*/
		printf("You don't have access to this command!\n");
		return;
	}
	else {
		while (current != NULL) {
			if (strcmp(name, current->name) == 0) {
				if (current->cash < cash) {
					printf("%s doesn't have enough money\n", name);
					break;
				}
				lastTrans = findLastTrans(current->trans_head);
				current->cash -= cash;
				newTrans = (transAct*)malloc(sizeof(transAct));
				lastTrans->next = newTrans;
				newTrans->next = NULL;
				strcpy(newTrans->type, "Withdraw");
				newTrans->amount = cash;
				current->num_of_transaction++;
				printf("Withdraw was successfull\n");
				break;
			}
			current = current->next;
		}
	}
}
void deleteUser(user_list* head, int *adminaccess) {/*delete an user*/
	char name[15];
	scanf(" %s", name);
	user_list* prevoius = head;
	user_list* current = head->next;
	transAct* temp;
	if (*adminaccess == 2) {/*only admin can use this command*/
		while (current != NULL) {
			if (strcmp(name, current->name) == 0) {
				while (current->trans_head->next != NULL) {
					temp = current->trans_head->next->next;
					free(current->trans_head->next);
					current->trans_head->next = temp;
				}
				free(current->trans_head);
				prevoius->next = current->next;
				free(current);
				printf("User was deleted successfully\n");
				break;
			}
			prevoius = current;
			current = current->next;
		}
	}
	else
		printf("You don't access to this command\n");
}
int command_type(user_list *head, user_list *userNode, int *adminaccess, int *standard_id) {/*what does admin or user want to do*/
	char command[60], space;
	scanf("%s", &command);
	scanf("%c", &space);
	if (strcmp(command, "add_user") == 0)
		add_user(head, adminaccess, standard_id);
	else if (strcmp(command, "view") == 0)
		view(head, userNode, adminaccess);
	else if (strcmp(command, "logout") == 0)
		logout(adminaccess);
	else if (strcmp(command, "deposit") == 0)
		deposit(head, adminaccess);
	else if (strcmp(command, "withdraw") == 0)
		withdraw(head, adminaccess);
	else if (strcmp(command, "delete") == 0)
		deleteUser(head, adminaccess);
	else if (strcmp(command, "transfer") == 0)
		transfer(head, userNode, adminaccess);
	else if (strcmp(command, "exit") == 0)
		return 1;
	return 0;
}
