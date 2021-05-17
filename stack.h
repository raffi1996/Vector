#ifndef STACK_H
#define STACK_H
#include "vector.h"


template <typename T>

class Stack : private Vector<T>{
	public:
		Stack() = default;
		~Stack() = default;
	
	void push(T);
	void pop();
	
	
	private:
		int sp = 0;	
};


#include "stack.tpp"  









#endif
