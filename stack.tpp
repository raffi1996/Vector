
template <typename T>

void Stack<T>::push(T elem){
	this->push_back(elem);
	++sp;
}

template <typename T>
void Stack<T>::pop(){
	this->pop_back();
	--sp;
}
