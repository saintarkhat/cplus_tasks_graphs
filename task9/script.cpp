#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[100001];
bool used[100001];
vector<int> komponent;
vector<int> newp[100001];

int summa = 0;
int n = 0;
int m = 0;

void depthSearch(int v) {
	used[v] = true;
	komponent.push_back(v);
	for (size_t i = 0; i < graph[v].size(); ++i) {
		int to = graph[v][i];
		if (!used[to])
			depthSearch(to);
	}
}

void summas() {
	for (int i = 0; i < n; ++i)
		used[i] = false;
	for (int i = 0; i < n; ++i)
		if (!used[i]) {
			komponent.clear();
			depthSearch(i);

			summa++;
		}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}

	summas();

	cout << summa << endl;

	for (int i = 0; i < n; ++i)
		used[i] = false;

	for (int k = 0; k < n; ++k)
		if (!used[k]) {
			komponent.clear();
			depthSearch(k);

			for (int i = 0; i < komponent.size(); ++i) {
				newp[komponent[i]].push_back(k+1);
			}
		}

	//cout << newp[0][0] << " ";
	for (int i = 0; i < n; ++i) {
		cout << newp[i][0] << " ";
	}
	return 0;
}