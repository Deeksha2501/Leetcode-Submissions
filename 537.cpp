class Solution {
public:
    pair<int , int> split(string a){
        string real = "";
        int i=0;
        for(i=0 ; i<a.length() ; i++){
            if(a[i] == '+')break;
            real += a[i];
        }
        string com = a.substr(i+1);
        pair<int , int> p;
        p.first = stoi(real);
        p.second = stoi(com);
        return p;
    }
    
    string complexNumberMultiply(string a, string b) {
        pair<int , int> aa = split(a);
        pair<int , int> bb = split(b);
        
        string real = to_string(aa.first*bb.first - aa.second*bb.second);
        string im = to_string(aa.first*bb.second + aa.second*bb.first);
        return real + "+" + im + "i";
    }
};