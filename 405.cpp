class Solution {
public:
    string toHex(int num) {
        if(num == 0)return "0";
        string res = "";
        
        if(num > 0){
            while(num){
                int r = num%16;
                if(r>9){
                    char c = 'a' + (r-10);
                    res = c + res;
                }else{
                    res = to_string(r) + res;
                }
                num = num/16;
            }
        }else{
            u_int n = num;
            while(n){
                int r = n%16;
                if(r>9){
                    char c = 'a' + (r-10);
                    res = c + res;
                }else{
                    res = to_string(r) + res;
                }
                n = n/16;
            }
        }
        return res;
    }
};