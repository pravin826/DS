#include<stdio.h>
#include<stdlib.h>
void insertatbeg(void);
void insertatend(void);
void insertatpos(void);
void deleteatpos(void);
void display(void);
void search(void);


struct node
{
  int data;
  struct node* next;
};

struct node* root = NULL;
 
int main()
{
   int choice;
   while(1)
   {
         printf("ENTER 1 TO INSERT AT BEGIN\n");
         printf("ENTER 2 TO INSERT AT END\n");
         printf("ENTER 3 TO INSERT AT SPECIFIC POSITION\n");
         printf("ENTER 4 TO DELETE AT SPECIFIC POSITION\n");
         printf("ENTER 5 TO DISPLAY\n");
         printf("ENTER 6 TO SEARCH\n");
         printf("ENTER 7 TO EXIT\n");
         printf("\n");
         printf(":: ENTER YOUR CHOICE ::\n");
         scanf("%d",&choice);
          
         switch(choice)
         {
             case 1: insertatbeg();
             break;
             case 2: insertatend();
             break;
             case 3: insertatpos();
             break;
             case 4: deleteatpos();
             break;
             case 5: display();
             break;
             case 6: search();
             break;
             case 7: exit(0);
             break;
             default: printf("INVALID CHOICE\n");
         }
    }
}


void insertatbeg()
{
      struct node* temp;
      temp = (struct node*)malloc(sizeof(struct node));
      
      if(temp == NULL)
      {
               printf("MEMORY IS NOT AVAILAIBLE\n");
      }
    else
      {
          printf("ENTER DATA IN THE CREATED NODE:: \n");
          scanf("%d",&temp->data);
          temp->next = NULL;
          
          if(root == NULL)
          {
               root = temp;
          }
          else
          {
               temp->next = root;
               root = temp;
          }
      }
}


void insertatend()
{
       struct node* temp;
       temp = (struct node*)malloc(sizeof(struct node));
     
       if(temp == NULL)
       {
               printf("MEMORY IS NOT AVAILAIBLE\n");
       }
       else
       {
           printf("ENTER DATA IN THE CREATED NODE:: \n");
           scanf("%d",&temp->data);
           temp->next = NULL;
           
           if(root == NULL)
           {
                root = temp ;
           }
           else
           {
               struct node* p;
               p = root;
               while(p->next != NULL)
               {
                    p = p->next;
               }
               p->next = temp;
           }
     }
}

void insertatpos()
{
       int counter = 0;
       int position;
       struct node* temp;
       temp = (struct node*)malloc(sizeof(struct node));
       
       if(temp == NULL)
       {
             printf("MEMORY IS FULL");
       }
       else
       {
             if(root == NULL)
             {
                  root = temp;
             }
             else
             {
             struct node *p , *q;
             p = root;
             printf("ENTER DATA IN THE CREATED NODE:: \n"); 
             scanf("%d",&temp->data);
             temp->next = NULL;
            
             printf("ENTER ENSERT POSITION:: \n");
             scanf("%d",&position);
             if(position == 0)
             {
                 temp->next = root;
                 root = temp;
             }
             else
             {
             while(counter!=position)
             {    
                  q = p;
                  p = p->next;
                  counter++;
             }
             temp->next = q->next;
             q->next = temp;
             }
             }
       }
}
      
           
void display()
{
     struct node* p;
     p = root;
     while(p!=NULL)
     {      
           printf("%d -> ",p->data);
           p = p->next;
     }
}

void search()
{
      struct node *p;
      p = root;
      int element,position,flag;
      flag = -1;
      position = 0;
      printf("ENTER ELEMENT TO BE SEARCHED\n");
      scanf("%d",&element);
      while(p!= NULL)
      {
           position++; 
           if(p->data == element)
            {    
                  flag = 0;
                  printf("ENTEMENT : %d , FOUND AT POSITOIN: %d",element,position);
            }
           p = p->next;
      }
      if(flag == -1)
      {
            printf("ELEMENT NOT FOUND\n");
      }

      
}



void deleteatpos()
{
    struct node *p , *q;
    p = root; 
    int position , counter;
    counter = 0;
    printf("ENTER THE POSITION OF NODE TO BE DELETED\n");
    scanf("%d",&position);
    if(position == 0)
    {
        root = p->next;
        p->next = NULL;
        free(p);
    }
    else
    {
    while(counter != position)
    { 
       q = p;
       p = p->next;
       counter++;
    }
     q->next = p->next;
     p->next = NULL;
     free(p);
    }
}





