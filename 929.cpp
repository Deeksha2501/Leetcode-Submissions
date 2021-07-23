class Solution {
    
    string normalise(string email){
        bool domain = false;
        bool plus = false;
        string res="";
        for(char c:email){
            if(domain){
                res += c;
                continue;
            }
            if(c == '@'){
                domain = true;
                res += c;
                continue;
            }
            if(plus)continue;
            if(c == '.')continue;
            if(c == '+'){
                plus = true;
                continue;
            }
            
            res += c;
        }
        // cout<<"\nres = "<<res;
        return res;
    }
    
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> res;
        
        for(int i=0 ; i<emails.size() ; i++){
            res.insert(normalise(emails[i]));
        }
        
        return res.size();
            
    }
};