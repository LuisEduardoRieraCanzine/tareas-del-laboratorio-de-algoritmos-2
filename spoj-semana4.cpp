#include <iostream>

using namespace std; 

int main() {
    uint32_t n, p1, d1, r1, m1, p2, d2, r2, m2;
    // Leemos n, p1, d1, r1, m1, p2, d2, r2:
    cin >> n >> p1 >> d1 >> r1 >> m1 >> p2 >> d2 >> r2 >> m2;
  
    uint32_t A[n][n], B[n][n];
    uint64_t C[n][n] = {0}, 
    V[n] = {0};

    // Asignamos los valores de A y de B
    for (uint32_t i = 0; i < n; ++i) {
        for (uint32_t j = 0; j < n; ++j) {
            d1 = d1 * p1 + r1;
            d2 = d2 * p2 + r2;
            A[i][j] = d1 >> (32 - m1);
            B[i][j] = d2 >> (32 - m2);
        }
    }

    // Hacemos la multiplicacion de matrices de forma estandar
    for (uint32_t i = 0; i < n; ++i) {
        for (uint32_t k = 0; k < n; ++k) {
            for (uint32_t j = 0; j < n; ++j) {
                C[i][j] += uint64_t(A[i][k]) * uint64_t(B[k][j]);
            }
        }
    }

    // Asignamos los valores de V 
    for (uint32_t i = 0; i < n; ++i) {
        for (uint32_t j = 0; j < n; ++j) {
            V[i] ^= C[i][j];
        }
    }

    // imprimimos V[0], ..., V[n-1], separados por un espacio:
    for (uint32_t i = 0; i < n; ++i) {
        cout << V[i] << " ";
    }
    cout << endl;

    return 0;
}
