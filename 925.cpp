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



class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=name.length()-1;
        int j=typed.length()-1;
        char prev = '@';
        while(i>=0 && j >=0){
            if(name[i] == typed[j]){
                prev = name[i];
                i--;
                j--;
            }else if(typed[j] == prev){
                j--;
            }else return false;
        }
        
        
        if(i == -1 && (j<0 || typed[j] == prev))return true;
        return false;
    }
};