class Solution {
public:
    string defangIPaddr(string add) {
        string res;
        for(char c : add){
            if(c != '.'){
                res += c;
            }else{
                res += "[.]";
            }
        }
        return res; 
    }
};