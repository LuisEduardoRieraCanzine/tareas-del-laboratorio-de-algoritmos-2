#include <iostream>
#include <vector>

using namespace std;

/*
La solucion consiste es ordenar las posiciones de los establos para poder aplicar una busqueda binaria 
sobre la distancia que estoy buscando.

debe haber una mejor solución, pero esto es tabajo honesto.
*/



////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////// merge //////////////////////////////////////////////
vector<int> merge(vector<int>& vec1, vector<int>& vec2)
{
    int i = 0 , j = 0;
    int tam1 = vec1.size() , tam2 = vec2.size();
     
    vector<int> vec12_ordenado(tam1+tam2 , 0);

    while( i < tam1 || j < tam2)
    {
        if(i == tam1)
        {
            while ( j < tam2)
            {
                vec12_ordenado[i+j] = vec2[j];
                j++;
            }    
        }
        else if(j == tam2)
        {
            while ( i < tam1)
            {
                vec12_ordenado[i+j] = vec1[i];
                i++;
            }   
        }
        else
        {
            if( vec1[i] <= vec2[j] )
            {
                vec12_ordenado[i+j] = vec1[i];
                i++;
            }
            else
            {
                vec12_ordenado[i+j] = vec2[j];
                j++;
            }
        }
    }

    return vec12_ordenado;
}

///////////////////////////////////////////// splitVector //////////////////////////////////////////
vector<int> splitVector(vector<int>& vec, int first_or_second)
{
    int tam = vec.size();

    if (first_or_second == 1)
    {
        vector<int> vec1( tam/2 , 0);
        int i = 0;
        while (i < tam/2)
        {
            vec1[i] = vec[i];
            i++;
        }
        return vec1;
    }
    
    if(first_or_second == 2)
    {
        vector<int> vec2(tam - tam/2, 0);
        int i = tam/2;
        while (i < tam)
        {
            vec2[i-tam/2] = vec[i];
            i++;
        }
        return vec2;
    }
}

///////////////////////////////////////////// mergeSort ////////////////////////////////////////////
vector<int> mergeSort(vector<int>& vec)
{
    int tam = vec.size();

    if (tam <= 1)
    {
        return vec;
    }

    vector<int> vec1 = splitVector(vec, 1);
    vector<int> vec2 = splitVector(vec, 2);

    vec1 = mergeSort(vec1);
    vec2 = mergeSort(vec2);

    return merge(vec1, vec2);
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////
//////////// función para ver si las vacas se pueden poner con una distancia mínima dada ///////////
bool chequeo(vector<int>& establos, int distancia, int N, int C) 
{
    int conteo = 1;                                          // Inicialmente, solo hay una vaca colocada
    int ult_position = establos[0];                          // Posición de la última vaca colocada
    
    // Recorremos los puestos y verificamos si es posible colocar las vacas con la distancia mínima dada
    for (int i = 1; i < N; ++i) 
    {
        if (establos[i] - ult_position >= distancia) 
        {
            conteo++;
            ult_position = establos[i];
            
            // Si hemos colocado todas las vacas
            if (conteo == C) 
            {
                return true;                                 // Se pueden colocar todas las vacas con la distancia mínima dada
            }
        }
    }
    
    return false;                                           // No se pueden colocar todas las vacas con la distancia mínima dada
}

//////// Implementación de la busqueda binaria para resolver el problama del mínimo-máximo ///////// 
int dist_min_max(vector<int>& establos_ord, int N, int C)
{
    int dist_min = 1;
    int dist_max = establos_ord[N-1] - establos_ord[0];
    int dist_min_max = 0;

    // Búsqueda binaria para encontrar la distancia mínima más grande
    while (dist_min <= dist_max) 
    {
        int med = (dist_max + dist_min) / 2;    // Calculamos la distancia media
        
        // Verificamos si es posible colocar las vacas con la distancia media
        if (chequeo(establos_ord, med, N, C)) 
        {
            dist_min_max = med;               // Actualizamos la distancia mínima más grande encontrada
            dist_min = med + 1;               // Ajustamos el inicio para buscar una distancia aún mayor
        } else {
            dist_max = med - 1;               // La distancia media es demasiado grande, ajustamos el final
        }
    }
    
    return dist_min_max;                      // Devolvemos la distancia mínima más grande encontrada
}
////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{

    // Leer el número de casos de prueba
    int t = 0;
    scanf("%d", &t);

    //Iteramos a través de cada caso de prueba
    for (int i = 0; i < t; i++)
    {
        // Número de establos y de vacas
        int N = 0 , C = 0;
        scanf("%d %d",&N ,&C);

        // Leer las posiciones de los establos
        vector<int> establos(N,0);
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &establos[j]);
        }
        
        // Ordenar el vector de los establos
        establos = mergeSort(establos);

        // Calculamos y mostramos la distancia mínima más grande para el caso actual
        printf("%d\n", dist_min_max(establos, N, C));
    }

    return 0;
}
