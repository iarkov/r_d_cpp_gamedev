#include "DynamicIntArray.h"
#include <iostream>

DynamicIntArray::DynamicIntArray(): m_size(0), m_array(new int[0] {}) {};

DynamicIntArray::DynamicIntArray(std::size_t size): m_size(size), m_array(new int[size] {}) {};

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) {

	m_size = other.m_size;
	m_array = new int[m_size];
	
	for (int i = 0; i < m_size; i++) {
		m_array[i] = other.m_array[i];
	}
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) {

	delete[] m_array; 

	m_size = other.m_size;
	m_array = new int[m_size];

	for (int i = 0; i < m_size; i++) {
		m_array[i] = other.m_array[i];
	}

	return *this;
}

DynamicIntArray::~DynamicIntArray() {
	delete[] m_array;
}

int& DynamicIntArray::operator[](std::size_t index) {
	return m_array[index];
}

void DynamicIntArray::setSize(std::size_t newSize) {
	std::size_t loopSize = (m_size < newSize) ? m_size : newSize;

	int* tmp = new int[newSize] {}; 

	for (int i = 0; i < loopSize; i++) {
		tmp[i] = m_array[i];
	}

	delete[] m_array;
	m_array = new int[newSize] {};

	for (int i = 0; i < loopSize; i++) {
		m_array[i] = tmp[i];
	}
	delete[] tmp;

	m_size = newSize;
}

std::size_t DynamicIntArray::getSize() const {
	return m_size;
}

void DynamicIntArray::clear() {
	delete[] m_array;

	m_size = 0; 
	m_array = new int[m_size] {};
}

void DynamicIntArray::push_back(int element) {
	int* tmp = new int[m_size + 1];

	for (int i = 0; i < m_size; i++) {
		std::cout << m_array[i] << " ";
		tmp[i] = m_array[i];
		std::cout << tmp[i] << " ";
	}
	delete[] m_array;

	tmp[m_size] = element;
	
	m_array = new int[m_size + 1] {};
	for (int i = 0; i < m_size + 1; i++) {
		m_array[i] = tmp[i];
	}
	delete[] tmp;

	m_size += 1;
};