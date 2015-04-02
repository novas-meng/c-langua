#include <stdio.h>
int  zeros(int x)
{
	 int count=0;
	
	 while(x%5==0)
	 {
	 	count++;
	 	x=x/5;
	 }
	 return count;
}
int main()
{
	int a,b;
	int i;
	int sum=0;
	scanf("%d",&b);
    int array[40001];
    int count=1;
    for(i=5;i<=200000;i=i+5)
      {
           sum=sum+zeros(i);
           array[count]=sum;
           count++;
      }
      int temp=200005;
      int tempsum=array[40000];
	while(b>0)
	{
		                 scanf("%d",&a);
		                 if(a<=200000)
		                 {
		                 	sum=array[a/5];
		                 }
		                 else
		                 {
		                 	sum=tempsum;;
		                 	 for(i=temp;i<=a;i=i+5)
                         {
                                sum=sum+zeros(i);
                         }
                         temp=a;

                     }
                        
                         printf("%d\n",sum);
                         sum=0;
                         b--;
                         
	}
}