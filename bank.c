#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int accountNumber;
    char name[100];
    float balance;
} Account;

void createAccount();
void viewAccount();
void updateAccount();
void searchAccount();
void deleteAccount();
void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice, read;
    while (1)
    {

        system("clear");
        printf("1. Create Bank Account \n");
        printf("2. View Bank Account Details \n");
        printf("3. Update Bank Account Details\n");
        printf("4. Search Bank Account \n");
        printf("5. Delete Bank Account \n");
        printf("6. Log Out \n\n\n");
        printf("~~~~~~Enter your choice then press enter!~~~~~~~\n\n");

        read = scanf("%d", &choice);
        while (getchar() != '\n')
            ;

        if (read == 1)
        {
            switch (choice)
            {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                updateAccount();
                break;
            case 4:
                searchAccount();
                break;
            case 5:
                deleteAccount();
                break;
            case 6:
                printf("Logging Out...");
                exit(0);
                break;
            default:
                printf("\nInvalid choice!\n");
                while (getchar() != '\n')
                    ;
                break;
            }
        }
        else
        {
            printf("\nInvalid input");
        }
        printf("\nPress Enter to Continue...\n");
        while (getchar() != '\n')
            ;
    }
}
void createAccount(){
    Account *newAccount = (Account *)malloc(sizeof(Account));

    if (newAccount == NULL){
        printf("Error: Unable to allocate memory for new account! \n");
        return;
    }
    char confirm[12];

    do {
        printf("Enter account number: \n");
        scanf("%d", &newAccount -> accountNumber);
        while (getchar() != '\n');

        printf("Enter Prefered Name: \n");
        fgets(newAccount -> name, sizeof(newAccount -> name), stdin);
        newAccount->name[strcspn(newAccount->name, "\n")] = '\0'; // Remove new line

        printf("Enter Initial Balance: \n");
        scanf("%f", &newAccount -> balance);
        while(getchar() != '\n'); // clear input buffer

        printf("\nAccount Number: %d\nName: %s\nInitial Balance: %.2f\n", newAccount -> accountNumber, newAccount -> name, newAccount -> balance);

        printf("Is this information correct? (yes/no): ");
        fgets(confirm, sizeof(confirm), stdin);
        confirm[strcspn(confirm, "\n")] = '\0';
        
    } while (strcmp(confirm, "yes") != 0);

    FILE *file = fopen("account.dat", "a");
    if (file == NULL){
        printf("Error: Unable to open file. \n");
        free(newAccount);
        return;
    }
    fprintf(file, "%d %s %.2f\n", newAccount -> accountNumber, newAccount -> name, newAccount -> balance);
    fclose(file);
    printf("Account created successfully!\n");
    free(newAccount);
}


void viewAccount()
{
    printf("View Account Function");
}

void updateAccount()
{
    printf("Update Account Function");
}

void searchAccount()
{
    printf("Search Account Function");
}

void deleteAccount()
{
    printf("Delete Account Function");
}