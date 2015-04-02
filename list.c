#include <stdio.h>
typedef struct listnode
{
	int data;
	struct listnode *next;
}*List;
int travellist(List list)
{
	List p=list->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
List reverselist(List list)
{
	List p=list;
	List m=list;
	List q=p->next;
	List temp;
	while(q!=NULL)
	{
		p->data=q->data;
		temp=q->next;
		q->next=p;
		p=q;
		q=temp;
		printf("p->data=%d\n",p);
	}
	m->next=NULL;
	printf("---");
	return p;
}
int main()
{
	int array[100];
	int count;
	int i;
	List list=(List *)malloc(sizeof(struct listnode));
	list->next=NULL;
	list->data=8;
	printf("请输入链表元素，#代表终止\n");
	while(scanf("%d",&array[count])==1)
	{
		count++;
	}
	printf("count=%d\n",count);
	List p=list;
    for(i=0;i<count;i++)
    {
    	List node=(List *)malloc(sizeof(struct listnode));
    	node->data=array[i];
    	node->next=NULL;
    	p->next=node;
    	p=node;
    }
    travellist(list);
    list=reverselist(list);
    travellist(list);
}
