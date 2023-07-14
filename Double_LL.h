#ifndef DOUBLE_LL_H_
#define DOUBLE_LL_H_

// Code Defintions
#define First_Node_Created      1

// Used Along The Code To trace whether a feature working or not
#define Success                 1
#define Fail                    0

// Used in Read & Chnage Functions
#define Choice_Change           1     
#define Choice_Read             2

// Definitions of User Choice
#define Choice_Create_SLL           1
#define Choice_Insert_Node          2
#define Choice_Delete_Node          3
#define Choice_Search_4_Data        4
#define Choice_Read_Data_By_ID      5
#define Choice_Read_Data_By_pos     6
#define Choice_Change_Data_By_ID    7
#define Choice_Change_Data_By_pos   8 
#define Choice_Get_List_Length      9
#define Choice_Dislpay_List         10
#define Exit_Code_Choice            11
#define something 0

#define Choice_Change 1
#define Choice_Read   2
// End of Code Defintions 

// Bank Specifications
#define Customers_Limit    1
#define Name_Limit         100

// Password Limit
#define Password_Limit 6

// Status of Enrollment
#define Register 0
#define Login    1

// Branch Availability
#define branch_found   0
#define branch_not_found 1

// Enrollment
#define Enrolled_Successfully 0
#define Enrolled_Failed       1

// Customer Limit Status
#define customer_limit_exceeded 1


struct bank_branches *create_Bank_Branches(int no_of_branches);
void display_bank_branches();
int insert_branch();
int delete_branch();
int search_4_data();
void read_or_change_info_by_pass(int choice);
void read_or_change_data_by_pos(int choice);
struct customer create_customer();
int check_password(int password, int login_status);
int check_name(char *ptr_to_name);
int display_customer_info(int branch_id, struct customer cus, int login_status);
int get_branchs_number();
int entry_number_of_branches();
int User_Choice(int choice);

typedef struct customer
{
    char Name[Name_Limit];
    int password;
    int money_balance;
}customer_info;

// customer_info no_customers[Customers_Limit];

typedef struct bank_branches{
    
    int branch_id;
    struct customer no_customers[Customers_Limit];
    struct node* next;
    struct node* prev;
}bank_branch;

#endif