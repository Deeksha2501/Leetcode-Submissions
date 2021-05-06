class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int i=0,j=0, n = w1.size(), m = w2.size();
        int f = 0;
        string res = "";
        while(i<n && j<m){
            if(f%2 == 0){
                res += w1[i];
                i++;
            }
            else{
              res += w2[j];
              j++;
            } 
            f++;
        }
        while(i<n){
            res += w1[i];
            i++;
        }
        while(j <m){
            res += w2[j];
            j++;
        }
        return res;
    }
};