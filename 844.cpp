class Solution {
public:
    string get(string s){
        string res="";
        int count=0;
        
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='#'){
                count++;
            }else{
                if(count==0)res += s[i];
                else count--;
            }
        }
        
        return res;
    }
    
    bool backspaceCompare(string s, string t) {
        s = get(s);
        t = get(t);
        return s == t;
    }
};