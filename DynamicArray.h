#pragma once
#include <cstdlib>

template<typename T>
class DynamicArray
{
public:
    //default c-tor
    DynamicArray();

    //c-tor with size
    DynamicArray(std::size_t size);

    //copy c-tor
    DynamicArray(const DynamicArray& other);

    //free allocated memory
    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);

    T& operator[](std::size_t index);

    //delete previous memory, create new inner array with updated size
    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    //Clear internal memory, set size to 0
    void clear();

	void reserve(std::size_t reservedSpace);
	std::size_t getCapacity() const;
	void shrinkToFit();

	void pop_back();
	T back() const;
	bool operator==(const DynamicArray& other) const;

    // Allocate new memory for new element
    // Copy old content to new inner array
    // insert element at the last index
    // update size
    void push_back(T element);

private:
    std::size_t m_size;
	std::size_t m_emptys;
    T* m_array;
};

template<typename T>
DynamicArray<T>::DynamicArray() : m_size(0), m_emptys(0), m_array(new T[]{}) {};

template<typename T>
DynamicArray<T>::DynamicArray(std::size_t size) : m_size(size), m_emptys(0), m_array(new T[size] {}) {};

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {

	m_size = other.m_size;
	m_emptys = other.m_emptys;
	m_array = new T[m_size];

	for (int i = 0; i < m_size; i++) {
		m_array[i] = other.m_array[i];
	}
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {

	if (m_array != other.m_array) {
		delete[] m_array;

		m_size = other.m_size;
		m_emptys = other.m_emptys;
		m_array = new T[m_size];

		for (int i = 0; i < m_size; i++) {
			m_array[i] = other.m_array[i];
		}
	}

	return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] m_array;
}

template <typename T>
T& DynamicArray<T>::operator[](std::size_t index) {
	return m_array[index];
}

template <typename T>
void DynamicArray<T>::setSize(std::size_t newSize) {
	if (m_size < newSize) {
		m_emptys = (this->getCapacity() < newSize) ? 0 : this->getCapacity() - newSize;

		T* tmp = new T[newSize]{};

		for (int i = 0; i < m_size; i++) {
			tmp[i] = m_array[i];
		}

		delete[] m_array;
		m_array = new T[newSize]{};

		for (int i = 0; i < m_size; i++) {
			m_array[i] = tmp[i];
		}
		delete[] tmp;

		m_size = newSize;
	}
}

template <typename T>
std::size_t DynamicArray<T>::getSize() const {
	return m_size;
}

template <typename T>
void DynamicArray<T>::clear() {
	delete[] m_array;

	m_size = 0;
	m_emptys = 0;
	m_array = new T[m_size] {};
}

template <typename T>
void DynamicArray<T>::push_back(T element) {
	if (m_emptys > 0) {
		m_array[this->getCapacity() - m_emptys] = element;
		m_emptys -= 1;
		m_size += 1;
	}
	else {
		T* tmp = new T[m_size + 1]{};

		for (int i = 0; i < m_size; i++) {
			tmp[i] = m_array[i];
		}
		delete[] m_array;

		tmp[m_size] = element;

		m_array = new T[m_size + 1]{};
		for (int i = 0; i < m_size + 1; i++) {
			m_array[i] = tmp[i];
		}
		delete[] tmp;

		m_size += 1;
	}
};

template <typename T>
void DynamicArray<T>::reserve(std::size_t reservedSpace) {
	if (reservedSpace > this->getCapacity()) {
		m_emptys += reservedSpace - m_size;

		T* tmp = new T[reservedSpace]{};

		for (int i = 0; i < m_size; i++) {
			tmp[i] = m_array[i];
		}
		delete[] m_array;

		m_array = new T[reservedSpace]{};
		for (int i = 0; i < m_size; i++) {
			m_array[i] = tmp[i];
		}
		delete[] tmp;
	}
}

template <typename T> 
std::size_t DynamicArray<T>::getCapacity() const {
	return m_size + m_emptys;
}

template <typename T>
void DynamicArray<T>::shrinkToFit() {
	if (m_size < this->getCapacity()) {
		m_emptys = 0;

		T* tmp = new T[m_size]{};

		for (int i = 0; i < m_size; i++) {
			tmp[i] = m_array[i];
		}
		delete[] m_array;

		m_array = new T[m_size]{};
		for (int i = 0; i < m_size; i++) {
			m_array[i] = tmp[i];
		}
		delete[] tmp;
	}
}

template <typename T>
T DynamicArray<T>::back() const {
	return m_array[m_size - 1];
}

template <typename T>
void DynamicArray<T>::pop_back() {
	if (m_size > 0) {
		T* tmp = new T[m_size - 1]{};

		for (int i = 0; i < m_size - 1; i++) {
			tmp[i] = m_array[i];
		}
		delete[] m_array;

		std::size_t newCapacity = m_emptys == 0 ? m_size - 1 : this->getCapacity();
		m_emptys = m_emptys > 0 ? m_emptys + 1 : 0;

		m_array = new T[newCapacity]{};
		for (int i = 0; i < m_size - 1; i++) {
			m_array[i] = tmp[i];
		}
		delete[] tmp;

		m_size -= 1;
	}
};

template <typename T> 
bool DynamicArray<T>::operator==(const DynamicArray& other) const {
	bool first_check = m_size == other.m_size && m_emptys == other.m_emptys;

	if (first_check) {
		for (int i = 0; i < m_size; i++) {
			if (m_array[i] != other.m_array[i]) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
};