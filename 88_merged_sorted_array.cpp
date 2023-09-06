void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m+n,0);
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                ans[k]=nums1[i];
                i+=1;
            } else {
                ans[k]=nums2[j];
                j+=1;
            }
            k+=1;
        }

        while(i<m){
            ans[k]=nums1[i];
            i+=1;
            k+=1;
        }

        while(j<n){
            ans[k]=nums2[j];
            j+=1;
            k+=1;
        }

        nums1=ans;

    }
