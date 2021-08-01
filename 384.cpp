class Solution {
public:
    vector<int> nums;
    unordered_map<int , int> mp;
    
    Solution(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        for(int i=0 ; i<n ; i++){
            mp[i] = nums[i];
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        int n = nums.size();
        for(int i=0 ; i<n ; i++)nums[i] = mp[i];
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        unordered_set<int> s;
        int n = nums.size();
        
        for(int i=0 ; i<n ; i++){
            int j = rand()%n;
            while(s.find(j) != s.end())j = rand()%n;
            nums[i] = mp[j];
            s.insert(j);
        }
        return nums;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */