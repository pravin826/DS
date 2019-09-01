#include<stdio.h>
void push(int value);
void pop();
int stack[5];
int top=-1;
main()
{
 int choice;
 do
 {
  printf("\n1-Push\n2-Pop\n3-Exit\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
   {
   int value;
   printf("\nEnter value to push:");
   scanf("%d",&value);
   push(value);
   break;
   }
   case 2:
   {
   pop();
   break; 
   }
   case 3:
   {
    break;
   }
   default:
   {
    printf("\nInvalid Choice");
    break;
   }
  }
 }while(choice!=3);
}
void push(int value)
{
 if(top==4)
 {
  printf("Failed!Stack is full.");
 }
 else
 {
 top++;
 stack[top]=value;
 printf("\n%d is pushed",value);
 }
}
void pop()
{
 if(top==-1)
 {
 printf("\nFailed! Stack is Empty.");
 }
 else
 {
 int x=stack[top];
 top--;
 printf("\n%d is poped!",x);
 }
}
