static bool customInterval(string x, string y){
        return x[0]<y[0];
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int j=0,totalCount=0;

        for(int i=0;i<s.size();i++){
            sort(words.begin(),words.end(),customInterval);
            j=0;

            while(words[j][0]!=s[i]){
                ++j;
                if(j>=words.size())
                    break;
            }

            while(j<words.size() && words[j][0]==s[i]){
                if(words[j].size()>1)
                    words[j]=words[j].substr(1);
                else{
                    words[j]="";
                    totalCount+=1;
                }
                ++j;
            }

        }

        return totalCount;
    }
