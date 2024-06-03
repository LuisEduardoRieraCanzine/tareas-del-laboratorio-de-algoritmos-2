#include <iostream>
#include <vector>

using namespace std;

/*
Notemos que si hay (al menos) k números iguales dentro del arreglo de enteros,
se puede ir convirtiendo (y eliminando uno de ellos) a todos esos 
en otro número x (existente dentro del arreglo) para volver a completar
nuevamente k números iguales. Este proceso se puede hacer hasta que 
queden k números en el arreglo. Luego, concluimos que si en el arrelgo
hay k números iguales, el resultado del proceso sera k-1. Sino hay k
números iguales no se puee hacer nada, y el resultado será el tamaño
del arreglo.
*/

// Función para calcular el número de cartas restantes.
int cambioDeCartas(int &n, int &k, vector<int> &cartas)
{
    // Como los números no son muy grande podemos contar la frecuencia
    // para saber si alguno alcaza a repetirse k veces

    vector<int> frecuencia(101,0);   // Según el problema los valores varían de 1 a 100.
    for (int i = 0; i < n; i++)
    {
        frecuencia[cartas[i]]++;
    }

    for (int i = 0; i < 101; i++)      
    {                                  
        if ( frecuencia[i] >= k)
        {
            return k-1;
        }
    }
    
    return n;
}

int main() {
    
    // Leer el número de casos de prueba
    int t = 0;
    cin >> t; 

    //Ingresar Todos los casos de prueba
    for (int i = 0; i < t; i++)
    {
        // Leer el número de cartas y el número de cartas a intercambiar (1≤n≤100, 2≤k≤100)
        int n, k;
        cin >> n >> k;

        // Leer los valores de las cartas (1 ≤ ci ≤ 100)
        vector<int> cartas(n,0);
        for (int i = 0; i < n; i++) 
        {
            cin >> cartas[i]; 
        }

        // Calcular el minimo numero da cartas posibles y mostrarlo
        cout << cambioDeCartas(n, k, cartas) << endl;
    }
    
    //tenrminar el programa
    return 0;
}
