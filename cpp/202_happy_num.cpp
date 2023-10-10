/*
Write an algorithm to determine if a number n is happy.
.
A happy number is a number defined by the following process:
 - Starting with any positive integer, replace the number by the sum of the squares of its digits.
 - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 - Those numbers for which this process ends in 1 are happy.
 - Return true if n is a happy number, and false if not.

Input: n = 19
Output: true
Input: n = 2
Output: false

Constraints:
1 <= n <= 231 - 1
*/

class Solution {
public:
    bool isHappy(int n) {
        if(n==1)
            return true;

        map<int,int> myMap;

        int sum = 0;
        while(n!=1){
            if(myMap.count(n)<=0){
                int x = n;
                while(x>0){
                    sum+=(x%10)*(x%10);
                    x/=10;
                }
                myMap[n]=sum;
            }
            else
                return false;

            n = sum;
            sum = 0;
        }

        myMap.clear();
        return (n==1)?true:false;
    }
};
