//没有virtual的时候，对象的类型决定了调用object方法：同一个子类型object，父引用调用父类方法（并且不能调用子类方法，他只是截取了一部分子类对象），子引用调用子类方方法。
//有virutal的时候，父类指针可以调用子类object的指定member
//只有通过引用或者指针*p=new
// child/&p=child才能够有多态的性质，直接复制构造的话不行，直接复制构造的话，相当于把子类所包含的父类给copy了一下
//普通方法不占用空间,virtual
//下面的那些都是没有理解清楚，其实本质上就是会对齐字节而已，我的机器是64位=8byte的，所以会自动补到8.
/*
//占用8个空间(不过即使有很多virtual也只占用一个8byte的空间),添加数据类型的时候，每次加上两个数据类型的长度，只有不够的时候才会继续加,每次依旧是2个数据类型的长度。
//父类public的成员的 数据成员会全部被继承下来，大小同上
//父类private的成员的 数据成员会全部被继承下来，大小同上
*/
#include <cstdio>
using namespace std;
class parent
{
  public:
	int a;
	char c, d;
	void self() { printf("parent\n"); }
	virtual void vself() { printf("v parent\n"); }
	virtual void test2() { printf("aaaa"); };

  private:
	int e, f;
};
class child : public parent
{
  public:
	int a, b, c, d, e, f;
	void self() { printf("child\n"); }
	void vself() { printf("v child\n"); }
};
int main()
{
	parent *p = new child;
	child *c = new child;
	/*
	p->self();  // assume "parent"
	c->self();  // assume "child"
	p->vself(); // assume "v child"
	c->vself(); // assume "v child"
	//all right above
	*/
	child ca;
	parent pa1 = ca;
	parent &pa2 = ca;
	/*
	pa1.self();  // parent
	pa2.self();  // parent
	ca.self();   // child
	pa1.vself(); // parent
	pa2.vself(); // child
	ca.vself();  // child
	*/
	printf("%d %d\n", sizeof(pa1), sizeof(ca));
	return 0;
}