#include<stdio.h>

#include<stdlib.h>
 struct node 
{
int data;
struct node *next;
struct node *prev;
} *start = NULL, *ptr, *ne, *temp, *temp2, *temp1 ;
 
int main () 
{
  int ch;
  void insert_beg ();
  int count();
  void insert_end ();
  int insert_pos ();
  void display ();
  void search();
  void delete_beg ();
  void delete_end ();
  int delete_pos ();
  
while (1)
{
printf ("\n\n---- Doubly Linked List(DLL) Menu ----");
printf ("\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit\n\n");
printf ("Enter your choice(1-5):");
scanf ("%d", &ch);
switch (ch)
{
	case 1 :
printf ("\n---- Insert Menu ----");
printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.count\n5.Exit");  
printf ("\n\nEnter your choice(1-4):");
scanf ("%d", &ch);
switch (ch)
{
case 1:  	    
      	insert_beg ();
  		      break;
case 2:	      insert_end ();
		     break;
case 3:	      insert_pos ();
		      break;
case 4:	      exit (0);
default:	      printf ("Wrong Choice!!");
}
break;
case 2:	  display ();
	   break;
case 3:	  printf ("\n---- Delete Menu ----");
printf("\n1.Delete from beginning\n2.Delete from end\n3.Delete from specified  position\n4.Exit");
printf ("\n\nEnter your choice(1-4):");
scanf ("%d", &ch);
switch (ch)
	{
	case 1:	      delete_beg ();
	      	       break;
	case 2:	      delete_end ();
	      	       break;
case 3:	      delete_pos ();
	      	       break;

case 4:      count();
             break;
	     
case 5:	      exit (0);
default:	      printf ("Wrong Choice!!");
	 }
	 break;
case 4:	      search();
	              break;
	 
case 5:
	  exit (0);
default:
	  printf ("Wrong Choice!!");
}}  
return 0;}



void insert_beg ()  
{  
      
   int num;  
   ne = (struct node *)malloc(sizeof(struct node));  
   
    printf("\nEnter Item value");  
    scanf("%d",&num);  
    ne->data=num;  
   if(start==NULL)  
   {  
       ne->next = NULL;  
       ne->prev=NULL;  
         
       start=ne;  
   }  
   else   
   {  
         
       ne->prev=NULL;  
       ne->next = start;  
       start->prev=ne;  
       start=ne;  
   }  
   printf("\nNode inserted\n");  
  
     
}  
void insert_end()  
{  
     
   int num;  
   ne = (struct node *) malloc(sizeof(struct node));  
   printf("\nEnter value");  
       scanf("%d",&num);  
        ne->data=num;  
       if(start == NULL)  
       {  
           ne->next = NULL;  
           ne->prev = NULL;  
           start = ptr;  
       }  
       else  
       {  
          temp = start;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ne;  
          ne ->prev=temp;  
          ne->next = NULL;  
          }  
             
         
     printf("\nnode inserted\n");  
    }  
 int insert_pos()  
{  
     
   int num,pos,i;  
   ne = (struct node *)malloc(sizeof(struct node));  
    
       temp=start;  
       printf("Enter the location");  
       scanf("%d",&pos);  
       for(i=0;i<pos;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("\n There are less than %d elements", pos);  
               return 0;  
           }  
       }  
       printf("Enter value");  
       scanf("%d",&num);  
       ne->data = num;  
       ne->next = temp->next;  
       ne -> prev = temp;  
       temp->next = ne;  
       temp->next->prev=ne;  
       printf("\nnode inserted\n");  
     
}  
void delete_beg()  
{  
      
    if(start == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(start->next == NULL)  
    {  
        start = NULL;   
        free(start);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        temp = start;  
        start = start -> next;  
        start -> prev = NULL;  
        free(temp);  
        printf("\nnode deleted\n");  
    }  
  
}  
void delete_end()  
{  
      
    if(start == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(start->next == NULL)  
    {  
        start = NULL;   
        free(start);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        temp = start;   
        while(temp->next != NULL)  
        {  
            temp = temp -> next;   
        }  
        temp -> prev -> next = NULL;   
        free(temp);  
        printf("\nnode deleted\n");  
    }  
}  
int delete_pos()  
{  
     
    int val;  
    printf("\n Enter the data after which the node is to be deleted : ");  
    scanf("%d", &val);  
    temp2 = start;  
    while(temp2 -> data != val)  
    temp2 = temp2 -> next;  
    if(temp2 -> next == NULL)  
    {  
        printf("\nCan't delete\n");  
    }  
    else if(temp2 -> next -> next == NULL)  
    {  
        temp2 ->next = NULL;  
    }  
    else  
    {   
        temp1 = temp2 -> next;  
        temp2 -> next = temp1 -> next;  
        temp1 -> next -> prev = temp2;  
        free(temp1);  
        printf("\nnode deleted\n");  
    }     
}  
void display()  
{  
      
    printf("\n printing values...\n");  
    ne = start;  
    while(ne != NULL)  
    {  
        printf("%d\n",ne->data);  
        ne=ne->next;  
    }  
}   

void search()  
{  
     
    int num,i=0,flag;  
    ne = start;   
    if(ne == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&num);  
        while (ne!=NULL)  
        {  
            if(ne->data == num)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ne = ne -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}

int count()
{
	int co=0;
	temp=start;
	while(temp != NULL)
	{
		temp=temp->next;
		co++;
	}
}

