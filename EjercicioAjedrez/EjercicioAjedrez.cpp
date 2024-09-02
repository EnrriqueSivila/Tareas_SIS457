#include <iostream>

using namespace std;

class Pieza {
private:
    short fila;
    short columna;

public:
    Pieza() : fila(1), columna(2) {}

    Pieza(short f, short c) {
        if (f >= 1 && f <= 8 && c >= 1 && c <= 8) {
            fila = f;
            columna = c;
        }
        else {
            cout << "Fila y columna deben estar entre 1 y 8. Estableciendo valores por defecto (1,1)." << endl;
            fila = 1;
            columna = 1;
        }
    }

    short getfila() const { return fila; }
    short getcolumna() const { return columna; }

    void verinfo() const {
        cout << "La fila es " << fila << ", la columna es " << columna << endl;
    }

    virtual void avanzar(short f, short c) = 0;
};

class Peon : public Pieza {
public:
    Peon(short f, short c) : Pieza(f, c) {}

    void avanzar(short f, short c) override {
        if (f < 1 || f > 8 || c < 1 || c > 8) {  
            cout << "Movimiento fuera de los límites del tablero. Intente de nuevo." << endl;
            return;
        }

        if (f == getfila() + 1 && c == getcolumna()) {  
            cout << "Peon movido a la fila " << f << ", columna " << c << endl;
        }
        else {  
            cout << "Movimiento no permitido para el Peon. Debe avanzar una fila adelante en la misma columna." << endl;
        }
    }
};

class Torre : public Pieza {
public:
    Torre(short f, short c) : Pieza(f, c) {}

    void avanzar(short f, short c) override {
        if (f < 1 || f > 8 || c < 1 || c > 8) { 
            cout << "Movimiento fuera de los límites del tablero" << endl;
            return;
        }

        if (f == getfila() || c == getcolumna()) { 
            cout << "Torre movida a la fila " << f << ", columna " << c << endl;
        }
        else { 
            cout << "Movimiento no permitido para la Torre. Debe moverse en línea recta" << endl;
        }
    }
};

int main() {
    short fila, columna;

    Peon peon(2, 2);
    Torre torre(1, 1);

    cout << "Informacion inicial del Peon:" << endl;
    peon.verinfo();

    cout << "Ingrese la nueva fila y columna para mover el Peon: ";
    cin >> fila >> columna;
    peon.avanzar(fila, columna);

    cout << "Informacion inicial de la Torre:" << endl;
    torre.verinfo();

    cout << "Ingrese la nueva fila y columna para mover la Torre: ";
    cin >> fila >> columna;
    torre.avanzar(fila, columna);

    return 0;
}
