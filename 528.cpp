class Solution {
public:
    vector<int> wsum;
    
    Solution(vector<int>& w) {
        int n = w.size();
        for(int i=1 ; i<n ; i++){
            w[i] += w[i-1];
        }    
        wsum = w;
    }
    
    int pickIndex() {
        return upper_bound(wsum.begin(), wsum.end(), rand() % wsum.back())- wsum.begin(); 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */