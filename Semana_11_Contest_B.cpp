#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {

    //Esto supuestamente mejora el rendimiento
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //Casos de prueba (1 ≤ t ≤ 2*10^4)
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        //Longitud del arreglo de Vasya (1≤ n ≤2*10^5)
        int n;
        cin >> n;

        //Rellenar el vector inicial "a" (1 ≤ a[i] ≤10^9)
        vector<int> a(n,0);
        for (int j = 0; j < n; j++) 
        {
            cin >> a[j];
        }

        // Ordenar el vector "a" y eliminar los elementos repetidos
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        //Iniciamos variables para hacer el proceso
        int respuesta = 0;
        int segmento = 0;

        //Recorremos el vector a para ver hasta donde podemos 
        //igualar los elementos al sumarle una perutación
        for (int j = 0; j < a.size(); j++)
        {
            int k = segmento;
            while ( k < a.size() )
            {   
                //verificamos que al sumarle elementos de la permutacion puedan ser iguales.1
                if( a[k]-a[j] < n )
                {
                    //k-(j-1) son todos los elementos igualables hasta este punto de la iteracion
                    //tomando como base del proceso e verificación al numero en la posición j
                    int convertibles = k-(j-1);
                    respuesta = max(respuesta, convertibles);
                    k++;
                }
                //Si entramos aqui es porque no se puede sumar un numero d ela permutación que iguale a[j] con a[k]
                //y por tanto no se va a docer hacer con los valores de k mayores (el pues el arreglo esta ordenado)
                else
                {
                    //Con esto iniciamos k en donde esta terminando
                    segmento = k;
                    break;
                }
            }
        }

        //Resultado
        cout << respuesta << endl;
    }

    return 0;
}
