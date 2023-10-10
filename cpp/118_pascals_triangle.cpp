#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascals;

        for (int i = 0; i < numRows; i += 1)
        {
            pascals.push_back(vector<int>(i + 1, 1));
        }

        for (int i = 2; i < numRows; i += 1)
        {
            for (int j = 1; j < pascals[i].size() - 1; j += 1)
                pascals[i][j] = pascals[i - 1][j - 1] + pascals[i - 1][j];
        }

        return pascals;
    }
};