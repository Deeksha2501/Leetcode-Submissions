class Solution {
public:
    string pushDominoes(string s) {
        int n = s.length();
        vector<int> left(n) , right(n);
        bool flag = true;
        for(int i=n-1 ; i>=0 ; i--){
            if((s[i] == 'R' || s[i] == '.') && flag){
                left[i] = 0;
                continue;
            }
            if(s[i] == 'L'){
                left[i] = -n;
                flag = false;
            }
            else if(s[i] == 'R')left[i] = 0;
            else{
                left[i] = min(left[i+1] + 1 , 0);
            }
        }
        
        
        
        flag = true;
        
        for(int i=0 ; i<n ; i++){
            if((s[i] == 'L' || s[i] == '.') && flag){
                right[i] = 0;
                continue;
            }
            if(s[i] == 'R'){   
                right[i] = n;
                flag = false;
            }
            else if(s[i] == 'L'){
                right[i] = 0;   
            }
            else{
                right[i] = max(right[i-1] - 1 , 0);
            }
        }
        
        
        string res = "";
        for(int i=0 ; i<n ; i++){
            int r = left[i] + right[i];
            if(r < 0)res += "L";
            if(r > 0)res += "R";
            if(r == 0)res += ".";
        }
        return res;
    }
};