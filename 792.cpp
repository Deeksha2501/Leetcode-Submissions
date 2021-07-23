class Solution {
public:
    bool isSubs(string t , string w){
        int i=0, j=0;
        int n = t.size() , m = w.size();
        while(i < n && j<m){
            if(t[i] == w[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j == m)return true;
        return false;
        
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
         int n = s.length() , count=0;
        unordered_map<string , bool> st;
         for(int i=0 ; i<words.size() ; i++){
             if(st.find(words[i]) != st.end()){
                 if(st[words[i]] == true)count++;
                 continue;
             }
             st[words[i]] = false;
             int m = words[i].length();
             if(n < m){
                 continue;
             }
             if(n == m && s == words[i]){
                 st[words[i]] = true;
                 count++;
             }
             else{
                 if(isSubs(s , words[i]) == true){
                     st[words[i]] = true;
                     count++;
                 }
             } 
         }
        return count;
    }
};