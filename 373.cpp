class Solution {
public:
    
    struct cmp{
        bool operator()(vector<int> a , vector<int> b){
            return a[0]+a[1] > b[0]+b[1];
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>> , cmp> pq;
        vector<vector<int>> res;
        if(nums1.size() == 0 || nums2.size() == 0 || k == 0)return res;
        for(int i : nums1)pq.push({i , nums2[0] , 0});
        while(k-- && !pq.empty()){
            auto curr = pq.top();
            pq.pop();
            res.push_back({curr[0] , curr[1]});
            if(curr[2] == nums2.size()-1)continue;
            pq.push({curr[0] , nums2[curr[2]+1] , curr[2]+1});
        }
        return res;
    }
};