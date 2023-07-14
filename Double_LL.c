#include <stdio.h>
#include <stdlib.h>
#include "Double_LL.h"
#include <string.h>

bank_branch *head = NULL, *tail = NULL, *prev_node = NULL, *next_node = NULL, *current_node = NULL, *temp = NULL, *new_node = NULL;
char client1_name[20] = "Ahmed Sabry";
char client2_name[20] = "Mohamed Samir";

struct bank_branches *create_Bank_Branches(int no_of_branches)
{
    bank_branch branch_info;
    int i = 0, j = 0;
    if ((head == NULL))
    {

        // printf("Creating a List...\n");

        while (i < no_of_branches)
        {
            // printf("Please, Enter Data to be Stored For Element %d !\n", (i + 1));
            // scanf("%d", &data_user.data);
            printf("--------------------------------------\n");
            printf("Please, Enter Branch ID\n");
            scanf("%d", &branch_info.branch_id);
            printf("--------------------------------------\n");
            i++;
            if (head == NULL)
            {
                // Means There is No list Created Previously... No node in First Position
                current_node = (bank_branch *)malloc(sizeof(bank_branch));
                // current_node->data = data_user.data;
                current_node->branch_id = branch_info.branch_id;
                for (j = 0; j < Customers_Limit; j++)
                {
                    current_node->no_customers[j].password = 0;
                }
                current_node->prev = NULL;
                current_node->next = NULL;
                head = current_node;
                // Created First Node
            }
            else
            {

                /* if elements number = 3, then first node would be created in the first if statement
                Then elements to create after the first node = 2, then we need i variable to reach 0 & 1 only, not to continue to 2
                , in which we put this condition :> */
                new_node = (bank_branch *)malloc(sizeof(bank_branch));
                prev_node = head;
                // Incrementing till reaching the last node to add up to the new node created
                while (prev_node->next != NULL)
                {
                    prev_node = prev_node->next;
                }
                new_node->branch_id = branch_info.branch_id;

                for (int q = 0; q < Customers_Limit; q++)
                {
                    new_node->no_customers[q].password = 0;
                    printf("%d", new_node->no_customers[q].password);
                    // printf("--------------------------------------------\n");
                }
                prev_node->next = new_node;
                new_node->prev = prev_node;
                new_node->next = NULL;
                tail = new_node;
                // j++;
            }
        }
        if (i == no_of_branches)
        {
            printf("Bank has currently %d branches.\n", no_of_branches);
            printf("--------------------------------------------\n");
            return tail;
        }
    }
    else
    {
        printf("There is Already List Created!\n");
        printf("Press On Insert Node to enter a node.\n");
        printf("-------------------------------------------\n");
    }
}

void display_bank_branches() // Display All Elements of The list
{
    int i = 0;
    current_node = head;
    if (current_node != NULL)
    {
        while (current_node->next != NULL)
        {
            ++i;
            printf("Branch No.%d has ID of %d\n", i, current_node->branch_id);
            // printf("Data of The %d Node is %d with ID Of %d\n", i, current_node->data, current_node->id);
            printf("--------------------------------------------------\n");
            current_node = current_node->next;
        }
        printf("Branch No.%d has ID of %d\n", ++i, current_node->branch_id);
        // printf("Data of The %d Node is %d with ID Of %d\n", ++i, current_node->data, current_node->id);
        printf("--------------------------------------------------\n");
    }
    else
    {
        printf("List is Empty, There is nothing to display!\n");
        printf("--------------------------------------------------\n");
    }
}

int insert_branch() // Insert any node at any specific required position
{
    bank_branch data_user;
    int user_data, branch_id, pos, i = 0, k, list_length;
    printf("Enter Position For Placing Data!\n");
    scanf("%d", &pos);
    printf("--------------------------------------------------\n");
    list_length = get_branchs_number();
    while (((pos - 1) > list_length) || (pos < 0))
    {
        if (pos < 0)
        {
            printf("Negative Positions are not permitted..\n");
            printf("Please, Enter a positive integer position\n");
        }
        else if (pos > list_length)
        {
            printf("The Position Entered exceedded the list length!\n");
            printf("Please, Enter a positive integer position\n");
        }
        scanf("%d", &pos);
        printf("--------------------------------------------------\n");
    }
    if ((head == NULL) && (pos == 1))
    {
        // check_entry_pos = 1;
        printf("There are No Bank Branches..!\n");
        printf("-------------------------------------------\n");
        printf("Making a Branch At Begining...\n");
        // printf("--------------------------------------------------\n");
        // printf("Enter Data of The Node!\n");
        // scanf("%d", &user_data);
        printf("-------------------------------------------\n");
        printf("Enter Branch ID!\n");
        scanf("%d", &branch_id);
        printf("-------------------------------------------\n");
        // data_user.data = user_data;
        // data_user.id = user_id;

        new_node = (bank_branch *)malloc(sizeof(bank_branch));
        // new_node->data = data_user.data;
        // new_node->id = data_user.id;
        // new_node->data = user_data;
        new_node->branch_id = branch_id;
        head = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
        // printf("Data %d and ID %d\n", new_node->data, new_node->id);
        printf("Branch has successfully been added!\n");
        printf("--------------------------------------------------\n");
        return Success;
    }
    else if ((head == NULL) && (pos > 1))
    {
        printf("The Position Entered exceedded the list length!\n");
        printf("Please, Enter a positive integer position\n");
        printf("--------------------------------------------------\n");
        return Fail;
    }
    else
    {
        if (pos == (list_length + 1)) // Last Position Entry
        {
            printf("Maknig Branch At End.....\n");
            printf("--------------------------------------------------\n");
            new_node = (bank_branch *)malloc(sizeof(bank_branch));
            // printf("Enter Data of The Node!\n");
            // scanf("%d", &user_data);
            // printf("-------------------------------------------\n");
            printf("Enter Branch ID!\n");
            scanf("%d", &branch_id);
            printf("-------------------------------------------\n");
            // new_node->data = user_data;
            new_node->branch_id = branch_id;
            new_node->next = NULL;
            prev_node = head;
            while (prev_node->next != NULL) // Transverse the list till the end pos :>
            {
                prev_node = prev_node->next; // Incrementing..
            }
            prev_node->next = new_node;
            new_node->prev = prev_node;

            printf("Branch has successfully been added!\n");
            printf("--------------------------------------------------\n");
            return Success;
        }
        else if (pos == 1)
        {
            // Insertion At Begining
            printf("Maknig Branch At Begining.....\n");
            printf("--------------------------------------------------\n");
            next_node = head;
            current_node = (bank_branch *)malloc(sizeof(bank_branch));
            // printf("Enter Data of The Node!\n");
            // scanf("%d", &user_data);
            // printf("-------------------------------------------\n");
            printf("Enter Branch ID!\n");
            scanf("%d", &branch_id);
            printf("-------------------------------------------\n");
            // current_node->data = user_data;
            current_node->branch_id = branch_id;
            current_node->next = next_node;
            next_node->prev = current_node;
            current_node->prev = NULL;
            head = current_node;
            printf("Branch has successfully been added!\n");
            printf("--------------------------------------------------\n");
        }
        else
        {

            /* For Any Position Except Ending and Begining...
               We need two pointers.. One before the position needed and Second After the position Required
            */
            list_length = get_branchs_number();
            printf("Making a Node at Required Position...\n");
            printf("--------------------------------------------------\n");
            new_node = (bank_branch *)malloc(sizeof(bank_branch));
            // printf("Enter Data of The Node!\n");
            // scanf("%d", &user_data);
            // printf("-------------------------------------------\n");
            printf("Enter Branch ID!\n");
            scanf("%d", &branch_id);
            printf("-------------------------------------------\n");
            // new_node->data = user_data;
            new_node->branch_id = branch_id;
            new_node->next = NULL;
            new_node->prev = NULL;
            prev_node = head;
            i = 1;
            while (i < (pos - 1)) // Transverse the list till the Required Position :>
            {
                prev_node = prev_node->next; // Incrementing..
                i++;
                // printf("increementing value is %d\n",i);
            }

            // PROBLEM HERE
            temp = prev_node->next;
            temp->prev = new_node;
            new_node->next = prev_node->next;
            prev_node->next = new_node;
            new_node->prev = prev_node;

            printf("Node has successfully been added!\n");
            printf("--------------------------------------------------\n");
        }
    }
}

int delete_branch()
{
    int list_length, i, pos;
    list_length = get_branchs_number();
    if (list_length != 0)
    {
        printf("Enter Position For Removing Branch!\n");
        scanf("%d", &pos);
        printf("--------------------------------------------------\n");
        while ((pos > list_length) || (pos <= 0))
        {

            if (pos < 0)
            {
                printf("Negative Positions are not permitted..\n");
                printf("Please, Enter a positive integer position\n");
                scanf("%d", &pos);
                printf("--------------------------------------------------\n");
            }
            else if (pos > list_length)
            {
                printf("The Position Entered exceedded the list length!\n");
                printf("Please, Enter a positive integer position\n");
                scanf("%d", &pos);
                printf("--------------------------------------------------\n");
            }
        }
        if (head == NULL)
        {
            printf("List is Empty, There is no Node to delete.\n");
            printf("--------------------------------------------------\n");
        }
        else
        {
            // Here we need 2 pointers to delete from End
            // list_length = get_length_list();
            i = 1;
            if ((pos == list_length) && (list_length != 1)) // Deleting the last Node
            {
                printf("Deleting Desired Branch From End....\n");
                printf("--------------------------------------------------\n");
                prev_node = head;
                while (i < pos - 1)
                {
                    prev_node = prev_node->next;
                    i++;
                }
                current_node = prev_node->next;
                prev_node->next = NULL;
                free(current_node); // Deleted the node
                printf("Branch has successfully been deleted!\n");
                printf("--------------------------------------------------\n");
            }
            else if ((pos == 1) && (list_length >= 1)) // Deleting From Begining
            {
                if (pos == list_length) // One Node In the List
                {
                    // current_node = head;
                    printf("Deleting The Only Branch In The List....\n");
                    printf("--------------------------------------------------\n");
                    free(head);
                    head = NULL;
                    // head = current_node;
                    printf("Branch has successfully been deleted!\n");
                    printf("--------------------------------------------------\n");
                }
                else
                {
                    printf("Deleting Desired Branch From Begining....\n");
                    printf("--------------------------------------------------\n");
                    current_node = head;
                    head = head->next;
                    head->prev = NULL;
                    free(current_node);
                    printf("Branch has successfully been deleted!\n");
                    printf("--------------------------------------------------\n");
                }
            }
            else
            {
                // Deleting Any Node in Any Desired Position
                // Here We need 3 pointers to delete from any position -> prev,current,next <-
                printf("Deleting Desired Branch From Required Position....\n");
                printf("------------------int entry_number_of_branches()--------------------------------\n");
                i = 1;
                prev_node = head;
                while (i < pos - 1) // Tranversing list till meeting the node preceeding the desired node to delete ^^
                {
                    prev_node = prev_node->next;
                    i++;
                }
                current_node = prev_node->next; // The Desired Node
                next_node = current_node->next; // After Desired Node
                prev_node->next = next_node;
                next_node->prev = prev_node;
                free(current_node); // Deleted the Desired Node
                printf("Node has successfully been deleted!\n");
                printf("--------------------------------------------------\n");
            }
        }
    }
    else
    {
        printf("List is Empty! There is Nothing To Delete\n");
        printf("--------------------------------------------------\n");
    }
}

// void delete_node_by_data_value(int data_user)
// {
//
// }

int search_4_data() // Returns the position of the element
{
    int i = 1, entry_id;
    printf("Please, Enter ID To access Data stored!\n");
    scanf("%d", &entry_id);
    printf("--------------------------------------------------\n");
    if (head == NULL)
    {
        printf("List is Empty!\n");
        printf("--------------------------------------------------\n");
    }
    else
    {
        current_node = head;
        if (entry_id == current_node->branch_id)
        {
            printf("ID has been found in First Node!\n");
            printf("--------------------------------------------------\n");
            // printf("Value of The Data = %d\n",current_node -> data);
            return 1;
        }
        else
        {
            while (current_node->next != NULL)
            {
                i++;
                if (entry_id == current_node->branch_id)
                {
                    printf("ID has been found In the %d Node!\n", i);
                    printf("--------------------------------------------------\n");
                    // printf("Value of The Data = %d\n",current_node -> data);
                    return i;
                }
                current_node = current_node->next;
            }
            if (current_node->next == NULL)
            {
                if (entry_id == current_node->branch_id)
                {
                    printf("ID has been found in End!\n");
                    printf("--------------------------------------------------\n");
                    return i;
                }
                else
                {
                    printf("ID has Not been found!\n");
                    printf("--------------------------------------------------\n");
                    return Fail;
                }
            }
        }
    }
}

void read_or_change_data_by_pos(int choice)
{
    int i = 1, pos, data_change, list_length;
    if (choice == Choice_Read)
    {
        printf("Enter Position To Access Read Procedure From!\n");
    }
    else if (choice == Choice_Change)
    {
        printf("Enter Position To Change Data Stored in it!\n");
    }
    scanf("%d", &pos);
    printf("--------------------------------------------------\n");
    list_length = get_branchs_number();
    if ((pos <= list_length) && (pos > 0))
    {
        if (head == NULL)
        {
            printf("List is Empty!\n");
            printf("--------------------------------------------------\n");
        }
        else
        {
            if (choice == Choice_Change)
            {
                printf("Enter Data To be Changed with the stored!\n");
                scanf("%d", &data_change);
                printf("--------------------------------------------------\n");
            }

            current_node = head;
            while (i < pos)
            {
                current_node = current_node->next;
                i++;
            }
            if (choice == Choice_Read)
            {
                // printf("Data of The Given ID = %d\n", current_node->data);
                printf("--------------------------------------------------\n");
            }
            else if (choice == Choice_Change)
            {
                // current_node->data = data_change;
                // printf("Data has successfully been changed to %d for ID %d\n", current_node->data, current_node->id);
                printf("--------------------------------------------------\n");
            }
        }
    }
    else
    {
        if (list_length == 0)
        {
            printf("List is Empty!\n");
        }
        else
        {

            printf("Position Given invalid!\n");
            printf("--------------------------------------------------\n");
        }
    }
}

// void read_similar_data(int data_sim)
// {
//
// }

void read_or_change_info_by_pass(int choice) // 2 Choices... 1- Read 2- Change
{
    int id, data_change;
    customer_info client;
    if (choice == Choice_Read)
    {
        printf("Enter Branch ID you are currently in\n");
        scanf("%d", &id);
        printf("--------------------------------------------------\n");
    }
    else if (choice == Choice_Change)
    {
        printf("Enter Branch ID you are currently in\n");
        scanf("%d", &id);
        printf("--------------------------------------------------\n");
        printf("Enter Data To be Changed with the stored!\n");
        scanf("%d", &data_change);
        printf("--------------------------------------------------\n");
    }

    if (head == NULL)
    {
        printf("List is Empty!\n");
        printf("--------------------------------------------------\n");
    }
    else
    {
        current_node = head;
        if (id == current_node->branch_id)
        {
            if (choice == Choice_Read)
            {
                // printf("Data of The Given ID = %d\n", current_node->data);
                // printf("--------------------------------------------------\n");
            }
            else if (choice == Choice_Change)
            {
                // current_node->data = data_change;
                // printf("Data has successfully been changed to %d for ID %d\n", current_node->data, current_node->id);
                printf("--------------------------------------------------\n");
            }
        }
        else
        {
            while (current_node->next != NULL)
            {
                if (id == current_node->branch_id)
                {

                    if (choice == Choice_Read)
                    {
                        // printf("Data of The Given ID = %d\n", current_node->data);
                        printf("--------------------------------------------------\n");
                    }
                    else if (choice == Choice_Change)
                    {
                        // current_node->data = data_change;
                        // printf("Data has successfully been changed to %d for ID %d\n", current_node->data, current_node->id);
                        printf("--------------------------------------------------\n");
                    }
                }
                current_node = current_node->next;
            }
            if (current_node->next == NULL)
            {
                if (id == current_node->branch_id)
                {
                    if (choice == Choice_Read)
                    {
                        // printf("Data of The Given ID = %d\n", current_node->data);
                        printf("--------------------------------------------------\n");
                    }
                    else if (choice == Choice_Change)
                    {
                        // current_node->data = data_change;
                        // printf("Data has successfully been changed to %d for ID %d\n", current_node->data, current_node->id);
                        printf("--------------------------------------------------\n");
                    }
                }
                else
                {
                    printf("There is No ID similar to what you enter!\n");
                    printf("--------------------------------------------------\n");
                }
            }
        }
    }
}

struct customer create_customer()
{
    customer_info client;
    char Name[Name_Limit];
    int branch, i = 0, customer_limit_status = 0, branch_availability = 0, Enrolled = Enrolled_Failed, check;

    while (1)
    {
        if ((customer_limit_status == customer_limit_exceeded) || (branch_availability == branch_not_found))
        {
            customer_limit_status = 0;
            branch_availability = 0;
            scanf("%d", &branch);
        }
        else
        {
            printf("Select which branch id you want to enroll in\n");
            scanf("%d", &branch);
        }
        i = 0;
        current_node = head;
        if (branch == current_node->branch_id)
        {
            while ((current_node->no_customers[i].password != 0) && (i < Customers_Limit))
            {
                i++;
            }
            // printf("i = %d\n", i);
            if (i >= Customers_Limit)
            {
                printf("--------------------------------------------------\n");
                printf("This Branch is Currently unavailable to enroll in due to high load\n");
                printf("Select Any Of The Other Available Branches\n");
                printf("--------------------------------------------------\n");
                customer_limit_status = customer_limit_exceeded;
            }
            else
            {
                // Found A Place to Fill In
                printf("--------------------------------------------------\n");
                printf("Please, Enter your 1st and 2nd Name in English\n");
                printf("--------------------------------------------------\n");
                while (1)
                {
                    scanf("\n");
                    scanf("%[^\n]%*c", client.Name);
                    check = check_name(&client.Name);
                    if (check == Success)
                    {
                        break;
                    }
                    else
                    {
                        printf("--------------------------------------------------\n");
                        printf("Re-Enter your First & Middle Name!\n");
                    }
                }

                printf("--------------------------------------------------\n");
                printf("Please, Enter your password\n");
                while (1)
                {
                    scanf("%d", &client.password);
                    check = check_password(client.password, 0);
                    if (check == Success)
                    {
                        break;
                    }
                    else
                    {
                        // printf("--------------------------------------------------\n");
                        // printf("passowrd should be 4 digits only\n");
                        printf("Re-Enter your password\n");
                    }
                }

                for (int k = 0; client.Name[k] != '\0'; k++)
                {
                    current_node->no_customers[i].Name[k] = client.Name[k];

                    printf("%c", current_node->no_customers[i].Name[k]);
                }
                printf("\n");
                current_node->no_customers[i].password = client.password;
                printf("%d\n", current_node->no_customers[i].password);
                printf("You Enrolled In Successfully\n");
                printf("--------------------------------------------------\n");
                Enrolled = Enrolled_Successfully;
                return client;
                // break;
            }
        }
        else
        {
            // Still current_node in head
            current_node = current_node->next;
            printf("%d\n", current_node->branch_id);
            while (current_node->next != NULL)
            {
                i = 0;
                if (branch == current_node->branch_id)
                {
                    while ((current_node->no_customers[i].password != 0) && (i < Customers_Limit))
                        i++;
                    if (i >= Customers_Limit)
                    {
                        printf("--------------------------------------------------\n");
                        printf("This Branch is Currently unavailable to enroll in due to high load\n");
                        printf("Select Any Of The Other Available Branches\n");
                        printf("--------------------------------------------------\n");
                        customer_limit_status = customer_limit_exceeded;
                        Enrolled = Enrolled_Failed;
                        break;
                    }
                    else
                    {
                        printf("--------------------------------------------------\n");
                        printf("Please, Enter your 1st and 2nd Name in English\n");
                        printf("--------------------------------------------------\n");
                        while (1)
                        {
                            scanf("\n");
                            scanf("%[^\n]%*c", client.Name);
                            check = check_name(&client.Name);
                            if (check == Success)
                            {
                                break;
                            }
                            else
                            {
                                printf("--------------------------------------------------\n");
                                printf("Re-Enter your First & Middle Name!\n");
                            }
                        }

                        printf("--------------------------------------------------\n");
                        printf("Please, Enter your password\n");
                        while (1)
                        {
                            scanf("%d", &client.password);
                            check = check_password(client.password, 0);
                            if (check == Success)
                            {
                                break;
                            }
                            else
                            {
                                printf("--------------------------------------------------\n");
                                // printf("passowrd should be 4 digits only\n");
                                printf("Re-Enter your password\n");
                            }
                        }
                        for (int k = 0; client.Name[k] != '\0'; k++)
                        {
                            current_node->no_customers[i].Name[k] = client.Name[k];

                            printf("%c", current_node->no_customers[i].Name[k]);
                        }
                        printf("\n");
                        current_node->no_customers[i].password = client.password;
                        printf("%d\n", current_node->no_customers[i].password);
                        printf("You Enrolled In Successfully\n");
                        printf("--------------------------------------------------\n");
                        Enrolled = Enrolled_Successfully;
                        return client;
                        // break;
                    }
                }
                else
                {
                    current_node = current_node->next;
                    // printf("%d", current_node->branch_id);
                }
            }
            if (Enrolled == Enrolled_Successfully)
            {
                break;
            }
            i = 0;
            printf("%d", current_node->branch_id);
            if (current_node->next == NULL)
            {
                if (branch == current_node->branch_id)
                {
                    while ((current_node->no_customers[i].password != 0) && (i < Customers_Limit))
                    {
                        i++;
                    }

                    if (i >= Customers_Limit)
                    {
                        printf("--------------------------------------------------\n");
                        printf("This Branch is Currently unavailable to enroll in due to high load\n");
                        printf("Select Any Of The Other Available Branches\n");
                        printf("--------------------------------------------------\n");
                        customer_limit_status = customer_limit_exceeded;
                    }
                    else
                    {

                        printf("--------------------------------------------------\n");
                        printf("Please, Enter your 1st and 2nd Name in English\n");
                        printf("--------------------------------------------------\n");
                        while (1)
                        {
                            scanf("\n");
                            scanf("%[^\n]%*c", client.Name);
                            check = check_name(&client.Name);
                            if (check == Success)
                            {
                                break;
                            }
                            else
                            {
                                printf("--------------------------------------------------\n");
                                printf("Re-Enter your First & Middle Name!\n");
                            }
                        }

                        printf("--------------------------------------------------\n");
                        printf("Please, Enter your password\n");
                        while (1)
                        {
                            scanf("%d", &client.password);
                            check = check_password(client.password, 0);
                            if (check == Success)
                            {
                                break;
                            }
                            else
                            {
                                printf("--------------------------------------------------\n");
                                printf("passowrd should be 4 digits only\n");
                                printf("Re-Enter your password\n");
                            }
                        }
                        for (int k = 0; client.Name[k] != '\0'; k++)
                        {
                            current_node->no_customers[i].Name[k] = client.Name[k];

                            printf("%c", current_node->no_customers[i].Name[k]);
                        }
                        printf("\n");
                        current_node->no_customers[i].password = client.password;
                        printf("%d\n", current_node->no_customers[i].password);
                        printf("You Enrolled In Successfully\n");
                        printf("--------------------------------------------------\n");
                        Enrolled = Enrolled_Successfully;
                        return client;
                        // break;
                    }
                }
                else
                {
                    printf("The Branch entered isn't existing!\n");
                    printf("--------------------------------------------------\n");
                    printf("Re-Enter Branch id you are in!\n");
                    branch_availability = branch_not_found;
                }
            }
        }
    }
}

int display_customer_info(int branch_id, struct customer cus, int login_status)
{
    int j, i, flag = 0;
    if (head == NULL)
    {
        // Nothing
    }
    else
    {
        current_node = head;
        if (branch_id == current_node->branch_id)
        {
            // Checking Name of Customer
            for (int j = 0; current_node->no_customers[j].password != 0; j++)
            {
                flag = 0;
                for (int i = 0; cus.Name[i] != '\0'; i++)
                {
                    if (cus.Name[i] != current_node->no_customers[0].Name[i])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag != 1)
                    break;
            }
            if ((flag == 1) && (login_status == Login))
            {
                printf("Name entered didn't match any other Names!\n");
                printf("Re-Enter your Name\n");
                return Fail;
            }
            else
            {
                // Entered the data Successfully
                printf("Name: ");
                for (int i = 0; cus.Name[i] != '\0'; i++)
                    printf("%c", cus.Name[i]);
                printf("\n");
                // Finish Stack implementation and use functions
                printf("Money Balance: %d\n",cus.money_balance);
                return Success;
            }
        }
        else
        {
            while (current_node->next != NULL)
            {
                if (branch_id == current_node->branch_id)
                {
                    // Checking Name of Customer
                    for (int j = 0; current_node->no_customers[j].password != 0; j++)
                    {
                        flag = 0;
                        for (int i = 0; cus.Name[i] != '\0'; i++)
                        {
                            if (cus.Name[i] != current_node->no_customers[0].Name[i])
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag != 1)
                            break;
                    }
                    if ((flag == 1) && (login_status == Login))
                    {
                        printf("Name entered didn't match any other Names!\n");
                        printf("Re-Enter your Name\n");
                        return Fail;
                    }
                    else
                    {
                        // Entered the data Successfully
                        printf("Name: ");
                        for (int i = 0; cus.Name[i] != '\0'; i++)
                            printf("%c", cus.Name[i]);
                        printf("\n");
                        // Finish Stack implementation and use functions
                        printf("Money Balance: %d\n",cus.money_balance);
                        return Success;
                    }
                }
                else
                    current_node = current_node->next;
            }
            if (current_node->next == NULL)
            {
                if (branch_id == current_node->branch_id)
                {
                    // Checking Name of Customer
                    for (int j = 0; current_node->no_customers[j].password != 0; j++)
                    {
                        flag = 0;
                        for (int i = 0; cus.Name[i] != '\0'; i++)
                        {
                            if (cus.Name[i] != current_node->no_customers[0].Name[i])
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag != 1)
                            break;
                    }
                    if ((flag == 1) && (login_status == Login))
                    {
                        printf("Name entered didn't match any other Names!\n");
                        printf("Re-Enter your Name\n");
                        return Fail;
                    }
                    else
                    {
                        // Entered the data Successfully
                        printf("Name: ");
                        for (int i = 0; cus.Name[i] != '\0'; i++)
                            printf("%c", cus.Name[i]);
                        printf("\n");
                        // Finish Stack implementation and use functions
                        printf("Money Balance: %d\n",cus.money_balance);
                        return Success;
                    }
                }
                else
                {
                    return Fail;
                }
            }
        }
    }
}

int check_password(int password, int login_status)
{
    char a[Password_Limit], length, i, k, current_num;
    int frequency = 0, flag = 0;
    int frequency_arr[10] = {0};
    itoa(password, a, 10); // converted to array
    length = strlen(a);
    if (length != Password_Limit)
    {
        printf("--------------------------------------------------\n");
        printf("Incorrect Password\n");
        printf("Password should be 6 digits only!\n");
        // printf("--------------------------------------------------\n");
        return Fail;
    }
    else
    {
        for (i = 0; i < Password_Limit - 1; i++)
        {
            current_num = a[i] - '0';
            printf("cuurent is %d\n", current_num);
            frequency_arr[current_num]++;
            printf("frequency is %d\n", frequency_arr[current_num]);
            if (frequency_arr[current_num] == 3)
            {
                printf("gg\n");
                flag = 1;
                break;
            }
            if ((a[i] == a[i - 1]) && (i != 0))
                break;
        }
        if (flag == 1)
        {
            printf("Password shouldn't include 3 same numbers\n");
            return Fail;
        }
        else if (a[i] == a[i - 1])
        {
            printf("Password shouldn't include 2 consective numbers\n");
            return Fail;
        }
        else
        {
            printf("--------------------------------------------------\n");
            printf("Accepted Password\n");
            printf("--------------------------------------------------\n");
            return Success;
        }
    }
}

int check_name(char *ptr_to_name)
{
    int x = 0, y = 1;
    if ((ptr_to_name[0] >= 65) && (ptr_to_name[0] <= 90))
    {
        for (x = 0; ptr_to_name[x] != '\0'; x++)
        {
            if (ptr_to_name[x] == ' ' && ptr_to_name[x + 1] != ' ')
            {
                y++;
            }
        }
        if (y >= 3) // 2 words
        {
            printf("--------------------------------------------------\n");
            printf("You typed incorrect number of names!\n");
            printf("--------------------------------------------------\n");
            return Fail;
        }
        else
        {

            printf("--------------------------------------------------\n");
            printf("Name is accepted\n");
            printf("--------------------------------------------------\n");
            return Success;
        }
    }
    else
    {
        if ((ptr_to_name[0] > 90) && (ptr_to_name[0] <= 122)) // lower case
        {
            printf("--------------------------------------------------\n");
            printf("First letter should be UpperCased!\n");
            // printf("Re-Enter your Name again!\n");
            // printf("--------------------------------------------------\n");
        }
        else
        {
            printf("--------------------------------------------------\n");
            printf("Symbols and non-characters are not allowed!\n");
            printf("Re-Enter you Name without Symbols.\n");
            printf("--------------------------------------------------\n");
        }
    }
}

int get_branchs_number()
{
    int i = 1;
    temp = head;
    if (head == NULL)
        return i - 1; // Return 0
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        return i;
    }
}

int entry_number_of_branches()
{
    int no_of_branches, user_data, user_id, i = 0;
    while (1)
    {

        printf("Enter How many Branches Needed in List!\n");
        scanf("%d", &no_of_branches);
        if (no_of_branches <= 0)
        {
            printf("Failed Process, You Entered -ve number Or Zero\n");
            printf("Please, Enter a +ve integer number....\n");
            printf("-------------------------------------------\n");
        }
        else
            break;
    }
    printf("-------------------------------------------\n");

    current_node = create_Bank_Branches(no_of_branches);
    // while (i < no_of_elements)
    // {
    //     printf("Enter Data of The Node!\n");
    //     scanf("%d", &user_data);
    //     printf("-------------------------------------------\n");
    //     printf("Enter ID of The Given Data!\n");
    //     scanf("%d", &user_id);
    //     printf("-------------------------------------------\n");
    //     entry_data.data = user_data;
    //     entry_data.id = user_id;
    //     current_node = create_DLL(entry_data);
    //     printf("User_data is %d with ID Of %d\n", current_node->data, current_node->id);
    //     printf("-------------------------------------------\n");
    //     i++;
    // }
    return no_of_branches;
}

// int User_Choice(int choice)
// {
//     int list_length;
//     switch (choice)
//     {
//     case Choice_Create_SLL:
//         entry_number_of_branches();
//         break;
//     case Choice_Insert_Node:
//         insert_branch();
//         break;
//     case Choice_Delete_Node:
//         delete_branch();
//         break;
//     case Choice_Search_4_Data:
//         search_4_data();
//         break;
//     case Choice_Read_Data_By_ID:
//         read_or_change_data_by_id(Choice_Read);
//         break;
//     case Choice_Read_Data_By_pos:
//         read_or_change_data_by_pos(Choice_Read);
//         break;
//     case Choice_Change_Data_By_ID:
//         read_or_change_data_by_id(Choice_Change);
//         break;
//     case Choice_Change_Data_By_pos:
//         read_or_change_data_by_pos(Choice_Change);
//         break;
//     case Choice_Get_List_Length:
//         list_length = get_branchs_number();
//         printf("List Size is %d\n",list_length);
//         break;
//     case Choice_Dislpay_List:
//         display_bank_branches();
//         break;
//     case Exit_Code_Choice:
//         return Exit_Code_Choice;
//         break;
//     default:
//         return 0;
//     }
// // }