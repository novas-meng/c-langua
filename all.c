#include <stdio.h>
#include <stdlib.h>
int alltest(int s[],int length,int t)
{
         int temp[100]={0};
         int k=0;
         int i=0;
         int layer=0;
         int res[t];
         int a=length-t;
         int count=0;       

         while(temp[0]<=a)
         {

               while(layer<=t-2)
              {
                  res[layer]=s[temp[layer]];
                  layer++;
                  temp[layer]=temp[layer-1]+1;
              }
                  temp[layer]=temp[layer-1]+1;
              while(temp[layer]<length)
              {
              	res[layer]=s[temp[layer]];
              	for(i=0;i<t;i++)
              	{
              		printf("%d ",res[i]);
              	}
              	count++;
              	printf("\n");
              	temp[layer]++;
              }
              layer=t-1;
              while(temp[layer]>=length)
              {
              	             // printf("temp=%d\n",temp[layer]);

                  temp[layer]=0;
                  layer--;
              }
              temp[layer]++;
              res[layer]=s[temp[layer]];
             // k=0;
         }
         printf("count=%d\n",count);
}
int main()
{
      int array[8]={1,2,3,4,5,6,7,8};
      alltest(array,8,8);
}