
#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>

using namespace std;

namespace _nmsp1 //命名空间
{	
	//一：对象的默认复制行为
	//如果我们不写自己的拷贝构造函数和拷贝赋值运算符，编译器也会有默认的对象拷贝和对象赋值行为；

	//二：拷贝赋值运算符，拷贝构造函数
	//当我们提供自己的拷贝赋值运算符和拷贝构造函数时，我们就接管了系统默认的拷贝行为，此时，我们有责任在拷贝赋值运算符和拷贝构造函数中写适当的代码，来完成对象的拷贝或者赋值的任务；

	//三：如何禁止对象的拷贝构造和赋值：把拷贝构造函数和拷贝赋值运算符私有起来，只声明，不需要些函数体；


	class A
	{
	public:
		int m_i, m_j;

		A() {} //缺省构造函数

	private:
		A & operator=(const A &tmp); //拷贝赋值运算符
		/*{
			m_i = tmp.m_i;
			m_j = tmp.m_j;
			return *this;
		}*/
		A(const A& tmp);  //拷贝构造函数
		/*{
			m_i = tmp.m_i;
			m_j = tmp.m_j;
		}*/
		
	};
	
	void func()
	{
		A aobj;
		aobj.m_i = 15;
		aobj.m_j = 20;

		//A aobj2 = aobj; //执行拷贝构造函数(如果你写了拷贝构造函数)
		A aobj2;

		A aobj3;
		aobj3.m_i = 13;
		aobj3.m_j = 16;
		//aobj2 = aobj3; //执行拷贝赋值运算符（如果你写了拷贝赋值运算符）
		
			
	}
}
namespace _nmsp2
{
	//四：析构函数语义
	//（4.1）析构函数被合成
	//什么情况下编译器会给我们生成一个析构函数？
	//a)如果继承一个基类，基类中带析构函数，那么编译器就会给咱们A合成出一个析构函数来调用基类JI中的析构函数
	//b)如果类成员是一个类类型成员，并且这个成员带析构函数，编译器也会合成出一个析构函数，这个析构函数存在的意义是要调用m_j这个类类型成员所在类的析构函数；

	//（4.2）析构函数被扩展
	//如果我们有自己的析构函数，那么编译器就会在适当的情况下扩展我们的析构函数代码；
	//a)如果类成员m_j是一个类类型JI成员，并且这个成员m_j带析构函数~JI()，编译器扩展类A的析构函数~A()代码
	//先执行了类A的析构函数代码，再执行JI的析构函数代码
	//b)如果继承一个基类，基类中带析构函数，那么编译器就会扩展咱们类A的析构函数来调用基类JI中的析构函数

	//虚基类：留给大家探索；虚基类会带来更多的复杂性，也会程序执行效率有一定的影响；

	
	class JI
	{
	public:
		JI()
		{
			cout << "JI::JI()" << endl;
		}
		virtual ~JI()
		{
			cout << "JI::~JI()" << endl;
		}
	};
	class A :public JI
	{
	public:
		//JI m_j; //类类型成员变量
		A()
		{
			cout << "A::A()" << endl;
		}
		virtual ~A()
		{
			cout << "A::~A()" << endl;
		}
	};

	void func()
	{
		A aobj;

	}
}

int main()
{	
	//_nmsp1::func();	
	_nmsp2::func();
	return 1;
}



