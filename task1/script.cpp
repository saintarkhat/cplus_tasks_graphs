
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, k;
    cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (a[i][j])
                cout << i + 1 << " " << j + 1 << endl;

    return 0;

}