//program for binary search tree and all opertions on it
#include<stdio.h>

#include<stdlib.h>

struct tree
{
	struct tree *left;
	int data;
	struct tree *right;
};

struct tree *root;

struct tree * create();

void search(struct tree *,int item);

void inorder(struct tree*);
void preorder(struct tree*);
void postorder(struct tree*);

void del(struct tree *, int item);

void main()
{
	int ch;
	int s;
	root=NULL;

	while(1)
	{
		printf("\n\n 1: Create");
		printf("\n 2: Inorder");
		printf("\n 3: Preorder");
		printf("\n 4: Postorder");
		printf("\n 5: Search");
		printf("\n 6: Delete");
		printf("\n 7: Exit");
		printf("\n Enter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: root=create();
				break;

			case 2: if(root==NULL)
				{
					printf("\n Tree is empty...");
				}
				else
				{
					printf("\n Inorder :");
					inorder(root);
				}
				break;

			case 3: if(root==NULL)
				{
					printf("\n Tree is empty...");
				}
				else
				{
					printf("\n Preorder :");
					preorder(root);
				}
				break;

			case 4: if(root==NULL)
				{
					printf("\n Tree is empty...");
				}
				else
				{
					printf("\n Postorder :");
					postorder(root);
				}
				break;

			case 5: if(root==NULL)
				{
					printf("\n Tree is empty...");
				}
				else
				{
					printf("\n Enter element which node you to search :");
					scanf("%d",&s);
					search(root,s);
				}
				break;

			case 6: if(root==NULL)
				{
					printf("\n Tree is empty...");
				}
				else
				{
					printf("\n Enter element which node you to delete :");
					scanf("%d",&s);
					del(root,s);
				}
				break;
			case 7: exit(0);

			default:printf("\n Wrong choice");
		}
	}
}

struct tree* create()
{
	struct tree *p;
	int nn,r;
	int ans;
	//create root node first
	root = (struct tree *)malloc(sizeof(struct tree));
	printf("\n Enter value of root :");
	scanf("%d",&r);
	root->left=NULL;
	root->data=r;
	root->right=NULL;
	//ask for insertion of new element
	while(ans != 0)
	{
		p=root;
		printf("\n\n Enter value of new node to be inserted: ");
		scanf("%d",&nn);

		/*traverse the tree for insertion process*/

		while(1)
		{
			//if new node value is less than root value then move to left
			if(nn < p->data)
			{
				if(p->left == NULL)
				{
					//allocate  memory and then move
			p->left = (struct tree *)malloc(sizeof(struct tree));
			p = p->left;
			p->data = nn;
			p->left=NULL;
			p->right=NULL;
			break;
				}
				else
				{
					p=p->left;
				}
			}
			//if new node value is greater than root value then move to right
			else
			{
				if(p->right == NULL)
				{
		//allocate  memory and then move
		p->right = (struct tree *)malloc(sizeof(struct tree));
		p = p->right;
		p->data = nn;
		p->left=NULL;
		p->right=NULL;
		break;
				}
				else
				{
					p=p->right;
				}
			}
		}
		printf("\n Do you want to continue (y-1/n-0) ? ");
		scanf("%d",&ans);			//ans=getch();
	}
	return root;
}

void search(struct tree *p,int item)
{
	struct tree *temp;
	temp=p;
	while(temp!=NULL && temp->data != item)
	{
		if(item < temp->data)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}
	if(temp)
	{
		printf("\n Node is present....");
	}
	else
	{
		printf("\n Node is not present....");
	}
}

void inorder(struct tree *p)
{
	if(p != NULL)
	{
		inorder(p->left);
		printf("  %d",p->data);
		inorder(p->right);
	}
}





void preorder(struct tree *p)
{
	if(p != NULL)
	{
		printf("  %d",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

void postorder(struct tree *p)
{
	if(p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("  %d",p->data);
	}
}

void del(struct tree *ptr, int item)
{
	struct tree *move,*back,*temp;
		   move=ptr;
		   back=move;
		   //searches for position of a node to be deleted
		   while(move->data!=item)
		   {
			     back=move;
			     if(item < move->data)
			     {
				      move=move->left;
			     }
			     else
			     {
				      move=move->right;
			     }
		   }
		   //deleting node with left child and right child
		   if(move->left!=NULL && move->right!=NULL)
		   {
			     temp=move->right;
			     //find inorder successor of node to be deleted
			     while(temp->left!=NULL)
			     {
				      back=temp;
				      temp=temp->left;
			     }
			     move->data=temp->data;
		   }
		   //deleting leaf node
		   if(move->left==NULL && move->right==NULL)
		   {
			     if(back->right==move)
			     {
				       back->right=NULL;
			     }
			     else
			     {
				      back->left=NULL;
			     }
			     free(move);
			     return;
		   }

		   //deleting node with right child
		   if(move->left==NULL && move->right!=NULL)
		   {
			     if(back->left==move)
			     {
				      back->left=move->right;
			     }
			     else
			     {
				      back->right=move->right;
			     }
			     free(move);
			     return;
		   }

		   //deleting node with left child
		   if(move->left!=NULL && move->right==NULL)
		   {
			     if(back->left==move)
			     {
				      back->left=move->left;
			     }
			     else
			     {
				      back->right=move->left;
			     }
			     free(move);
			     return;
		   }

}

/* output

 1: Create
 2: Inorder
 3: Preorder
 4: Postorder
 5: Search
 6: Delete
 7: Exit
 Enter your choice :1

 Enter value of root :82

 Enter the value of new node :77

 Do you want to continue? y

 Enter the value of new node :90

 Do you want to continue? y

 Enter the value of new node : 346

 Do you want to continue? y

 Enter the value of new node :35

 Do you want to continue? n

 1: Create
 2: Inorder
 3: Preorder
 4: Postorder
 5: Search
 6: Delete
 7: Exit
 Enter your choice :2
 Inorder :
  35  77  82  90  346
 1: Create
 2: Inorder
 3: Preorder
 4: Postorder
 5: Search
 6: Delete
 7: Exit
 Enter your choice :3
 Preorder :
  82  77  35  90  346
 1: Create
 2: Inorder
 3: Preorder
 4: Postorder
 5: Search
 6: Delete
 7: Exit
 Enter your choice :4
 Postorder :
  35 77 346 90 82

 1: Create
 2: Inorder
 3: Preorder
 4: Postorder
 5: Search
 6: Delete
 7: Exit
 Enter your choice :6

 Enter element which node you to delete :90

 1: Create
 2: Inorder
 3: Preorder
 4: Postorder
 5: Search
 6: Delete
 7: Exit
 Enter your choice :2

 Inorder :  35  77  82  346
 1: Create
 2: Inorder
 3: Preorder
 4: Postorder
 5: Search
 6: Delete
 7: Exit
 Enter your choice :7

*/
