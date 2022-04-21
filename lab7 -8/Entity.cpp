//
// Created by ivarg on 06.04.2022.
//

#include "Entity.h"
#include<iostream>
#include<cstring>
using namespace std;

Entity::Entity() {
    this->id = 0;
    this->nrap = 0;
    this->suma = 0;
    this->tip = nullptr;
}

Entity::Entity(int id, int nrap, int suma, const char *tip) {
    if (strcmp(tip, "apa") != 0 && strcmp(tip, "gaz") != 0 && strcmp(tip, "caldura") != 0 &&
        strcmp(tip, "electricitate") != 0 && strcmp(tip, "altele") != 0) {
        throw std::invalid_argument("Tip invalid");
    }
    if (nrap <= 0) {
        throw std::invalid_argument("Apartament invalid");
    }
    if (suma <= 0) {
        throw std::invalid_argument("Suma invalida");
    }
    this->id = id;
    this->nrap = nrap;
    this->suma = suma;
    this->tip = new char[strlen(tip) + 1];
    strcpy(this->tip, tip);
}

Entity::Entity(const Entity &entity) {
    this->id = entity.id;
    this->nrap = entity.nrap;
    this->suma = entity.suma;
    this->tip = new char[strlen(entity.tip) + 1];
    strcpy(this->tip, entity.tip);
}

Entity::~Entity(){
    delete [] this->tip;
    this->tip = nullptr;
}

int Entity::getId() const {
    return this->id;
}

int Entity::getNrap() const {
    return this->nrap;
}

int Entity::getSum() const {
    return this->suma;
}

char *Entity::getTip() const {
    return this->tip;
}

void Entity::setId(int id) {
    this->id = id;
}

void Entity::setNrap(int nrap) {
    this->nrap = nrap;
}

void Entity::setSum(int suma) {
    this->suma = suma;
}

void Entity::setTip(const char *tip) {
    delete[] this->tip;
    this->tip = new char[strlen(tip) + 1];
    strcpy(this->tip, tip);
}

bool Entity::operator==(const Entity &entity) const {
    return (entity.suma == this->suma) && (entity.nrap == this->nrap) && (strcmp(entity.tip, this->tip) == 0);
}

bool Entity::operator!=(const Entity &entity) const {
    return (entity.suma == suma) && (entity.nrap == nrap) && (strcmp(entity.tip, this->tip) == 0);
}

std::istream &operator>>(std::istream &is, Entity &entity) {
    std::cout << "id: " << "\n";
    is >> entity.id;
    std::cout << "nrap: " << "\n";
    is >> entity.nrap;
    std::cout << "suma: " << "\n";
    is >> entity.suma;
    std::cout << "tip: " << "\n";
    is >> entity.tip;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Entity &entity) {
    os << "id: " << entity.id << "\n" << "nrap: " << entity.nrap << "\n" << "suma: " << entity.suma << "\n" << "tip: "<< entity.tip << "\n";
    return os;
}

Entity &Entity::operator=(const Entity &e) {
    if (this != &e) {
        this->id = e.getId();
        this->nrap = e.getNrap();
        this->suma = e.getSum();
        delete [] this->tip;
        this->tip = new char[strlen(e.tip) + 1];
        strcpy(this->tip, e.tip);
    }
    return *this;
}