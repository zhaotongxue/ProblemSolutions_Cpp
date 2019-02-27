#include <cstdio>
using namespace std;
class my_iterator
{
	// friend int my_iterator::operator*();
	// friend void my_iterator::check_integrity();

  public:
	my_iterator(int index) : _index(index - 1){};
	bool operator==(const my_iterator &) const;
	bool operator!=(const my_iterator &) const;
	int operator*(const my_iterator &rhs);
	my_iterator &operator++();	// prefix
	my_iterator &operator++(int); // postfix
  private:
	void check_integrity();
	int _index;
};

inline bool my_iterator::operator==(const my_iterator &rhs) const { return _index == rhs._index; }
inline bool my_iterator::operator!=(const my_iterator &rhs) const { return _index != rhs._index; }
// inline int my_iterator::operator*(const my_iterator &rhs) const
inline int my_iterator::operator*(const my_iterator &rhs)
{
	check_integrity();
	// return my_iterator::
}
int main() {}