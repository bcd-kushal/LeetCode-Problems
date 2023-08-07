#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];

        if(nums.size()==2)
            return (nums[0]>nums[1])?nums[1]:nums[0];

        if(nums[0]<nums.back())
            return nums[0];



        int min,mid=0;
        int low=0, high=nums.size()-1;

        while(low<=high){
            mid=low+(int)((high-low)/2);

            if(mid-1>=0 && nums[mid-1]>nums[mid])
                return nums[mid];


            int left_mid = low+(int)((mid-low)/2);
            int right_mid = mid+(int)((high-mid)/2);
            
            cout << "\n" << left_mid << " ..... " << mid << " ..... " << right_mid << "\n";

            if(nums[left_mid]<nums[mid] && nums[mid]<nums[right_mid]){
                if(nums[left_mid]<nums[0]){
                    //goto left
                    high=mid-1;
                    continue;
                } else {
                    //goto right
                    low=mid+1;
                    continue;
                }

            }

            if(nums[left_mid]<nums[mid] && nums[mid]>nums[right_mid]){
                //goto right
                low=mid+1;
                continue;
            }

            if(nums[left_mid]>nums[mid] && nums[mid]<nums[right_mid]){
                //goto left
                high=mid-1;
                continue;
            }

            if(nums[left_mid]>nums[mid] && nums[mid]>nums[right_mid]){
                //goto left
                high=mid-1;
                continue;
            }

        }


        return nums[mid];
    }
    
    int main(){
		vector<int> x{4,5,6,7,0,1,2};
		cout << findMin(x);
    	return 0;
	}
