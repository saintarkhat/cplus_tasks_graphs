#include <iostream>

using namespace std;

int main() {

    int n;
    int m;
    int x;
    int y;

    cin >> n >> m;

    int** answer = new int* [n];
    for (int i = 0; i < n; i++) {
        answer[i] = new int[2];
    }

    for (int i = 0; i < n; i++) {
        answer[i][1] = 0;
        answer[i][0] = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        answer[x - 1][1]++;
        answer[y - 1][0]++;
    }
    for (int i = 0; i < n; i++) {
        cout << answer[i][0] << endl << answer[i][1] << endl;
    }

    return 0;
}