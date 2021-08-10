class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int , vector<int>> mp;
        int n=arr.size();
        for(int i=0 ; i<n ; i++){
            mp[arr[i]].push_back(i);
        }
        int cnt=1;
        for(auto it : mp){
            vector<int> v = it.second;
            for(int k : v){
                arr[k] = cnt;
            }
            cnt++;
        }
        return arr;
    }
};