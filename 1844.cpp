class Solution {
public:
char shift(char c , int n){

    return c+n;
}
    
    string replaceDigits(string s) {
        int n = s.length();
        int i=1;
        while(i<n){
            // cout<<"i = "<<i<<endl;
            s[i] = shift(s[i-1] ,s[i]-'0');
            // cout<<"s[i] = "<<s[i]<<endl;
            i+=2;
        }
        return s;
        
    }
};