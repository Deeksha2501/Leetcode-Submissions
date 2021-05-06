class Solution {
public:
    bool isSame(int a1[] , int a2[]){
        for(int i=0 ; i<26 ; i++){
            if(a1[i] != a2[i])return false;
        }
        return true;
    }
    
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int count=0;
        int ar1[26] = {0};
        int ar2[26] = {0};
        for(int i=0 ; i<n ; i++){
            ar1[s1[i]-'a']++;
            ar2[s2[i]-'a']++;
            if(s1[i] != s2[i]){
                count++;
            }
        }
        
        if(isSame(ar1,ar2) && (count == 2 || count == 0))return true;
        return false;
    }
};