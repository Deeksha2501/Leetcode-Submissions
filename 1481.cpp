class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for(int i=0 ; i<arr.size() ; i++){
            m[arr[i]]++;
        }
        vector<int> v;
        for(auto a:m){
            v.push_back(a.second); 
        }
        sort(v.begin(), v.end());

        int n = v.size();
        for(int i=0 ; i<v.size() ; i++){
            k = k - v[i];
            n--;
            if(k<0)return n+1;
            if(k == 0)return n;
        }
        return n;
    }
};