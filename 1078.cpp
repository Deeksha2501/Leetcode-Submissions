class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        istringstream ss(text);
        string word; 
        vector<string> w;
        while (ss >> word) {
            w.push_back(word);   
        }
        vector<string> res;
        for(int i=2 ; i<w.size() ; i++){
            if(w[i-1] == second && w[i-2] == first){
                res.push_back(w[i]);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        int i=0;
        string curr="";
        bool flag = false;
        vector<string> res;
        while(i<text.length()){
            if(text[i] == ' '){
                string word = curr;
                // cout<<"\nword = "<<word;
                curr = "";
                if(flag){
                    // cout<<"\ninside flag";
                    if(second == word){
                        // cout<<"\nsecond word matched";
                        i++;
                        curr = "";
                        // cout<<"\nlooking for";
                        while(i<text.size() && text[i] != ' '){
                            curr += text[i];
                            i++;
                        }
                        if(curr != ""){
                            // cout<<"\npushing "<<curr;
                            res.push_back(curr);
                        }
                        if(curr == first){
                            // cout<<"\nfirst matched too";
                            flag = true;
                            curr = "";
                        }else{
                            curr = "";
                            flag = false;
                        }    
                    }
                    else if(word == first) flag = true;
                    else flag = false;
                }else{
                    // cout<<"\ninside ----flag";
                    if(first == word){
                        // cout<<"\nfirst word matched";
                        curr = "";
                        flag = true;
                    }
                }
            }else{
                curr += text[i];
            }
            i++;
        }
        return res;
    }
};