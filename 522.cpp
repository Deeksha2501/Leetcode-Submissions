class Solution {
public:
    static bool cmp(string a , string b){
        return a.length() < b.length();
    }
    
    bool fun(string a , string b){
        if(a.length() == b.length())return a == b;
        int i=0, j=0, n=a.length(), m = b.length();
        while(j < m && i < n){
            if(a[i] == b[j])i++;
            j++;
        }
        return i == n;
    }
    
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin() , strs.end() , cmp);
        unordered_map<string , int> mp;
        for(string st : strs)mp[st]++;
        
        int n = strs.size();
        for(int i=n-1 ; i>=0 ; i--){
            string st = strs[i];
            if(mp[st] == 1 && i == n-1)return st.length();
            if(mp[st] == 1){
                // cout<<st;
                int j=i+1;
                bool flag = true;
                for(; j<n ; j++){
                    if(fun(st , strs[j])){
                        flag = false;
                        break;
                    }
                }
                // cout<<"\nj = "<<j<<" i = "<<i;
                if(flag)return st.length();                
            }
        }
        return -1;
    }
};