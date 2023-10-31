#include<iostream>
using namespace std;

bool visit[101][101];

int main() {
    int n;
    int m; 
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int s;
        int e; 
        cin >> s >> e;
        visit[s][e] = visit[s][e] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (visit[i][j] == false) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
