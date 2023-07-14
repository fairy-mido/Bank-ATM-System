#ifndef STACK_H_
#define STACK_H_

#define Choice_Dynamic 2
#define Choice_Static  1 

#define Stack_Limit    3 

#define Push    1
#define Pop     2
#define Display 3
#define Peek    4

void Deposit(int value,int choice_allocation);
int Withdraw(int choice_allocation);
void display(int choice_allocation);
void peek(int choice_allocation);
long long get_balance();

typedef struct stack
{
    int data;
    struct stack* next;
    struct stack* prev;
} Dyn_Stack;

#endif