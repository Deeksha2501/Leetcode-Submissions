class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> :: iterator itr;
        int prev = nums[0],count=0;
        unordered_map<int,int> m;
        for(itr = nums.begin() ; itr != nums.end() ; itr++){
            m[*itr]++;
            if(m[*itr] > 2){
                nums.erase(itr);
                itr--;
            }
        }
        return nums.size();
    }
};