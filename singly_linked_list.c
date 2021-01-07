#include<stdio.h>

#include<stdlib.h>
 struct node 
{
int data;
struct node *next;
} *start = NULL, *ptr, *ne;
typedef struct node n;
    n* create_node();
 
int main () 
{
  int ch;
  void insert_beg ();
  void insert_end ();
  int insert_pos ();
  void display ();
  void delete_beg ();
  void delete_end ();
  int delete_pos ();
  void search();
  
while (1)
{
printf ("\n\n---- Singly Linked List(SLL) Menu ----");
printf ("\n1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit\n\n");
printf ("Enter your choice(1-4):");
scanf ("%d", &ch);
switch (ch)
{
	case 1 :
printf ("\n---- Insert Menu ----");
printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Exit");  
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
case 4:	      exit (0);
default:	      printf ("Wrong Choice!!");
	 }
	 break;
	 case 4:  search();
break;	 
case 5:
	  exit (0);
default:
	  printf ("Wrong Choice!!");
}}  
return 0;}

 n* create_node()
    {

        int num;
        printf("Enter Data");
        scanf("%d",&num);
        ne = (n *)malloc(sizeof(n));
        ne->data = num;
        ne->next = NULL;
        return ne;
    }

void insert_beg () 
{
ne=create_node();
 if (start == NULL)		
    {
 	ne->next = NULL;
      	start = ne;
    }
  else
   {
  	ne->next = start;
      	start = ne;
    }
}

void insert_end () 
{
 ne=create_node();
  if (start == NULL)		
    {
 	start = ne;
    }
  else
    {
  	ptr = start;
      	while (ptr->next != NULL)
	ptr = ptr->next;
      	ptr->next = ne;
    }
}

int insert_pos () 
{
int pos, i;
if (start == NULL)
     {
      printf ("List is empty!!");
      return 0;
      }
  printf ("Enter position to insert:");
 scanf ("%d", &pos);
 
  ne=create_node();
 
ptr = start;
for (i = 1; i < pos - 1; i++)
{
  if (ptr->next == NULL)
{
printf ("There are less elements!!");
	  	return 0;
	}
 ptr = ptr->next;
 }
 ne->next = ptr->next;
  ptr->next = ne;
  return 0;
}

 
void display () 
{
if (start == NULL)
    {
printf ("List is empty!!");
    }
  else
    {
  	ptr = start;
      	printf ("The linked list is:\n");
      	while (ptr != NULL)
	{
printf ("%d->", ptr->data);
	  	ptr = ptr->next;
	}
    }
}


 void delete_beg () 
{
  if (start == NULL)
      {
  printf ("The list is empty!!");
       }
  else
      {
  	ptr = start;
      	start = start->next;
      	printf ("Deleted element is %d", ptr->data);
      	free (ptr);
}
}



 
void delete_end () 
{
  if (start == NULL)
        {
    	printf ("The list is empty!!");
         }
  else
      {
  	ptr = start;
      	while (ptr->next->next != NULL)
	ptr = ptr->next;
      	ne = ptr->next;
      	ptr->next = NULL;
      	printf ("Deleted element is %d", ne->data);
      	free (ne);
    }
}


 
int delete_pos () 
{
  int pos, i;
  if (start == NULL)
      {
  	printf ("List is empty!!");
      	return 0;
       }
printf ("Enter position to delete:");
scanf ("%d", &pos);
 ptr = start;
 for (i = 1; i < pos - 1; i++)
     {
 	if (ptr->next == NULL)
		{
			printf ("There are less elements!!");
	  		return 0;
		}
      ptr = ptr->next;
    }
ne = ptr->next;
ptr->next = ne->next;
printf ("Deleted element is %d", ne->data);
free (ne);
return 0;
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


