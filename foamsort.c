//冒泡排序
#include <stdio.h>
int foamsort(int array[],int n)
{
    int i,j;
    for(i=0;i<=n-1;i++)
    {
        for(j=n-1;j>=i+1;j--)
        {
            if(array[j]<=array[j-1])
            {
                array[j-1]=array[j]+array[j-1];
                array[j]=array[j-1]-array[j];
                array[j-1]=array[j-1]-array[j];
            }
        }
    }
    return 0;
}


/*
int foamsort(int array[],int n)
{
    int i,j;
    for(i=0;i<=n-1;i++)
    {
    	for(j=n-1;j>=i+1;j--)
    	{
    		if(array[j]<array[j-1])
    		{
    			array[j]=array[j]+array[j-1];
    			array[j-1]=array[j]-array[j-1];
    			array[j]=array[j]-array[j-1];
    		}
    	}
    }
    return 0;
}
*/
int main()
{
	int array[10]={3,4,2,13,5,67,34,26,26,20};
    int i=0;
    foamsort(array,10);
    for(i=0;i<10;i++)
    {
    	printf("%d ",array[i]);
    }
    printf("\n");
}