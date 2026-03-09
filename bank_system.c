#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accNumber;
    char name[50];
    float balance;
};

int main() {

    FILE *file;
    struct Account acc;
    int choice;

    while(1) {

        printf("\n1 Create Account\n");
        printf("2 View Accounts\n");
        printf("3 Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1) {

            file = fopen("accounts.txt", "a");

            printf("Enter account number: ");
            scanf("%d", &acc.accNumber);

            printf("Enter name: ");
            scanf("%s", acc.name);

            printf("Enter balance: ");
            scanf("%f", &acc.balance);

            fprintf(file, "%d %s %.2f\n",
            acc.accNumber,
            acc.name,
            acc.balance);

            fclose(file);

            printf("Account created successfully!\n");
        }

        else if(choice == 2) {

            file = fopen("accounts.txt", "r");

            if(file == NULL) {
                printf("No accounts found.\n");
                continue;
            }

            printf("\nAccounts List:\n");

            while(fscanf(file, "%d %s %f",
                  &acc.accNumber,
                  acc.name,
                  &acc.balance) != EOF) {

                printf("Account: %d | Name: %s | Balance: %.2f\n",
                       acc.accNumber,
                       acc.name,
                       acc.balance);
            }

            fclose(file);
        }

        else if(choice == 3) {
            printf("Exiting program...\n");
            break;
        }

        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}