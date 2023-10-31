#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > mat;
vector<bool> used;
vector<int> placed;

int n;
int m;

void depthSearch(int dot, int table)
{
    int dotx;
    used[dot] = true;
    placed[dot] = table;

    for (int i = 0; i < mat[dot].size(); i++)
    {
        dotx = mat[dot][i];
        if (!used[dotx])
            depthSearch(dotx, table ^ 1);
    }

}

int main(void) {

    bool cheked = true;

    cin >> n >> m;
    mat = vector<vector<int> >(n, vector<int>());
    used = vector<bool>(n);
    placed = vector<int>(n);

    int x, y;

    for (int i = 0; i < m; i++) {
        
        cin >> x >> y;
        x--; y--;
        mat[x].push_back(y);
        mat[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
        if (!used[i])
            depthSearch(i, 0);

    for (int i = 0; i < n; i++)

        for (int j = 0; j < mat[i].size(); j++)

        if (placed[mat[i][j]] == placed[i]) cheked = false;

    if (cheked) {
        cout << "YES" << endl;

        for (int i = 0; i < used.size(); i++) {
            if (placed[i] == 1) cout << i+1 << ' ';
        }
    }
    else {
        cout << "NO" << endl;
    }
}
