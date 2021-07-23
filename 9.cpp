class Solution {
public:
    string reverse(string s){
        int low = 0;
        int high = s.length()-1;
        while(low<high){
            swap(s[low],s[high]);
            low++;
            high--;
        }
        return s;
    }
    
    bool isPalindrome(int x) {
        if(x<0)return false;
       string s = to_string(x);
        string st = reverse(s);
        if(st == s)return true;
        return false;
        
    }
};