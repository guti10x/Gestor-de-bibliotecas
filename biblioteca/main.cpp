#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;


class Libro {
private:
    string titulo;
    string categoria;
    int isbn;
    int prestado;
public:
    Libro() {
        titulo = "";
        categoria = "";
        isbn = 0;
        prestado = 0;
    }
    Libro(string new_title, string new_cat, int new_isbn, int new_borrow) {
        titulo = std::move(new_title);
        categoria = std::move(new_cat);
        isbn = new_isbn;
        prestado = new_borrow;
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

    [[nodiscard]] int ID() const {
        return id;
    }

    string Historial() {
        return historial;
    }

    void getHistorial() {

        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        fstream file("../csv/" + dni + ".csv", ios::in);
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
            for (int j = 0; j < content[i].size(); j++){
                if (i > 0){
                    cout << content[i][j] << endl;
                 }
            }
        }
    }
    
};


class Historial {
private:
    long int id;
    string titulo;
    int isbn;
    string categoria;
public:
    Historial() {
        id = 0;
        titulo = "";
        isbn = 0;
        categoria = "";
    };
    Historial(long int new_id, string new_title, int new_isbn, string new_cat) {
        id = new_id;
        titulo = std::move(new_title);
        isbn = new_isbn;
        categoria = std::move(new_cat);
    };
};


class biblioteca {
private:
    string nombre;
    vector<Cliente> clientes;
    vector<Libro> libros;
    vector<Historial> historiales;
public:
    biblioteca() {
        nombre = "CRAI Dulce Chacón";
    };

    /*void crear_libro() {
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

    };*/

    /*void guardar_libro(const string& t, const int& i, const string& c, const int& d) {
        libros.emplace_back(t, i, c, d);
    };*/
    void guardar_historial(long int id, const string& t, int i, const string& c) {
        historiales.emplace_back(id, t, i, c);
    };

    void guardar_cliente(int i, const string& n, const string& a, const string& d, const string& ac, const string& h) {
        clientes.emplace_back(i, n, a, d, ac, h);

        vector<vector<string>> content;
        vector<string> row;
        string line, word;

        cout << "../csv/" + h << endl;

        fstream file("../csv/" + h, ios::in);
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

        for (int j = 0; j < content.size(); j++) {
            if (j > 0){
                guardar_historial(j, content[j][0], std::stoi(content[j][1]), content[j][2]);
            }
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

    void print_historial(int id) {

        string name = clientes[id - 1].Cliente::Nombre();
        string surname = clientes[id - 1].Cliente::Apellido();
        string history = clientes[id - 1].Historial();
        cout << "Historial Cliente " << name << " " << surname << endl;
        cout << "Historial Cliente " << name << " " << surname << endl;
        cout << "Historial Cliente " << name << " " << surname << endl;
        cout << "Historial Cliente " << name << " " << surname << endl;
    };
};


int main() {

    Cliente c;
    biblioteca biblioteca;

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
        if (i > 0){
            biblioteca.guardar_cliente(i, content[i][0], content[i][1], content[i][2], content[i][3], content[i][4]);
        }
    }
    file.close();
    biblioteca.print_clientes();
    biblioteca.print_historial(1);

    return 0;
}