#include <iostream>
#include <vector>

using namespace std;


bool allOnesInRow(const std::vector<std::vector<int>>& matrix, int rowIndex) {
    for (int element : matrix[rowIndex]) {
        if (element != 1) {
            return false;
        }
    }
    return true;
}

bool allOnesInCol(const std::vector<std::vector<int>>& matrix, int colIndex) {
    for (const auto& row : matrix) {
        if (row[colIndex] != 1) {
            return false;
        }
    }
    return true;
}

int main() {
    // Leer las dimensiones de la matriz B (número de filas y columnas)
    int m, n;
    cin >> m >> n;

    // Crear una matriz B con m filas y n columnas, inicializada con ceros
    vector<vector<int>> B(m, vector<int>(n));

    // Leer los elementos de la matriz B fila por fila
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            // Leer un elemento de la matriz B
            cin >> B[i][j];
        }
    }

    // Crear una matriz A con m filas y n columnas, inicializada con unos
    vector<vector<int>> A(m, vector<int>(n, 0));


    // Aplicar las reglas de la lógica para construir la matriz A
    // Para que A[i][j]==1, debe ocurrir que toda la fila i de B y la columna j de B sean de 1's
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if( allOnesInRow(B,i) && allOnesInCol(B,j))
            {
                A[i][j] = 1;
            }
        }
    }

    // Verificar si todos los elementos de la matriz A y B son ceros
    bool allZeroA = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                allZeroA = false;
                break;
            }
        }
        if (!allZeroA) break;
    }

    bool allZeroB = true;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (B[i][j] != 0) {
                allZeroB = false;
                break;
            }
        }
        if (!allZeroB) break;
    }

    // Imprimir el resultado
    if (allZeroA == allZeroB) 
    {
        cout << "YES" << endl;
        // Imprimir la matriz A
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if(allZeroA != allZeroB) 
    {
        cout << "NO" << endl;
    }

    // for (int i = 0; i < m; i++) 
    // {
    //     for (int j = 0; j < n; j++) 
    //     {
    //     cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}
