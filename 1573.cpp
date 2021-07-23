class Solution {
public:
    int numWays(string s) {
      int n = s.length();
        int ones=0;
        vector<int> res;
        
        for(int i=0 ; i<n ; i++){
            char c = s[i];
            if(c == '1'){
                ones++;
                res.push_back(i);
            }
        }
        
        if(ones == 0){
            return (int)((long long)(n-2)*(long long)(n-1)/2%1000000007);
        }else if(ones % 3 != 0){
            return 0;
        }else{
            int d = ones/3;
            int p1= res[d-1];
            int p2 = res[d];
            int p3 = res[2*d-1];
            int p4 = res[2*d];
            long long r= (long long)(p2-p1)*(long long)(p4-p3);
            return int(r%1000000007);
            
        }  
    }
};