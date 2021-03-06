
#include "pch.h"
#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>

using namespace std;

namespace _nmsp1 //命名空间
{		
	//一：对象的构造顺序
	//二：虚函数的继续观察
	//大家千万不要在构造函数中你自己的代码中使用诸如memcpy或者直接操作等手段，来修改虚函数表指针的值，否则，调用虚函数时就可能造成系统崩溃；
	//三：构造函数中对虚函数的调用
	//某个类的构造函数 中 调用一个虚函数，那么走的不是虚函数表，而是直接调用。
	//四：举一反三


	class A
	{
	public:
		A()
		{
			printf("A this = %p\n", this);
			cout << "A::A()" << endl;
		}
		virtual ~A() {}
		virtual void myvirfunc() {}
		virtual void myvirfunc2() {}
	};

	class B:public A
	{
	public:
		B()
		{
			printf("B this = %p\n", this);
			cout << "B::B()" << endl;
		}
		virtual ~B() {}
		virtual void myvirfunc() {}
		virtual void myvirfunc2() {}
	};

	class C:public B
	{
	public:
		C():m_c(11)
		{
			//memcpy(this,)
			myvirfunc(); //构造函数中，这里没有走虚函数表，而是直接通过虚函数地址，直接调用这个虚函数（静态方式调用）
			printf("C this = %p\n", this);
			cout << "C::C()" << endl;
		}
		virtual ~C() {}
		virtual void myvirfunc() { myvirfunc2(); }
		virtual void myvirfunc2() {}
		int m_c;

	};
	//---------------------
	void func()
	{
		//C cobj;
		C *mycobj = new C();
		mycobj->myvirfunc(); //代码实现上的多态，五章四节
				
			
	}
}

int main()
{
	
	_nmsp1::func();	
	return 1;
}



