#include<stdio.h>
int maxheapify(int array[],int i,int heapsize)
{
	int l=(i<<1)+1;
	int r=(i<<1)+2;
	int largest;
	int temp;
	if(l<=heapsize&&array[l]>array[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}
	if(r<=heapsize&&array[r]>array[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		temp=array[largest];
		array[largest]=array[i];
		array[i]=temp;
		maxheapify(array,largest,heapsize);
	}
}
int buildmaxheap(int array[],int heapsize)
{
	int i;
	for(int i=heapsize/2;i>=0;i--)
	{
		maxheapify(array,i,heapsize);
	}
}
int heapsort(int array[],int heapsize)
{
	int i;
	int temp;
	buildmaxheap(array,heapsize);
	for(i=heapsize;i>=1;i--)
	{
		temp=array[0];
		array[0]=array[heapsize];
		array[heapsize]=temp;
		heapsize--;
		maxheapify(array,0,heapsize);
	}
}
int main()
{
    int i;
	int array[10]={89,34,23,45,67,2,34,1,764,3};
	heapsort(array,9);
	for(i=0;i<10;i++)
	{
		printf("%d\n",array[i]);
	}
}