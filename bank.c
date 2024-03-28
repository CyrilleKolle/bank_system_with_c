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
    int choice;
    while (1)
    {
        printf("1. Create Bank Account \n");
        printf("2. View Bank Account Details \n");
        printf("3. Update Bank Account Details\n");
        printf("4. Search Bank Account \n");
        printf("5. Delete Bank Account \n");
        printf("6. Log Out \n\n\n");
        printf("~~~~~~Enter your choice then press enter!~~~~~~~\n\n");

        scanf("%d", &choice);
        while (getchar() != '\n')
            ;

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
}

void createAccount()
{
    printf("Create Account Function");
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