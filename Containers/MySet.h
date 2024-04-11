#include "MyVector.h"

template <class Information>
class MySet: public MyVector<Information>
{
public:
	MySet(Information inf = NULL) : MyVector<Information>(){};
	bool operator == (MySet&);
	MySet& operator += (MySet&);
	MySet& operator -= (MySet&);
	MySet& operator *= (MySet&);

	template <class U> 
	friend MySet<U> operator+(MySet<U>&, MySet<U>&);
	template <class U>
	friend MySet<U> operator-(MySet<U>&, MySet<U>&);
	template <class U>
	friend MySet<U> operator*(MySet<U>&, MySet<U>&);
};

template<class Information>
inline bool MySet<Information>::operator==(MySet& other)
{
	if (this->currentSize != other.currentSize)
		return false;
	for (int i = 0; i < this->currentSize - 1; i++)
		if (this->find(other.inf[i]) == -1)
			return false;
	return true;
}

template<class U>
inline MySet<U> operator+(MySet<U>& lhs, MySet<U>& rhs)
{
	MySet<U> result;
	for (int i = 0; i < lhs.currentSize; i++)
		result.addElement(lhs.inf[i]);
	for (int j = 0; j < rhs.currentSize; j++)
		if (result.find(rhs.inf[j]) == -1)
			result.addElement(rhs.inf[j]);
	return result;
}

template<class Information>
inline MySet<Information>& MySet<Information>::operator+=(MySet<Information>& source)
{
	*this = *this + source;
	return *this;
}

template<class U>
inline MySet<U> operator-(MySet<U>& lhs, MySet<U>& rhs)
{
	MySet<U> result = lhs;
	for (int i = 0; i < rhs.currentSize; i++)
		if (result.find(rhs.inf[i]) != -1)
			result.deleteElement(result.find(rhs.inf[i]) - 1);
	return result;
}

template<class Information>
inline MySet<Information>& MySet<Information>::operator-=(MySet<Information>& source)
{
	*this = *this - source;
	return *this;
}

template<class U>
inline MySet<U> operator*(MySet<U>& lhs, MySet<U>& rhs)
{
	MySet<U> result;
	for (int i = 0; i < lhs.currentSize; i++)
		if (lhs.find(lhs.inf[i]) != -1 && rhs.find(lhs.inf[i]) != -1)
			result.addElement(lhs.inf[i]);
	return result;
}

template<class Information>
inline MySet<Information>& MySet<Information>::operator*=(MySet<Information>& source)
{
	*this = *this * source;
	return *this;
}