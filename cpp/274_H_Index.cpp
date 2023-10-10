class Solution {
public:
    int hIndex(vector<int>& citations) {
        unordered_map<int,int> levels;
        int h=0;

        for(auto x: citations)
            for(int i=0;i<=x;i++)
                levels[i]+=1;

        for(auto el: levels){
            h=max(h,min(el.first,el.second));
        }

        return h;
    }
};
