#include <iostream>
#include <string.h>
using namespace std;

#define USUARIO "Usuario" //USUARIO respetando las mayúsculas
#define PASS "123456789" //CONTRASEÑA respetando las mayúsculas

int main(int argc, char const *argv[])
{
    char Usuario[25];
    char Pass[25];
    int c = 1;
    bool f = false;

    //Solo te puede fallar 3 veces
    while (c <= 3 && f == false)
    {
        system("cls"); //Borrar la pantalla anterior

        // Solicitar usuario y contraseña
        cout << "\n\n\n\t\t\t ********************** Ingreso al Sistema ********************** \n\n";
        cout << "\t\t\t Usuario (user) : \t\t";
        cin.getline(Usuario, 25);

        cout << "\t\t\t Contrasenya (password) : \t";
        cin.getline(Pass, 25);
        c++;
        
        // Ver si la contraseña tiene al menos 8 caracteres
        if(strlen(Pass) >= 8)
        {
            // Ver si el usuario y la contraseña tienen los mismos caracteres
            if((strcmp(Pass, PASS) == 0) && (strcmp(Usuario, USUARIO) == 0))
            {
                f = true;
            }
            else 
            {
                cout << "\n\n\n\t\t ********************** ERROR **********************\n";
                cout << "\t\t El usuario o la contrasenya son incorrectos. \n";
                cout << "\t\t ***************************************************\n";
                system("pause");
            }
        }
        else
        {
            cout << "\n\n\n\t\t ********************** ERROR **********************\n";
            cout << "\t\t La contrasenya o password deben tener al menos 8 caracteres. \n";
            cout << "\t\t ***************************************************\n";
            system("pause");
        }
    }

    // Si se ha puesto correctamente
    system("cls"); //Borrar la pantalla anterior
    if(f == true)
    {
        cout << "\n\n\n\t\t ********************** Ingreso con Exito **********************\n";
        cout << "\t\t Bienvenido al SISTEMA. \n";
        cout << "\t\t ***************************************************************\n";
    }
    else
    {
        cout << "\n\n\n\t\t ********************** ERROR **********************\n";
            cout << "\t\t Intento tres veces sin exito. Pruebe mas tarde \n";
            cout << "\t\t ***********************************************\n";
    }
    system("pause");
}
