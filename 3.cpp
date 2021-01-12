class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int c[256];
        fill(c , c+256 , -1);
        int count=0,res=0,start=0;
        for(int i=0 ; i<s.length() ; i++){
            // cout<<"\nchecking for = "<<s[i];
            // cout<<"\nstart = "<<start;
            if(c[s[i]] > -1 && c[s[i]]>=start){
                // cout<<"\nelse";
                int j = c[s[i]];
                start = j;
                c[s[i]] = i;
                count = i-j;
                
                // cout<<"\ncount updated to = "<<count;
            }
            else {
                // cout<<"\nif";
                count++;
                res = max(res , count);
                c[s[i]] = i;
                // cout<<"\ncount updated to = "<<count;
            }
        }
        res = max(res , count);
        return res;
    }
};
