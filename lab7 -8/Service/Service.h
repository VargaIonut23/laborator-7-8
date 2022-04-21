//
// Created by ivarg on 12.04.2022.
//

#ifndef MAIN_CPP_SERVICE_H
#define MAIN_CPP_SERVICE_H

#include<set>
#include"../Repository/Repository.h"
#include "../Entity.h"

class Service {
private:
    Repository<Entity> repo;
public:
    Service();

    ~Service();

    void add_entity(int id, int nrap, int sum, const std::string &tip);

    void delete_entity(int id);

    void update_entity(int id, int nrap, int sum, const std::string &tip);

    void deleteallappexpense(int nrapp);

    void deleteallintervalexpense(int nrapp1, int nrapp2);

    void updatesum(int sum, int nrapp, const std::string &tip);

    void deletealltipexpense(const std::string &tip);

    void showallexpense();

    void showallappexpense(int nrapp);

    void showallbiggerexpense(int sum);

    void showallequalexpense(int sum);

    void showalllowerexpense(int sum);

    void tipfilter(const std::string &tip);

    void sumbiggerfilter(int sum);

    void sumequalfilter(int sum);

    void sumlowerfilter(int sum);

    int showtotalsumtip(const std::string &tip);

    int showbiggestappsum(int nrapp);

    void tipsort(const std::string &tip);

    Entity get_entity(int id);

    Vector<Entity> get_entities();

    void undo();

    void redo();

};


#endif //MAIN_CPP_SERVICE_H
