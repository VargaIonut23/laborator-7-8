//
// Created by ivarg on 12.04.2022.
//

#include "Service.h"
#include<cstring>
#include<string>

Service::Service() = default;

Service::~Service() = default;

void Service::add_entity(int id, int nrap, int sum, const std::string &tip) {

    Entity e(id, nrap, sum, tip.c_str());
    this->repo.addEntity(e);
}

void Service::delete_entity(int id) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getId() == id) {
            repo.remove(entities[i]);
            return;
        }
    throw std::invalid_argument("Id invalid");
}

void Service::update_entity(int id, int nrap, int sum, const std::string &tip) {
    char *tip1 = new char[tip.size() + 1];
    std::strcpy(tip1, tip.c_str());
    Entity e;
    e.setSum(sum);
    e.setNrap(nrap);
    e.setId(id);
    e.setTip(tip1);
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++) {
        if (entities[i].getId() == id) {
            repo.update(i, e);
        }
    }
    throw std::invalid_argument("Id invalid");
}

Entity Service::get_entity(int id) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getId() == id)
            return entities[i];
}

Vector<Entity> Service::get_entities() {
    return this->repo.getAll();
}

void Service::deleteallappexpense(int nrapp) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getNrap() == nrapp)
            delete_entity(entities[i].getId());
}

void Service::deleteallintervalexpense(int nrapp1, int nrapp2) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getNrap() >= nrapp1 && entities[i].getNrap() <= nrapp2)
            delete_entity(entities[i].getId());
}

void Service::deletealltipexpense(const std::string &tip) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getTip() == tip)
            delete_entity(entities[i].getId());
}

void Service::updatesum(int sum, int nrapp, const std::string &tip) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getNrap() == nrapp && entities[i].getTip() == tip)
            {entities[i].setSum(sum);
            repo.update(i, entities[i]);
            }
}

void Service::showallexpense(){
    Vector<Entity> entities = repo.getAll();
    for(int i= 0 ;i< entities.size();i++)
        std::cout<<entities[i]<<"\n";
}

void Service::showallappexpense(int nrapp) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getNrap() == nrapp)
            std::cout<<entities[i]<<"\n";
}

void Service::showallbiggerexpense(int sum) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getSum() > sum)
            std::cout << entities[i]<<"\n";
}

void Service::showallequalexpense(int sum) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getSum() == sum)
            std::cout <<entities[i]<<"\n";
}

void Service::showalllowerexpense(int sum) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getSum() < sum)
            std::cout << entities[i]<<"\n";
}

void Service::tipfilter(const std::string &tip) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getTip() != tip)
            delete_entity(entities[i].getId());
}

void Service::sumbiggerfilter(int sum) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getSum() <= sum)
            delete_entity(entities[i].getId());
}

void Service::sumequalfilter(int sum) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getSum() < sum && entities[i].getSum() > sum)
            delete_entity(entities[i].getId());
}

void Service::sumlowerfilter(int sum) {
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getSum() >= sum)
            delete_entity(entities[i].getId());
}

int Service::showtotalsumtip(const std::string &tip) {
    int sum = 0;
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getTip() == tip)
            sum = sum + entities[i].getSum();
    return sum;
}

int Service::showbiggestappsum(int nrapp) {
    int max = 0;
    Vector<Entity> entities = repo.getAll();
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getNrap() == nrapp && entities[i].getSum() > max)
            max = entities[i].getSum();
    return max;
}

void Service::tipsort(const std::string &tip) {
    Vector<Entity> entities = repo.getAll();
    Vector<Entity> finalentities;
    Entity e;
    for (int i = 0; i < entities.size(); i++)
        if (entities[i].getTip() == tip)
            finalentities.push_back(entities[i]);
    for (int i = 0; i < finalentities.size() - 1; i++)
        for (int j = i + 1; j < finalentities.size(); j++)
            if (finalentities[i].getSum() < finalentities[j].getSum()) {
                e = finalentities[i];
                finalentities[i] = finalentities[j];
                finalentities[j] = e;
            }
    for(int i = 0 ;i< finalentities.size();i++)
        std::cout<<finalentities[i]<<"\n";

}

void Service::undo(){
    if (!repo.undo()) {
        throw std::invalid_argument("No more transactions to undo");
    }
}

void Service::redo(){
    if (!repo.redo()) {
        throw std::invalid_argument("No more transactions to redo");
    }
}