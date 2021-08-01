class Solution {
public:
    static bool cmp(vector<int> a , vector<int> b){
        if(a[0] == b[0])return a[1]<b[1];
        return a[0]>b[0];
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i : nums)mp[i]++;
        
        int n = mp.size();
        vector<vector<int>> v;
        for(auto it : mp){
            v.push_back({it.second , it.first});
        }
        sort(v.begin() , v.end() ,cmp);
        vector<int> res;
        for(int i=0 ; i<k ; i++){
            res.push_back(v[i][1]);
        }
        return res;
    }
};