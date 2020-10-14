# 数据结构学习笔记

## 课程介绍

浙大的《数据结构》课程

[课程地址](https://www.bilibili.com/video/BV1JW411i731  “数据结构”)

**计划分别实现c++和python两个版本的课程代码**

## 第一讲 基本概念

### 1.1 什么是数据结构

**官方统一定义——没有**

* 数据结构是数据对象，以及存在于该对象的实例和组成实例的数据元素之间的各种联系。这些联系可以通过定义相关的函数来给出。 ——Sartaj Sahni 《数据结构、算法与应用》
* 数据结构是 ADT（Abstract Data Type，数据抽象类型）的物理实现。 ——Clifford A.Shaffer 《数据结构与算法分析》
* 数据结构（data structure）是计算机中存储、组织数据的方式。通常情况下，精心选择的数据结构可以带来最优效率的算法。 ——中文维基百科

**例1：如何在书架上摆放图书？**

图书的摆放要使得2个相关操作方便实现：

* 操作1：新书怎么插入？
* 操作2：怎么找到某本指定的书？

> 方法1：随便放

* 操作1：新书怎么插入？
  * 哪里有空放哪里，一步到位！
* 操作2：怎么找到某本指定的书？
  * 累死...

> 方法2：按照书名的拼音字母顺序排放

* 操作1：新书怎么插入？
  * 新进一本《阿Q正传》
* 操作2：怎么找到某本指定的书？
  * 二分查找！

> 方法3：把书架划分为几块区域，每块区域指定摆放 某种类别的图书；在每种类别内，按照书名的拼音 字母顺序排放    

* 操作1：新书怎么插入？
  * 先定类别，二分查找确定位置，移出空位
* 操作2：怎么找到某本指定的书？
  * 先定类别，再二分查找

**解决问题方法的效率， 跟数据的组织方式有关**



**例2：写程序实现一个函数PrintN，使得 传入一个正整数为N的参数后，能顺序 打印从1到N的全部正整数**    

```循环实现
void PrintN(int N)
{
    int i;
    for(i=1; i<=N; i++)
    {
        printf("%d\n", i);
    }
    
    return;
}
```

```递归实现
void PrintN(int N)
{
	if(N)
	{
        printN(N-1);
        printf("%d\n", N);
	}
	
	return;
}
```

**令N = 100,1000,10000,100000，...**

```c
#include <stdio.h>

void PrintN(int N);

int main()
{
    int N;
    scanf("%d", &N);
    PrintN(N);
    
    return 0;
}
```

**解决问题方法的效率， 跟空间的利用效率有关**



**例3：写程序计算给定多项式在给定点x 处的值$f(x)=a_0+a_1x+...+a_{n-1}x^{n-1}+a_nx^n$**

```c
double f(int n, double a[], double x)
{
    int i;
    double p = a[0];
    for(i=1; i<=n; i++)
    {
        p += (a[i] * pow(x, i));
    }
    
    return p;
}
```

$f(x)=a_0+x(a_1+x(...(a_{n-1}+x(a_n))...))$

```c
double f(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for(i=n; i>0; i--)
    {
        p = a[i-1] + x*p;
    }
    
    return p;
}
```

```c
#include <stdio.h>
#include <time.h>

clock_t start, stop;/* clock_t是clock()函数返回的变量类型 */

double duration;/* 记录被测函数运行时间，以秒为单位 */
int main ()
{
    /* 不在测试范围内的准备工作写在clock()调用之前*/
	start = clock();/* 开始计时 */
	MyFunction();/* 把被测函数加在这里 */
	stop = clock();/* 停止计时 */
	duration = ((double)(stop - start))/CLK_TCK;/* 计算运行时间 */
    /* 其他不在测试范围的处理写在后面，例如输出duration的值 */
	return 0;
}
```

**例3：写程序计算给定多项式$f(x)=\sum_{i=0}^9i·x^i$在给定点x=1.1处的值f(1.1)**

```c
double f1( int n, double a[], double x )
{
    int i;
	double p = a[0];
	for (i=1; i<=n; i++)
    {
		p += (a[i] * pow(x, i));        
    }

	return p;
}
```

```c
double f2( int n, double a[], double x )
{
    int i;
	double p = a[n];
	for (i=n; i>0; i--)
    {
		p = a[i-1] + x*p;        
    }

	return p;
}
```

```c
#include <stdio.h>
#include <time.h>
#include <math.h>

clock_t start, stop;
double duration;

#define MAXN 10 /* 多项式最大项数，即多项式阶数+1 */

double f1( int n, double a[], double x );
double f2( int n, double a[], double x );

int main ()
{
    int i;
	double a[MAXN]; /* 存储多项式的系数 */
    
	for ( i=0; i<MAXN; i++ )
    {
        a[i] = (double)i;
    }
	start = clock();
	f1(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
    
	printf("ticks1 = %f\n", (double)(stop - start));
	printf("duration1 = %6.2e\n", duration);
    
	start = clock();
	f2(MAXN-1, a, 1.1);
	stop = clock();
	duration = ((double)(stop - start))/CLK_TCK;
    
	printf("ticks2 = %f\n", (double)(stop - start));
	printf("duration2 = %6.2e\n", duration);
    
	return 0;
}
```

**解决问题方法的效率， 跟算法的巧妙程度有关**



**所以到底什么是数据结构**

* 数据对象在计算机中的组织方式
  * 逻辑结构
  * 物理存储结构
* 数据对象必定与一系列加在其上的操作相关联
* 完成这些操作所用的方法就是算法

**抽象数据类型（Abstract Data Type)**

* 数据类型
  * 数据对象集
  * 数据集合相关联的操作集
* 抽象：描述数据类型的方法不依赖于具体实现
  * 与存放数据的机器无关
  * 与数据存储的物理结构无关
  * 与实现操作的算法和编程语言均无关



**例4：“矩阵”的抽象数据类型定义“**

* 类型名称：矩阵(Matrix)
* 数据对象集：一个M*N的矩阵$A_{M×N}=(a_{ij})$(i=1,...,M;j=1,...,N)由M×N个三元组<a,i,j>构成，其中a是矩阵元素的值，i是元素所在的行号，j是元素所在的列号。
* 操作集：对于任意矩阵A、B、C∈Matrix，以及整数i、j、M、N
  * Matrix Create( int M, int N )：返回一个MN的空矩阵    
  * int GetMaxRow( Matrix A )：返回矩阵A的总行数    
  * int GetMaxCol( Matrix A )：返回矩阵A的总列数    
  * ElementType GetEntry( Matrix A, int i, int j )：返回矩 阵A的第i行、第j列的元素    
  * Matrix Add( Matrix A, Matrix B )：如果A和B的行、列数一 致，则返回矩阵C=A+B，否则返回错误标志    
  * Matrix Multiply( Matrix A, Matrix B )：如果A的列数等于B 的行数，则返回矩阵C=AB，否则返回错误标志    
  * ...

### 1.2 什么是算法

**定义**

> 算法(Algorithm)

* 一个有限指令集
* ≥ 0 个输入
* ＞0 个输出 
* 一定在有限步骤之后终止
* 每一条指令必须 
  * 有充分明确的目标，不可以有歧义
  * 计算机能处理范围内
  * 描述应不依赖于任何一种计算机语言以及具体的实现手段



**描述算法的手段**

* 空间复杂度 S(n)

		根据算法写成的程序在执行时**占用存储空间的长度**。这个长度往往与输入数据的 规模有关。空间复杂度过高的算法可能导致使用的 内存超限，造成程序非正常中断。    

* 时间复杂度T(n)

		根据算法写成的程序在执行时**耗费的时间的长度**。这个长度往往也与输入数据的规 模有关。时间复杂度过高的低效算法可能导致我们 在有生之年都等不到运行结果。



**什么是好的算法**

在分析一般算法的效率时，常常关注 

* 最坏情况复杂度 $T_{worst}(n)$

* 平均情况复杂度 $T_{avg}(n)$

    $T_{avg}(n) ≤ T_{worst}(n)$



**复杂度的渐进表示法**

* T(n) = O(f(n))表示存在常数C>0，$n_0$>0，使得当n>$n_0$时有T(n)≤C·f(n)
* T(n) = Ω(f(n))表示存在常数C>0，$n_0$>0，使得当n>$n_0$时有T(n)≥C·g(n)
* T(n) = Θ (h(n)) 表示同时有T(n) = O(h(n)) 和 T(n) = Ω(h(n))    



![1602578309581](C:\Users\ADMINI~1\AppData\Local\Temp\1602578309581.png)

![1602578323756](C:\Users\ADMINI~1\AppData\Local\Temp\1602578323756.png)



**复杂度分析小窍门**

* 若两段算法分别有复杂度T1(n) = O(f1(n)) 和T2(n) = O(f2(n))，则    
  * $T_1(n) + T_2(n) = max(O(f_1(n)), O(f_2(n))) $   
  * $T_1(n) * T_2(n) = O(f_1(n) * f_2(n))$
* 若T(n)是关于n的k阶多项式，那么T(n)=Θ ($n^k$)
*  一个for循环的时间复杂度等于循环次数乘以循环体 代码的复杂度    
*  if-else 结构的复杂度取决于if的条件判断复杂度 和两个分枝部分的复杂度，总体复杂度取三者中最大    



### 1.3 应用实例：最大子列和问题

**给定N个整数的序列{$A_1,A_2,...,A_N$}，求函数$f(i,j)=max(0,\sum_{k=i}^jA_k)$的最大值**

```算法1
int MaxSubseqSum1(int A[], int N)
{
    int ThisSum, MaxSum = 0;
	int i, j, k;
	for( i = 0; i < N; i++ )
    { /* i是子列左端位置 */
        for( j = i; j < N; j++ ) 
        { /* j是子列右端位置 */
            ThisSum = 0; /* ThisSum是从A[i]到A[j]的子列和 */
            for( k = i; k <= j; k++ )
                ThisSum += A[k];
            if( ThisSum > MaxSum ) /* 如果刚得到的这个子列和更大 */
                MaxSum = ThisSum; /* 则更新结果 */
        } /* j循环结束 */
    } /* i循环结束 */
	return MaxSum;
} 
```

**$T(N)=O(N^3)$**

```c
int MaxSubseqSum2(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j;
    for( i = 0; i < N; i++ ) 
    { /* i是子列左端位置 */
        ThisSum = 0; /* ThisSum是从A[i]到A[j]的子列和 */
        for( j = i; j < N; j++ ) 
        { /* j是子列右端位置 */
            ThisSum += A[j];/*对于相同的i，不同的j，只要在j-1次循环的基础上累加1项即可*/
            if( ThisSum > MaxSum ) /* 如果刚得到的这个子列和更大 */
                MaxSum = ThisSum; /* 则更新结果 */
        } /* j循环结束 */
    } /* i循环结束 */
	return MaxSum;
}
```

**$T(n)=O(N^2)$**

![1602579316449](C:\Users\ADMINI~1\AppData\Local\Temp\1602579316449.png)

```算法4
int MaxSubseqSum4( int A[], int N )
{
	int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for( i = 0; i < N; i++ ) 
    {
        ThisSum += A[i]; /* 向右累加 */
        if( ThisSum > MaxSum )
            MaxSum = ThisSum; /* 发现更大和则更新当前结果 */
        else if( ThisSum < 0 ) /* 如果当前子列和为负 */
            ThisSum = 0; /* 则不可能使后面的部分和增大，抛弃之 */
    }
	return MaxSum;
}
```

**$T(N)=O(N)$**

