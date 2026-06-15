// ============================ Big O: O(n) Worst Case, Average Case, Best Case ============================
/*
#include <iostream>

using namespace std;


void printItems(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }
}


int main() { 

    printItems(10);

}

// The "1" is best case, the "4" is average case, the "7" is the worst case.
*/

// ============================== Drop Constants =====================================
// This function is n + n = 2n but the constant 2 will be dropped, so this will be O(n).
/*
#include <iostream>

using namespace std;


void printItems(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }

    for (int j = 0; j < n; j++) {
        cout << j << endl;
    }
}


int main() { 

    printItems(10);

}
*/

// ================================== Big O: O(n^2) ==================================
// n * n = n^2, but it's less efficient than O(n)
/*
#include <iostream>

using namespace std;


void printItems(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << endl;
        }
    }
}


int main() { 

    printItems(10);

}
*/

// ============================== Big O: Drop Non-Dominants ==================================

// So this nested loop is O(n^2) and the other function for-loop is O(n) = O(n^2 + n), but the n will be dropped,
// so the Big O is still O(n^2).
/*
#include <iostream>

using namespace std;


void printItems(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << endl;
        }
    }

    for (int k = 0; k < n; k++) {
            cout << k << endl;
    }
}



int main() { 

    printItems(10);

}
*/