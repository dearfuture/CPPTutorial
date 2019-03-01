// project100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
//
//class M0TX
//{
//public:
//	M0TX() //默认构造函数
//	{
//		cout << "wodeceshi" << endl;
//	}
//};
//class MATX
//{
//public:
//	MATX() //默认构造函数
//	{
//		cout << "goodHAHAHAHA" << endl;
//	}
//};
//
//class MBTXPARENT
//{
//public:
//	MBTXPARENT()
//	{
//		cout << "MBTXPARENT()" << endl;
//	}
//};
//class MBTX :public MBTXPARENT
//{
//public:
//	int m_i;
//	int m_j;
//
//	//M0TX m0;  //类类型成员变量
//	//MATX ma; //类类型成员变量
//	void funct()
//	{
//		cout << "IAmVeryGood" << endl;
//	}
//
//	virtual void mvirfunc()
//	{
//		cout << "mvirfunc" << endl;
//	}
//
//	MBTX()
//	{
//		m_i = 15;
//	}
//};

class Grand //爷爷类
{
public:
};

class A : virtual public Grand
{
public:
};

class A2 : virtual public Grand
{
public:
};

class C :public A, public A2 //这里不需要virtual
{
public:
	C()
	{
		int aa;
		aa = 1;
	}
};


int main()
{
	//第四节 分析obj(目标文件)，构造函数语义
	//构造函数；
	//默认构造函数（缺省构造函数）：没有参数的构造函数；

	//传统认识认为：如果我们自己没定义任何构造函数，那么编译器就会为我们隐式自动定义 一个默认的构造函数，
	   //我们称这种构造函数为：“合成的默认构造函数”

	//结论：“合成的默认构造函数”，只有在 必要的时候，编译器才会为我们合成出来，而不是必然或者必须为我们合成出来。
	//必要的时候 是什么时候？

	//每个.cpp源文件会编译生成一个.obj(.o) linux下gcc -c，最终把很多的.obj(.o)文件链接到一起生成一个可执行。
	//介绍在windows下怎么看obj文件。
	//MBTX myb;

	//用dumpbin把.obj文件内容导出成可查看文件my.txt，这个my.txt格式，一般被认为是COFF：通用对象文件格式(Common Object File Format);
	//MBTX::MBTX
	//编译器会在哪些必要的时候帮助我们把默认的构造函数合成出来呢？
	//(1)该类MBTX没有任何构造函数，但包含一个类类型的成员ma,而该对象ma所属于的类MATX 有一个缺省的构造函数。
		//这个时候，编译器就会为该类MBTX生成一个 “合成默认的构造函数”，合成的目的是为了调用MATX里的默认构造函数。
	 //换句话说：编译器合成了默认的MBTX构造函数，并且在其中 安插代码，调用MATX的缺省构造函数；

	//第五节  构造函数语义续
	//(2)父类带缺省构造函数，子类没有任何构造函数，那因为父类这个缺省的构造函数要被调用，所以编译器会为这个子类合成出一个默认构造函数。
	   //合成的目的是为了调用这个父类的构造函数。换句话说，编译器合成了默认的构造函数，并在其中安插代码，调用其父类的缺省构造函数。

	//(3)如果一个类含有虚函数，但没有任何构造函数时
	//因为虚函数的存在，
	//a)编译器会给我们生成一个基于该类的虚函数表vftable。
	//b)编译给我们合成了一个构造函数，并且在其中安插代码： 把类的虚函数表地址赋给类对象的虚函数表指针 （赋值语句/代码）;
	      //我们可以把 虚函数表指针  看成是我们表面上看不见的一个类的成员函数,
	        //为什么这么麻烦，因为虚函数的调用存在一个多态问题，所以需要用到虚函数表指针。第三章详细讨论。

	//编译器给我们往MBTX缺省构造函数中增加了代码：
	//（a）生成了类MBTX的虚函数表
	//（b）调用了父类的构造函数
	//（c）因为虚函数的存在，把类的虚函数表地址赋给对象的虚函数表指针。
	//当我们有自己的默认构造函数时，编译器会根据需要扩充我们自己写的构造函数代码，比如调用父类构造函数，给对象的虚函数表指针赋值。
	//编译器干了很多事，没默认构造函数时必要情况下帮助我们合成默认构造函数，如果我们有默认构造函数，编译器会根据需要扩充默认构造函数里边的代码。

	//（4）如果一个类带有虚基类，编译器也会为它合成一个默认构造函数。
	//虚基类：通过两个直接基类继承同一个简介基类。所以一般是三层 ，有爷爷Grand，有两个爹A,A2，有孙子C
	C cc;

	//vbtable虚基类表。    vftalble(虚函数表）；
	//虚基类结构，编译器为子类和父类都产生了“合成的默认构造函数”




	return 1;
}

