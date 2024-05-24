#include <iostream>
#include <vector>

using namespace std;

/*
La solución es basicamente la misma de la clase pero con la corrección sobre la variable acc que al alcanzar 
valores maximos generaba problemas. Y con la optimizacion de una vez esta ordenado el arreglo, si en al 
hacer el juego para la posicion j, logré llegar a la posicion j+r , ya se que desde la j a la j+r tienen 
la misma puntuación.
*/


// merge: función para unir dos vectores ordenados de forma creciente en un solo vector ordenado de forma creciente
vector<vector<int>> merge(const vector<vector<int>>& vec1, const vector<vector<int>>& vec2)
{
    int i = 0 , j = 0;
    int tam1 = vec1.size() , tam2 = vec2.size();
     
    vector<vector<int>> vec12_ordenado( tam1+tam2 , vector<int>(2,0));

    while( i < tam1 || j < tam2)
    {
        if(i == tam1)
        {
            while ( j < tam2)
            {
                vec12_ordenado[i+j][0] = vec2[j][0];
                vec12_ordenado[i+j][1] = vec2[j][1];
                j++;
            }    
        }
        else if(j == tam2)
        {
            while ( i < tam1)
            {
                vec12_ordenado[i+j][0] = vec1[i][0];
                vec12_ordenado[i+j][1] = vec1[i][1];
                i++;
            }   
        }
        else
        {
            if( vec1[i][0] <= vec2[j][0])
            {
                vec12_ordenado[i+j][0] = vec1[i][0];
                vec12_ordenado[i+j][1] = vec1[i][1];
                i++;
            }
            else
            {
                vec12_ordenado[i+j][0] = vec2[j][0];
                vec12_ordenado[i+j][1] = vec2[j][1];
                j++;
            }
        }
    }

    return vec12_ordenado;
}

// splitVector: funcion para partir un vector en dos partes iguaes
vector<vector<int>> splitVector(const vector<vector<int>>& vec, int first_or_second)
{
    int tam = vec.size();

    if (first_or_second == 1)
    {
        vector<vector<int>> vec1( tam/2 , vector<int>(2,0));
        int i = 0;
        while (i < tam/2)
        {
            vec1[i][0] = vec[i][0];
            vec1[i][1] = vec[i][1];
            i++;
        }
        return vec1;
    }
    else if(first_or_second == 2)
    {
        vector<vector<int>> vec2(tam - tam/2, vector<int>(2,0));
        int i = tam/2;
        while (i < tam)
        {
            vec2[i-tam/2][0] = vec[i][0];
            vec2[i-tam/2][1] = vec[i][1];
            i++;
        }
        return vec2;
    }

    return vec; // lo pongo para que siempre regrese algo
}

// mergeSort: implementación propia del clasico algoritmo
vector<vector<int>> mergeSort(vector<vector<int>>& vec)
{
    int tam = vec.size();

    if (tam <= 1)
    {
        return vec;
    }

    vector<vector<int>> vec1 = splitVector(vec, 1);
    vector<vector<int>> vec2 = splitVector(vec, 2);

    vec1 = mergeSort(vec1);
    vec2 = mergeSort(vec2);

    return merge(vec1, vec2);
}
 
int main()
{
    // Leer el numero de casos de prueba (t). Recuerde que 1<=t<=5000.
    int t=0;
    scanf("%d", &t);

    //Comenzar las t iteraciones de juego del score
    for (int iter = 0 ; iter < t ; iter++)
    {
        // Leer la longitud del arreglo (n). Recuerde que 1 <= n <= 10^5
        int n = 0;
        scanf("%d", &n);

        // Leer las n entradas del vector al que se le hara el juego de score, e indexarlas simultaneamente
        // Recuerde que cada entrada es de tamaño 1 <= arr[i] <= 10^9 
        vector<vector<int>> arr(n, vector<int>(2,0));
        
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i][0]);
            arr[i][1] = i;
        }

        // Ordenar el arreglo usando mergSort
        vector<vector<int>> arr_ord = mergeSort(arr);

        // Aqui se aplica la lógica del juego del score
        vector<int> puntaje(n , 0);
        long long acc = 0;
        int i = 0;

        while (i < n)
        {
            acc += arr_ord[i][0];
            long long score = acc;
            int j = i+1;
            
            while( j < n && score >= arr_ord[j][0])
            {
                score += arr_ord[j][0];
                j++;
            }

            for (int k = i; k < j; k++)
            {
                puntaje[arr_ord[k][1]] = j-1;
            }
            acc = score;
            i = j;
        }
        
        for (int i = 0; i < n; i++)
        {
            printf("%d ", puntaje[i]);
        }
        printf("\n");
    }

    return 0;
}
