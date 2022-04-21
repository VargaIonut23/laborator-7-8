//
// Created by ivarg on 20.04.2022.
//

#include "UI.h"
#include<string>
#include<sstream>
using namespace std;

UI::UI() = default;

UI::~UI() = default;

void UI::print_menu() {
    cout<<"Menu"<<"\n";
    cout<<"1.Adauga cheltuiala"<<"\n";
    cout<<"2.Modificare cheltuieli"<<"\n";
    cout<<"3.Identificarea cheltuielilor cu anumite proprietati"<<"\n";
    cout<<"4.Obtinerea unor caracteristici ale cheltuielilor"<<"\n";
    cout<<"5.Filtrari"<<"\n";
    cout<<"6.Undo"<<"\n";
    cout<<"7.Redo"<<"\n";
    cout<<"8.Exit"<<"\n";
}

void UI::print_menu2() {
    cout<<"Menu2"<<"\n";
    cout<<"1.Eliminarea tuturor cheltuielilor unui apartament"<<"\n";
    cout<<"2.Eliminarea tuturor cheltuielilor tuturor apartamentelor aflate intr un interval [a,b]"<<"\n";
    cout<<"3.Eliminarea tuturor cheltuielilor apartamentelor cu tipul precizat"<<"\n";
    cout<<"4.Inlocuirea sumei vechi de la un apartament precizand nr apartamentului si tipul cheltuielii"<<"\n";
    cout<<"5.Exit"<<"\n";
}

void UI::print_menu3(){
    cout<<"Menu3"<<"\n";
    cout<<"1.Afisarea tuturor cheltuielilor"<<"\n";
    cout<<"2.Afisarea tuturor cheltuielilor unui apartament"<<"\n";
    cout<<"3.Afisarea cheltuielilor care au suma mai mare decat o suma data"<<"\n";
    cout<<"4.Afisarea cheltuielilor care au suma egala decat o suma data"<<"\n";
    cout<<"5.Afisarea cheltuielilor care au suma mai mica decat o suma data"<<"\n";
    cout<<"6.Exit"<<"\n";
}
void UI::print_menu4(){
    cout<<"Menu4"<<"\n";
    cout<<"1.Afisarea sumei totale pentru tipul precizat"<<"\n";
    cout<<"2.Afiseaza cea mai valoroasa cheltuiala pentru un apartament dat"<<"\n";
    cout<<"3.Afiseaza toate cheltuielile de un anumit tip sortate descrescator"<<"\n";
    cout<<"4.Exit"<<"\n";
}

void UI::print_menu5(){
    cout<<"Menu5"<<"\n";
    cout<<"1.Filtrare dupa tip"<<"\n";
    cout<<"2.Filtru dupa suma(se pastreaza cheltuielile mai mici decat o suma)"<<"\n";
    cout<<"3.Filtru dupa suma(se pastreaza cheltuielile egale decat o suma)"<<"\n";
    cout<<"4.Filtru dupa suma(se pastreaza cheltuielile mai mari decat o suma)"<<"\n";
    cout<<"5.Exit"<<"\n";
}
void UI::start() {
    int optiune, ok = 1;
    while(ok == 1){
        print_menu();
        cout<<"Dati optiunea: "<<"\n";
        cin>>optiune;
        switch (optiune) {
            case 1:
            {
                addentity();
                break;
            }
            case 2:
            {
                int ok2 = 1, optiune2;
                while(ok2 == 1){
                    print_menu2();
                    cout<<"Dati optiunea: "<<"\n";
                    cin>>optiune2;
                    switch(optiune2){
                        case 1:
                        {
                            deleteallappexpense();
                            break;
                        }
                        case 2:
                        {
                            deleteallintervalexpense();
                            break;
                        }
                        case 3:
                        {
                            deletealltipexpense();
                            break;
                        }
                        case 4:
                        {
                            updatesum();
                            break;
                        }
                        case 5:
                        {
                            ok2 = 0;
                            break;
                        }
                        default:{
                            cout<<"A aparut o eroare"<<"\n";
                            break;
                        }

                    }
                }
                break;
            }
            case 3:
            {
                int ok3 =1, optiune3 ;
                while(ok3==1){
                    print_menu3();
                    cout<<"Dati optiunea: "<<"\n";
                    cin>>optiune3;
                    switch (optiune3) {
                        case 1:
                        {
                            showallexpense();
                            break;
                        }
                        case 2:
                        {
                            showallappexpense();
                            break;
                        }
                        case 3:
                        {
                            showallsumexpense(optiune3);
                            break;
                        }
                        case 4:
                        {
                            showallsumexpense(optiune3);
                            break;
                        }
                        case 5:
                        {
                            showallsumexpense(optiune3);
                            break;
                        }
                        case 6:
                        {
                            ok3 =0;
                            break;
                        }
                        default:{
                            cout<<"A aparut o eroare"<<"\n";
                            break;
                        }


                    }
                }
                break;
            }
            case 4:
            {   int ok4 = 1, optiune4;
                while(ok4 == 1){
                    print_menu4();
                    cout<<"Dati optiunea: "<<"\n";
                    cin>>optiune4;
                    switch (optiune4) {
                        case 1:{
                            showtotalsumtip();
                            break;
                        }
                        case 2:{
                            showbiggestappsum();
                            break;

                        }
                        case 3:{
                            tipsort();
                            break;
                        }
                        case 4:{
                            ok4 = 0;
                            break;
                        }
                        default:{
                            cout<<"A aparut o eroare"<<"\n";
                            break;
                        }

                    }
                }
                break;
            }
            case 5:
            {
                int ok5 =1, optiune5;
                while(ok5==1){
                    print_menu5();
                    cout<<"Dati optiunea: "<<"\n";
                    cin>>optiune5;
                    switch (optiune5) {
                        case 1:{
                            tipfilter();
                            break;
                        }
                        case 2:{
                            sumfilter(optiune5);
                            break;
                        }
                        case 3:{
                            sumfilter(optiune5);
                            break;
                        }
                        case 4:{
                            sumfilter(optiune5);
                            break;
                        }
                        case 5:{
                            ok5=0;
                            break;
                        }
                        default:{
                            cout<<"A aparut o eroare"<<"\n";
                            break;
                        }

                    }
                }
                break;
            }
            case 6:
            {
                undo();
                break;
            }
            case 7:
            {
                redo();
                break;
            }
            case 8:
            {
                ok = 0;
                break;
            }
            default:{
                cout<<"A aparut o eroare"<<"\n";
                break;
            }
        }
    }
}

void UI::addentity() {
    int id, sum, nrap;
    string tip;
    cout<<"Dati id ul: "<<"\n";
    cin>>id;
    cout<<"Dati numarul apartamentului: "<<"\n";
    cin>>nrap;
    cout<<"Dati suma: "<<"\n";
    cin>>sum;
    cout<<"Dati tipul cheltuielii: "<<"\n";
    cin >>tip;
    service.add_entity(id, nrap, sum, tip);
}

void UI::deleteentity() {
    int id;
    cout<<"Dati id ul cheltuielii de sters: "<<"\n";
    cin>>id;
    service.delete_entity(id);
}

void UI::updateentity() {
    int id, sum, nrap;
    string tip;
    cout<<"Dati id ul : "<<"\n";
    cin>>id;
    cout<<"Dati numarul apartamentului: "<<"\n";
    cin>>nrap;
    cout<<"Dati suma: "<<"\n";
    cin>>sum;
    cout<<"Dati tipul cheltuielii: "<<"\n";
    getline(cin, tip);
    service.update_entity(id, nrap, sum, tip);
}

void UI::deleteallappexpense() {
    int nrapp;
    cout<<"Dati nr apartamentului caruia vreti sa i stergeti toate cheltuielile: "<<"\n";
    cin>>nrapp;
    service.deleteallappexpense(nrapp);

}

void UI::deleteallintervalexpense(){
    int nrapp1, nrapp2;
    cout<<"Dati primul apartament din interval: "<<"\n";
    cin>>nrapp1;
    cout<<"Dati al doilea apartament din interval: "<<"\n";
    cin>>nrapp2;
    service.deleteallintervalexpense(nrapp1, nrapp2);
}

void UI::deletealltipexpense() {
    string tip;
    cout<<"Dati tipul: "<<"\n";
    cin>>tip;
    service.deletealltipexpense(tip);
}

void UI::updatesum() {
    int nrapp, sum;
    string tip;
    cout<<"Dati noua suma: "<<"\n";
    cin>>sum;
    cout<<"Dati numarul apartamentului: "<<"\n";
    cin>>nrapp;
    cout<<"Dati tipul cheltuielii: "<<"\n";
    cin>>tip;
    service.updatesum(sum, nrapp, tip);
}

void UI::showallexpense(){
    service.showallexpense();
}

void UI::showallappexpense() {
    int nrapp;
    cout<<"Dati numarul apartamentului: "<<"\n";
    cin>>nrapp;
    service.showallappexpense(nrapp);
}

void UI::showallsumexpense(int optiune){
    int sum;
    cout<<"Dati suma: "<<"\n";
    cin>>sum;
    switch (optiune) {
        case 3:{
            service.showallbiggerexpense(sum);
            break;
        }
        case 4:{
            service.showallequalexpense(sum);
            break;
        }
        case 5:{
            service.showalllowerexpense(sum);
            break;
        }
        default:{
            cout<<"A aparut o eroare"<<"\n";
            break;
        }

    }
}

void UI::tipfilter() {
    string tip;
    cout<<"Dati tipul: "<<"\n";
    cin>>tip;
    service.tipfilter(tip);
}

void UI::sumfilter(int optiune) {
    int sum;
    cout<<"Dati suma: "<<"\n";
    cin>>sum;
    switch (optiune) {
        case 2:{
            service.sumlowerfilter(sum);
            break;
        }
        case 3:{
            service.sumequalfilter(sum);
            break;
        }
        case 4:{
            service.sumbiggerfilter(sum);
            break;
        }
        default:{
            cout<<"A aparut o eroare"<<"\n";
            break;
        }

    }
}

void UI::showtotalsumtip(){
    string tip;
    cout<<"Dati tipul cheltuielii: "<<"\n";
    cin>>tip;
    cout<<service.showtotalsumtip(tip)<<"\n";
}

void UI::showbiggestappsum(){
    int nrapp;
    cout<<"Dati numarul partamentului: "<<"\n";
    cin>>nrapp;
    cout<<service.showbiggestappsum(nrapp)<<"\n";
}

void UI::tipsort() {
    string tip;
    cout<<"Dati tipul cheltuielii: "<<"\n";
    cin>>tip;
    service.tipsort(tip);
}

void UI::undo() {
    try {
        service.undo();
        std::cout << "Undo successful" << std::endl;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
}

void UI::redo(){
    try {
        service.redo();
        std::cout << "Redo successful" << std::endl;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
    }
}