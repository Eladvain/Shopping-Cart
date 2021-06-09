#ifndef _AT_H
#define _AT_H

template<class T>
class Array
{
public:
	int logic, physic,dynamic;
	T* arr;

public:
	
	Array(int size = 10,int Dynamic=0) 
	{
	logic = 0;
	physic = size;
	arr = new T[physic];
	dynamic = Dynamic;
	}
	~Array()
	{
		
		delete[] arr;
	}
	const Array<T>& operator+= (const T& newVal)
	{
		if (logic < physic)
		{
			arr[logic++] = newVal;
		}
		else
		{
			physic *= 2;
			T* newArr = new T[physic];
			for (int i = 0; i < logic; i++)
			{
				newArr[i] = arr[i];
			}
			newArr[logic++] = newVal;
			delete[] arr;
			arr = newArr;
		}
		return *this;
	}
	void print()
	{
		for (int i = 0; i < logic; i++)
		{
			arr[i].print();
		}
	}

};
#endif 