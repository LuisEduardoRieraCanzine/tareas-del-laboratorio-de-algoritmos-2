#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*
cartas = 2*h + 3*h*(h-1)/2 es el número de cartas que se necesitan para construir la torre de nivel h. Es facil llegar a es aconclusión resolviendo una 
sencilla ecuación recursiva de la forma "a_{h+1} = a_{h} + 2(h+1) + h"  que da el número de cartas del nivel h+1 en función del número de cartas del nivel h.
*/

int main()
{
    
    //Entrada de números de casos de prueba (t).
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        //Número de cartas (n).
        int n;
        cin >> n;
        
        //Numeor de piramides construidas (k).
        int k = 0;

        //Verificar cuantas piramides maximale se pueden construir.
        while ( n >= 2)
        {
            //Iniciamos (h) y (cartas).
            int h = 1;
            int cartas = 2*h + 3*h*(h-1)/2;

            //Cuando el ciclo se acabe es porque a ese nivel no se puede llegar.
            while (n >= cartas)
            {
                h++;
                cartas = 2*h + 3*h*(h-1)/2;
            }

            h--;
            cartas = 2*h + 3*h*(h-1)/2;
            n = n - cartas;
            k++;
        }

        cout << k << endl;
    }
    
    return 0;
}
