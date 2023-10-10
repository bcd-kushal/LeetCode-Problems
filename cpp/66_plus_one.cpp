/*
You are given a large integer represented as an integer array digits, where each digits[i]
is the ith digit of the integer. The digits are ordered from most significant to least
significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Input: digits = [9]
Output: [1,0]

Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.back()!=9)
            digits.back()+=1;
        else{
            vector<int> aux;
            while(digits.back()==9){
                aux.push_back(0);
                if(digits.size()==1){
                    digits.back()=0;
                    break;
                }
                else
                    digits.pop_back();
            }
            digits.back()+=1;
            digits.insert(digits.end(),aux.begin(),aux.end());
        }

        return digits;
    }
};
