#include <iostream>

using namespace std;

int intmax = 100000000000;

int chipestPath(int* weight, bool* mark, int n) {

    int out = -1;
    int weightMin = intmax;

    for (int i = 0; i < n; ++i)
    {
        if (weight[i] <= weightMin && mark[i] == false)
        {
            out = i;
            weightMin = weight[i];
        }
    }

    return out;
}

int main()
{
    
    int n;
    int s;
    int f;

    cin >> n >> s >> f;

    --s;
    --f;

    int** mat = new int* [n];

    for (int i = 0; i < n; ++i) {

        mat[i] = new int[n];

        for (int j = 0; j < n; ++j) {

            cin >> mat[i][j];
        }
    }


    bool* flag = new bool[n];
    int* weight = new int[n];
    int cursor = s;

    for (int i = 0; i < n; ++i) {
        flag[i] = false;
        weight[i] = intmax;
    }


    
    weight[cursor] = 0;
    flag[cursor] = true;

    while (true)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mat[cursor][j] > 0 && false == flag[j])
            {
                int weightJ = mat[cursor][j] + weight[cursor];
                if (weightJ < weight[j])
                {
                    weight[j] = weightJ;
                }
            }
        }

        cursor = chipestPath(weight, flag, n);

        if (cursor == -1) {
            break;
        }
        else {
            flag[cursor] = true;
            if (cursor == f) {
                break;
            }
        }
    }

    if (s == f) {
        std::cout << mat[s][f] << std::endl;
    }
    else {
        if (cursor == f && weight[cursor] != intmax) {

            std::cout << weight[cursor] << std::endl;

        }
        else {

            std::cout << -1 << std::endl;

        }
    }
    return 0;

}