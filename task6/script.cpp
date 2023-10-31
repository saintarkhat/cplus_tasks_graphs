#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>>vec;
int n;
int mat;
int path;

void breadthSearch() {
    vector<int>started(n);
    vector<bool>visited(n);
    queue<int>que;

    que.push(mat);
    started[mat] = -1;
    visited[mat] = 1;

    while (!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i = 0; i < n; ++i)
            if (!visited[i] && vec[t][i]) {
            visited[i] = 1;
            que.push(i);
            started[i] = t;
        }
    }
    if (path == mat) {
        cout << 0;
        return;
    }
    if (!visited[path]) {
        cout << -1;
        return;
    }
    vector<int>answer;
    for (int i = path;;) {
        if (i == -1)
            break;
        answer.push_back(started[i] + 1);
        i = started[i];
    }
    cout << answer.size() - 1 << "\n";
    if (!(answer.size() - 1))
        return;
    answer.pop_back();
    for (int i = answer.size() - 1; i >= 0; --i)
        cout << answer[i] << ' ';
    cout << path + 1;
}

int main()
{
    cin >> n;
    vec.resize(n);

    for (int i = 0; i < n; ++i)
        vec[i].resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> vec[i][j];
    }
    cin >> mat >> path;
    --mat; --path;
    breadthSearch();

    return 0;
}