#include<stdio.h>
#include<stdlib.h>
int c=0;
void EnQueue(int value);
void DeQueue();
void count();
void Display();
struct Node
{
    int data;
    struct Node *next;
}*rear=NULL,*front=NULL;
int main()
{
    int choice,value;
    do
    {
        printf("\n\t\t\t\t\t\t**Queue using Linked List**\n\t\t\t\t\t\t1-Enqueue\n\t\t\t\t\t\t2-Dequeue\n\t\t\t\t\t\t3-Count\n\t\t\t\t\t\t4-Display\n\t\t\t\t\t\t5-Exit\n");
        printf("\n\t\t\t\t\t\tEnter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter value to enqueue:");
            scanf("%d",&value);
            EnQueue(value);
            break;
        case 2:
            DeQueue();
            break;
        case 3:
            count();
            break;
        case 4:
            Display();
            break;
        case 5:
            break;
        default:
            printf("\nInvalid Choice");
            break;
        }
    }while(choice!=5);
}
void EnQueue(int value)
{
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->next=NULL;
    temp->data=value;
    if((rear==NULL)&&(front==NULL))
    {
        front=temp;
        rear=temp;
    }
    else
    {
        rear->next =temp;
        rear=temp;
    }
    c++;
    printf("Given Number %d EnQueued.",value);
}
void DeQueue()
{
    struct Node *temp;
    if(front==NULL)
    {
        printf("Queue is Empty!");
    }
    else
    {
        temp=front;
        front=front->next;
        printf("Number %d DeQueued",temp->data);
        free(temp);
        c--;
    }
}
void Display()
{
    struct Node *temp=front;
    while(temp!=rear)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
void count()
{
    printf("Queue have %d elements.",c);
}
