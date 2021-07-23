class Solution {
public:
    unordered_set<string> dfs(int n){
        unordered_set<string> st;
        if(n == 0){
            st.insert("");
            return st;
        }
//         for(int k=1 ; k<n ; k++){
//             string left_str = s.substr(0 , k);
//             for(int kk=0 ; kk<k ; kk++){
//                 left_str = left_str + ")";
//             }
            
//             string right_str = s.substr(k , n-k);
//             for(int kk=0 ; kk<(n-k) ; kk++){
//                 right_str = right_str + ")";
//             }
//             cout<<"\nleft = "<<left_str;
//             cout<<"\nright = "<<right_str;
            
//             vector<string> left = dfs(k, left_str) ;
//             vector<string> right = dfs((n-k) , right_str);
//             for(int i=0 ; i<left.size() ; i++){
//                 for(int j=0 ; j<right.size() ; j++){
//                     st.push_back(left[i] + right[j]);
//                 }
//             }
//         }
        for(int k=0 ; k<n ; k++){
            for(string left : dfs(k))
                for(string right : dfs(n-k-1))
                    st.insert("(" + left + ")" + right);
        }
        return st;
    }
    
    
    vector<string> generateParenthesis(int n) {
        
        unordered_set<string> s = dfs(n);
        vector<string> v;
        for(string st : s){
            v.push_back(st);
        }
        return v;
    }
};