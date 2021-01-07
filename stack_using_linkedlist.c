    #include <stdio.h>  
    #include <stdlib.h>  
    void push();  
    void pop();  
    void display();  
    struct node   
    {  
    int val;  
    struct node *next;  
    };  
    struct node *top;  
      
    void main ()  
    {  
        int choice=0;     
        printf("Stack operations using linked list");  
 
        while(choice != 4)  
        {  
 
            printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
            printf("\nEnter your choice: ");        
            scanf("%d",&choice);  
            switch(choice)  
            {  
                case 1:  
                {   
                    push();  
                    break;  
                }  
                case 2:  
                {  
                    pop();  
                    break;  
                }  
                case 3:  
                {  
                    display();  
                    break;  
                }  
                case 4:   
                {  
                    printf("Exiting....");  
                    break;   
                }  
                default:  
                {  
                    printf("Please Enter valid choice ");  
                }   
        };  
    }  
    }  
    void push ()  
    {  
        int val;  
        struct node *ptr = (struct node*)malloc(sizeof(struct node));   
        if(ptr == NULL)  
        {  
            printf("Memory not allocated\n");   
        }  
        else   
        {  
            printf("Enter the value: ");  
            scanf("%d",&val);  
            if(top==NULL)  
            {         
                ptr->val = val;  
                ptr -> next = NULL;  
                top=ptr;  
            }   
            else   
            {  
                ptr->val = val;  
                ptr->next = top;  
                top=ptr;  
                   
            }  
            printf("Item pushed\n");  
              
        }  
    }  
      
    void pop()  
    {  
        int item;  
        struct node *ptr;  
        if (top == NULL)  
        {  
            printf("Stack is empty\n");  
        }  
        else  
        {  
            
            item = top->val;  
            ptr = top;  
            top = top->next;
            printf("%d is popped\n",ptr->val);  
            free(ptr);  
             
              
        }  
    }  
    void display()  
    {  
        int i;  
        struct node *ptr;  
        ptr=top;  
        if(ptr == NULL)  
        {  
            printf("Stack is empty\n");  
        }  
        else  
        {  
            printf("Stack Elements are: ");  
            while(ptr!=NULL)  
            {  
                printf("%d  ",ptr->val);  
                ptr = ptr->next;  
            }  
        }  
printf("\n");
    }  
