#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;


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


class Cliente {
private:
    int id;
    string nombre;
    string apellido;
    string dni;
    string libro_en_posesion;
    string historial;

public:
    Cliente() {
        id = 0;
        nombre = "";
        apellido = "";
        dni = "";
        libro_en_posesion = "";
        historial = "";
    }

    Cliente(int id_new, string nuevo_nombre, string nuevo_apellido, string nuevo_dni, string nuevo_libro,
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
    vector<Cliente> clientes;
    vector<Libro> libros;
    vector<Historial> historiales;
public:
    Biblioteca() = default;

    void guardar_libros(int id, const string &t, const string &i, const string &c, const string& d) {
        libros.emplace_back(id, t, i, c, d);
    };

    void guardar_historiales(const string &id, const string &t, const string &i, const string &c) {
        historiales.emplace_back(id, t, i, c);
    };

    void guardar_clientes(int id, const string &n, const string &a, const string &d, const string &ac, const string &h) {
        clientes.emplace_back(id, n, a, d, ac, h);
    };

    void asignar_libro(int id) {
        string name = clientes[id - 1].Cliente::Nombre();
        string surname = clientes[id - 1].Cliente::Apellido();
        string dni = clientes[id - 1].Cliente::DNI();
        if (clientes[id - 1].Cliente::Libro_actual() == "Ninguno"){
            cout << "Asignar nuevo libro a cliente: " << name << " " << surname << endl;
            print_libros_disponibles();
            int new_book_id = 0;
            cout << "Elegir ID de nuevo libro a asignar: ";
            cin >> new_book_id;
            cout << endl;
            guardar_historiales(dni, libros[new_book_id - 1].Libro::Titulo(), libros[new_book_id - 1].Libro::ISBN(), libros[new_book_id - 1].Libro::Categoria());
            cout << "Asignado nuevo libro: " << endl;
            cout << "Título: " << libros[new_book_id - 1].Libro::Titulo() << endl;
            cout << "ISBN: " << libros[new_book_id - 1].Libro::ISBN() << endl;
            cout << "Categoría: " << libros[new_book_id - 1].Libro::Categoria() << endl;
            cout << endl;
            libros[new_book_id - 1].Cambiar_prestado("0");
        }
        else {
            cout << "Usuario ya tiene libro asignado, volviendo al menú." << endl;
            cout << endl;
        }

    };

    void desasignar_libro(int id) {
        string name = clientes[id - 1].Cliente::Nombre();
        string surname = clientes[id - 1].Cliente::Apellido();
        string dni = clientes[id - 1].Cliente::DNI();
        if (clientes[id - 1].Cliente::Libro_actual() != "Ninguno"){
            cout << "Desaignar libro a cliente: " << name << " " << surname << endl;
            string old_book_name = clientes[id - 1].Cliente::Libro_actual();
            int old_book_id = 0;
            int i = 0;
            while (i < libros.size()){
                if (libros[i].Libro::Titulo() == old_book_name){
                    old_book_id = libros[i].Libro::ID();
                }
                ++i;
            }
            guardar_historiales(dni, libros[old_book_id - 1].Libro::Titulo(), libros[old_book_id - 1].Libro::ISBN(), libros[old_book_id - 1].Libro::Categoria());
            cout << "Desasignado libro: " << endl;
            cout << "Título: " << libros[old_book_id - 1].Libro::Titulo() << endl;
            cout << "ISBN: " << libros[old_book_id - 1].Libro::ISBN() << endl;
            cout << "Categoría: " << libros[old_book_id - 1].Libro::Categoria() << endl;
            cout << endl;
            clientes[id - 1].Cambiar_actual("Ninguno");
            libros[old_book_id - 1].Cambiar_prestado("1");
        }
        else {
            cout << "Usuario no tiene libro asignado, volviendo al menú." << endl;
            cout << endl;
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
            cout << "Disponible: " << libros[i].Libro::Disponible() << endl;
            cout << endl;
            cout << endl;
            ++i;
        }
    };

    void print_libros_disponibles() {
        cout << "Libros: " << endl;
        int i = 0;
        while (i < libros.size()) {
            if (libros[i].Libro::Disponible() == "1"){
                cout << "ID: " << libros[i].Libro::ID() << endl;
                cout << "Título: " << libros[i].Libro::Titulo() << endl;
                cout << "ISBN: " << libros[i].Libro::ISBN() << endl;
                cout << "Categoría: " << libros[i].Libro::Categoria() << endl;
                cout << "Disponible: " << libros[i].Libro::Disponible() << endl;
                cout << endl;
            }
            ++i;
        }
    };

    void print_clientes() {
        cout << "Clientes: " << endl;
        int i = 0;
        while (i < clientes.size()) {
            cout << "ID: " << clientes[i].Cliente::ID() << endl;
            cout << "Nombre: " << clientes[i].Cliente::Nombre() << endl;
            cout << "Apellido: " << clientes[i].Cliente::Apellido() << endl;
            cout << "DNI: " << clientes[i].Cliente::DNI() << endl;
            cout << "Libro en posesion: " << clientes[i].Cliente::Libro_actual() << endl;
            cout << "Historial: " << clientes[i].Cliente::Historial() << endl;
            cout << endl;
            cout << endl;
            ++i;
        }
    };

    void print_cliente(int id) {
        string name = clientes[id - 1].Cliente::Nombre();
        string surname = clientes[id - 1].Cliente::Apellido();
        string dni = clientes[id - 1].Cliente::DNI();
        cout << "Cliente: " << name << " " << surname << endl;
        cout << "ID: " << clientes[id - 1].Cliente::ID() << endl;
        cout << "Nombre: " << clientes[id - 1].Cliente::Nombre() << endl;
        cout << "Apellido: " << clientes[id - 1].Cliente::Apellido() << endl;
        cout << "DNI: " << clientes[id - 1].Cliente::DNI() << endl;
        cout << "Libro en posesion: " << clientes[id - 1].Cliente::Libro_actual() << endl;
        cout << "Historial: " << clientes[id - 1].Cliente::Historial() << endl;
        cout << endl;
        cout << endl;
    };

    void print_historial_cliente(int id) {

        string name = clientes[id - 1].Cliente::Nombre();
        string surname = clientes[id - 1].Cliente::Apellido();
        cout << "Historial Cliente " << name << " " << surname << endl;
        int i = 0;
        while (i < historiales.size()) {
            if (historiales[i].Historial::ID_h() == clientes[id - 1].Cliente::DNI()){
                int j = 0;
                while (j < libros.size()){
                    if (libros[j].Libro::ISBN() == historiales[i].Historial::ISBN_h()){
                        cout << "ID: " << libros[j].Libro::ID() << endl;
                    }
                    ++j;
                }
                cout << "Título: " << historiales[i].Historial::Titulo_h() << endl;
                cout << "ISBN: " << historiales[i].Historial::ISBN_h() << endl;
                cout << "Categoría: " << historiales[i].Historial::Categoria_h() << endl;
                cout << endl;
            }
            ++i;
        }
    };
};


int main() {

    Cliente cliente{};
    Libro libro{};
    Historial historial{};
    Biblioteca biblioteca;
    Biblioteca Biblioteca(string name = "CRAI Dulce Chacón");

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
        cout << "Could not open the file\n";

    for (int i = 0; i < content.size(); i++) {
        if (i > 0) {
            biblioteca.guardar_clientes(i, content[i][0], content[i][1], content[i][2], content[i][3], content[i][4]);

            vector<vector<string>> content2;
            vector<string> row2;
            string line2, word2;

            string d = content[i][2];
            string h = content[i][4];

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
                cout << "Could not open the file\n";

            for (int j = 0; j < content2.size(); j++) {
                if (j > 0) {
                    biblioteca.guardar_historiales(d, content2[j][0], content2[j][1], content2[j][2]);
                }
            }
            file2.close();
        }
    }
    file.close();

    vector<vector<string>> content3;
    vector<string> row3;
    string line3, word3;

    fstream file3("../csv/libros.csv", ios::in);
    if (file3.is_open()) {
        while (getline(file3, line3)) {
            row3.clear();

            stringstream str3(line3);

            while (getline(str3, word3, ','))
                row3.push_back(word3);
            content3.push_back(row3);
        }
    } else
        cout << "Could not open the file\n";

    for (int i = 0; i < content3.size(); i++) {
        if (i > 0) {
            biblioteca.guardar_libros(i, content3[i][0], content3[i][1], content3[i][2], content3[i][3]);
        }
    }
    file3.close();

    // biblioteca.print_clientes(); // Imprime todos los clientes.
    // biblioteca.print_libros(); // Imprime todos los libros.
    // biblioteca.print_historial_cliente(1); // Imprime el historial de un cliente.
    // biblioteca.print_libros_disponibles(); // Imprime todos los libros disponibles.
    // biblioteca.asignar_libro(1); // Permite asignar un libro a un usuario.
    // Imprime la lista de libros disponibles para elegir, parámetro de entrada ID del cliente a asignar el libro.
    // biblioteca.print_historial_cliente(1); // Imprime el historial de un cliente. Puesto para comprobar que se asignaba.
    // biblioteca.print_cliente(1); // Imprime un cliente. Parámentro de entrada ID del cliente.
    // biblioteca.desasignar_libro(1); // Desasignar un libro a un cliente. Parámetro de entrada ID del cliente.

    return 0;
}