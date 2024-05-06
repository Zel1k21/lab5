#include "Containers/MySet.h"
#include <locale>

int main() 
{
    setlocale(LC_ALL, "RUSSIAN");
    MyVector<int> ab;
    MySet<int> ba;
    ab.addElement(2);
    ab.addElement(2);
    ab.deleteElement(10);
    ba.addElement(2);
    ba.addElement(2);
    ba.delete_Element(2);
    std::cout << ab << ' ' << ba << std::endl;

	MySet<int> t1, t2, result;
	t1.addElement(7);
	t1.addElement(123);
	t1.addElement(23);
	t1.addElement(73);

	t2.addElement(7);
	t2.addElement(27);
	t2.addElement(2545);
	t2.addElement(73);
	//std::cout << "array 1:" << t1 << ", array 2:" << t2 << std::endl << std::endl;
	//std::cout << t1 << " + " << t2 << " => " << t1 + t2 << std::endl;
	//std::cout << t1 << " - " << t2 << " => " << t1 - t2 << std::endl;
    //std::cout << t2 << " - " << t1 << " => " << t2 - t1 << std::endl;
	//std::cout << t1 << " * " << t2 << " => " << t1 * t2 << std::endl;
	//std::cout << t1 << " == " << t2 << " => ";
	bool a = (t1 == t2);
	//std::cout << a;

    MyVector<char*> v;
    v.addElement("������!");
    v.addElement("������!");
    v.addElement("������!");
    v.addElement("������!");
    v.addElement("������!");
    std::cout << "������ v: " << v << std::endl;
    v.addElement("������!");
    v.addElement("������!");
    v.addElement("������!");
    std::cout << "������ v: " << v << std::endl;
    MyVector<char*> v1 = v;
    std::cout << "������ v1: " << v1 << std::endl;
    for (int i = 0; i < MAX_SIZE; i++)
        v1.deleteElement(0);
    std::cout << "������ v1: " << v1 << std::endl;
    MySet <char*> s, s1, s2;
    s.addElement("������!");
    s.addElement("No");
    char* str = "Hello!";
    s.addElement(str);
    std::cout << "��������� s: " << s << std::endl;
    s1.addElement("Cat");
    s1.addElement("No");
    s1.addElement("������!");
    std::cout << "��������� s1: " << s1 << std::endl;
    s2 = s1 - s;
    std::cout << "��������� s2=s1-s: " << s2 << std::endl;
    std::cout << "��������� s1: " << s1 << std::endl;
    std::cout << "��������� s: " << s << std::endl;
    s2 = s - s1;
    std::cout << "��������� s2=s-s1: " << s2 << std::endl;
    std::cout << "��������� s1: " << s1 << std::endl;
    std::cout << "��������� s: " << s << std::endl;
    s2 = s1 + s;
    std::cout << "��������� s2=s1+s: " << s2 << std::endl;
    std::cout << "��������� s1: " << s1 << std::endl;
    std::cout << "��������� s: " << s << std::endl;
    s2 = s1 * s;
    std::cout << "��������� s2=s1*s: " << s2 << std::endl;
    std::cout << "��������� s1: " << s1 << std::endl;
    std::cout << "��������� s: " << s << std::endl;
    MySet<char*> s3 = s2;
    std::cout << "��������� s3=s2: " << s3 << std::endl;
    if (s3 == s2)
        std::cout << "��������� s3=s2\n";
    else
        std::cout << "��������� s3!=s2\n";
    if (s3 == s1)
        std::cout << "��������� s3=s1\n";
    else
        std::cout << "��������� s3!=s1\n";
    if (s1 == s3)
        std::cout << "��������� s1=s3\n";
    else
        std::cout << "��������� s1!=s3\n";
    return 0;

	
	return 0;
}