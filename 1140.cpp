class Solution {
public:
    vector<int> arr;
    int alice = 0;
    unordered_map<string , int> mp;
    
    int dfs(int i , int m , bool flag){
        string s = to_string(i) + " " + to_string(m) + " " + to_string(flag);
        if(i >= arr.size())return 0;
        if(mp.find(s) != mp.end())return mp[s];
        int sum=0,res=INT_MIN, ress=INT_MAX;
        for(int j=i ;j<i+2*m && j<arr.size(); j++){
            sum += arr[j];
            int mm = max(m , (j-i+1));
            int temp = dfs(j+1 , mm , !flag);
            res = max(res , temp+sum);
            ress = min(ress , temp);
        }
         
        if(flag)return mp[s] = res;
        return mp[s] = ress;
    }
    
    int stoneGameII(vector<int>& piles) {
        arr = piles;
        return dfs(0 , 1 , true);
    }
    
};
