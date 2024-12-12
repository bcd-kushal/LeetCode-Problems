#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    bool isVowel(char ch) {
        for(int i=0;i<10;i+=1)
            if(ch == vowels[i])
                return true;
        
        return false;
    }

public:
    string reverseVowels(string s) {
        int left = 0, right = s.size()-1;
        
        while(left < right) {
            while(left<s.size() && !isVowel(s[left]))
                left += 1;
            while(right>=0 && !isVowel(s[right]))
                right -= 1;
            
            if(left >= right)
                break;
            
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;

            left += 1;
            right -= 1;
        }

        return s;
    }
};