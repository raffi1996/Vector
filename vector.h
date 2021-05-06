#ifndef VECTOR_H
#define VECTOR_H 
template <typename T>
class Vector{
	public:
		Vector();
		~Vector();
		
		Vector(int capacity);
		Vector(const Vector& oth);
		Vector& operator=(const Vector& oth);
		Vector& operator=(Vector&& oth);
		Vector operator+(Vector& oth);
		Vector(Vector&& oth);
		
		void push_back(T elem);
		void push_front(T elem);
		void pop_back();
		void pop_front();
		void insert (T value, int index);
		void erase();
		void reverse();
		void reserve(int capacity);
		T& operator[](int value);
		int size();
		bool empty();
		
	private:
		int m_capacity;
		int m_size;
		T* m_arr;
	
};

#include "vectorimpl.tpp"  









#endif
