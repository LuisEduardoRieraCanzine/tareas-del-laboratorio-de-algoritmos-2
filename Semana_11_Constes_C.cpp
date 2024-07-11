#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s); // Leer la entrada del usuario

    string t, u;
    t.reserve(s.size()); // Reservar memoria para t
    u.reserve(s.size()); // Reservar memoria para u

    size_t index = 0; // Índice para rastrear la posición en s
    char min_char = *min_element(s.begin(), s.end()); // Encontrar el carácter mínimo en s

    while (index < s.size()) 
    { // Mientras no lleguemos al final de s
        if (t.empty()) 
        { // Si t está vacío
            char c = s[index++]; // Obtener el siguiente carácter de s y avanzar el índice
            while (c != min_char) 
            { // Mientras el carácter no sea el mínimo
                t.push_back(c); // Agregar el carácter a t
                c = s[index++]; // Obtener el siguiente carácter de s y avanzar el índice
            }
            u.push_back(c); // Agregar el carácter mínimo a u
            if (index < s.size()) 
            { // Si aún no hemos llegado al final de s
                min_char = *min_element(s.begin() + index, s.end()); // Actualizar el carácter mínimo
            }
        } else { // Si t no está vacío
            while (!t.empty() && (t.back() <= min_char)) 
            { // Mientras t no esté vacío y el último carácter de t sea menor o igual al mínimo
                u.push_back(t.back()); // Mover el último carácter de t a u
                t.pop_back(); // Eliminar el último carácter de t
            }
            while (index < s.size() && s[index] != min_char) 
            { // Mientras no lleguemos al final de s y el carácter actual no sea el mínimo
                t.push_back(s[index++]); // Agregar el carácter actual a t y avanzar el índice
            }
            if (index < s.size()) 
            { // Si aún no hemos llegado al final de s
                u.push_back(s[index++]); // Agregar el carácter mínimo a u y avanzar el índice
                if (index < s.size()) 
                { // Si aún no hemos llegado al final de s
                    min_char = *min_element(s.begin() + index, s.end()); // Actualizar el carácter mínimo
                }
            }
        }
    }

    while (!t.empty()) 
    { // Mover todos los caracteres restantes de t a u
        u.push_back(t.back());
        t.pop_back();
    }

    cout << u << endl;
    return 0;
}
