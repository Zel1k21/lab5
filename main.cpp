#include "Containers/MySet.h"

int main() 
{
	MySet<int> t1, t2, result;
	t1.addElement(7);
	t1.addElement(123);
	t1.addElement(23);
	t1.addElement(73);

	t2.addElement(7);
	t2.addElement(27);
	t2.addElement(2545);
	t2.addElement(73);
	std::cout << "array 1:" << t1 << ", array 2:" << t2 << std::endl << std::endl;
	std::cout << t1 << " + " << t2 << " => " << t1 + t2 << std::endl;
	std::cout << t1 << " - " << t2 << " => " << t1 - t2 << std::endl;
	std::cout << t1 << " * " << t2 << " => " << t1 * t2 << std::endl;
	std::cout << t1 << " == " << t2 << " => ";
	bool a = (t1 == t2);
	std::cout << a;

	
	return 0;
}