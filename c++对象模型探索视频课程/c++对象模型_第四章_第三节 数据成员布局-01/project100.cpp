// project100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <time.h >
#include <stdio.h>
using namespace std;

#define GET(A,m) (int)(&((A*)0)->m) 
//定义一个类
#pragma pack(1) //对齐方式设置为1字节对齐（不对齐）
class MYACLS
{
public:
	int m_i;
	static int m_si; //声明不是定义

	int m_j;
	static int m_sj;

	int m_k;
	static int m_sk;	

	char m_c;  //1字节
	int m_n;   //4字节

private:
	int m_pria;
	int m_prib;

public:
	void printMemPoint()
	{
		cout << "打印成员变量偏移值------------" << endl;
		printf("MYACLS::m_i = %d\n", &MYACLS::m_i);
		printf("MYACLS::m_j = %d\n", &MYACLS::m_j);
		printf("MYACLS::m_k = %d\n", &MYACLS::m_k);
		printf("MYACLS::m_c = %d\n", &MYACLS::m_c);
		printf("MYACLS::m_n = %d\n", &MYACLS::m_n);

		printf("MYACLS::m_pria = %d\n", &MYACLS::m_pria);
		printf("MYACLS::m_prib = %d\n", &MYACLS::m_prib);
		cout << "-------------------------" << endl;

		cout << GET(MYACLS, m_prib) << endl;

	}
public:
	virtual void myfv() {}
};
#pragma pack() //取消指定对齐，恢复缺省对齐；


int MYACLS::m_sj = 0; //这才是定义；

int main()
{	
	//一：观察成员变量地址规律
	MYACLS myobj;
	cout << sizeof(myobj) << endl;

	//普通成员变量的存储顺序 是按照在类中的定义顺序从上到下来的；
	//比较晚出现的成员变量在内存中有更高的地址；
	//类定义中pubic,private,protected的数量，不影响类对象的sizeof；

	//二：边界调整，字节对齐
	//某些因素会导致成员变量之间排列不连续，就是边界调整（字节对齐），调整的目的是提高效率，编译器自动调整；
	        //调整：往成员之间填补一些字节，使用类对象的sizoef字节数凑成 一个4的整数倍，8的整数倍；

	//为了统一字节对齐问题，引入一个概念叫一字节对齐(不对齐)；
	//有虚函数时，编译器往类定义中增加vptr虚函数表指针：内部的数据成员。

	//三：成员变量偏移值的打印
	//成员变量偏移值，就是这个成员变量的地址，离对象首地址偏移多少；



	myobj.m_i = 2;
	myobj.m_k = 8;
	myobj.m_j = 5;

	printf("myobj.m_i = %p\n", &myobj.m_i);
	printf("myobj.m_j = %p\n", &myobj.m_j);
	printf("myobj.m_k = %p\n", &myobj.m_k);
	printf("myobj.m_c = %p\n", &myobj.m_c);
	printf("myobj.m_n = %p\n", &myobj.m_n);

	MYACLS *pmyobj = new MYACLS();
	printf("pmyobj->m_i = %p\n", &pmyobj->m_i);
	printf("pmyobj->m_j = %p\n", &pmyobj->m_j);
	printf("pmyobj->m_k = %p\n", &pmyobj->m_k);
	printf("pmyobj->m_c = %p\n", &pmyobj->m_c);
	printf("pmyobj->m_n = %p\n", &pmyobj->m_n);

	pmyobj->printMemPoint();

	//成员变量指针
	int MYACLS::*mypoint = &MYACLS::m_n;
	printf("pmyobj->m_n偏移值 = %d\n", mypoint);
	

	return 1;
}

