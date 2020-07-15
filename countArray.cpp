#include <stdio.h>
#include <iostream>

using namespace std;

int countArray(int *a, int length, int start, int end);

/*
	参数：a：输入一个整形数组
		  length：数组长度
	返回值：返回要找的数
*/
int GetDuplications(int *a, int length)
{
	if ( a == nullptr && length < 0 )
	{
		return false;
	}
	int start = 1;
	int end = length - 1;

	while (end >= start)
	{
		int middle = ((end - start) >> 1) + start; //二分法
		int count = countArray(a, length, start, middle);

		if (end == start)
		{
			if (count > 1)
			{
				return start;
			}
			else
				break;
		}
	

		if (count > (middle - start) + 1)
		{
			end = middle;
		}
		else
		{
			start = middle + 1;
		}
	}
	return -1;
}

/*
	函数countArray（）：用来计数比较数组在真数组出现的次数
	参数：a：输入的整形数组
		length：输入数组的长度
		start：比较数组的起点
		end：比较数组的终点（二分法后真数组的中点）
	返回值：count：比较数组出现的次数
*/
int countArray(int *a, int length,int start, int end )
{
	int count = 0;    //计数初始化
	if (a == nullptr && length < 0)
	{
		return false;
	}

	for (int i = 0; i < length; ++i)
	{
		if (a[i] >= start && a[i] <= end)
		{
			count++;
		}
	}
	return count;
}




//===================测试用例==========================

void test(const char* testname, int *a, int length, int *duplication,int duplictionlength )
{
	int result = GetDuplications(a, length);
	for(int i = 0; i < duplictionlength;i++)
	{
		if (result == duplication[i])
		{
			printf("%s PASSED\n", testname);
			return ;
		}
	}

	printf("%s FAILED!\n ", testname);
}


void test1()
{
	int numbers[] = { 2,3,5,4,3,2,6,7 };
	int dupliction[] = { 3 };
	test("test1", numbers, sizeof(numbers) / sizeof(int),(int *)dupliction, sizeof(dupliction) / sizeof(int));
}


int main()
{
	test1();
}
