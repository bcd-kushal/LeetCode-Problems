#include <string>
using namespace std;

class Solution {
private:
    bool checkIsPalindrome(string s, int end) {
        bool isPalindrome = true;
        int left    = (end+1)%2==0 ? end/2 : end/2 - 1;
        int right   = end/2 + 1;

        for(;left>=0;left-=1,right+=1) 
            isPalindrome = isPalindrome && (s[left]==s[right] ? true : false);
            
        return isPalindrome;
    }

public:
    string shortestPalindrome(string s) {
        int maxIndexPalindrome = 0;
        int i=1;
        while(i<s.size() && s[i]==s[0]) {
            maxIndexPalindrome = i;
            i += 1;
        }
        
        for(;i<s.size();i+=1)
            if(checkIsPalindrome(s,i))
                maxIndexPalindrome = i;
        
        string temp = "";
        for(int i=s.size()-1;i>maxIndexPalindrome;i-=1)
            temp += s[i];
    
        return temp+s;
    }
};