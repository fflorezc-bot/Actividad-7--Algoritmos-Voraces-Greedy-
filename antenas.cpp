#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, R;
    //datos
    cout << "Cantidad de casas: ";
    cin >> n;
    vector<int> casas(n);
    cout << "Posiciones: ";
    for (int &c : casas) cin >> c;
    cout << "Cobertura R: ";
    cin >> R;

    // Las casas pueden venir desordenadas, asi que primero se ordenan
    sort(casas.begin(), casas.end());

    int cantidad = 0;   // antenas usadas
    int i = 0;          // primera casa que todavia no esta cubierta
    cout << "Antenas en:\n";

    while (i < n) {
   // ahora la estrategia greddy
        // La casa i no esta cubierta, asi que necesita una antena, la ponemos lo mas a la derecha posible sin dejar fuera a la casa i
        int antena = casas[i] + R; // en casas[i] + R. Asi cubre mas casas hacia la derecha
        cout << antena;
        cantidad++;

        // Saltamos todas las casas que ya quedaron cubiertas por esta antena
        while (i < n && casas[i] <= antena + R) i++;
    }

    cout << "Cantidad total: " << cantidad << "\n";
    return 0;
}
