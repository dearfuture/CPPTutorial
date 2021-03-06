
#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>
using namespace std;

namespace _nmsp1
{
	//一：拷贝构造函数相关的临时性对象
	class A
	{
	public:
		A()
		{
			cout << "A::A()构造函数被执行" << endl;
		}
		A(const A& tmpobj)
		{
			cout << "A::A()拷贝构造函数被执行" << endl;
		}
		~A()
		{
			cout << "A::~A()析构函数被执行" << endl;
		}
	};

	A operator+(const A& obj1, const A& obj2)
	{
		A tmpobj; 

		printf("tmpobj的地址为%p\n", &tmpobj);
		printf("---------------------\n");
		//.....
		return tmpobj; //编译器产生临时对象，把tmpobj对象的内容通过调用拷贝构造函数 把tmpobj的内容拷贝构造给这个临时对象；
		                      //然后返回的是这个临时对象；

	}

	void func()
	{			
		A myobj1;
		printf("myobj1的地址为%p\n", &myobj1);

		A myobj2;
		printf("myobj2的地址为%p\n", &myobj2);

		A resultobj = myobj1 + myobj2; //这个从operator +里返回的临时对象直接构造到了resultobj里；
		printf("resultobj的地址为%p\n", &resultobj);

		return;			
	}
}
namespace _nmsp2
{
	//二：拷贝赋值运算符相关的临时性对象
	class A
	{
	public:
		A()
		{
			cout << "A::A()构造函数被执行" << endl;
		}
		A(const A& tmpobj)
		{
			cout << "A::A()拷贝构造函数被执行" << endl;
		}

		A & operator=(const A& tmpaobj)
		{
			cout << "A::operator()拷贝赋值运算符被执行" << endl;

			printf("拷贝赋值运算符中tmpaobj的地址为%p\n", &tmpaobj);
			return *this; 
		}

		~A()
		{
			cout << "A::~A()析构函数被执行" << endl;
		}
	};

	A operator+(const A& obj1, const A& obj2)
	{
		A tmpobj;

		printf("tmpobj的地址为%p\n", &tmpobj);
		//printf("---------------------\n");
		//.....
		return tmpobj; //编译器产生临时对象，把tmpobj对象的内容通过调用拷贝构造函数 把tmpobj的内容拷贝构造给这个临时对象；
							  //然后返回的是这个临时对象；

	}

	void func()
	{
		A myobj1;
		printf("myobj1的地址为%p\n", &myobj1);

		A myobj2;
		printf("myobj2的地址为%p\n", &myobj2);

		A resultobj;
		resultobj = myobj1 + myobj2;	//拷贝赋值运算符

		//A resultobj = myobj1 + myobj2; //拷贝构造函数

		printf("resultobj的地址为%p\n", &resultobj);

		return;
	}
	
}
namespace _nmsp3
{
	//三：直接运算产生的临时性对象
	//（3.1）临时对象被摧毁
	//（3.2）临时对象因绑定到引用而被保留
	class A
	{
	public:
		A()
		{
			cout << "A::A()构造函数被执行" << endl;
		}
		A(const A& tmpobj)
		{
			cout << "A::A()拷贝构造函数被执行" << endl;
			m_i = tmpobj.m_i;
		}

		A & operator=(const A& tmpaobj)
		{
			cout << "A::operator()拷贝赋值运算符被执行" << endl;			
			return *this;
		}

		~A()
		{
			cout << "A::~A()析构函数被执行" << endl;
		}
		int m_i;
	};

	A operator+(const A& obj1, const A& obj2)
	{
		A tmpobj;
		tmpobj.m_i = obj1.m_i + obj2.m_i;
		
		return tmpobj; //编译器产生临时对象，把tmpobj对象的内容通过调用拷贝构造函数 把tmpobj的内容拷贝构造给这个临时对象；
							  //然后返回的是这个临时对象；

	}

	void func()
	{
		/*A myobj1;
		myobj1.m_i = 1;

		A myobj2;		
		myobj2.m_i = 2;*/
		
		//A resultobj = myobj1 +myobj2;
		//myobj1 + myobj2; //产生了临时对象，然后该临时对象立即被析构；
		//printf("(myobj1 + myobj2).m_i = %d\n", (myobj1 + myobj2).m_i); //临时对象的析构是整行语句的最后一步，这样就能保证printf打印出来一个有效值；

		//A tmpobja1 = (myobj1 + myobj1); 编译器要往必要的地方，帮助我们插入代码，来产生临时对象供编译器完成我们程序开发者代码要实现的意图；
		/*if ((myobj1 + myobj1).m_i > 1 || (myobj1 + myobj2).m_i > 5)
		{
			int abc;
			abc = 4;
		}*/

		//const char *p = (string("123") + string("456")).c_str(); //这一行有问题，因为临时对象过了这行就被摧毁；

		//string aaa = (string("123") + string("456"));
		//const char *q = aaa.c_str();   //这个应该OK

		//printf("p = %s\n", p); 
		//printf("q = %s\n", q);

		const string &aaa = string("123") + string("456");
		printf("aaa = %s\n", aaa.c_str());




		return;
	}
}

int main()
{	
	//_nmsp1::func();	
	//_nmsp2::func();
	_nmsp3::func();
	return 1;
}



