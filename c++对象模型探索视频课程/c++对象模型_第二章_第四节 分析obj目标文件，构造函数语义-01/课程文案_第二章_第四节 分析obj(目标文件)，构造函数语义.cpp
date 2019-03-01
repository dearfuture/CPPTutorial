// project100.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

class M0TX
{
public:
	M0TX() //默认构造函数
	{
		cout << "wodeceshi" << endl;
	}
};
class MATX
{
public:
	MATX() //默认构造函数
	{
		cout << "goodHAHAHAHA" << endl;
	}
};

class MBTX
{
public:
	int m_i;
	int m_j;

	M0TX m0;  //类类型成员变量
	MATX ma; //类类型成员变量
	

	void funct()
	{
		cout << "IAmVeryGood" << endl;
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
	MBTX myb; 

	//用dumpbin把.obj文件内容导出成可查看文件my.txt，这个my.txt格式，一般被认为是COFF：通用对象文件格式(Common Object File Format);
	//MBTX::MBTX
	//编译器会在哪些必要的时候帮助我们把默认的构造函数合成出来呢？
	//(1)该类MBTX没有任何构造函数，但包含一个类类型的成员ma,而该对象ma所属于的类MATX 有一个缺省的构造函数。
	    //这个时候，编译器就会为该类MBTX生成一个 “合成默认的构造函数”，合成的目的是为了调用MATX里的默认构造函数。
	 //换句话说：编译器合成了默认的MBTX构造函数，并且在其中 安插代码，调用MATX的缺省构造函数；




	return 1;
}

