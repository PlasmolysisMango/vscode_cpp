#include <queue>
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>
#include <functional>
#include <cstring>   
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int N, K;

int main()
{
    cin >> N >> K;
    vector<vector<int>> map(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> map[i][j];
    for (auto ivec : map) {
        for (int y = 0; y < K; ++y) {
            bool flag = false;
            for (auto i : ivec)
            {
                for (int x = 0; x < K; ++x)
                {
                    if (!flag)
                        flag = true;
                    else
                        cout << " ";
                    cout << i;
                }
            }
            cout << endl;
        }
        
    }
}