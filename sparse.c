#include<stdio.h>
void trans();
struct sparse
{
 int row;
 int col;
 int val;
};
  int a[10][10],i,j,k,r,c,count=0;
  struct sparse s1[10],s2[10];
int main()
{ 
  
  printf("enter the size of row");
  scanf("%d",&r);
  printf("Enter the size of coloumn");
  scanf("%d",&c);
  printf("enter %d elements",(r*c));
for(i=0;i<r;i++)                              //taking elements of sparse matrix
{
     for(j=0;j<c;j++)
  {
    scanf("%d",&a[i][j]);
  }
}
    
 for(i=0;i<r;i++)                
  {
   for(j=0;j<c;j++)
     {
       if(a[i][j]!=0)
       count++;
       printf("\t %d ",a[i][j]);
 }
  printf("\n");
}
  s1[0].row=r;
  s1[0].col=c;
  s1[0].val=count;
  k=0;                                //printing triples
printf("\n triples of matrix are");
for(i=0;i<r;i++)
  { 
   for(j=0;j<c;j++)
    {
      if(a[i][j]!=0)
        {
          k++;
          s1[k].row=i;
          s1[k].col=j;
          s1[k].val=a[i][j];
        }
    }
  }
for(i=0;i<=count;i++)
{ 
 printf("\n %d \t %d \t\t %d",s1[i].row,s1[i].col,s1[i].val);
}
  printf(" \n Transpose=\n");
  trans();
  return 0;
}
//fuction
void trans()
{ 
 
  s2[0].row=r;
  s2[0].col=c;
  s2[0].val=count;
  k=0;
for(i=0;i<=s1[0].col;i++)
  {
     for(j=1;j<=count;j++)
    {
      if(s1[j].col==i)
        { 
                  k++;
          s2[k].row=s1[j].col;
                  s2[k].col=s1[j].row;
                  s2[k].val=s1[j].val;
                }
         }
  }
  //printf("\n transpose of s1=");
  for(i=0;i<=count;i++)
    {
         printf("\n %d \t %d \t %d",s2[i].row,s2[i].col,s2[i].val);
    }


}
