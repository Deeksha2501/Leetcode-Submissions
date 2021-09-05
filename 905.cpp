class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j=n-1;
        while(i < j){
            while(i<n && nums[i]%2 == 0)i++;
            while(j >=0 && nums[j]%2 == 1)j--;
            if(i < j)swap(nums[i], nums[j]);
            i++;
            j--;
        }
        return nums;
    }
};


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=-1;
        for(int j=0 ; j<nums.size() ; j++){
            if(nums[j]%2 == 0){
                swap(nums[i+1] , nums[j]);
                i++;
            }
        }
        return nums;
    }
};



class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int e = 0;
        int o = n-1;
        int i=0;
        while(i<n){
            if(nums[i]%2 == 0){
                res[e] = nums[i];
                e++;
            }else{
                res[o] = nums[i];
                o--;
            }
            i++;
        }
        return res;
    }
};