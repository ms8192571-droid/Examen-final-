#include <iostream>
#include <string>
using namespace std;

class Publicacion {
protected:
    string titulo;
    string autor;
    int anio;

public:
    Publicacion(string t, string a, int an)
        : titulo(t), autor(a), anio(an) {}

    virtual int diasPrestamo() const = 0;

    virtual void imprimir() const {
        cout << "[" << anio << "] " << titulo << " - " << autor << endl;
        cout << "Prestamo: " << diasPrestamo() << " dias" << endl;
    }

    string getTitulo() const {
        return titulo;
    }

    virtual ~Publicacion() {}
};

ostream& operator<<(ostream& os, const Publicacion& p) {
    p.imprimir();
    return os;
}

class Libro : public Publicacion {
private:
    int paginas;

public:
    Libro(string t, string a, int an, int p)
        : Publicacion(t, a, an), paginas(p) {}

    int diasPrestamo() const override {
        if (paginas <= 300)
            return 14;
        else
            return 21;
    }

    void imprimir() const override {
        Publicacion::imprimir();
        cout << "Paginas: " << paginas << endl;
    }
};

class Revista : public Publicacion {
private:
    int numero;

public:
    Revista(string t, string a, int an, int n)
        : Publicacion(t, a, an), numero(n) {}

    int diasPrestamo() const override {
        return 7;
    }

    void imprimir() const override {
        Publicacion::imprimir();
        cout << "Numero: " << numero << endl;
    }
};

int main() {

    Publicacion* publicaciones[4];

    publicaciones[0] = new Libro( "Cien Anios de Soledad", "Gabriel Garcia Marquez", 1967, 471 );
    publicaciones[1] = new Revista( "Muy Interesante", "Editorial GYJ", 2025, 410 );
    publicaciones[2] = new Libro( "Harry Potter y la Piedra Filosofal", "J. K. Rowling", 1997, 223 );
    publicaciones[3] = new Revista( "National Geographic Kids", "National Geographic", 2024, 158 );

    cout << " CATALOGO DE LA BIBLIOTECA " << endl << endl;

    for (int i = 0; i < 4; i++) {
        cout << *publicaciones[i] << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete publicaciones[i];
        publicaciones[i] = nullptr;
    }

    return 0;
}