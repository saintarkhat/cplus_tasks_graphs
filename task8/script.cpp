#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> graph;
vector<int> used;
vector<int> parent;

bool flag;
int ended;
int started;

void dfs(int v) {

    used[v] = 1;
    for (size_t i = 0; i < graph[v].size(); ++i) {
        int to = graph[v][i];
        if (used[to] == 0) {
            parent[to] = v;
            dfs(to);
        }
        else if (used[to] == 1 && to != parent[v]) {
            flag = true;
            ended = v;
            started = to;
        }
    }
    used[v] = 2;
}

int main() {

    int a;
    int n;
    cin >> n;
    graph.resize(n + 1);
    used.resize(n + 1, 0);
    parent.resize(n + 1);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a;
            if (a != 0) graph[i].push_back(j);
        }

    for (int l = 0; l < n; ++l) {
        if (!used[l]) dfs(l);
        if (flag) {
            cout << "YES" << endl;

            int ch = ended;
            int sum = 0;
            while (ch != started) {
                sum++;
                ch = parent[ch];
            }
            cout << sum + 1 << endl;

            int k = ended;
            while (k != started) {
                cout << k+1 << " ";
                k = parent[k];
            }
            cout << started+1;
            return 0;
        }
    }
    cout << "NO" << endl;


    return 0;
}