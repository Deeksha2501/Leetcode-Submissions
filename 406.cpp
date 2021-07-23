class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[1] == b[1])return a[0]<b[0];
        return a[1]<b[1];
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin() , p.end() , cmp);
        
        int n = p.size();
        vector<vector<int>>res(n);
        
        res[0] = p[0];
        for(int i=1 ; i<n ; i++){
            int a = p[i][0];
            int j=0;
            int count=0;
            int flag = 0;
            while(j<i){
                if(res[j][0] >= a)count++;
                if(count == p[i][1])break;                 
                j++;
            }
            
            // int pos = j;
            j++;
            
            while(j < i){
                if(res[j][0]<a)j++;
                else break;
            }
            
            res.insert(res.begin()+j , p[i]);
            
        }
        
        res.resize(n);
        
        return res;
    }
};