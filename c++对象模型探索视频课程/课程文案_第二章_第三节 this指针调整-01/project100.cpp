// project100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

class A {
public:
	int a;
	A()
	{
		printf("A::A()的this指针是：%p!\n", this);
	}
	void funcA()
	{
		printf("A::funcA()的this指针是：%p!\n", this);
	}
};

class B {
public:
	int b;
	B()
	{
		printf("B::B()的this指针是：%p!\n", this);
	}
	void funcB()
	{
		printf("B::funcB()的this指针是：%p!\n", this);
	}
};

class C : public A, public B
{
public:
	int c;
	C()
	{
		printf("C::C()的this指针是：%p!\n", this);
	}
	void funcC()
	{
		printf("C::funcC()的this指针是：%p!\n", this);
	}

	void funcB()
	{
		printf("C::funcB()的this指针是：%p!\n", this);
	}
};


int main()
{
	//this指针调整：多重继承
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;

	C myc;
	myc.funcA();
	myc.funcB(); //已经被子类C覆盖了
	myc.B::funcB(); 
	myc.funcC();

	//派生类对象 它是包含 基类子对象的。
	//如果派生类只从一个基类继承的话，那么这个派生类对象的地址和基类子对象的地址相同。
	//但如果派生类对象同时继承多个基类，那么大家就要注意：
	  //第一个基类子对象的开始地址和派生类对象的开始地址相同。
	     //后续这些基类子对象的开始地址 和派生类对象的开始地址相差多少呢？那就得吧前边那些基类子对象所占用的内存空间干掉。

	//总结：你调用哪个子类的成员函数，这个this指针就会被编译器自动调整到对象内存布局中 对应该子类对象的起始地址那去；


	
	return 1; 
}

