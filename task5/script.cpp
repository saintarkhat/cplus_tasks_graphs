#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<int> calc;
vector<vector<int> > graph;

void depthSearch(int vec)
{
    visited[vec] = true;
    for (int i = 0; i < graph[vec].size(); ++i)
    {
        int dot = graph[vec][i];
        if (!visited[dot])
            depthSearch(dot);
    }
    calc.push_back(vec);
}

int main(void)
{
    int n;
    int m;
    cin >> n >> m;
    
    visited.resize(n);
    graph.resize(n);

    if (m > 0)
    {
        for (int i = 0, a, b; i < m; ++i)
        {
            cin >> a >> b;
            --a;
            --b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        int i;
        i = 0;
        if (!visited[i])
        {
            calc.clear();
            depthSearch(i);
            cout << calc.size() << endl;
            sort(calc.begin(), calc.end());
            for (int j = 0; j < calc.size(); ++j)
                cout << ++calc[j] << ' ';
            cout << endl;
        }
    }
    else {
        cout << 1 << endl;
        cout << 1 << endl;
    }
    return 0;
}