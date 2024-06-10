#include <iostream>
#include <string>

using namespace std;

/*
la idea consiste en ir eliminando parejas de forma local e ir contando si se requieren reemplazos ,
y ver que queda al final
*/

int main() {

    string s;
    cin >> s;

    // Si la cantidad de elementos es impar, no se pueden emparejar todos los signos
    bool imposible = false;
    if(s.size() % 2 == 1)
    {
        imposible = true;
    }

    // Creamos contadores para los signos de apertura y cierre
    int i=0;
    int aper=0 , cerr=0, reemplazos=0;

    while (i < s.size() && imposible == false)
    {
        
        // Contamos cada vez que tengamos un signo de apertura o de cierre
        if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == '<')
        {
            aper++;
        }
        else
        {
            cerr++;
        }

        // Si en algún momento hay mas signo de cierre que de apertura, ya no se pueden emmparejar todos
        if( aper < cerr)
        {
            imposible = true;
            break;
        }

        //Si detecto un signo de cierre, lo elimino junto con el signo anterior
        //y regresoal signo de apertura anterior (se que sera de apertura porque voy leyendo asi -->)
        if ( s[i] == ')' || s[i] == '}' || s[i] == ']' || s[i] == '>' )
        {
            if ( i > 0)
            {
                if ( ( s[i-1]!= '(' && s[i] == ')' ) ||
                     ( s[i-1]!= '{' && s[i] == '}' ) || 
                     ( s[i-1]!= '[' && s[i] == ']' ) || 
                     ( s[i-1]!= '<' && s[i] == '>' ) )
                {
                    reemplazos++;
                }
                
                s.erase(i-1, 2);
                i -=2;             // restar 2 es lo que hace que el proceso cuadre, lo lo detecte de forma empírica
            }
        }
            
        i++;
    }

    if ( aper != cerr)
    {
        imposible = true;
    }
    
    // Salida del prpgrama segun sea el caso
    if ( imposible == true)
    {
    cout << "Impossible" << endl;
    }
    else
    {
        cout << reemplazos;
    }

    return 0;
}
