#include <stdio.h>
#include <stdlib.h>
#include "Double_LL.h"
#include "Stack.h"
#include <string.h>
// #include <gtk/gtk.h>

int main(void)
{
    char client_name[1000] = "Mohamed Momen Ahmed";
    char client_name_2[100] = "Yahia 7assan";
    char client_name_3[100] = "GG TT";
    customer_info c1, c2, c3;
    // c1.Name =
    // scanf("%[^\n]%*c", &c1.Name);
    // c1.credit_money = 100;
    // c1.debit_money = 10;
    // // printf("\n");
    // scanf("%[^\n]%*c",&c2.Name);
    // c2.credit_money = 50;
    // c2.debit_money = 5;
    // scanf("%[^\n]%*c",&c3.Name);
    // c3.credit_money = 10;
    // c3.debit_money = 1;

    create_Bank_Branches(3);
    display_bank_branches();

    create_customer();
    create_customer();
    create_customer();

    display_customer_info(102, c1, Register);
    display_customer_info(103, c2, Login);
    display_customer_info(103, c3, Login);
    // display_bank_branches();
    // insert_branch();
    // display_bank_branches();
    // delete_branch();
    // display_bank_branches();
    // insert_branch();
    // display_bank_branches();
    // insert_branch();
    // display_bank_branches();
    return 0;
}