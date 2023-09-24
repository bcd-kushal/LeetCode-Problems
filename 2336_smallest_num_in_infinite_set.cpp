class SmallestInfiniteSet {
private:
    unordered_map<int,bool> nums;
    int smallest;
public:
    SmallestInfiniteSet() {
        smallest=1;
        for(int i=1;i<INT_MAX;i++)
            nums[i]=true;
    }
    
    int popSmallest() {
        nums[smallest]=false;
        int i = smallest, ans=smallest;
        while(!nums[i])
            i+=1;
        smallest=i;
        return ans;
    }
    
    void addBack(int num) {
        if(!nums[num]){
            nums[num]=true;
            if(num<smallest)
                smallest=num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */