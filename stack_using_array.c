#include <stdio.h>
#define MAXSIZE 10
int top,n;
     int stk[MAXSIZE];
void push(void);
int  pop(void);
void display(void);
void main ()
{
    int choice;
    top = -1;
printf("Enter The size of stack");
scanf("%d",&n);
    printf ("STACK OPERATION\n");
    while (1)
    {
        printf ("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        printf ("Enter your choice : ");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        }
        fflush (stdin);
           }
}
void push ()
{
    int num;
    if (top == (n - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        printf ("Enter the element to be pushed : ");
        scanf ("%d", &num);
        top = top + 1;
        stk[top] = num;
    }
    return;
}
int pop ()
{
    int num;
    if (top == - 1)
    {
        printf ("Stack is Empty\n");
        return (top);
    }
    else
    {
        num = stk[top];
        printf ("poped element is = %d\n", stk[top]);
        top = top - 1;
    }
    return(num);
}

void display ()
{
    int i;
    if (top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The Element of the stack is :  ");
        for (i = top; i >= 0; i--)
        {
            printf ("%d  ", stk[i]);
        }
    }
    printf ("\n");
}
