#include <iostream>
#include "ClassTest.h"
ParentClass::ParentClass(string name)
{
	std::cout << "构造函数正在执行" << endl;
	std::cout << this << endl;
	ParentClass::publicString = name + " public";
	ParentClass::protectedString = name + " protected";
	ParentClass::privateString = name + " private";
}

ParentClass::ParentClass(const ParentClass & p)
{
	std::cout <<"复制构造函数执行"<< this << endl;
}

ParentClass::~ParentClass()
{
	std::cout << "parent class destory"<<endl;
	std::cout << this << endl;
}

string ParentClass::publicMethod()
{
	std::cout << publicString << endl;
	return string();
}

string ParentClass::protectedMethod()
{
	std::cout << protectedString << endl;
	return string();
}

string ParentClass::privateMethod()
{
	std::cout << privateString << endl;
	return string();
}
