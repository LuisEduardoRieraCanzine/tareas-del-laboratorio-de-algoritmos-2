#include <iostream>
#include <cstdio>
#include <vector>  
#include <algorithm>

using namespace std;

/*
Lo que haremos será que a medida que se estén ingresando los números del mensaje,
se irán aguardando en un vector de tripletas (3-vectores) la frecuencia del número,
y un número que indicara cuando fue ingresado por primera vez.
*/


/*
Función para verificar que un entero sea distinto a unos valores dados en un vector vectores.
Esta funcion es necesaría para hacer el control de flujo al momento de ingresar los números 
del mensaje.
*/
vector<int> pertenece_y_posicion(int &num, vector<vector<int>> &vec)
{

    vector<int> pertenece_y_posicion = {0 , -1};
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i][0] == num)
        {
            pertenece_y_posicion[0] = 1;
            pertenece_y_posicion[1] = i;
            break;
        }
    }
    return pertenece_y_posicion;
}


int main()
{
    /*
    Se ingresa la longitud; N, del mensaje, y la el valor tope de las entradas; C.
    1 <= N <= 10^3 y 1 <= C <= 10^9.
    */ 

    int N, C;
    scanf("%d %d", &N, &C);

    /* 
    Creamos el vector msj_frec_card, cuyo nombre es un recordatorio de la forma que tendrán sus elementos
    (que son tripletas), donde la primera componente es un número que forme parte del mensaje, la segunda
    componente se refiere a la frecuencia de dicho número en el mensaje, y la tercera (cardinalidad) es para
    ordenarlos segun su orden de aparición.
    */

    vector<vector<int>> msj_frec_card;    
    
    // Agrego el primer elemento al arreglo
    // Creo que se podia usar un ciclo do while para toda esa parte de la lógica

    int num;
    scanf("%d", &num);
    msj_frec_card.push_back({num,1,0});

    for (int i = 0; i < N-1; i++)
    {
        scanf("%d", &num);
        //Verifico si el número ingresado está repetido o es nuevo 
        vector<int> per_y_pos = pertenece_y_posicion(num, msj_frec_card);
        if (per_y_pos[0] == 1)
        {
            msj_frec_card[per_y_pos[1]][1]++;
        }
        else
        {
            msj_frec_card.push_back({num, 1, i+1});
        } 
    }
    
    /*
    Ordenamiento de los numeros según la frecuencia y el orden de aparicion
    usando BubbleSort.
    */

    for (int i = 0; i < msj_frec_card.size() - 1; i++) 
    {
        for (int j = 0; j < msj_frec_card.size() - i - 1; j++) 
        {
            if ((msj_frec_card[j][1] < msj_frec_card[j+1][1]) || 
                ((msj_frec_card[j][1]  == msj_frec_card[j+1][1]) && (msj_frec_card[j][2] > msj_frec_card[j+1][2]) )) 
                {
                swap(msj_frec_card[j], msj_frec_card[j+1]);
            }
        }
    }
    
    /*
    Imprimir: Itero sobre la longitud de msj_frec_card e imprimo
    el número msj_frec_card[i][0], tantas veces como lo indique su frecuencia.
    */

    for (int i = 0; i < msj_frec_card.size(); i++)
    {
        for (int j = 0; j < msj_frec_card[i][1]; j++)
        {
            printf("%d ", msj_frec_card[i][0]);
        }
    }
    printf("\n");

    return 0;
}
