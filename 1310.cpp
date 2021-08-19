class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int> res;
        arr.insert(arr.begin() , 0);
        int n = arr.size();
        for(int i=1 ; i<n ; i++){
            arr[i] ^= arr[i-1];
        }
        for(int i=0 ; i<q.size() ; i++){
            int left = q[i][0];
            int right = q[i][1]+1;
            res.push_back(arr[left]^arr[right]);
        }
        
        return res;
    }
};