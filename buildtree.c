#include <stdio.h>
#include <stdlib.h>
typedef struct treenode 
{
   int data;
   struct treenode *lchild;
   struct treenode *rchild;
}*Node;

Node createTree(int array[],int length)
{
	Node nodes[100];
	int i=0;
	int j=0;
	int parent;
	for(i=0;i<length;i++)
	{
		if(array[i]!=-1)
		{
			Node treenode=(Node *)malloc(sizeof(struct treenode));
			treenode->data=array[i];
			treenode->lchild=NULL;
			treenode->lchild=NULL;
			nodes[i]=treenode;
			int parent=(i-1)/2;
			if(i!=0&&array[parent]!=-1)
			{
				if(i%2==1)
				{
					nodes[parent]->lchild=treenode;
				}
				else
				{
					nodes[parent]->rchild=treenode;
				}
			}
		}
		else
		{
			nodes[i]=NULL;
		}
	}
	return nodes[0];
}
int pretravel(Node root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		pretravel(root->lchild);
		pretravel(root->rchild);
	}
}
int midtravel(Node root)
{
	if(root!=NULL)
	{
		midtravel(root->lchild);
		printf("%d ",root->data);
		midtravel(root->rchild);
	}
}
int posttravel(Node root)
{
	if(root!=NULL)
	{
		posttravel(root->lchild);
		posttravel(root->rchild);
		printf("%d ",root->data);
	}
}

recurpretravel(Node root)
{
	Node array[100];
	int i=-1;
	Node p=root;
	while(i!=-1||p!=NULL)
	{
		while(p!=NULL)
		{
			printf("%d ",p->data);
			i++;
			array[i]=p;
			p=p->lchild;
		}
		p=array[i];
		i--;
		p=p->rchild;
	}
}
recurmidtravel(Node root)
{
	Node array[100];
	int i=-1;
	Node p=root;
	while(i!=-1||p!=NULL)
	{
		while(p!=NULL)
		{
			i++;
			array[i]=p;
			p=p->lchild;
		}
		p=array[i];
		printf("%d ",p->data);
		i--;
		p=p->rchild;
	}
}

/*
int recurposttravel(Node root)
{
	Node array[100];
	Node p,temp;
	int i=0;
	p=root;
	array[i]=root;
	p=p->lchild;
	while(i!=-1)
	{
		while(p!=NULL)
		{
			i++;
			array[i]=p;
			p=p->lchild;
		}

	}
}

*/









recurposttravel(Node root)
{
	Node array[100];
	Node temp,p;
	int i=0;
	p=root;
	array[i]=p;
	p=p->lchild;
	while(i!=-1)
	{
        while(p!=NULL)
        {
        	i++;
        	array[i]=p;
        	p=p->lchild;
        }
        p=array[i];
        while((p->rchild==temp)|| (p->rchild==NULL&&p->lchild==NULL))
        {
        	i--;
        	printf("%d ",p->data);
        	if(i==-1)
        		break;
        	temp=p;
        	p=array[i];
        }
        p=p->rchild;
	}
}





























/*
typedef struct treenode
{
	int data;
	struct treenode *lchild;
	struct treenode *rchild;
}*Node ;
Node createTree(int array[],int length)
{
    Node nodes[100];
	int i=0;
	int j;
	int parent;
	for(int i=0;i<length;i++)
	{
		if(array[i]!=-1)
		{
			Node treenode=(Node *)malloc(sizeof(struct treenode));
			treenode->data=array[i];
			treenode->lchild=NULL;
			treenode->rchild=NULL;
			nodes[i]=treenode;
			parent=(i+1)/2-1;			
			if(parent>=0&&array[parent]!=-1)
			{
				if(i%2==1)
				{
					nodes[parent]->lchild=treenode;
				}
				else
				{
					nodes[parent]->rchild=treenode;
				}
			}
			
		}
        else
        {
        	//Node treenode=(Node *)malloc(sizeof(struct treenode));
        	//treenode->data=-1;
        	//treenode->lchild=NULL;
        	//treenode->rchild=NULL;
        	nodes[i]=NULL;
        }

	}
	return nodes[0];
}
int pretravel(Node tree)
{
	if(tree!=NULL)
	{
		printf("%d ",tree->data);
		pretravel(tree->lchild);
		pretravel(tree->rchild);
	}
}
int midtravel(Node tree)
{
	if(tree!=NULL)
	{
		midtravel(tree->lchild);
        printf("%d ",tree->data);
        midtravel(tree->rchild);
	}
}
int posttravel(Node tree)
{
	if(tree!=NULL)
	{
		posttravel(tree->lchild);
		posttravel(tree->rchild);
		printf("%d ",tree->data);
	}
}
int recurpretravel(Node tree)
{
	Node array[100];
	int i=-1;
	//array[i]=tree;
	//i++;
	Node p=tree;
	while(i!=-1||p!=NULL)
	{ 

         while(p!=NULL)
         {
         	i++;
         	printf("%d ",p->data);
         	array[i]=p;
         	p=p->lchild;
         }
         p=array[i];
         i--;
         p=p->rchild;
	}
}
*/
int main()
{
	int array[100];
	int i=0;
	int n;
	Node root;
	printf("请输入树的节点,如果节点为空输入-1，#停止\n");
    while(scanf("%d",&n)==1)
    {
    	array[i]=n;
    	i++;
    }
    printf("i=%d\n",i);
    root=createTree(array,i);
    printf("\n前序遍历为\n");
    pretravel(root);
    recurpretravel(root);
    printf("\n中序遍历为\n");
    midtravel(root);
    recurmidtravel(root);
    printf("\n后序遍历为\n");
    posttravel(root);
    printf("\n"); 
    recurposttravel(root);
  // printf("%d",root->data);
}