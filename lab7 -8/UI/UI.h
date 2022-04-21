//
// Created by ivarg on 20.04.2022.
//

#ifndef MAIN_CPP_UI_H
#define MAIN_CPP_UI_H

#include"../Service/Service.h"

class UI {
private:
    Service service;

    static void print_menu();

    static void print_menu2();

    static void print_menu3();

    static void print_menu4();

    static void print_menu5();

    void addentity();

    void deleteentity();

    void deleteallappexpense();

    void deleteallintervalexpense();

    void deletealltipexpense();

    void showallexpense();

    void showallappexpense();

    void showallsumexpense(int optiune);

    void showtotalsumtip();

    void tipfilter();

    void sumfilter(int optiune);

    void updatesum();

    void showbiggestappsum();

    void tipsort();

    void updateentity();

    void undo();

    void redo();

public:
    UI();

    ~UI();

    void start();
};


#endif //MAIN_CPP_UI_H
