class Solution {
public:
    int minFlips(string t) {
        int n = t.length();
        int i=0;

        
        int count=0;
        i=0;
        char curr = '0';
        while(i<n){
            
            if(t[i] != curr){
                count++;
                if(curr == '1')curr = '0';
                else curr = '1';
            }
            
            i++;
        }
        return count;
    }
};