class Solution {
public:
    
    static bool cmp(vector<int> a , vector<int> b){
        if( a[0] == b[0])return a[1]<b[1];
        return a[0] < b[0];
    }
    
    vector<vector<long long>> splitPainting(vector<vector<int>>& sg) {
        
        map<long long, long long> mp;
        for(vector<int> a : sg){
            mp[(long long)a[0]] += (long long)a[2];
            mp[(long long)a[1]] -= (long long)a[2];
        }
        

        long long sum=0, i=0;
        vector<vector<long long>> res;
        for(auto it : mp){
            // cout<<"\n"<<it.first<<" "<<it.second;
            long long j = it.first;
            if(sum>0){
                res.push_back({i , j , sum});
            }
            sum += it.second;
            // cout<<"\nsum = "<<sum;
            i = j;
        }
        return res;
        
    }
};