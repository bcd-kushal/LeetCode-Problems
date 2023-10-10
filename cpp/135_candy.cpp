/*
There are n children standing in a line.
Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:
-Each child must have at least one candy.
-Children with a higher rating get more candies than their neighbors.
-Return the minimum number of candies you need to have to distribute the candies to the children.

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

Constraints:
n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1)
            return 1;

        int i=1, n=ratings.size();
        int min_candies = n;

        while(i<n){
            //constant land
            if(ratings[i]==ratings[i-1]){
                i+=1;
                continue;
            }

            //uphill
            int peak = 0;
            while(ratings[i]>ratings[i-1]){
                peak+=1;
                min_candies+=peak;
                i+=1;
                if(i==n)
                    return min_candies;
            }

            //downhill
            int valley = 0;
            while(i<n && ratings[i]<ratings[i-1]){
                valley+=1;
                min_candies+=valley;
                i+=1;
            }

            min_candies-=min(peak,valley);
        }

        return min_candies;
    }
};
