class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int maxR= 0;
        for(int i=31 ; i>=0 ; i--){
            mask = mask | (1<<i);
            unordered_set<int> s;
            for(int num : nums){
                int left = num & mask;
                s.insert(left);
            }
            int greedy = maxR| (1<<i);
            for(int n : s){
                if(s.find(n ^ greedy) != s.end()){
                    maxR = greedy;
                    break;
                }
            }
        }
        
        return maxR;
    }
};