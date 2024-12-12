#include <unordered_map>
#include <set>
using namespace std;

class AllOne {
unordered_map<string,int> map;
set<pair<int,string>> list;
int prev;

public:
    AllOne() {}
    
    void inc(string key) {
        prev = map[key];
        map[key] += 1;
        if(prev > 0)    
            list.erase(make_pair(prev,key));        
        list.insert(make_pair(prev+1,key));
    }
    
    void dec(string key) {
        prev = map[key];
        map[key] -= 1;
        list.erase(make_pair(prev,key));
        if(prev-1 > 0)
            list.insert(make_pair(prev-1,key));
    }
    
    string getMaxKey() {
        if(list.empty())    return "";
        return list.rbegin()->second;
    }
    
    string getMinKey() {
        if(list.empty())    return "";
        return list.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */