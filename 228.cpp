class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)return {};
        int start = nums[0] , end = nums[0];
        int prev = nums[0];
        vector<string> res;
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i] == prev + 1){
                //nothing
            }else{
                string s = "";
                s += to_string(start);
                if(start != end)s += "->" + to_string(end);
                res.push_back(s);
                start = nums[i];
            }
            prev = nums[i];
            end = nums[i];
        }
        
        string s = "";
        s += to_string(start);
        if(start != end)s += "->" + to_string(end);
        res.push_back(s);
        return res;
    }
};
