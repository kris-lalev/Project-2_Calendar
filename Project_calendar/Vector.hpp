#include <iostream>

template <typename T>
class Vector {
private:
	T* arr;
	int curr_el;
	int capacity;
	void free();
	void copy_from(const Vector<T>& other);
	void resize();

public:
	Vector();
	Vector(const Vector& other);
	Vector<T>& operator=(const Vector<T>& other);
	~Vector();
	int size() const;
	int get_capacity() const;
	T& at(int index) const;
	void push_back(T element);
	void erase(int index);
	bool empty() const;
	void print() const;
	int find(T element) const;
};

template <typename T>
Vector<T>::Vector()
{
	capacity = 4;
	arr = new T[capacity];
	curr_el = 0;
}
template <typename T>
Vector<T>::Vector(const Vector& other)
{
	copy_from(other);
}
template <typename T>
void Vector<T>::copy_from(const Vector<T>& other)
{
	capacity = other.capacity;
	curr_el = other.curr_el;
	arr = new T[capacity];
	for (int i = 0; i < curr_el; i++)
	{
		arr[i] = other.arr[i];
	}
}
template <typename T>
void Vector<T>::free()
{
	delete[] arr;
}
template <typename T>
void Vector<T>::resize()
{
	capacity *= 2;
	T* new_arr = new T[capacity];
	for (int i = 0; i < curr_el; i++)
	{
		new_arr[i] = arr[i];
	}
	free();
	arr = new_arr;
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		free();
		copy_from(other);
	}
	return *this;
}
template <typename T>
Vector<T>::~Vector()
{
	free();
}
template <typename T>
int Vector<T>::size() const
{
	return curr_el;
}
template <typename T>
int Vector<T>::get_capacity() const
{
	return capacity;
}
template <typename T>
T& Vector<T>::at(int index) const
{
	if (index < 0 || index >= curr_el) {
		std::cerr << "Invalid index, output changed to the value of arr[0]" << std::endl;
		return arr[0];
	}
	return arr[index];
}
template <typename T>
void Vector<T>::push_back(T element)
{
	if (curr_el == capacity)
		resize();
	arr[curr_el] = element;
	curr_el++;
}
template <typename T>
void Vector<T>::erase(int index)
{
	if (index < 0 || index >= curr_el) {
		std::cerr << "Invalid index, no value here" << std::endl;
		return;
	}
	for (int i = index; i < curr_el - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	curr_el--;
}
template <typename T>
bool Vector<T>::empty() const
{
	if (curr_el)
		return false;
	return true;
}
template <typename T>
void Vector<T>::print() const
{
	for (int i = 0; i < curr_el; i++)
	{
		std::cout << arr[i] << " ";
	}
}
template <typename T>
int Vector<T>::find(T element) const
{
	for (int i = 0; i < curr_el; i++)
	{
		if (arr[i] == element)
			return i;
	}
	std::cerr << "The input value does not exist" << std::endl;
	return -1;
}