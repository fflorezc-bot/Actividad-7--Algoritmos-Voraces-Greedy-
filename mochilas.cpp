#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Cada objeto tiene un nombre, un valor y un peso
struct Objeto {
    string nombre;
    double valor, peso;
};

int main() {
    double capacidad;
    int n;

    //datos
    cout << "Capacidad: ";
    cin >> capacidad;
    cout << "Cantidad de objetos: ";
    cin >> n;

    vector<Objeto> obj(n);
    for (auto &o : obj) {
        cout << "Nombre valor peso: ";
        cin >> o.nombre >> o.valor >> o.peso;
    }

    //la estrategia Greedy
    // ordenar los objetos por valor/peso de mayor a menory se compara a.valor/a.peso > b.valor/b.peso, 
    //pero multiplicando en cruz para no tener que dividir
    sort(obj.begin(), obj.end(), [](const Objeto &a, const Objeto &b) {
        return a.valor * b.peso > b.valor * a.peso;
    });

    double total = 0;   // valor total que llevamos en la mochila
    cout << "Objetos seleccionados:\n";

    for (auto &o : obj) {
        // si ya no queda espacio, terminamos
        if (capacidad <= 0) break;

        if (o.peso <= capacidad) {
            // El objeto cabe completo: lo metemos entero
            cout << o.nombre << " completo\n";
            capacidad -= o.peso;
            total += o.valor;
        } else {
            // No cabe completo: tomamos solo la fraccion que cabe
            cout << capacidad << "/" << o.peso << " Parte del objeto " << o.nombre << "\n";
            total += o.valor * capacidad / o.peso;
            capacidad = 0;   // la mochila queda llena
        }
    }

    cout << "Valor total: " << total;
    return 0;
}
