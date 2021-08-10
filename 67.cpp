class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.length(), m=b.length();
        int i=n-1,j=m-1,carry=0;
        string res="";
        while(i>=0 && j>=0){
            int sum = (a[i]-'0') + (b[j]-'0') + carry;
            if(sum > 1){
                carry = 1;
                sum = sum%2;
            }else carry = 0;
            res = to_string(sum) + res;
            i--;
            j--;
        }
        while(i>=0){
            int sum = (a[i]-'0') + carry;
            if(sum > 1){
                carry = 1;
                sum = 0;
            }else carry = 0;
            res = to_string(sum) + res;
            i--;
        }
        
        
        while(j>=0){
            int sum = (b[j]-'0') + carry;
            if(sum > 1){
                carry = 1;
                sum = 0;
            }else carry = 0;
            res = to_string(sum) + res;
            j--;
        }
        
        if(carry)res = '1' + res;
        
        
        return res;
    }
};