#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
题目：输入一个正数 n，输出所有和为n 连续正数序列。
例如输入 15，由于1+2+3+4+5=4+5+6=7+8=15，所以输出3 个连续序列1-5、4-6 和7-8。
用到的思路是等差数列的思想；

malloc函数介绍
返回值类型为 void *,调用格式为：malloc(size),size的类型为unsigned int 。
    malloc函数用来分配size个字节的存储区，返回一个指向存储区首地址的基类型为void的地址。若没有足够的内存单元供分配，函数返回空（NULL）
    通过调用malloc函数所分配的动态存储单元中没有确定的初值，这个存储单元也没有名字，吸能靠指针来引用它。
例：int *pi;
float *pf;
pi=(int *)malloc(2); 
pf=(float *)malloc(4);
因为malloc函数的返回的地址为void *,在调用函数时，必须延用强制类型转换将其转换为所需要的类型。括号中的*号代表返回的是指针类型的
*/
int seqn(int n)
{
   int start;
   double end;
   int j;
   for(start=1;start<=n/2;start++)
   {
   	  j=2*n+start*start-start;
      end=(-1+sqrt(4*j+1))/2;
      if(end==(int)end)
      {
      	for(j=start;j<=end;j++)
      	{
      		printf("%d",j);
      	}
      	printf("\n");
      }
   }
}
int main()
{
   int n;
   int *mem;
   mem=(int *)malloc(sizeof(int));
   printf("mem=%d\n",(int)mem);
   printf("请输入n\n");
   scanf("%d",&n);
   seqn(n);
}