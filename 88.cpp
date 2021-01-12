class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        if(n==0){
            nums1 = nums2;
            return;
        };
        if(m == 0){
            return;
        }
        vector<int> res(m+n);
        int i=0,j=0,k=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                res[k] = nums1[i];
                i++;
            }
            else{
                res[k] = nums2[j];
                j++;
            }
            k++;   
        }
        // cout<<"\n j = "<<j;
        while(i<n){
            res[k++] = nums1[i++];
        }
        while(j<m){
            // cout<<" k= "<<k;
            res[k++] = nums2[j++];
            // cout<<"\nj = "<<j;
            // cout<<"\nm = "<<m;
        }
        nums1 = res;
        return;
    }
};
