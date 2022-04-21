//
// Created by ivarg on 06.04.2022.
//

#ifndef LAB7_VECTOR_H
#define LAB7_VECTOR_H

#include<ostream>
#include"Entity.h"
#include<iostream>

template<class T>
class Vector {
private:
    int Size = 1024;
    T *_entities;
    int _capacity = 1024;
    int _size = 0;

    void resize();

public:
    Vector();

    ~Vector();

    void push_back(T const &entity);

    int size() const;

    T &operator[](int index) const;

    friend std::ostream &operator<<(std::ostream &os, const Vector<Entity> &vector);

    void remove(unsigned int index);

    Entity front();

    T at(int idex) const;

    Vector(const Vector<T> &vector);

    Vector<T> &operator=(const Vector<Entity> &vector);

};

template<class T>
Vector<T>::Vector() {
    this->_entities = new T[Size];
}

template<class T>
Vector<T>::Vector(const Vector<T> &vector) {
    this->_entities = new T[vector._capacity];
    this->_capacity = vector._capacity;
    this->_size = vector._size;
    for (int i =0; i< vector._size; i++){
        this->_entities[i] = vector._entities[i];
    }
}

template<class T>
Vector<T>::~Vector() {
    delete[] this->_entities;
}

template<class T>
void Vector<T>::resize() {
    T *temp = new T[this->_capacity + Size];
    for (int i = 0; i< this->_size; i++){
        temp[i] = this->_entities[i];
    }
    delete[] this->_entities;
    this->_entities = temp;
    this->_capacity += Size;
}

template<class T>
void Vector<T>::push_back(T const &entity) {
    if (this->_size == this->_capacity) {
        this->resize();
    }
    this->_entities[this->_size++] = entity;
}

template<class T>
int Vector<T>::size() const {
    return this->_size;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const Vector<Entity> &vector) {
    for (int i = 0; i < vector.size(); i++)
        os << vector[i] << '\n';
    return os;
}

template<class T>
void Vector<T>::remove(unsigned int index) {
    if (index >= this->_size) {
        return;
    }
    for (unsigned int i = index; i < this->_size - 1; i++) {
        this->_entities[i] = this->_entities[i + 1];
    }
    this->_size--;
}

template<class T>
Entity Vector<T>::front() {
    return this->_entities[_size];
}

template<class T>
Vector<T> &Vector<T>::operator=(const Vector<Entity> &vector) {
    if(this != &vector){
        delete[] this->_entities;
        this->_entities = new T[vector._capacity];
        this->_capacity = vector._capacity;
        this->_size = vector._size;
        for (int i = 0;i< vector._size;i++){
            this->_entities[i] = vector._entities[i];
        }
    }
    return *this;
}

template<class T>
T &Vector<T>::operator[](int index) const {
    return this->_entities[index];
}

template<class T>
T Vector<T>::at(int index) const{
    return this->_entities[index];
}

#endif //LAB7_VECTOR_H
