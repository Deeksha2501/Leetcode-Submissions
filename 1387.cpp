class Solution {
public:
    int getKth(int lo, int hi, int kin) {
        // int x = 2*((hi*3)+1);
        // int x = 1000;
        // vector<int>dp(x , -1);
        
        unordered_map<int, int> m;
        // for(int i=2 ; i<x ; i++){
        //     
        // }
        vector<pair<int, int>> res;
        map<int, int> mp;
        for(int j=lo ; j<=hi ; j++){
            int k=0;
            int i=j;
            while(i != 1){
                if(m.find(i) != m.end()){
                    k += m[i];
                    break;
                }
                if(ceil(log2(i)) == floor(log2(i))){
                    m[i] = log2(i);
                    k += m[i];
                    break;
                }
                else if(i%2)i = 3*i + 1;
                else i = i/2;
                k++;
            }
            m[j] = k;
            mp[j] = k;
        }
        
        for(auto it : mp){
            res.push_back({it.second , it.first});
            // cout<<it.first<<" - "<<it.second<<"\n";
        }
        
        sort(res.begin() , res.end());
        pair<int , int> p = res[kin-1];
    
        // cout<<"\n";
        return p.second;
    }
};