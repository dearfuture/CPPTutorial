// project100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <time.h >
using namespace std;

class X
{
public:
	int m_i;
	X(const X &tmpx)
	{
		m_i = tmpx.m_i;
		cout << "拷贝构造函数被调用" << endl;
	}
	X()
	{
		m_i = 0;
		cout << "构造函数被调用" << endl;
	}
	~X()
	{
		cout << "析构函数被调用" << endl;
	}
	void functest()
	{
		cout << "functest()被调用" << endl;
	}
};

//void func(X tmpx)
//{
//	return;
//}

//老编译器看func(老编译器角度)
//void func(X &tmpx)
//{
//	return;
//}

//人类视角
//X func()
//{
//	X x0;
//	//....
//	return x0;   //系统产生临时对象并把x0的内容拷贝构造给了临时对象。
//}

//编译器角度的func
void func(X &extra)
{
	X x0; //从编译器角度，这行不调用X的构造函数
	//...
	//...
	extra.X::X(x0);
	return;
}

int main()
{
	//第七节   程序转化语义
	//我们写的代码，编译器会对代码进行拆分，拆分成编译器更容易理解和实现的代码。
	//看一看编译器是如何解析这些代码的。
	//站在程序员角度/站在编译器角度  
	//程序员看代码视角 和 编译器看代码视角之间不断切换。

	////(1)定义时初始化对象(程序员视角)
	//X x0;
	//x0.m_i = 15;
	//X x1 = x0; //定义的时候初始化
	//X x2(x0);
	//X x3 = (x0);

	////切换到编译器角度，编译器会拆分成两个步骤(编译器视角)
	//cout << "---------------" << endl;
	//X x100;           //步骤一：定义一个对象，为对象分配内存。从编译器视角来看，这句是不调用X类的构造函数。
	//x100.X::X(x0);    //步骤二：直接调用对象的拷贝构造函数去了；

	
	////(2)参数的初始化(程序员视角/现代编译器)
	//X x0;
	////func(x0);

	////老编译器视角
	//X tmpobj; //编译器产生一个临时对象
	//tmpobj.X::X(x0); //调用拷贝构造函数
	//func(tmpobj); //用临时对象调用func
	//tmpobj.X::~X(); //func()被调用完成后，本析构被调用。

	//(3)返回值初始化(程序员角度)
	//X my = func();
	
	//编译器对上述代码的理解(编译器角度)
	//X my; //不会调用X的构造函数
	//func(my);

	//人类视角
	//func().functest();

	//切换到编译器视角
	//X my; //不会调用X的构造函数
	//(func(my), my).functest(); //逗号表达式：先计算表达式1，再计算表达式2，整个逗号表达式的结果是表达式2的值；

	//程序员视角
	//X(*pf)(); //定义个函数指针
	//pf = func;
	//pf().functest();

	//编译器视角
	X my; //不调用构造函数
	void (*pf)(X &);
	pf = func;
	pf(my);
	my.functest();



	return 1;
}

