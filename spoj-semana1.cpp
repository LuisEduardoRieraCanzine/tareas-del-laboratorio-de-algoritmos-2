#include <iostream>
using namespace std;

int main() {
    int num;
    
    while (cin >> num) {
        if (num == 42) {
            break;
        }
        
        if (num < 100) {
            cout << num << endl;
        }
    }
    
    return 0;
}
