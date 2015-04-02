#include<stdio.h>




for(j=0;j<count;j++)
	{
		
	}



int partition(int array[],int p,int q)
{
	int x=array[q];
	int i=p-1;
	int j;
	int temp;

	for(j=p;j<=q-1;j++)
	{
		if(array[j]<=x)
		{
			
			i++;
			/*
			//printf("i=%d j=%d ",i,j);
			//printf("%d %d \n",array[i],array[j]);
			array[i]=array[i]^array[j];
			//printf("%d %d \n",array[i],array[j]);
			array[j]=array[i]^array[j];
			//			printf("%d %d\n",array[i],array[j]);

			array[i]=array[i]^array[j];
			//			printf("%d %d \n",array[i],array[j]);
*/
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
		}
	}
	/*
	array[i+1]=array[i+1]^array[q];
	array[q]=array[i+1]^array[q];
	array[i+1]=array[i+1]^array[q];
	*/
	temp=array[i+1];
	array[i+1]=array[q];
	array[q]=temp;
	return i+1;
}
int quicksort(int array[],int p,int q)
{
	int flag;
	if(p<q)
	{
		flag=partition(array,p,q);
		quicksort(array,p,flag-1);
		quicksort(array,flag+1,q);
	}
}
int select(int array[],int p,int q,int i)
{
	if(p==q)
	{
		return array[p];
	}
	int flag=partition(array,p,q);
	//printf("flag=%d\n",flag);
	int k=flag-p+1;
	if(k==i)
	{
		return array[flag];
	}
	else if(k>i)
	{
		return select(array,p,flag-1,i);
	}
	else
	{
		return select(array,flag+1,q,i-k);
	}
}
/*
int partition(int array[],int p,int q)
{
	int x=array[q];
	int i=p-1;
	int j;
	int temp;
	for(j=p;j<=q-1;j++)
	{
		if(array[j]<=x)
		{
			i++;
		    temp=array[j];
		    array[j]=array[i];
		    array[i]=temp;

		}
	}
	temp=array[i+1];
	array[i+1]=array[q];
	array[q]=temp;
	return i+1;
}
int quicksort(int array[],int p,int q)
{
	int flag;
	if(p<q)
	{
		flag=partition(array,p,q);
		quicksort(array,p,flag-1);
		quicksort(array,flag+1,q);
	}
}
int select(int array[],int p,int q,int i)
{
	if(p==q)
	{
		return array[p];
	}
	int flag=partition(array,p,q);
	int k=flag-p+1;
	if(k==i)
	{
		return array[flag];
	}
	else if(k>i)
	{
		return select(array,p,flag-1,i);
	}
	else
	{
		return select(array,flag+1,q,i-k);
	}
}
*/
int main()
{
	int i;
	int array[10]={89,34,23,45,67,2,34,16,764,3};
	//quicksort(array,0,9);
	for(i=1;i<=10;i++)
	{
		//printf("in select");
		select(array,0,9,i);
	}
	for(i=0;i<10;i++)
	{
		printf("%d\n",array[i]);
	}
}