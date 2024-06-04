#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;

/*
A medida que se introducen los datos se llevan dos contadores que revisan si se han introducido (hasta cierto punto de la ejecución)
la misma cantidad de los dos tipos de sushi de forma balanceada, y se va registrando en "max" la cantidad máxima que hay de ambos hasta
cierto punto.
*/
 
int main()
{
    //Tamaño del arreglo.
    int n;
    cin >> n;
 
    //Introducimos los valores de la entrada del vector
    vector<int> mesa(n , 0);
    int t1=1 , t2=1 , max=1;
 
    cin >> mesa[0];
 
    for (int i = 1; i < n; i++)
    {
        cin >> mesa[i];
        
        if ( mesa[i] == 1 && mesa[i] == mesa[i-1])
        {
            t1++;
            //Si t2 ya paso por un valor por el cual t1 esta pasando, actualiza max con el valor mas bajo (t1)
            if ( t1 <= t2 &&  t1 > max)
            {
                max = t1;
            }  
        }
        else if ( mesa[i] == 2 && mesa[i] == mesa[i-1])
        {
            t2++;
            //Si t1 ya paso por un valor por el cual t2 esta pasando, actualiza max con el valor mas bajo (t2)
            if (t2 <= t1 &&  t2> max)
            {
                max = t2;
            }  
        }
        else if ( mesa[i] == 1 && mesa[i] != mesa[i-1])
        {
            //Comienza nuevamente el conteo 
            t1=1;
        }
        else if (mesa[i] == 2 && mesa[i] != mesa[i-1])
        {
            //Comienza nuevamente el conteo 
            t2=1;
        }
        
    }
    
    cout << 2*max << endl;
 
    return 0;
}
