class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        
        int res = 0;
        string ans = "";
        for(int i=0 ; i<d.size() ; i++)   {
            int c=0;
            int m = d[i].length();
            for(int j=0 ; j<s.length() ; j++){
                if(s[j] == d[i][c]){
                    c++;
                }
                if(c == m){
                   if(m > res){
                       res = m;
                       ans = d[i];
                       break;
                   }else if(m == res){
                       if(d[i].compare(ans) < 0)ans = d[i];
                   }
                }
            } 
        }
        return ans;
    }
};