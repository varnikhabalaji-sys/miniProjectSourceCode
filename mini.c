// creating a mini project in c for bank account management system

// MODULE 0:-(structure + file)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct account
{
    int accNo;
    char name[20];
    float balance;
};
// file used bank.dat

// MODULE 1:-(create account + display account)

void printAccount(const struct account *acc)
{
    printf("Account Number: %d\n", acc->accNo);
    printf("Name: %s\n", acc->name);
    printf("Balance: %.2f\n", acc->balance);
    printf("--------------------------\n");
}

int main()
{
    struct account acc;
    FILE *fp = fopen("bank.dat", "a+b");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter account number: ");
    scanf("%d", &acc.accNo);
    printf("Enter name: ");
    scanf(" %[^\\n]", acc.name);
    printf("Enter balance: ");
    scanf("%f", &acc.balance);

    fwrite(&acc, sizeof(struct account), 1, fp);
    fflush(fp);
    rewind(fp);

    printf("\nRecord inserted successfully!\n");
    printf("\n-----Bank Records-----\n");

    struct account temp;
    while (fread(&temp, sizeof(struct account), 1, fp) == 1) {
        printAccount(&temp);
    }

    fclose(fp);
    return 0;
}
