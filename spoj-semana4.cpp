#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

////// NO FUNCIONA BIEN


// Definición de un alias para vector<unsigned long>
typedef vector<unsigned long> VectorUL;

// Definición de un alias para vector<vector<unsigned long>>
typedef vector<vector<unsigned long>> MatrizUL;

// Función para calcular la potencia de 2 que sea cota mínima de un número n
int proxPot2(int numero) {
    int pos = int(log2(numero)) + 1;
    return 1 << pos;
}

// Suma de matrices
MatrizUL suma_matrices(const MatrizUL& A, const MatrizUL& B) {
    int n = A.size();
    MatrizUL C(n, VectorUL(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Resta de matrices
MatrizUL resta_matrices(const MatrizUL& A, const MatrizUL& B) {
    int n = A.size();
    MatrizUL C(n, VectorUL(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Multiplicación de matrices por el algoritmo de Strassen
MatrizUL strassen_multiplicacion(const MatrizUL& A, const MatrizUL& B) {
    int n = A.size();
    MatrizUL C(n, VectorUL(n));

    if (n <= 16) { // Cambio a algoritmo convencional para tamaños pequeños
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                C[i][j] = 0;
                for (int k = 0; k < n; ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    } else {
        int mitad = n / 2;

        // División de las matrices en submatrices
        MatrizUL A11(mitad, VectorUL(mitad));
        MatrizUL A12(mitad, VectorUL(mitad));
        MatrizUL A21(mitad, VectorUL(mitad));
        MatrizUL A22(mitad, VectorUL(mitad));

        MatrizUL B11(mitad, VectorUL(mitad));
        MatrizUL B12(mitad, VectorUL(mitad));
        MatrizUL B21(mitad, VectorUL(mitad));
        MatrizUL B22(mitad, VectorUL(mitad));

        for (int i = 0; i < mitad; ++i) {
            for (int j = 0; j < mitad; ++j) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + mitad];
                A21[i][j] = A[i + mitad][j];
                A22[i][j] = A[i + mitad][j + mitad];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + mitad];
                B21[i][j] = B[i + mitad][j];
                B22[i][j] = B[i + mitad][j + mitad];
            }
        }

        // Cálculo de los términos de apoyo
        MatrizUL M1 = strassen_multiplicacion(suma_matrices(A11, A22), suma_matrices(B11, B22));
        MatrizUL M2 = strassen_multiplicacion(suma_matrices(A21, A22), B11);
        MatrizUL M3 = strassen_multiplicacion(A11, resta_matrices(B12, B22));
        MatrizUL M4 = strassen_multiplicacion(A22, resta_matrices(B21, B11));
        MatrizUL M5 = strassen_multiplicacion(suma_matrices(A11, A12), B22);
        MatrizUL M6 = strassen_multiplicacion(resta_matrices(A21, A11), suma_matrices(B11, B12));
        MatrizUL M7 = strassen_multiplicacion(resta_matrices(A12, A22), suma_matrices(B21, B22));

        // Cálculo de las submatrices de C
        MatrizUL C11 = suma_matrices(resta_matrices(suma_matrices(M1, M4), M5), M7);
        MatrizUL C12 = suma_matrices(M3, M5);
        MatrizUL C21 = suma_matrices(M2, M4);
        MatrizUL C22 = suma_matrices(resta_matrices(suma_matrices(M1, M3), M2), M6);

        // Construcción de C a partir de las submatrices
        for (int i = 0; i < mitad; ++i) {
            for (int j = 0; j < mitad; ++j) {
                C[i][j] = C11[i][j];
                C[i][j + mitad] = C12[i][j];
                C[i + mitad][j] = C21[i][j];
                C[i + mitad][j + mitad] = C22[i][j];
            }
        }
    }

    return C;
}

int main() {
    unsigned int n, d1, p1, r1, m1, d2, p2, r2, m2;
    cin >> n >> d1 >> p1 >> r1 >> m1 >> d2 >> p2 >> r2 >> m2;

    int proxPot2n = proxPot2(n);

    MatrizUL A(proxPot2n, VectorUL(proxPot2n, 0)), B(proxPot2n, VectorUL(proxPot2n, 0)), C(proxPot2n, VectorUL(proxPot2n, 0));
    VectorUL V(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            d1 = d1 * p1 + r1;
            d2 = d2 * p2 + r2;
            A[i][j] = d1 >> (32 - m1);
            B[i][j] = d2 >> (32 - m2);
        }
    }

    // Hacer la multiplicación
    C = strassen_multiplicacion(A, B);

    // Calcular el vector V
    for (int i = 0; i < n; ++i) {
        V[i] = 0;
        for (int j = 0; j < n; ++j) {
            V[i] ^= C[i][j];
        }
    }

    // Imprimir el vector V
    for (int i = 0; i < n; ++i) {
        cout << V[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
