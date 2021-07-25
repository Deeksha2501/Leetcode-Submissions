class Solution {
public:
    
    static bool cmp(string a  , string b){
        size_t aa = a.find('-');
        size_t bb = b.find('-');
        string a1 = a.substr(0 , aa);
        string b1 = b.substr(0 , bb);
        if(a1 == b1)return a<b;
        return a1 < b1;
    }
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        vector<string> digits;
        vector<string> letters;
        for(int i=0 ; i<n ; i++){
            istringstream ss(logs[i]);
            string word; 
            vector<string> v;
            while (ss >> word) {
                v.push_back(word);
                
            }
            if(isdigit(v[1][0])){
                string s = "";
                for(int j=1 ; j<v.size() ; j++){
                    s = s + " " + v[j];
                }
                s = s + "-" + v[0];
                digits.push_back(s);
            }else{
                string s = "";
                for(int j=1 ; j<v.size() ; j++){
                    s = s + " " + v[j];
                }
                s = s + "-" + v[0];
                letters.push_back(s);
            }
        }
        
        sort(letters.begin() , letters.end() , cmp);
        
        for(int i=0 ; i<digits.size() ; i++){
            string s = digits[i];
            size_t a = s.find('-');
            size_t b = a + 1;
            string id = s.substr(b);
            s = s.substr(0 , a);
            s = id + s;
            digits[i] = s;
        }
        
        for(int i=0 ; i<letters.size() ; i++){
            string s = letters[i];
            size_t a = s.find('-');
            size_t b = a + 1;
            string id = s.substr(b);
            s = s.substr(0 , a);
            s = id + s;
            letters[i] = s;
        }
        
        for(int i=0 ; i<digits.size() ; i++){
            letters.push_back(digits[i]);
        }
        
        return letters;
        
    }
};