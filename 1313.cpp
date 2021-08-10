class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i=0 ; i<n ; i+=2){
            int freq = nums[i];
            int val = nums[i+1];
            while(freq--)res.push_back(val);
        }
        
        return res;
    }
};