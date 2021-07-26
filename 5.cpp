class Solution {
public:

    string s;
    int n;
 
    
    int expandAroundCentre(int i , int j){
        while(i>=0 && j < n && s[i] == s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
    
    string longestPalindrome(string s) {
        this->s = s;
        n = s.length();
        if(s.length() <= 1)return s;
        int end=0, start=0;
        int len=INT_MIN;
        for(int i=0 ; i<s.length() ; i++){
            int len1 = expandAroundCentre(i , i);
            int len2 = expandAroundCentre(i , i+1);
            len = max({len1 , len2});
            if(len > (end - start)){
                start = i - (len-1)/2;
                end = i + (len/2);
            }
            
        }
        return s.substr(start , end+1-start);
    }
};


// cabad