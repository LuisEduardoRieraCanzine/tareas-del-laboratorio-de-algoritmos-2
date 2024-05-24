#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Sea cual sea el orden del arreglo, lo que se calcula es una suma telescópica,
entonces  al final lo que importa es la diferencia que hay entre el último 
elemento del arreglo y el primero. De esta forma, si el arreglo está ordenado
de forma creciente la diferencia es la maxima que podría ser.
*/ 

int main() {
    // Leer el número de casos de prueba (t)
    int t;
    scanf("%d", &t);

    // Esto hace t decresca y cuando sea cero acaba en ciclo
    while (t--) {
        // Leer la longitud del arreglo(n)
        int n;
        scanf("%d", &n);

        // Declarar el arreglo
        vector<int> arr(n,0);

        // Leer las entradas del arreglo
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Ordenar la matriz usando bubbleSort
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        // Imprimir el resultado
        printf("%d\n", arr[n-1]-arr[0]);
    }

    return 0;
}
