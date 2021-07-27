class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> mp1;
        unordered_map<int , int> mp2;
        for(int i=0 ; i<nums1.size() ; i++){
            mp1[nums1[i]]++;
        }
        for(int i=0 ; i<nums2.size() ; i++){
            mp2[nums2[i]]++;
        }
        
        vector<int> res;
        
        for(auto [key, val] : mp1){
            if(mp2.find(key) != mp2.end()){
                int x = min(val , mp2[key]);
                while(x--)res.push_back(key);
            }
        }
        
        return res;
    }
};