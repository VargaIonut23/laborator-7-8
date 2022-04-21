//
// Created by ivarg on 06.04.2022.
//

#ifndef LAB7_ENTITY_H
#define LAB7_ENTITY_H

#include"ostream"

class Entity {
private:
    int id;
    int nrap;
    int suma;
    char *tip;
public:
    Entity();

    Entity(int id, int nrap, int suma, const char *tip);

    Entity(const Entity &entity);

    ~Entity();

    int getId() const;

    int getNrap() const;

    int getSum() const;

    char *getTip() const;

    void setId(int id);

    void setNrap(int nrap);

    void setSum(int suma);

    void setTip(const char *tip);

    bool operator==(const Entity &entity) const;

    bool operator!=(const Entity &entity) const;

    friend std::istream &operator>>(std::istream &is, Entity &entity);

    friend std::ostream &operator<<(std::ostream &os, const Entity &entity);

    Entity &operator=(const Entity &e);
};


#endif //LAB7_ENTITY_H
