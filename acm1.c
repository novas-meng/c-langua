#include <stdio.h>
#include <math.h>
int main()
{
	double temp;
	double a,b;
	int i;
	int j=0;
	int flag=1;
	double s,t;
	while(scanf("%lf %lf",&a,&b)==2&&(a!=0||b!=0))
	{
		flag=1;
		if(a==0.0)
		{
			printf("0\n");
			flag=0;
		}
		for(i=1;i<=100;i++)
	  {
          s=log((60*i)/a);
          t=log(b+1);
          temp=s/t;
         if(temp==(int)temp)
        {
         	printf("%d\n",(int)temp);
         	flag=0;
        	break;
        }
	 }

	   if(flag==1)
	  {
		printf("Impossible\n");
	  }
  }
  return 0;
}