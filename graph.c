#include <stdio.h>
#include <stdlib.h>
//定义链表的节点
typedef struct listnode
{
	int index;
	struct listnode *next;
}*ListNode;
//定义链表的边顶点
typedef struct edgenode
{
	int data;
	//每个节点对应的链表的首节点
    ListNode *first;
}*EdgeNode;

//定义图
typedef struct graph
{
	//n为顶点数，e为边数
	int n;
	int e;
	//定义顶点构成的数组；
   EdgeNode list[100];
}*Graph;
int main()
{
	Graph listgraph;
	int i=0;
	int j,k;
	listgraph=(Graph *)malloc(sizeof(struct graph));
	printf("请输入节点数和边数\n");
	scanf("%d %d",&(listgraph->n),&(listgraph->e));
	//printf("%d %d ",listgraph->n,listgraph->e);
	printf("请输入节点信息\n");
    while(i<listgraph->n)
    {
    	 listgraph->list[i]=(EdgeNode *)malloc(sizeof(struct edgenode));
    	 listgraph->list[i]->first=NULL;
         scanf("%d",&(listgraph->list[i]->data));
         i++;
    }
    printf("请输入各个边的节点的关联关系\n");
    setbuf(stdin,NULL);
    i=0;
    while(i<listgraph->e)
    {
    	scanf("%d %d",&j,&k);
    	//printf("---\n");
        ListNode node=(ListNode *)malloc(sizeof(struct listnode));
        node->index=k;
        node->next=NULL;
        ListNode p=listgraph->list[j]->first;
        if(p==NULL)
        {
        	listgraph->list[j]->first=node;
        }
        else
        {
        	while(p->next!=NULL)
        	{
        		p=p->next;
        	}
        	p->next=node;
        }
       i++;
       //printf("i=%d\n",i);
    }

    printf("输入完全");
}
