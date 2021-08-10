class Solution {
public:
    string mostCommonWord(string s, vector<string>& b) {
        string punc = "!?',;.";
        transform(s.begin() , s.end() , s.begin() , ::tolower);
        for(char c : punc)replace(s.begin(), s.end(), c, ' ');
        
        unordered_set<string> banned(b.begin(), b.end());
        unordered_map<string , int> mp;
        
        istringstream ss(s); 
        string word;
        while(ss >> word){
            if(banned.find(word) != banned.end())continue;
            mp[word]++;
        }
        
        int mx = INT_MIN;
        string res = "";
        for(auto it : mp){
            if(it.second > mx){
                mx = it.second;
                res = it.first;
            }
        }
        return res;
        
    }
};



///-----------------------------------------------------------------------///



class Solution {
public:
    string mostCommonWord(string pr, vector<string>& banned) {
        
        transform(pr.begin(), pr.end(), pr.begin(), ::tolower); 
        // cout<<pr;
        unordered_set<string> bn;
        unordered_map<string , int> mp;
        for(int i=0 ; i<banned.size() ; i++){
            bn.insert(banned[i]);
        }
        
        istringstream ss(pr);
        string word; 
        while (ss >> word) 
        {
            int n = word.length();
            char c = word[n-1];
            // if(c == '!' || c == '?' || c == ',' || c == ';' || c == '.')
            //     word = word.substr(0 , n-1);
            // // cout<<"\nword = "<<word;
            // string w = word;
            // for(int i=0)
            
            string w = "";
            int i=0;
            while(i < n){
                char c = word[i];
                if(c == '!' || c == '?' || c == ',' || c == ';' || c == '.' || (int)c == 39 ){
                    // cout<<"w = "<<w<<" ";
                    if(w != "")if(bn.find(w) == bn.end())mp[w]++;
                    w = "";
                }else{
                    w += word[i];
                }
                i++;
            }
            
            // if(bn.find(word) == bn.end())mp[word]++;
            if(w != "")if(bn.find(w) == bn.end())mp[w]++;
        }
        
        int mx = INT_MIN;
        string res;
        for(auto it : mp){
            // cout<<"\n"<<it.first<<" "<<it.second;
            if(it.second>=mx){
                mx = it.second;
                res = it.first;
            }
        }
        
        return res;

        
        
    }
};