class Solution {
public:
    string s;
    vector<int> mcm(int i , int j){
        vector<int> res;
        if(i > j)return res;
        if(i == j){
            res.push_back(s[i]-'0');
            // cout<<res[0]<<" ";
            return res;
        }
        bool flag=false;
        for(int k=i+1 ; k<j ; k++){
            if(s[k] == '+' || s[k] == '*' || s[k] == '-'){
                flag = true;
                // cout<<"\n i = "<<i<<" j= "<<j<<" k = "<<k;
                vector<int> left = mcm(i , k-1);
                // cout<<"\nleft ========\n";
                // for(int d=0 ; d<left.size() ; d++){
                //     cout<<left[d]<<" ";
                // }
                // cout<<"\n=============\n";
                vector<int> right = mcm(k+1 , j);

    //             cout<<"\nright=============\n";

    //             for(int d=0 ; d<right.size() ; d++){
    //                 cout<<right[d]<<" ";
    //             }
    //             cout<<"\n============\n";
                for(int ii=0 ; ii<left.size() ; ii++){
                    for(int jj=0 ; jj<right.size() ; jj++){
                        // cout<<"\n ii = "<<s[ii]<<" jj = "<<s[jj];
                        // cout<<"\n k "<<s[k]<<" ";
                        if(s[k] == '*')res.push_back(left[ii] * right[jj]);
                        if(s[k] == '+')res.push_back(left[ii] + right[jj]);
                        if(s[k] == '-')res.push_back(left[ii] - right[jj]);
                        // cout<<"\n res = "<<res[res.size()-1];
                    }   
                }
            }
            // cout<<"\nres =============\n";
            // for(int rr=0 ; rr<res.size() ; rr++){
            //     cout<<res[rr]<<" ";
            // }
            // cout<<"\n=============\n";
        }
        
        if(!flag){
            res.push_back(stoi(s.substr(i , j-i+1)));
        }
        
        return res;
    }
    
    vector<int> diffWaysToCompute(string expression) {
        s = expression;
        int n = s.length();
        return mcm(0 , n-1);
    }
};