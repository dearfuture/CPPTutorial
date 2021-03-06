// project100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
//
//class CTB
//{
//public:
//	/*CTB(const CTB&)
//	{
//		cout << "CTB()的拷贝构造函数执行了" << endl;
//	}
//	CTB()
//	{
//	}*/
//	virtual void mvirfunc() {}
//};
//
//class CTBSon  :public CTB
//{
//public:
//	//virtual void mvirfunc() {}
//};
//
//class ASon
//{
//public:
//	int m_testson;
//};
//
//class A
//{
//public:
//	int m_test;
//	ASon asubobj;
//	CTB m_ctb;
//};

class Grand //爷爷类
{
public:
};
class A :virtual public Grand
{
public:
};
class A2 :virtual public Grand
{
public:
};
class C :public A, public A2
{
public:
};

int main()
{		
	//第六节   拷贝构造函数语义
	//传统上，大家认为：如果我们没有定义一个自己的拷贝构造函数，编译器会帮助我们合成 一个拷贝构造函数。
	//这个合成的拷贝构造函数，也是在 必要的时候才会被编译器合成出来。  所以  “必要的时候”；
	//A mya1;
	//mya1.m_test = 15;
	//mya1.asubobj.m_testson = 120;
	//A mya2 = mya1; //调用拷贝构造函数。 这个mya2.m_test = 15，这个其实是编译器内部的一个手法：
	//                               //成员变量初始化手法，比如int这种简单类型，直接就按值就拷贝过去,编译器不需要合成拷贝构造函数的情况下就帮助我们把这个事情办了；

	//a) A mya2 = mya1; 是拷贝构造一个对象。
	//b)我们自己也没有写类A的拷贝构造函数，编译器也没有帮助我们生成拷贝构造函数。
	//c)我们却发现mya1对象的一些成员变量值确实被拷贝到mya2中去。这是编译器内部的一些直接拷贝数据的实现手法，
	        //比如类A中有类类型ASon成员变量asubobj，也会递归是的去拷贝类ASon的每个成员变量。

	//某些情况下，如果我们不写自己的拷贝构造函数，编译器就会帮助我们合成出拷贝构造函数来。
	//那编译器在什么情况下会帮助我们合成出拷贝构造函数来呢？那这个编译器合成出来的拷贝构造函数又要干什么事情呢？
	//(1)如果一个类A没有拷贝构造函数，但是含有一个类类型CTB的成员变量m_ctb。该类型CTB含有拷贝构造函数，那么
	        //当代码中有涉及到类A的拷贝构造时，编译器就会为类A合成一个拷贝构造函数。
	//编译器合成的拷贝构造函数往往都是干一些特殊的事情。如果只是一些类成员变量值的拷贝这些事，编译器是不用专门合成出拷贝构造函数来干的，编译器内部就干了；

	//(2)如果一个类CTBSon没有拷贝构造函数，但是它有一个父类CTB，父类有拷贝构造函数，
	   //当代码中有涉及到类CTBSon的拷贝构造时，编译器会为CTBSon合成一个拷贝构造函数 ，调用父类的拷贝构造函数。
	/*CTBSon myctbson1;
	CTBSon myctbson2 = myctbson1;*/

	//(3)如果一个类CTBSon没有拷贝构造函数，但是该类声明了或者继承了虚函数
	     //当代码中有涉及到类CTBSon的拷贝构造时，编译器会为CTBSon合成一个拷贝构造函数 ,往这个拷贝构造函数里插入语句：
	          //这个语句的含义 是设定类对象myctbson2的虚函数表指针值。虚函数表指针，虚函数表等概念，详细可以学习第三章。

	//(4)如果 一个类没有拷贝构造函数， 但是该类含有虚基类
	   //当代码中有涉及到类的拷贝构造时，编译器会为该类合成一个拷贝构造函数；

	C cc;
	C cc2 = cc;  //当代码中有涉及到类的拷贝构造时

	//(5)(6)其他编译器合成拷贝构造函数的情形留给大家探索。


	return 1;
}

