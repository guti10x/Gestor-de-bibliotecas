#include <iostream>
using namespace std;

void menu_principal(){

cout<< "  ######    ####    ######   ####      ####     #####   ######   #######    ####     ##               ####              ####  "<<"\n";
cout<< "   ##  ##    ##      ##  ##   ##        ##     ##   ##  # ## #    ##   #   ##  ##   ####             ##  ##            ##  ## "<<"\n";
cout<< "   ##  ##    ##      ##  ##   ##        ##     ##   ##    ##      ## #    ##       ##  ##                ##            ## ### "<<"\n";
cout<< "   #####     ##      #####    ##        ##     ##   ##    ##      ####    ##       ##  ##              ###             ###### "<<"\n";
cout<< "   ##  ##    ##      ##  ##   ##   #    ##     ##   ##    ##      ## #    ##       ######             ##               ### ## "<<"\n";
cout<< "   ##  ##    ##      ##  ##   ##  ##    ##     ##   ##    ##      ##   #   ##  ##  ##  ##            ##  ##     ##     ##  ## "<<"\n";
cout<< "  ######    ####    ######   #######   ####     #####    ####    #######    ####   ##  ##            ######     ##      ####  " <<"\n";

    cout<<"BIENVENIDO A LA BIBLIOTECA 2.0"<<"\n";
    
    cout<<"1-Sacar libro"<<"\n";
    cout<<"2-Devolver libro"<<"\n";
    cout<<"3-Consultar stock"<<"\n";
    cout<<"4-Consultar historial de libros de una persona"<<"\n";
    cout<<"5-Consultar libro asociado a una persona"<<"\n"<<"\n";

    cout<<"Introduczca el número de la acción que desea realizar: ";
    int opcion;
    cin>>opcion;
    switch (opcion){
        case 1:
            /* code */
            break;
        case 2:
        
            break;
        case 3:
        
            break;

        case 4: 
            break;

        case 5:
            break;
        
        default:
            break;
        }
}

int main(int, char**) {
    menu_principal();
}