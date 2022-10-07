/*********************************************
 * Programación con Estructuras Lineales     *
 *                                           *
 * Trabajo grupal: Gestion de una biblioteca *
 *                                           *
 * Código creado por:                        *
 * Grupo 4                                   *
 *                                           *
 ********************************************/


#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;


class Admin {
private:
    string user;
    string pass;

public:
    Admin() {
        user = "";
        pass = "";
    }
    Admin(string nuevo_user, string nuevo_pass) {
        user = std::move(nuevo_user);
        pass = std::move(nuevo_pass);
    }

    string User(){
        return user;
    }

    string Password(){
        return pass;
    }
};


class Libro {
private:
    int id;
    string titulo;
    string categoria;
    string isbn;
    string prestado;
public:
    Libro() {
        id = 0;
        titulo = "";
        categoria = "";
        isbn = "";
        prestado = "";
    }

    Libro(int new_id, string new_title, string new_isbn, string new_cat, string new_borrow) {
        id = new_id;
        titulo = std::move(new_title);
        isbn = std::move(new_isbn);
        categoria = std::move(new_cat);
        prestado = std::move(new_borrow);
    }

    [[nodiscard]] int ID() const {
        return id;
    }

    string Titulo() {
        return titulo;
    }

    string ISBN() {
        return isbn;
    }

    string Categoria() {
        return categoria;
    }

    string Disponible() {
        return prestado;
    }

    void Cambiar_prestado(string prest) {
        prestado = std::move(prest);
    }


};


class Usuario {
private:
    int id;
    string nombre;
    string apellido;
    string dni;
    string libro_en_posesion;
    string historial;

public:
    Usuario() {
        id = 0;
        nombre = "";
        apellido = "";
        dni = "";
        libro_en_posesion = "";
        historial = "";
    }

    Usuario(int id_new, string nuevo_nombre, string nuevo_apellido, string nuevo_dni, string nuevo_libro,
            string nuevo_historial) {
        id = id_new;
        nombre = std::move(nuevo_nombre);
        apellido = std::move(nuevo_apellido);
        dni = std::move(nuevo_dni);
        libro_en_posesion = std::move(nuevo_libro);
        historial = std::move(nuevo_historial);
    }

    [[nodiscard]] int ID() const {
        return id;
    }

    string Nombre() {
        return nombre;
    }

    string Apellido() {
        return apellido;
    }

    string DNI() {
        return dni;
    }

    string Libro_actual() {
        return libro_en_posesion;
    }

    string Historial() {
        return historial;
    }

    void Cambiar_actual(string posesion) {
        libro_en_posesion = std::move(posesion);
    }
};


class Historial {
private:
    string id;
    string titulo;
    string isbn;
    string categoria;
public:
    Historial() {
        id = "";
        titulo = "";
        isbn = "";
        categoria = "";
    };

    Historial(string new_id, string new_title, string new_isbn, string new_cat) {
        id = std::move(new_id);
        titulo = std::move(new_title);
        isbn = std::move(new_isbn);
        categoria = std::move(new_cat);
    };

    string ID_h() {
        return id;
    }

    string Titulo_h() {
        return titulo;
    }

    string ISBN_h() {
        return isbn;
    }

    string Categoria_h() {
        return categoria;
    }
};


class Biblioteca {
private:
    vector<Admin> admins;
    vector<Usuario> usuarios;
    vector<Libro> libros;
    vector<Historial> historiales;
public:
    Biblioteca() = default;

    void guardar_ficheros() {

        int i;
        int j;
        int k;

        ofstream book_file("../csv/libros.csv", ios::trunc);

        book_file << "Libro,ISBN,Categoría,Disponibilidad" << endl;
        i = 0;
        while (i < libros.size()) {
            book_file << libros[i].Titulo() << "," << libros[i].ISBN() << "," << libros[i].Categoria() << ","
                      << libros[i].Disponible() << endl;
            ++i;
        }
        book_file.close();

        ofstream user_file("../csv/usuarios.csv", ios::trunc);
        user_file << "Nombre,Apellidos,DNI,Libro Prestado,Historial" << endl;

        i = 0;
        while (i < usuarios.size()) {
            user_file << usuarios[i].Nombre() << "," << usuarios[i].Apellido() << "," << usuarios[i].DNI() << ","
                      << usuarios[i].Libro_actual() << "," << usuarios[i].Historial() << endl;

            ofstream history_file("../csv/" + usuarios[i].Historial(), ios::trunc);
            history_file << "Título,ISBN,Categoría" << endl;
            j = 0;
            while (j < historiales.size()) {
                if (historiales[j].Historial::ID_h() == usuarios[i].Usuario::DNI()) {
                    k = 0;
                    while (k < libros.size()) {
                        if (libros[k].Libro::ISBN() == historiales[j].Historial::ISBN_h()) {
                            history_file << historiales[j].Historial::Titulo_h() << ","
                                         << historiales[j].Historial::ISBN_h()
                                         << "," << historiales[j].Historial::Categoria_h() << endl;
                            break;
                        }
                        ++k;
                    }
                }
                ++j;
            }
            history_file.close();
            ++i;
        }
        user_file.close();
    };

    void cargar_usuarios() {

        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        fstream file("../csv/usuarios.csv", ios::in);
        if (file.is_open()) {
            while (getline(file, line)) {
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        } else
            cout << "No se pudo abrir el fichero" << endl;

        for (int i = 0; i < content.size(); i++) {
            if (i > 0) {
                guardar_usuarios(i, content[i][0], content[i][1], content[i][2], content[i][3], content[i][4]);

                vector<vector<string>> content2;
                vector<string> row2;
                string line2, word2;

                string d = content[i][2];
                string h = content[i][4];
                if (h.size() > 12){
                    h.pop_back();
                }

                fstream file2("../csv/" + h, ios::in);
                if (file2.is_open()) {
                    while (getline(file2, line2)) {
                        row2.clear();

                        stringstream str2(line2);

                        while (getline(str2, word2, ','))
                            row2.push_back(word2);
                        content2.push_back(row2);
                    }
                } else
                    cout << "No se pudo abrir el fichero" << endl;

                for (int j = 0; j < content2.size(); j++) {
                    if (j > 0) {
                        guardar_historiales(d, content2[j][0], content2[j][1], content2[j][2]);
                    }
                }
                file2.close();
            }
        }
        file.close();
    };


    void cargar_libros() {

        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        fstream file("../csv/libros.csv", ios::in);
        if (file.is_open()) {
            while (getline(file, line)) {
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        } else
            cout << "No se pudo abrir el fichero" << endl;

        for (int i = 0; i < content.size(); i++) {
            if (i > 0) {
                guardar_libros(i, content[i][0], content[i][1], content[i][2], content[i][3]);
            }
        }
        file.close();
    };

    void cargar_admins() {

        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        fstream file("../csv/admin.csv", ios::in);
        if (file.is_open()) {
            while (getline(file, line)) {
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        } else
            cout << "No se pudo abrir el fichero" << endl;

        for (int i = 0; i < content.size(); i++) {
            if (i > 0) {
                guardar_admins(content[i][0], content[i][1]);
            }
        }
        file.close();
    };

    void guardar_admins(const string &u, const string &p) {
        admins.emplace_back(u, p);
    };

    void guardar_libros(int id, const string &t, const string &i, const string &c, const string &d) {
        libros.emplace_back(id, t, i, c, d);
    };

    void guardar_historiales(const string &id, const string &t, const string &i, const string &c) {
        historiales.emplace_back(id, t, i, c);
    };

    void
    guardar_usuarios(int id, const string &n, const string &a, const string &d, const string &ac, const string &h) {
        usuarios.emplace_back(id, n, a, d, ac, h);
    };

    void asignar_libro(int id) {
        string name = usuarios[id - 1].Usuario::Nombre();
        string surname = usuarios[id - 1].Usuario::Apellido();
        string dni = usuarios[id - 1].Usuario::DNI();
        if (usuarios[id - 1].Usuario::Libro_actual() == "Ninguno") {
            cout << "Asignar nuevo libro a usuario: " << name << " " << surname << endl;
            print_libros_disponibles();

            int new_book_id = 0;
            cout << "Elegir ID de nuevo libro a asignar: ";
            cin >> new_book_id;
            cout << endl;
            cout << "Asignado nuevo libro: " << endl;
            cout << "Título: " << libros[new_book_id - 1].Libro::Titulo() << endl;
            cout << "ISBN: " << libros[new_book_id - 1].Libro::ISBN() << endl;
            cout << "Categoría: " << libros[new_book_id - 1].Libro::Categoria() << endl << endl;
            usuarios[id - 1].Usuario::Cambiar_actual(libros[new_book_id - 1].Libro::Titulo());
            libros[new_book_id - 1].Cambiar_prestado("0");
        } else {
            cout << "Usuario ya tiene libro asignado, volviendo al menú." << endl << endl;
        }

    };

    void desasignar_libro(int id) {
        string name = usuarios[id - 1].Usuario::Nombre();
        string surname = usuarios[id - 1].Usuario::Apellido();
        string dni = usuarios[id - 1].Usuario::DNI();
        if (usuarios[id - 1].Usuario::Libro_actual() != "Ninguno") {
            cout << "Desasignar libro a usuario: " << name << " " << surname << endl;
            string old_book_name = usuarios[id - 1].Usuario::Libro_actual();
            int old_book_id = 0;
            int i = 0;
            while (i < libros.size()) {
                if (libros[i].Libro::Titulo() == old_book_name) {
                    old_book_id = libros[i].Libro::ID();
                }
                ++i;
            }
            guardar_historiales(dni, libros[old_book_id - 1].Libro::Titulo(), libros[old_book_id - 1].Libro::ISBN(),
                                libros[old_book_id - 1].Libro::Categoria());
            cout << "Desasignado libro: " << endl;
            cout << "Título: " << libros[old_book_id - 1].Libro::Titulo() << endl;
            cout << "ISBN: " << libros[old_book_id - 1].Libro::ISBN() << endl;
            cout << "Categoría: " << libros[old_book_id - 1].Libro::Categoria() << endl << endl;
            usuarios[id - 1].Cambiar_actual("Ninguno");
            libros[old_book_id - 1].Cambiar_prestado("1");
        } else {
            cout << "Usuario no tiene libro asignado, volviendo al menú." << endl << endl;
        }
    };

    void print_libros() {
        cout << "Libros: " << endl;
        int i = 0;
        while (i < libros.size()) {
            cout << "ID: " << libros[i].Libro::ID() << endl;
            cout << "Título: " << libros[i].Libro::Titulo() << endl;
            cout << "ISBN: " << libros[i].Libro::ISBN() << endl;
            cout << "Categoría: " << libros[i].Libro::Categoria() << endl;
            cout << "Disponible: " << libros[i].Libro::Disponible() << endl << endl;
            ++i;
        }
    };

    void print_libros_disponibles() {
        cout << "Libros: " << endl;
        int i = 0;
        while (i < libros.size()) {
            if (libros[i].Libro::Disponible() == "1") {
                cout << "ID: " << libros[i].Libro::ID() << endl;
                cout << "Título: " << libros[i].Libro::Titulo() << endl;
                cout << "ISBN: " << libros[i].Libro::ISBN() << endl;
                cout << "Categoría: " << libros[i].Libro::Categoria() << endl;
                cout << "Disponible: " << libros[i].Libro::Disponible() << endl << endl;
            }
            ++i;
        }
    };

    void print_usuarios() {
        cout << "Usuarios: " << endl;
        int i = 0;
        while (i < usuarios.size()) {
            cout << "ID: " << usuarios[i].Usuario::ID() << endl;
            cout << "Nombre: " << usuarios[i].Usuario::Nombre() << endl;
            cout << "Apellido: " << usuarios[i].Usuario::Apellido() << endl;
            cout << "DNI: " << usuarios[i].Usuario::DNI() << endl << endl;
            ++i;
        }
    };

    void print_usuario(int id) {
        string name = usuarios[id - 1].Usuario::Nombre();
        string surname = usuarios[id - 1].Usuario::Apellido();
        string dni = usuarios[id - 1].Usuario::DNI();
        cout << endl;
        cout << "Usuario: " << name << " " << surname << endl;
        cout << "ID: " << usuarios[id - 1].Usuario::ID() << endl;
        cout << "Nombre: " << usuarios[id - 1].Usuario::Nombre() << endl;
        cout << "Apellido: " << usuarios[id - 1].Usuario::Apellido() << endl;
        cout << "DNI: " << usuarios[id - 1].Usuario::DNI() << endl;
        cout << "Libro en posesion: " << usuarios[id - 1].Usuario::Libro_actual() << endl;
        cout << "Historial: " << usuarios[id - 1].Usuario::Historial() << endl << endl;
    };

    void print_historial_usuarios(int id) {

        string name = usuarios[id - 1].Usuario::Nombre();
        string surname = usuarios[id - 1].Usuario::Apellido();
        cout << endl;
        cout << "Historial Usuario " << name << " " << surname << endl;
        int i = 0;
        while (i < historiales.size()) {
            if (historiales[i].Historial::ID_h() == usuarios[id - 1].Usuario::DNI()) {
                int j = 0;
                while (j < libros.size()) {
                    if (libros[j].Libro::ISBN() == historiales[i].Historial::ISBN_h()) {
                        cout << "ID: " << libros[j].Libro::ID() << endl;
                        cout << "Título: " << historiales[i].Historial::Titulo_h() << endl;
                        cout << "ISBN: " << historiales[i].Historial::ISBN_h() << endl;
                        cout << "Categoría: " << historiales[i].Historial::Categoria_h() << endl << endl;
                        break;
                    }
                    ++j;
                }
            }
            ++i;
        }
    };


    void menu_principal() {

        int num;
        int opcion = 0;

        cargar_admins();

        string aux;
        string User;
        string Pass;
        int c = 1;
        int i = 0;
        bool f = false;

        while (c <= 3 and !f) {

            system("cls");

            cout << "********************** Ingreso al Sistema **********************" << endl;
            cout << "Usuario (user) : ";
            cin >> User;

            cout << "Contraseña (password) : ";
            cin >> Pass;
            ++c;

            if(Pass.size() >= 8) {
                i = 0;
                while (i < admins.size()) {
                    if ((User == admins[i].User()) and (Pass == admins[i].Password())) {
                        f = true;
                        break;
                    } else {
                        cout << "********************** ERROR ****************" << endl;
                        cout << "El usuario o la contraseña son incorrectos. *" << endl;
                        cout << "*********************************************" << endl;
                        system("pause");
                    }
                    ++i;
                }
            }
            else {
                cout << "*************************** ERROR ***************************" << endl;
                cout << "La contraseña o password debe tener al menos 8 caracteres.  *" << endl;
                cout << "*************************************************************" << endl;
                system("pause");
            }
        }

        if(!f) {
            cout << "**************** ERROR ******************" << endl;
            cout << "Intento tres veces sin exito. Saliendo. *" << endl;
            cout << "*****************************************" << endl;
            system("pause");
        }
        else {
            system("cls");
            cout << "  ######    ####    ######   ####      ####     #####   ######   #######    ####     ##               ####              ####  " << endl;
            cout << "   ##  ##    ##      ##  ##   ##        ##     ##   ##  # ## #    ##   #   ##  ##   ####             ##  ##            ##  ## " << endl;
            cout << "   ##  ##    ##      ##  ##   ##        ##     ##   ##    ##      ## #    ##       ##  ##                ##            ## ### " << endl;
            cout << "   #####     ##      #####    ##        ##     ##   ##    ##      ####    ##       ##  ##              ###             ###### " << endl;
            cout << "   ##  ##    ##      ##  ##   ##   #    ##     ##   ##    ##      ## #    ##       ######             ##               ### ## " << endl;
            cout << "   ##  ##    ##      ##  ##   ##  ##    ##     ##   ##    ##      ##   #   ##  ##  ##  ##            ##  ##     ##     ##  ## " << endl;
            cout << "  ######    ####    ######   #######   ####     #####    ####    #######    ####   ##  ##            ######     ##      ####  " << endl << endl;

            cout << "BIENVENIDO A LA BIBLIOTECA 2.0" << endl << endl;

            while (opcion != 6) {

                cout << "1 - Consultar libros disponibles." << endl;
                cout << "2 - Consultar historial de libros de una persona." << endl;
                cout << "3 - Consultar libro asociado a una persona." << endl;
                cout << "4 - Asignar libro." << endl;
                cout << "5 - Devolver libro." << endl;
                cout << "6 - Salir" << endl << endl;

                cout << "Introduczca el número de la acción que desea realizar: ";
                cin >> opcion;

                cout << endl;

                switch (opcion) {
                    case 1:
                        print_libros_disponibles();
                        break;
                    case 2:
                        print_usuarios();

                        cout << "Elige ID usuario a consultar: ";
                        cin >> num;
                        if (num > 0 and num < 21){
                            print_historial_usuarios(num);
                        } else {
                            cout << "No existe el usuario con ID " << num << "." << endl << endl;
                        }
                        break;
                    case 3:
                        print_usuarios();

                        cout << "Elige ID usuario a consultar: ";
                        cin >> num;
                        if (num > 0 and num < 21){
                            print_usuario(num);
                        } else {
                            cout << "No existe el usuario con ID " << num << "." << endl << endl;
                        }
                        break;
                    case 4:
                        print_usuarios();

                        cout << "Elige ID usuario a asignar libro: ";
                        cin >> num;
                        if (num > 0 and num < 21){
                            asignar_libro(num);
                        } else {
                            cout << "No existe el usuario con ID " << num << "." << endl << endl;
                        }
                        break;

                    case 5:
                        print_usuarios();

                        cout << "Elige ID usuario a desasignar libro: ";
                        cin >> num;
                        if (num > 0 and num < 21){
                            desasignar_libro(num);
                        } else {
                            cout << "No existe el usuario con ID " << num << "." << endl << endl;
                        }
                        break;
                    case 6:
                        guardar_ficheros();
                        cout << "Gracias por confiar en Bilioteca 2.0" << endl;
                        system("pause");
                        break;
                    default:
                        cout << "Opcion incorrecta" << endl << endl;
                        break;
                }
            }
        }
    };
};


int main(int argc, char const *argv[]) {

    Biblioteca biblioteca;

    biblioteca.cargar_usuarios();

    biblioteca.cargar_libros();

    biblioteca.menu_principal();

    return 0;

}