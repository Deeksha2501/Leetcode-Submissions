class Solution {
public:
    vector<int> r;
    int solve(int i , int j){
        if(i >= j)return 0;
        int res=0;
        
        for(int k=i+1 ; k<j ; k++){
            int left = solve(i , k);
            int right = solve(k , j);
            cout<<" i = "<<i<<" j = "<<j<<endl;
            cout<<"\nleft = "<<left<<" right = "<<right;
            res += left + right;
            if((r[i]<r[k] && r[k]<r[j]) || (r[i]>r[k] && r[k]>r[j]))res++;
            cout<<"\nk = "<<k<<" res = "<<res<<"\n";
        }
        return res;
    }
    
    int numTeams(vector<int>& rating){
        r = rating;
        int n = r.size() , res=0;
        // return solve(0 , r.size()-1);
        for(int i=0 ; i<r.size() ; i++){
            int ll=0, rr=0;
            for(int k=0 ; k<i ; k++){
                if(r[k]<r[i])ll++;
            }
            for(int k=i+1 ; k<n ; k++){
                if(r[i]<r[k])rr++;
            }
            res += (ll*rr) + (i-ll)*(n-i-rr-1);
        }
        return res;
    }
};