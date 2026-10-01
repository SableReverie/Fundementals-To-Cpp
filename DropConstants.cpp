#include <iostream>
using std::endl;
using std::cout;
using std::string;
using std::cin;

int printNumbers(int n){
    for(int i = 1; i <= n; i++){
        cout << i << " ";
    }
    for(int j = 1; j <= n; j++){
        cout << j << " ";
    }
    cout << endl;
    return 0;
}


int main (){

    printNumbers(10);

    return 0;
}