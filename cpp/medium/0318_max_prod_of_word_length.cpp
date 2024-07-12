#include <stdlib.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
private:
    bool wordsCollide(string a, string b) {
        int len_a = a.size();
        int len_b = b.size();
        
        unordered_map<char,bool> registry;
        
        for(char c: a)
            registry[c] = true;
        for(char c: b)
            if(registry.find(c) != registry.end())
                return true;
        return false;
    }
    
    int letterDistance(string a, string b) { return a.size()*b.size(); }
    
public:
    int maxProduct(vector<string>& words) {
        int max_prod = INT_MIN;
        int n = words.size();
        
        for(int i=0; i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(!wordsCollide(words[i],words[j])) 
                    max_prod = max(max_prod,letterDistance(words[i],words[j]));

        if(INT_MIN==max_prod)
            return 0;
        
        return max_prod;
    }
};
