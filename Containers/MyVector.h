#include <iostream>
#include <iomanip>

const int MAX_SIZE = 5;

template <class Information>

class MyVector
{
	typedef class MyVector<Information> Vector;
protected:
	Information *inf;
	int maxSize;
	int currentSize;
	void resize();
public:
	MyVector() : inf(nullptr), maxSize(MAX_SIZE), currentSize(0) {};
	MyVector(MyVector&);
	~MyVector() { delete[] inf; }
	void addElement(Information);
	void deleteElement(int);
	Information operator [] (int i);
	void sort();
	int getSize() { return currentSize; }
	int getMaxSize() { return maxSize; }
	int find(Information);
	MyVector<Information>& operator = (MyVector<Information>&);
	template<class U>
	friend std::ostream& operator <<(std::ostream&,const MyVector<U>&);
};

template<class Information>
inline void MyVector<Information>::resize()
{
	if (currentSize > maxSize)
		maxSize *= 2;
	else if (maxSize / 2 > currentSize)
		maxSize /= 2;
	Information* temp = new Information[maxSize];
	for (int i = 0; i < currentSize - 1; i++)
		temp[i] = this->inf[i];
	delete[] inf;
	inf = temp;
}

template<class Information>
inline MyVector<Information>::MyVector(MyVector& other)
{
	maxSize = MAX_SIZE;
	currentSize = other.currentSize;
	inf = new Information[currentSize];
	for (int i = 0; i < other.currentSize; i++) {
		inf[i] = other.inf[i];
	}
}

template<class Information>
inline void MyVector<Information>::addElement(Information elem)
{
	currentSize += 1;
	resize();
	inf[currentSize - 1] = elem;
}

template<class Information>
inline void MyVector<Information>::deleteElement(int ignore)
{
	for (int i = ignore; i < currentSize - 1; i++)
		inf[i] = inf[i + 1];
	resize();
	currentSize -= 1;
}

template<class Information>
inline Information MyVector<Information>::operator[](int i)
{
	return *(inf + i);
}

template<class Information>
inline void MyVector<Information>::sort()
{
	for (int i = 0; i < currentSize - 1; i++)
		for (int j = i + 1; j < currentSize; j++)
			if (inf[i] > inf[j])
				std::swap(inf[i], inf[j]);
}

template<class Information>
inline int MyVector<Information>::find(Information element)
{
	for (int i = 0; i < currentSize; i++)
		if (inf[i] == element)
			return i + 1;
	return -1;
}

template<class Information>
inline MyVector<Information>& MyVector<Information>::operator=(MyVector<Information>& source)
{
	this->currentSize = 0;
	delete[] inf;
	inf = new Information[currentSize];
	for (int i = 0; i < source.currentSize; i++)
		this->addElement(source.inf[i]);
	return *this;
}

template<class U>
inline std::ostream& operator<<(std::ostream& out, const MyVector<U>& el)
{
	if (el.currentSize == 0)
		return out;
	out << '{';
	for (int i = 0; i < el.currentSize - 1; i++)
		out << el.inf[i] << ", ";
	out << el.inf[el.currentSize - 1];
	out << '}';
	return out;
}
