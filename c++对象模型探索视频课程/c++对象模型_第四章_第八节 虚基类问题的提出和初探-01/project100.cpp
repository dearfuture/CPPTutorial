// project100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <time.h >
#include <stdio.h>
#include <vector>

using namespace std;

class Grand //爷爷类
{
public:
	int m_grand;
};
class A1 : virtual public Grand
{
public:
	int m_a1;
};

class A2 : virtual public Grand
{
public:
	int m_a2;
};

class C1 :public A1, public A2
{
public:
	int m_c1;
};

int main()
{
	//一：虚基类（虚继承/虚派生）问题的提出
	//传统多重继承造成的 ：空间问题，效率问题，二义性问题；
	cout << sizeof(Grand) << endl;
	cout << sizeof(A1) << endl;
	cout << sizeof(A2) << endl;
	cout << sizeof(C1) << endl;

	//C1 c1;
	//c1.m_grand = 12; //访问不明确，名字冲突，二义性；
	//                         //引入虚基类之后，就不会出现访问不明确的问题了
	//c1.A1::m_grand = 13;
	//c1.A2::m_grand = 15;

	//虚基类，让Grand类只被继承一次；

	//二：虚基类初探
	//两个概念：(1)虚基类表 vbtable(virtual base table).(2)虚基类表指针 vbptr(virtual base table pointer)
	//空类sizeof(Grand) ==1好理解； 
	//virtual虚继承之后，A1,A2里就会被编译器插入一个虚基类表指针，这个指针，有点成员变量的感觉
	//A1,A2里因为有了虚基类表指针，因此占用了4个字节
	A1 a1;
	A2 a2;
	//虚基类表指针，用来指向虚基类表（后续谈）。

	   	  	

	return 1;
}
