/*
Proyecto Biblioteca
Programación con estructuras lineales
12/10/2021
*/

//Librerías
#include <cstdlib>
#include <iostream>
#include<stdio.h>
#include<string.h>
#include <vector>
#include<stdlib.h>
#include<time.h>
#include <string>


//Espacio de nombres para utilizar input / output
using namespace std;

//Variable global;
//int contador = 20; //Aumentar contador cuando se cree un libro

//Clase libro
class libro {
private:
    //Atributos
    string titulo;
    string categoria;
    bool disponible;
    int isbn;
    int prestado; //if cliente_prestado = 0, el libro esta disponible

public:
    //Constructor

    libro() {
        titulo = "";
        isbn = 0;
        categoria = "";
        disponible = false;
    }

    libro(string titulo_nuevo, string autor_nuevo, int id_libro_nuevo,
          string fecha_publicacion_new, string categoria_nueva) {
        titulo = titulo_nuevo;
        isbn = id_libro_nuevo;
        categoria = categoria_nueva;
        disponible = true;

    }

    //Getters
    string titulo() {
        return titulo;
    }

    string categoria() {
        return categoria;
    }

    int isbn() {
        return isbn;
    }

    bool disponible() {
        return disponible;
    }

    int cliente() {
        return prestado;
    }

    //Setters
    void titulo(string titulo_nuevo) {
        titulo = titulo_nuevo;
    }

    void categoria(string categoria_nueva) {
        categoria = categoria_nueva;
    }

    void isbn(int id) {
        isbn = id;
    }

    void disponible(bool disp) {
        disponible = disp;
    }

    void prestado(int prestamo) {
        prestado = prestamo;
    }
};


// Clase cliente
class cliente {
private:
    //Atributos
    int id;
    string nombre;
    string apellido;
    string dni;
    string libro_en_posesion;
    vector<string> historial;

public:
    //Constructor
    cliente() {
        id = 0;
        nombre = "";
        apellido = "";
        dni = "";
        libro_en_posesion = "";
    }

    cliente(int id_new, string nombre_new, string apellido_new, string dni_new,
            int edad_new) {
        id = id_new;
        nombre = nombre_new;
        apellido = apellido_new;
        dni = dni_new;
        libro_en_posesion = "";

    }

    //getters
    bool getTiene_libro_posesion() {
        return tiene_libro_posesion;
    }

    string getNombre() {
        return nombre;
    }

    string getApellido() {
        return apellido;
    }

    string getDni() {
        return dni;
    }

    string getLibro_en_posesion() {
        return libro_en_posesion;
    }

    int getId() {
        return id;
    }

    int getEdad() {
        return edad;
    }

    vector<string> getHistorial() {
        return historial;
    }

    //setters
    void setId(int id_new) {
        id = id_new;
    }

    void setNombre(string nombre_new) {
        nombre = nombre_new;
    }

    void setAppellido(string apellido_new) {
        apellido = apellido_new;
    }

    void setDni(string dni_new) {
        dni = dni_new;
    }

    void setHistorial(string historial_new) {
        historial.push_back(historial_new);
    }

    void setLibro_en_posesion(string libro_en_posesion_new) {
        libro_en_posesion = libro_en_posesion_new;
    }

    void setTiene_libro_posesion(bool tiene_libro_new) {
        tiene_libro_posesion = tiene_libro_new;
    }

};

//Clase biblioteca
class biblioteca {
private:
    string nombre;
    vector<cliente> clientes;
    vector<libro> libros;

public:
    //Constructor
    biblioteca() {
        nombre = "";
        ubicacion = "";
    }

    biblioteca(string nombre_new, string ubicacion_new) {
        nombre = nombre_new;
        ubicacion = ubicacion_new;
    };

    //Getters
    string getNomrbe() {
        return nombre;
    }

    string getUbicacion() {
        return ubicacion;
    }

    vector<cliente> getClientes() {
        return clientes;
    }

    vector<libro> getLibros() {
        return libros;
    }

    //Setters

    void setNombre(string nombre_new) {
        nombre = nombre_new;
    }

    void setUbicacion(string ubica_new) {
        ubicacion = ubica_new;
    }

    void setClientes(vector<cliente> clientes_new) {
        clientes = clientes_new;
    }

    void setLibros(vector<libro> libros_new) {
        libros = libros_new;
    }

    //Funciones

    void listar_libros() {
        cout << "LISTAR LIBROS" << "\n";
        for (int i = 0; i < libros.size(); i++) {
            cout << "ID: " << libros.at(i).isbn() << "\n";
            cout << "Titulo: " << libros.at(i).titulo() << "\n";
            cout << "Categoria: " << libros.at(i).categoria() << "\n";
            cout << "-----------------------" << "\n";
        }
    };

    void listar_clientes() {
        cout << "Listar clientes: " << "\n";
        for (int i = 0; i < clientes.size(); ++i) {
            cout << "ID: " << clientes[i].getId() << "\n";
            cout << "Nombre: " << clientes[i].getNombre() << "\n";
            cout << "Apellido: " << clientes[i].getApellido() << "\n";
            cout << "DNI: " << clientes.at(i).getDni() << "\n";
            cout << "Edad: " << clientes.at(i).getEdad() << "\n";
            cout << "Libro en posesion: " << clientes.at(i).getLibro_en_posesion() << "\n";
            cout << "-----------------------" << "\n";
        };
    };


    void listar_libros_disponibles() {
        bool ninguno_disponible = true;
        for (int i = 0; i < libros.size(); i++) {
            if (libros.at(i).getDisponible()) {
                cout << "ID: " << libros.at(i).getId_libro() << "\n";
                cout << "Título: " << libros.at(i).getTitulo() << "\n";
                cout << "Categoría: " << libros.at(i).getCategoria() << "\n";
                cout << "-----------------------" << "\n";
                ninguno_disponible = false;
            }
        }

        if (ninguno_disponible) {
            cout << "Todos los libros se encuentran reservados/prestados.";
        }
    };

    void listar_libros_no_disponibles() {
        bool todos_disponibles = true;
        for (int i = 0; i < libros.size(); i++) {
            if (!libros.at(i).getDisponible()) {
                cout << "ID: " << libros.at(i).getId_libro() << "\n";
                cout << "Titulo: " << libros.at(i).getTitulo() << "\n";
                cout << "Categoria: " << libros.at(i).getCategoria() << "\n";
                cout << "-----------------------" << "\n";
                todos_disponibles = false;
            }
        }

        if (todos_disponibles) {
            cout << "Todos los libros se encuentran disponibles.";
        }
    };

    void pedir_libro() {
        string id_cliente_str;
        string id_libro_pedido_str;
        listar_clientes();
        cout << "Introduce el id del cliente: "
             << "\n"; //Modificar para comprobar si el cliente ya tiene un libro prestado, en ese caso, no dejar alquilar libro
        cin >> id_cliente_str;
        //getline(cin,id_cliente_str);
        int id_cliente = atoi(id_cliente_str.c_str());

        listar_libros_disponibles();
        cout << "Introduce el id del libro que desea pedir: "
             << "\n"; //Modificar para comprobar si el cliente ya tiene un libro prestado, en ese caso, no dejar alquilar libro
        cin >> id_libro_pedido_str;
        //getline(cin,id_libro_pedido_str);
        int id_libro_pedido = stoi(id_libro_pedido_str);

        bool libro_encontrado = false;
        bool cliente_encontrado = false;
        int i = 0;
        int j = 0;
        while (i < clientes.size() && !cliente_encontrado) {
            if (clientes.at(i).getId() == id_cliente) {
                cliente_encontrado = true;
                while (j < libros.size() && !libro_encontrado) {
                    if (libros.at(j).getId_libro() == id_libro_pedido && libros.at(j).getDisponible()) {
                        clientes.at(i).setLibro_en_posesion(libros.at(j).getTitulo());
                        clientes.at(i).setTiene_libro_posesion(true);
                        clientes.at(i).setHistorial(libros.at(j).getTitulo());
                        libros.at(j).setDisponible(false);
                        libros.at(j).setCliente_prestado(id_cliente);
                        libro_encontrado = true;
                    } else {
                        j++;
                    }
                }
            } else {
                i++;
            }
        }
    };

    void devolver_libro() {
        string id_cliente_str;
        string id_libro_pedido_str;
        listar_clientes();
        cout << "Introduce el id del cliente " << "\n";
        cin >> id_cliente_str;
        int id_cliente = stoi(id_cliente_str);

        listar_libros();
        cout << "Introduce el id del libro que desea devolver " << "\n";
        cin >> id_libro_pedido_str;
        int id_libro_devolver = stoi(id_libro_pedido_str);

        bool libro_encontrado = false;
        bool cliente_encontrado = false;
        int i = 0;
        int j = 0;
        while (i < clientes.size() && !cliente_encontrado) {
            if (clientes.at(i).getId() == id_cliente) {
                cliente_encontrado = true;
                while (j < libros.size() && !libro_encontrado) {
                    if (libros.at(j).getId_libro() == id_libro_devolver && !libros.at(j).getDisponible()) {
                        clientes.at(i).setLibro_en_posesion("");
                        clientes.at(i).setTiene_libro_posesion(false);
                        libros.at(j).setCliente_prestado(0);
                        libros.at(j).setDisponible(true);
                        libro_encontrado = true;
                    } else {
                        j++;
                    }
                }
            } else {
                i++;
            }
        }
    };

    void crear_libro() {
        string titulo_;
        string autor_;
        string fecha_;
        string id_str;
        string categoria_;

        cout << "Registrar nuevo libro en la biblioteca " << "\n";
        cout << "Por favor, introduce el titulo del libro:" << "\n";
        cin >> titulo_;

        cout << "Por favor, introduce el autor del libro:" << "\n";
        cin >> autor_;

        cout << "Por favor, introduce la fecha de publicacion del libro:" << "\n";
        cin >> fecha_;

        cout << "Por favor, introduce el id del libro:" << "\n";
        cin >> id_str;
        int id_ = stoi(id_str);

        cout << "Por favor, introduce la categoria del libro:" << "\n";
        cin >> categoria_;

        libros.push_back(libro(titulo_, autor_, id_, fecha_, categoria_));


    };

    void crear_libros_random() {
        for (int i = 0; i < 21; i++) {
            if (i < 5) {
                libros.push_back(libro("Suenos de papel", "Samuel Mendez", i, "10/02/2021", "Drama"));
            } else if (i >= 5 && i < 10) {
                libros.push_back(libro("Divina comedia", "Samuel Mendez2", i, "11/02/2021", "Comedia"));
            } else if (i >= 10 && i < 15) {
                libros.push_back(libro("El hobbit", "Samuel Mendez3", i, "12/02/2021", "Fantasía"));
            } else {
                libros.push_back(libro("La biblioteca encantada", "Samuel Mendez4", i, "13/02/2021", "Terror"));
            }
        }
    };

    void crear_cliente() {
        string nombre_;
        string apellido_;
        string id_str;
        string dni_;
        string edad_;

        cout << "Registrar nuevo cliente en la biblioteca " << "\n";
        cout << "Por favor, introduce el nombre del cliente:" << "\n";
        cin >> nombre_;

        cout << "Por favor, introduce el apellido del cliente:" << "\n";
        cin >> apellido_;

        cout << "Por favor, introduce el id del cliente:" << "\n";
        cin >> id_str;
        int id_ = stoi(id_str);

        cout << "Por favor, introduce el dni del cliente:" << "\n";
        cin >> dni_;

        cout << "Por favor, introduce la edad del cliente:" << "\n";
        cin >> edad_;
        int edad_int = stoi(edad_);

        clientes.push_back(cliente(id_, nombre_, apellido_, dni_, edad_int));
        cout << "hecho";

    };

    void ver_historial() {
        string id_cliente_str;
        listar_clientes();
        cout << "Introduce el id del cliente " << "\n";
        cin >> id_cliente_str;
        int id_cliente = stoi(id_cliente_str);

        bool encontrado = false;
        int i = 0;
        vector<string> historial_;
        string nombre_cliente;

        while (i < clientes.size() && !encontrado) {
            if (clientes.at(i).getId() == id_cliente) {
                historial_ = clientes.at(i).getHistorial();
                nombre_cliente = clientes.at(i).getNombre();
                encontrado = true;
            } else {
                i++;
            }
        }

        if (encontrado) {
            cout << "Historial de " << nombre_cliente << " es: " << "\n";
            for (int j = 0; j < historial_.size(); j++) {
                cout << historial_.at(j);
            }
        } else {
            cout << "Cliente no encontrado";
        }

    };

    void ver_libros_cliente() {
        string id_cliente_str;
        listar_clientes();
        cout << "Introduce el id del cliente " << "\n";
        cin >> id_cliente_str;

        int id_cliente = stoi(id_cliente_str);

        bool encontrado = false;
        int i = 0;
        string nombre_cliente;
        string libro_;
        bool tiene_libro = false;

        while (i < clientes.size() && !encontrado) {
            if (clientes.at(i).getId() == id_cliente) {
                nombre_cliente = clientes.at(i).getNombre();
                libro_ = clientes.at(i).getLibro_en_posesion();
                tiene_libro == clientes.at(i).getTiene_libro_posesion();
                tiene_libro = true;
                encontrado = true;
            } else {
                i++;
            }
        }

        if (encontrado) {
            cout << "El " << nombre_cliente << " tiene el siguiente libro prestado: " << "\n" << libro_;

        } else {
            cout << "Cliente no encontrado o el cliente no tiene libros.";
        }
    };

};


//Clase main
int main(int argc, char *argv[]) {
    //Declaramos un vector de clientes y libros
    vector<cliente> clientes;
    vector<libro> libros;

    //Numeros aleatorios
    int num_aleatorio;
    srand(time(NULL));

    //Creamos clientes con un bucle
    for (int j = 0; j < 5; j++) {
        num_aleatorio = 20 + rand() % 51;
        clientes.push_back(usuario(j + 1, "Usuario " + to_string(j + 1), "Apellido " + to_string(j + 1),
                                   "55555 " + to_string(j + 1), num_aleatorio));
    };

    //Creamos objeto biblioteca y añadimos clientes y libros
    biblioteca biblioteca("UEM", "Calle Tajo");
    biblioteca.setClientes(clientes);
    biblioteca.crear_libros_random();




    //Menú interactivo
    int opcion;
    bool repetir = true;

    do {
        system("cls");

        // Texto del menú que se verá cada vez
        cout << "\n\nBienvenido a la Biblioteca" << endl;
        cout << "1. Listar todos los libros de la biblioteca." << endl;
        cout << "2. Listar los usuarioss dados de alta." << endl;
        cout << "3. Libros libros disponibles." << endl;
        cout << "4. Libros libros no disponibles." << endl;
        cout << "5. Ver libro que posee un usuario." << endl;
        cout << "6. Pedir un libro." << endl;
        cout << "7. Devolver un libro." << endl;
        cout << "8. Ver historial de un usuario." << endl;
        cout << "9. Dar de alta un usuario." << endl;
        cout << "10. Registrar nuevo libro." << endl;
        cout << "0. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                biblioteca.listar_libros();
                system("pause>nul"); // Pausa             
                break;

            case 2:
                biblioteca.listar_usuario();
                system("pause>nul"); // Pausa            
                break;

            case 3:
                biblioteca.listar_libros_disponibles();
                system("pause>nul"); // Pausa                        
                break;

            case 4:
                biblioteca.listar_libros_no_disponibles();
                system("pause>nul"); // Pausa              
                break;

            case 5:
                biblioteca.ver_libros_usuarios();
                system("pause>nul"); // Pausa            
                break;

            case 6:
                biblioteca.pedir_libro();
                system("pause>nul"); // Pausa             
                break;

            case 7:
                biblioteca.devolver_libro();
                system("pause>nul"); // Pausa            
                break;

            case 8:
                biblioteca.ver_historial();
                system("pause>nul"); // Pausa               
                break;

            case 9:
                biblioteca.crear_usuario();
                system("pause>nul"); // Pausa             
                break;

            case 10:
                biblioteca.crear_libro();
                system("pause>nul"); // Pausa               
                break;

            case 0:
                repetir = false;
                break;
        }
    } while (repetir);

    return 0;
};