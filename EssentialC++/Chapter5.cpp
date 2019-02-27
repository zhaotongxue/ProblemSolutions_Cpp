/*
Object-Oriented Programmming.
*/

#include <iostream>
#include <typeinfo>
using namespace std;
class parent
{
  public:
	parent(int i) { printf("parent constructor,number is %d\n", i); }
	virtual void virtual_method();
	void method();
	// General Rules
	// virtual ~parent();
	inline ~parent() { printf("parent deconstructor\n"); }
	void only_parent() { printf("Only parent have\n"); }
	virtual void virtual_only_parent() { printf("Virtual Only parent have\n"); }
	void public_method() { printf("parent's public method\\"); }

  protected:
	// virtual void virutal_protected_method();
	void protected_method();
};
void parent::virtual_method() { printf("parent executes virutal method\n"); }
// void parent::vritual_protected_method() { printf("parent executes virutal protected method\n"); }
class child : public parent
{
  public:
	child(int i);
	virtual void virtual_method();
	void public_method() { printf("child's public method\n"); }
	// call child's public_method;
	// void call_parent() { public_method(); }
	// call parent's public method;
	void call_parent() { parent::public_method(); }
	child(const child &rhs);
	child &operator!=(const child &rhs);

  protected:
	virtual void virtual_protected_method();
	int number;
};
void child::virtual_method() { printf("Childe executes parent's virtual method\n"); }
void child::virtual_protected_method() { printf("Child execute parent's vitual protected method\n"); }
child &child::operator!=(const child &rhs)
{
	printf("copied");
	return *this;
}
child::child(int i) : parent(i)
{
	this->number = i;
	printf("child constructor,number is %d\n", i);
}
child::child(const child &rhs) : parent(rhs.number) { printf("child's copy constructor\n"); }
int main()
{
	child c(10);
	c.virtual_method();
	child e = c;
	// false,parent class is not the type of child classes.
	printf("e==child??%d\n", (typeid(e) == typeid(parent)));
	// ture
	printf("e==child??%d\n", (typeid(e) == typeid(child)));
	/*
	c.only_parent();
	c.virtual_only_parent();
	*/
	c.call_parent();

	// parent p;
	// p.virtual_method();
	return 0;
}
