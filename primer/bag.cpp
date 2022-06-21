#include <iostream>
#include <vector>
using namespace std;

int solveBag(const vector<int> &values, const vector<int> &weights, const int bagSize)
{
    int itemSize = values.size();
    vector<vector<int>> dp(itemSize, vector<int>(bagSize+1, 0));
    for (int i = 0; i < itemSize; ++i)
        dp[i][0] = 0;
    for (int j = 0; j <= bagSize; ++j) {
        if (weights[0] <= j)
            dp[0][j] = values[0];
        else
            dp[0][j] = 0;
    }
    for (int i = 1; i < itemSize; ++i)
        for (int j = 1; j <= bagSize; ++j) {
            if (j < weights[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
        }
    return dp[itemSize - 1][bagSize];
}

int solveBag_one(const vector<int> &values, const vector<int> &weights, const int bagSize)
{
    const int itemSize = values.size();
    vector<int> dp(bagSize + 1, 0);
    for (int i = 0; i < itemSize; ++i)
        for (int j = bagSize; j >= weights[i]; --j)
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
    return dp[bagSize];
}

int main()
{
    cout << solveBag_one({15, 20, 20}, {1, 3, 4}, 4);
    return 0;
}