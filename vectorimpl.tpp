//DEFAULT
template <typename T>
Vector<T>::Vector()
{
	 m_capacity = 4; 
	 m_size = 0; 
	 m_arr = new T[m_capacity];
}

//PARAMETER
template <typename T>
Vector<T>::Vector(int capacity)
{
	m_capacity = capacity;
	m_size = capacity;
	m_arr = new T[m_capacity];
	
}


//COPY 
template <typename T>
Vector<T>::Vector(const Vector& oth)
{	
	this->m_capacity = oth.m_capacity;
	this->m_size = oth.m_size;
	this->m_arr = new T[this->m_capacity];
	for(int i = 0; i < this->m_size; ++i){
		this->m_arr[i] = oth.m_arr[i];
	}
	
}

//OPERATOR = 
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& oth){
	if(this == &oth){
		return *this;
	}
	delete[] m_arr;
	m_capacity = oth.m_capacity;
	m_size = oth.m_size;
	m_arr = new T[m_capacity];
	for(int i = 0; i < m_size; ++i){
		m_arr[i] = oth.m_arr[i];
	}
	
	return *this;
}


//OPERATOR MOVE
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& oth)
{
	this->m_capacity = oth.m_capacity;
	this->m_size = oth.m_size; 
	delete[]this-> m_arr;
	this->m_arr = oth.m_arr;
	oth.m_arr = nullptr;
	oth.m_capacity = 0;
	oth.m_size = 0;
	return *this;
}

//OPERATOR +
template <typename T>
Vector<T> Vector<T>::operator+(Vector& oth){
	Vector<T> result;
	for(int i = 0; i < this->m_size; ++i){
		result.push_back(this->m_arr[i]);
	}
	for(int i = 0; i < oth.m_size; ++i){
		result.push_back(oth.m_arr[i]);
	}
	
	return result;
}

//MOVE CONSTRUCTOR
template <typename T>
Vector<T>::Vector(Vector&& oth){
	this->m_capacity = oth.m_capacity;
	this->m_size = oth.m_size; 
	this->m_arr = oth.m_arr;
	oth.m_arr = nullptr;
	oth.m_capacity = 0;
	oth.m_size = 0;
}

//DESTRUCTOR
template <typename T>
Vector<T>::~Vector()
{
	delete[] m_arr;
}

//PUSH BACK
template <typename T>
void Vector<T>::push_back(T elem)
{
	if(m_size == m_capacity){
		m_capacity *= 2;
		T *tmp = new T[m_capacity];
		for(int i = 0; i < m_size; ++i){
			tmp[i] = m_arr[i];
		}
		delete [] m_arr;
		m_arr = tmp;
	}
	 m_arr[m_size] = elem;
	 m_size += 1 ;
}

//OPERATOR []
template <typename T>
T& Vector<T>::operator[](int value){
	
	try {
		if(value <= m_size){
			return m_arr[value];
		}
		else{
			throw value;
		}
		
	}catch(int value){
		std::cout<<"throw new error: your index "<<value <<" is bigger than your size"<<std::endl;
		return m_arr[m_capacity + 3];
	}
	
}

//SIZE
template <typename T>
int Vector<T>::size(){
	return m_size;
}

//PUSH FRONT
template <typename T>
void Vector<T>::push_front(T elem){
	if(m_size == m_capacity){
		m_capacity *= 2;
		T *tmp = new T[m_capacity];
		for(int i = 0; i < m_size; ++i){
			tmp[i + 1] = m_arr[i];
		}
		delete [] m_arr;
		m_arr = tmp;
	}
	else if(m_size < m_capacity){
		for(int i = m_size; i > 0; --i){
			 m_arr[i] = m_arr[i - 1];
		}
	}
	m_arr[0] = elem;
	m_size += 1;
}

//POP BACK
template <typename T>
void Vector<T>::pop_back(){
	--m_size;
}

//POP FRONT
template <typename T>
void Vector<T>::pop_front(){
	T *tmp = new T[m_capacity];
	for(int i = 1; i < m_size; ++i){
		tmp[i - 1] = m_arr[i];
	}
	delete [] m_arr;
	
	m_arr = tmp;
	m_size -= 1;
	m_capacity -= 1;
}

//INSERT
template <typename T>
void Vector<T>::insert(T value , int index){
	try{
		if(m_capacity >=  index){
			if(m_size <= m_capacity){
			m_capacity *= 2;
			T *tmp = new T[m_capacity];
		for(int i = 0; i < m_size; ++i){
			tmp[i] = m_arr[i];
		}
		
		for(int i = m_size; i > index; --i){
			tmp[i] = m_arr[i - 1];
		}
		delete [] m_arr;
		
		tmp[index] = value;
		m_arr = tmp;
		m_size += 1; 
	}	
			
	  }else{
	  	throw index;
	  }
	
	}catch(int index){
		std::cout<< "throw new error: the index " <<index<<" is very large in insert function"<< std::endl;
	}
}

//ERASE
template <typename T>
void Vector<T>::erase(){
	for(int i = 0; i < m_size; ++i){
		m_arr[i] = 0;
	}
		
	m_size = 0;
}

//EMPTY
template <typename T>
bool Vector<T>::empty(){
	
	if(m_size <= 0){
		return false;
	}else{
		return true;	
	}
}

template <typename T>

//REVERSE
void Vector<T>::reverse(){
	T* tmp = new T[m_capacity]; 
	for(int i = 0; i < m_size; ++i){
		tmp[i] = m_arr[(m_size - 1) - i]; 
	}
	delete [] m_arr;
	m_arr = tmp;
}

//RESERVE
template <typename T>
void Vector<T>::reserve(int capacity){
	m_capacity = capacity;
	T* tmp = new T[m_capacity];
	for(int i = 0; i < m_size; ++i){
		tmp[i] = m_arr[i];
	}
	delete[] m_arr;
	m_arr = tmp;
}




