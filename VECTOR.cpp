#include "VECTOR.h"
#include <stdexcept>
//  //defoult ctor:

 Vector::Vector() {
    m_size = 0;
    m_capasity = 0;
    m_ptr = nullptr;
}
//parametr ctot:
 Vector::Vector(int capasity) {
    m_size = 0;
    m_capasity = capasity;
    m_ptr = new int[capasity];
}
 //copy ctor:
 Vector::Vector(const Vector& other) {
    m_size = other.m_size;
    m_capasity = other.m_capasity;
    if (other.m_ptr == nullptr) {
        m_ptr = nullptr;
    } else {
        m_ptr = new int [m_capasity];
        for (int i = 0; i < m_size; ++i) {
            m_ptr[i] = other.m_ptr[i];
        }
    }
}
//move ctor
 Vector::Vector(Vector&& other)noexcept {
   m_size = other.m_size;
   m_capasity = other.m_capasity;
   m_ptr = other.m_ptr;

   other.m_size = 0;
   other.m_capasity = 0;
   other.m_ptr = nullptr;
 }
  
//copy operator= 
Vector& Vector::operator=(const Vector& other) {
    if (this == &other){
        return *this;
    }

    if (m_ptr != nullptr){
        delete [] m_ptr;
    }

    m_size = other.m_size;
    m_capasity = other.m_capasity;
    if (other.m_ptr == nullptr){
        m_ptr = nullptr;
        return *this;
    }
    
    m_ptr = new int [other.m_capasity];
    for (int i = 0; i < m_size; ++i){
        m_ptr[i] = other.m_ptr[i];
    }
   return *this;
}

//size
int Vector::size() {
    return m_size;
}

//capasity
int Vector::capacity() {
    return m_capasity;
}

 //move operator=
 Vector& Vector::operator=(Vector&& other) {
    if (this == &other) {
        return  *this;
    }
    
    
    m_size = other.m_size;
    m_capasity = other.m_capasity;
    if (m_ptr != nullptr) {
        delete [] m_ptr;
    }

    m_ptr = other.m_ptr;

    other.m_size = 0;
    other.m_capasity = 0;
    other.m_ptr = nullptr;

    return *this;
 }

//operator []
 int& Vector::operator[](int index){
    return m_ptr[index];
 }

//push_pack
void Vector::push_back(int object) {
    insert(m_size, object);
}

 //push_front
void Vector::push_front(int object) {
    insert(0, object);
}

//insert
 void Vector::insert(int index, int object) {
    if (index < 0 || index > m_size) {
        throw std::out_of_range("error");
    }
    if (m_ptr == nullptr) {
        m_size = 0;
        m_capasity = 1;
        m_ptr = new int [m_capasity];
    }
    if (m_size == m_capasity) {
        m_capasity *=2;
        int* ptr = new int [m_capasity];
        for (int i = 0; i < m_size; ++i) {
            ptr[i] = m_ptr[i];
        }
        delete [] m_ptr;
        m_ptr = ptr;
    }
    for (int i = m_size - 1; i > index; --i) {
        m_ptr[i] = m_ptr[i - 1];
    }
    m_ptr[index] = object;
    m_size += 1;
 }

 //pop_back
 void Vector::pop_back() {
    if (m_size == 0) {
        return;
    }
    --m_size;
    if (m_size < m_capasity / 2) {
        m_capasity /= 2;
        int* ptr = new int [m_capasity];
        for (int i = 0; i < m_size; ++i) {
            ptr[i] = m_ptr[i];
        }
        delete [] m_ptr;
        m_ptr = ptr;
    }
 }

 //at 
 int& Vector::at(int index) {
    if (index < 0 || index >= m_size){
        throw std::out_of_range("error");
    }
    return m_ptr[index];
 }

// Destructr
Vector::~Vector() {
    if (m_ptr != nullptr) {
        delete [] m_ptr;
    }
}
