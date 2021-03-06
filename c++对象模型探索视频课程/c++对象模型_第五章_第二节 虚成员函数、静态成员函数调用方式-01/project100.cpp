// project100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <time.h >
#include <stdio.h>
#include <vector>
using namespace std;

class MYACLS
{
public:
	int m_i;
	void myfunc(int abc)
	{
		//m_i += abc; //这里需要用到this指针，而this指针为空，则会报告异常
		mystfunc();
	}
	virtual void myvirfunc()
	{
		printf("myvirfunc()被调用,this = %p\n", this);
		//myvirfunc2(); 居然走虚函数表指针调用
		MYACLS::myvirfunc2(); //直接调用虚函数，效率更高。这种写法压制了虚拟机制，不再通过查询虚函数表来调用
		                   //这种用类名::虚函数名()明确调用虚函数的方式等价于直接调用一个普通函数；
	}
	virtual void myvirfunc2() 
	{
		printf("myvirfunc2()被调用,this = %p\n", this);
	}

	//静态成员函数
	//static int m_si;
	static void mystfunc() //不需要this参数
	{
		printf("mystfunc()被调用\n");
		//m_si = 1;
	}
};

int main()
{	
	//一：虚成员函数（虚函数）调用方式
	MYACLS myacls;
	//myacls.myvirfunc(); //用对象调用虚函数，就像调用普通成员函数一样(三章六节),不需要通过虚函数表

	MYACLS *pmyacls = new MYACLS();
//	pmyacls->myvirfunc(); //要通过虚函数表指针查找虚函数表，通过虚函数表在好到虚函数的入口地址，完成对虚函数的调用
	//编译器视角
	//(*pmyacls->vptr[0])(pmyacls);
	//a)vptr，编译器给生成的虚函数表指针，指向虚函数表
	//b)[0] 虚函数表中第一项。代表myvirfunc()地址
	//c)传递一个参数进去，就是this，也是编译器给加的
	//d)*就得到了虚函数的地址；
	
	//printf("MYACLS::myvirfunc2虚函数的地址为%p", &MYACLS::myvirfunc2);


	
	//二：静态成员函数调用方式
	myacls.mystfunc();
	pmyacls->mystfunc();
	MYACLS::mystfunc();

	//编译器眼中：
	//_ZN6MYACLS8mystfuncEv();
	//_ZN6MYACLS8mystfuncEv();
	//_ZN6MYACLS8mystfuncEv();

	((MYACLS *)0)->mystfunc();  //能够正常调用静态成员函数
	((MYACLS *)0)->myfunc(12);  //有些成员函数希望支持独立于类对象之外的存取操作；

	myacls.myfunc(12);
	pmyacls->myfunc(12);

	//静态成员函数特性
	//a)静态成员函数没有this指针，这点最重要
	//b)无法直接存取类中普通的非静态成员变量；
	//c)静态成员函数不能在屁股后使用const，也不能设置为virtual 
	//d)可以用类对象调用，但不非一定要用类对象调用。
	//e)静态成员函数等同于非成员函数，有的需要提供回调函数的这种场合，可以将静态成员函数作为回调函数；

	printf("MYACLS::mystfunc()地址 = %p\n", MYACLS::mystfunc);



	delete pmyacls;
	return 1;
}
