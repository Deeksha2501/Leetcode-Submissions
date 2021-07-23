class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0, j=0;
        int n = name.length();
        int m = typed.length();
        if(n>m)return false;
        if(n == m) return name == typed;
        
        while(i<n){
            char prev = name[i];
            if(name[i] != typed[j]){
                return false; 
            }
            while(name[i] == typed[j] && i<n && j<m){
                prev = name[i];
                i++;
                j++;
                
            }
            while(typed[j] == prev && j<m )j++;
        }
        if(j != m)return false;
        return true;
    }
};