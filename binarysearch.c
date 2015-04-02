#include<stdio.h>
int binarysearch(int array[],int len,int goal)
{
	int low=0;
	int high=len-1;
	int middle;
	while(low<=high)
	{
        middle=(low+high)/2;
        if(array[middle]==goal)
        {
        	return middle;
        }
        else if(array[middle]>goal)
        {
        	high=middle-1;
        }
        else
        {
        	low=middle+1;
        }
	}
	return -1;
}
int main()
{
	int array[2]={1,2};
	printf("location=%d\n",binarysearch(array,2,1));
}