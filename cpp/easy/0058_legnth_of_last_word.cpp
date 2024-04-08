#include <bits/stdc++.h>
using namespace std;

class Words {
    public:
        int lengthOfLastWord(string s) {
            bool flag = false;
            int size = 0;

            for(int i=s.size()-1; i>=0; i--) {
                if(s[i]==' ')
                    if(!flag)   continue;
                    else        return size;
                if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) {
                    flag = true;
                    size += 1;
                }
            }

            return size;
        }
};

int main() {
    string s = "luffy is still joyboy";
    Words word;
    
    auto start = chrono::steady_clock::now();
    cout << word.lengthOfLastWord(s); 
    auto end = chrono::steady_clock::now();

    cout << "\n... time taken: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms";
    return 0;
}