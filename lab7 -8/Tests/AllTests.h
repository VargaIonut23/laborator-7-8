//
// Created by ivarg on 12.04.2022.
//

#ifndef MAIN_CPP_ALLTESTS_H
#define MAIN_CPP_ALLTESTS_H

#include"../Entity.h"
#include<cassert>
#include"../Repository/Repository.h"
#include"../Service/Service.h"
#include<cstring>

class AllTests {
private:
    void TestEntity() {
        Entity e;
        e.setId(1);
        e.setNrap(15);
        e.setSum(120);
        e.setTip("test");
        assert(e.getId() == 1);
        assert(e.getNrap() == 15);
        assert(e.getSum() == 120);
        assert(strcmp(e.getTip(), "test") == 0);
    }

    void TestRepository() {
        Entity e;
        Repository<Entity> repository, entities;
        e.setId(1);
        e.setNrap(15);
        e.setSum(120);
        e.setTip("test1");
        repository.addEntity(e);
        e.setId(2);
        e.setNrap(10);
        e.setSum(50);
        e.setTip("test2");
        repository.addEntity(e);
        assert(repository.getEntity(0).getId() == 1);
        assert(repository.getEntity(0).getNrap() == 15);
        assert(repository.getEntity(0).getSum() == 120);
        assert(strcmp(repository.getEntity(0).getTip(), "test1") == 0);
        assert(repository.getEntity(1).getId() == 2);
        assert(repository.getEntity(1).getNrap() == 10);
        assert(repository.getEntity(1).getSum() == 50);
        assert(strcmp(repository.getEntity(1).getTip(), "test2") == 0);
        e.setId(1);
        e.setNrap(20);
        e.setSum(100);
        e.setTip("test2");
        repository.update(1, e);
        assert(repository.getEntity(0).getId() == 1);
        assert(repository.getEntity(0).getNrap() == 20);
        assert(repository.getEntity(0).getSum() == 100);
        assert(strcmp(repository.getEntity(0).getTip(), "test2") == 0);
        e.setId(2);
        e.setNrap(10);
        e.setSum(50);
        e.setTip("test2");
        repository.remove(e);
        assert(repository.getSize() == 1);
    }

    void TestService() {
        Service service;
        service.add_entity(1, 10, 100, "gaz");
        service.add_entity(2, 5, 200, "apa");
        Vector<Entity> v = service.get_entities();
        assert(v.size() == 2);
        assert(v.front().getId() == 2);
        assert(v.front().getNrap() == 5);
        assert(v.front().getSum() == 200);
        assert(strcmp(v.front().getTip(), "apa") == 0);
        v.remove(2);
        assert(v.size() == 1);
        assert(v.front().getId() == 1);
        assert(v.front().getNrap() == 10);
        assert(v.front().getSum() == 100);
        assert(strcmp(v.front().getTip(), "gaz") == 0);

        service.delete_entity(2);
        service.update_entity(1, 1, 1, "caldura");
        v = service.get_entities();
        assert(v.size() == 1);
        assert(v.front().getId() == 1);
        assert(v.front().getNrap() == 1);
        assert(v.front().getSum() == 1);
        assert(strcmp(v.front().getTip(), "caldura") == 0);
    }

    void TestFunctionalities() {
        Service service;
        service.add_entity(1, 10, 100, "gaz");
        service.add_entity(2, 10, 200, "apa");
        Vector<Entity> v = service.get_entities();
        assert(v.size() == 2);
        service.deleteallappexpense(10);
        v = service.get_entities();
        assert(v.size() == 0);
        service.add_entity(1, 10, 100, "gaz");
        service.add_entity(2, 15, 200, "apa");
        service.deleteallintervalexpense(9, 11);
        v = service.get_entities();
        assert(v.size() == 1);
        assert(v.front().getId() == 2);
        service.add_entity(1, 10, 100, "gaz");
        service.deletealltipexpense("gaz");
        v = service.get_entities();
        assert(v.size() == 1);
        assert(v.front().getId() == 2);
        service.updatesum(10, 15, "apa");
        v = service.get_entities();
        assert(v.size() == 1);
        assert(v.front().getId() == 2);
        assert(v.front().getSum() == 10);
        service.add_entity(1, 10, 100, "gaz");
        service.add_entity(3, 50, 225, "apa");
        service.add_entity(4, 12, 315, "electricitate");
        service.sumbiggerfilter(300);
        v = service.get_entities();
        assert(v.size() == 1);
        assert(v.front().getId() == 4);
        service.add_entity(1, 10, 100, "gaz");
        service.add_entity(3, 50, 225, "apa");
        service.sumequalfilter(100);
        v = service.get_entities();
        assert(v.size() == 1);
        assert(v.front().getId() == 1);
        service.add_entity(3, 50, 225, "apa");
        service.add_entity(4, 12, 315, "electricitate");
        service.sumlowerfilter(101);
        v = service.get_entities();
        assert(v.size() == 1);
        assert(v.front().getId() == 1);
        service.add_entity(3, 50, 225, "apa");
        service.add_entity(4, 50, 315, "apa");
        int sum = service.showtotalsumtip("apa");
        assert(sum == 540);
        int max = service.showbiggestappsum(50);
        assert(max == 315);


    }

public:
    void RunTests() {
        TestEntity();
        TestRepository();
        TestService();
        TestFunctionalities();
    }
};


#endif //MAIN_CPP_ALLTESTS_H
