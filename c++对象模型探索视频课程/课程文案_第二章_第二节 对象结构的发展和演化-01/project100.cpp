// project100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
//
//class A
//{
//public:
//	//int a = 100; //非静态成员变量（普通成员变量）
//
//	//static int a; //静态成员变量是跟着类走的；
//	//static int b;
//
//	//static void sfunc() {}; //静态成员函数
//	//void myfunc() {}; //普通成员函数
//	//int i;
//
//	/*virtual void myfunc3() {};
//	virtual void myfunc4() {};
//	virtual void myfunc5() {};
//	virtual void myfunc6() {};
//	virtual void myfunc7() {};*/
//
//	char a; //1字节
//	int b;  //4字节
//};

class myobject
{
public:
	myobject() {};//构造函数
	virtual ~myobject() {}; //析构函数       4
	float getvalue() const //普通成员函数
	{
		return m_value;
	}

	static int s_getcount() //静态成员函数 
	{
		return ms_scount;
	}

	virtual void vfrandfunc() {}; //虚函数 

protected:
	float m_value; //普通成员变量     4字节
	static int ms_scount; //静态成员变量
};

int main()
{
	//对象结构的发展和演化
	//c++对象模型逐步建立起来
	//(1)非静态的成员变量(普通成员变量)跟着类对象走（存在对象内部），也就是每个类对象都有自己的成员变量；
	/*A aobj; 
	int ilen = sizeof(aobj);
	cout << ilen << endl;*/

	//(2)静态成员变量跟对象没有什么关系，所以肯定不会保存在对象内部，是保存在对象外面（表示所占用的内存空间和类对象无关）的。
	//(3)成员函数：不管静态的还是非静态，全部都保存在类对象之外。所以不管几个成员函数，不管是否是静态的成员函数，对象的sizeof的大小都是不增加的；

	//(4)虚函数：不管几个虚函数，sizeof()都是多了4个字节。
	//(4.1)类里只要有一个虚函数（或者说至少有一个虚函数），这个类 会产生一个 指向 虚函数 的指针。
	  //有两个虚函数，那么这个类 就会产生两个指向虚函数的指针。
	//类本身  指向虚函数的 指针（一个或者一堆）要有地方存放，存放在一个表格里，这个表格我们就称为“虚函数表(virtual table【vtbl】)”；
	 //这个虚函数表一般是保存在可执行文件中的，在程序执行的时候载入到内存中来。
	//虚函数表是基于类的，跟着类走的；

	//(4.2)说说类对象，这四个字节的增加，其实是因为虚函数的存在；因为有了虚函数的存在，导致系统往类对象中添加了一个指针，
	 //这个指针正好指向这个虚函数表，很多资料上把这个指针叫vptr；这个vptr的值由系统在适当的时机（比如构造函数中通过增加额外的代码来给值）；

	//---------------总结：对于类中
	//（1）静态数据成员不计算在类对象sizeof()内；
	//（2）普通成员函数和静态成员函数不计算在类对象的sizeof()内
	//（3）虚函数不计算在类对象的sizeof()内，但是虚函数会让类对象的sizeof()增加4个字节以容纳虚函数表指针。
	//（4）虚函数表[vtbl]是基于类的（跟着类走的，跟对象没关系，不是基于对象的）；
	//（5）如果有多个数据成员，那么为了提高访问速度，某些编译器可能会将数据成员之间的内存占用比例进行调整。(内存字节对齐)
	//（6）不管什么类型指针char *p,int *q;,该指针占用的内存大小是固定的
	/*int ilen2 = sizeof(char *);
	int ilen3 = sizeof(int *);*/


	myobject obj;
	int ilen = sizeof(obj);
	cout << ilen << endl; //8字节，成员变量m_value占4字节，虚函数表指针占4字节。

	//总结类对象大小的组成：
	//(1)非静态成员变量所占的内存总量以及这些成员变量之间内u才能字节对齐所额外占用的内存；
	//(2)若有虚函数，则会产生虚函数表指针（vptr）。

	//当然，如果类之间是多重继承关系。并且每个父类都有虚函数，情况不同，后续探讨。


    


	return 1; 
}

