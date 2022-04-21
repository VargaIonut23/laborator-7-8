//
// Created by ivarg on 06.04.2022.
//

#ifndef LAB7_REPOSITORY_H
#define LAB7_REPOSITORY_H

#include<ostream>
#include"../Entity.h"
#include"../Vector.h"
#include <stack>

template<class T>
class Repository {
private:
    Vector<T> entities;
    std::stack<Vector<T>> undoStack;
    std::stack<Vector<T>> redoStack;
public:
    Repository() = default;

    ~Repository() = default;

    void addEntity(T entity){
        undoStack.push(entities);
        redoStack = std::stack<Vector<T>>();
        entities.push_back(entity);
    }

    Vector<T> getAll(){
    return entities;
    }

    T getEntity(int index){
        return entities.at(index);
    }

    int getSize(){
        return this->entities.size();
    }

    friend std::ostream &operator<<(std::ostream &os, const Repository<T> &repository){
        os << repository.entities;
        return os;
    }

    void remove(T entity){
        undoStack.push(entities);

        for (int i = 0; i < this->entities.size(); i++) {
            if (this->entities[i] == entity) {
                this->entities.remove(i);
                break;
            }
        }
        redoStack = std::stack<Vector<T>>();
    }

    void update(int index, T entity){
        undoStack.push(entities);
        redoStack = std::stack<Vector<T>>();

        this->entities.remove(index);
        this->entities.push_back(entity);
    }

    bool undo(){
        if (this->undoStack.empty()) {
            return false;
        }

        Vector<T> temp = this->undoStack.top();
        this->undoStack.pop();
        this->redoStack.push(this->entities);

        this->entities = temp;

        return true;
    }

    bool redo() {
        if (this->redoStack.empty()) {
            return false;
        }

        Vector<T> temp = this->redoStack.top();
        this->redoStack.pop();
        this->undoStack.push(this->entities);

        this->entities = temp;

        return true;
    }


};
#endif //LAB7_REPOSITORY_H
