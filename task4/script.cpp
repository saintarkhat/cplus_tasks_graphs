#include <iostream>

using namespace std;

long long n;
bool m[100][100], answer = true;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			cin >> m[i][j];

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n; y++)
			for (int z = 0; z < n; z++)
				if (x - y && y - z && x - z && m[x][y] && m[y][z] && !m[x][z]) answer = false;

	if (answer != false) cout << "YES" << endl;
	else cout << "NO" << endl;
}