/*
Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11

Constraints:
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
        int total = 0;
        for(int i=0;i<triangle.size();i++){
            if(i==0){
                total = triangle[0][0];
                continue;
            }

            for(int j=0;j<triangle[i].size();j++){
                if(i>1)
                    if(j>1)
                        triangle[i][j] = min(triangle[i-1][j]+triangle[i][j], triangle[i-1][j-1]+triangle[i][j]);
                    else
                        triangle[i][j] = triangle[i-1][j]+triangle[i][j];

                if(i==triangle.size()-1)
                    total = (total>triangle[i][j])? triangle[i][j]:total;
            }
        }
        return total;
}
