class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n =  nums.size();
        vector<int> temp(101 , 0);
        for(int i : nums)temp[i]++;
        for(int i=1 ; i<101 ; i++){
            temp[i] += temp[i-1];
        }
        for(int i=0 ; i<n ; i++){
            if(nums[i] == 0)nums[i] = 0;
            else nums[i] = temp[nums[i]-1];
        }
        return nums;
    }
    
};


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i=0 ; i<n ; i++){
            int count=0;
            for(int j=0 ; j<n ; j++){
                if(nums[j]<nums[i]){
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};