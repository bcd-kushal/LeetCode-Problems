vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        int prod = 1, count=0;

        for(auto const &el: nums){
            if(el==0){
                count+=1;
                continue;
            }
            prod*=el;
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(count>=2)
                    answer.push_back(0);
                else
                    answer.push_back(prod);

                continue;
            }

            if(count==0)
                answer.push_back((int)(prod/nums[i]));
            else
                answer.push_back(0);
        }

        return answer;
    }
