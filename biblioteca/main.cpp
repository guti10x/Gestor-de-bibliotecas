#include <iostream>
#include <fstream>
#include <string.h>
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
    Biblioteca() {};

    void guardar_libros(int id, const string &t, const string &i, const string &c, const string& d) {
        libros.emplace_back(id, t, i, c, d);
    };

    void guardar_historiales(const string &id, const string &t, const string &i, const string &c) {
        historiales.emplace_back(id, t, i, c);
    };

    void guardar_clientes(int id, const string &n, const string &a, const string &d, const string &ac, const string &h) {
        clientes.emplace_back(id, n, a, d, ac, h);
    };

    void print_libros() {
        cout << "Libros: " << endl;
        for (int i = 0; i < libros.size(); ++i) {
            cout << "ID: " << libros[i].Libro::ID() << endl;
            cout << "Título: " << libros[i].Libro::Titulo() << endl;
            cout << "ISBN: " << libros[i].Libro::ISBN() << endl;
            cout << "Categoría: " << libros.at(i).Libro::Categoria() << endl;
            cout << "Disponible: " << libros.at(i).Libro::Disponible() << endl;
            cout << endl;
            cout << endl;
        }
    };

    void print_clientes() {
        cout << "Clientes: " << endl;
        for (int i = 0; i < clientes.size(); ++i) {
            cout << "ID: " << clientes[i].Cliente::ID() << endl;
            cout << "Nombre: " << clientes[i].Cliente::Nombre() << endl;
            cout << "Apellido: " << clientes[i].Cliente::Apellido() << endl;
            cout << "DNI: " << clientes.at(i).Cliente::DNI() << endl;
            cout << "Libro en posesion: " << clientes.at(i).Cliente::Libro_actual() << endl;
            cout << "Historial: " << clientes[i].Cliente::Historial() << endl;
            cout << endl;
            cout << endl;
        }
    };

    void print_historial_cliente(int id) {

        string name = clientes[id - 1].Cliente::Nombre();
        string surname = clientes[id - 1].Cliente::Apellido();
        string history = clientes[id - 1].Historial();
        cout << "Historial Cliente " << name << " " << surname << endl;
        for (int i = 0; i < historiales.size(); ++i) {
            if (historiales[i].Historial::ID_h() == clientes[id - 1].Cliente::DNI()){
                cout << "Título: " << historiales[i].Historial::Titulo_h() << endl;
                cout << "ISBN: " << historiales[i].Historial::ISBN_h() << endl;
                cout << "Categoría: " << historiales[i].Historial::Categoria_h() << endl;
                cout << endl;
            }
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

    biblioteca.print_clientes();
    biblioteca.print_libros();
    biblioteca.print_historial_cliente(1);

    return 0;
}