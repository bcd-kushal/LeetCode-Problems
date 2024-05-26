#include <bits/stdc++.h>
using namespace std;

class Strings {
public:
    void reverseString(vector<char>& s) {
        
        for(int i=0;i<s.size()/2; i++) {
            s[i] = s[i] + s[s.size()-1-i];
            s[s.size()-1-i] = s[i] - s[s.size()-1-i];
            s[i] = s[i] - s[s.size()-1-i];
        }
    }
};

int main() {
    vector<char> s = {'h','e','l','l','o'};
    Strings str;

    auto start = chrono::steady_clock::now();
    str.reverseString(s);
    auto end = chrono::steady_clock::now();

    for(char ch: s) 
        cout << ch << ", ";
    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms" ;
    return 0;
}
