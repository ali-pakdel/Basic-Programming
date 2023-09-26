#include <stdio.h>
#include <string.h>
typedef struct UTBank user_list;
typedef struct transaction_info transAct;
struct transaction_info {
	char type[20];
	double amount;
	transAct *next;
};
struct UTBank {
	char name[20];
	char password[20];
	char phoneNumber[20];
	long int uniq_id;
	double cash;
	int num_of_transaction;
	user_list *next;
	transAct *trans_head;
};
void read_list(user_list *head, int *standard_id);
void write_list(user_list *haed);
user_list* head();
user_list* findLastUser(user_list* head);
transAct* transhead();
transAct* findLastTrans(transAct* transHead);
void transfer(user_list *head, user_list *userNode, int *adminaccess);
user_list* login(user_list *head, int *adminaccess, int *exit);
void add_user(user_list* head, int *adminaccess, int *standard_id);
void withdraw(user_list* head, int *adminaccess);
int command_type(user_list *head, user_list *userNode, int *adminaccess, int *standard_id);
void view(user_list* head, user_list* userNode, int *adminaccess);
void logout(int *adminaccess);
void deposit(user_list* head, int *adminaccess);
void deleteUser(user_list* head, int *adminaccess);
void free_nodes(user_list* head);