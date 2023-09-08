#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
        int start=0,end=s.size()-1,n=s.size(),flag=false;
		cout << "\n( " << start << ", " << end << " )";
        while(start<end){
            while(start<n && !(tolower(s[start])>='a'&&tolower(s[start])<='z'))
                ++start;

		cout << "\n( " << start << ", " << end << " )  ....1";

            if(flag && (start>end || start>=n || end<0))
                return false;

            while(end>=0 && !(tolower(s[end])>='a'&&tolower(s[end])<='z'))
                --end;

		cout << "\n( " << start << ", " << end << " )  ....2";

            if(flag && (start>end || start>=n || end<0))
                return false;

            if(start<n && end>=0 && (s[start]==s[end] || s[start]+32==s[end] || s[start]==s[end]+32 || s[start]+32==s[end]+32)){
                start+=1;
                end-=1;
                flag=true;
                continue;
            }

		cout << "\n( " << start << ", " << end << " )  ....3";

            return false;
        }

		if((start<n && end<0)||(start>=n && end>=0))
			return false;
			
        return true;
    }
    
    int main(){
    	cout << "\n\n--------------------------\n\n" << isPalindrome("a.");
    	return 0;
	}
