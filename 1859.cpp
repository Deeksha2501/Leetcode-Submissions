class Solution {
public:
    string sortSentence(string str) {
        
        istringstream ss(str);
        string word; 
        
        vector<pair<string , string> > wds;
        
        while (ss >> word) 
        {
            int n = word.length();
            string w =  word.substr(0 , n-1);
            string num = word.substr(n-1);
            // cout<<num<<"\n";
            
            wds.push_back({num , w});
        }
        
        sort(wds.begin() , wds.end());
        string ans = "";
        
        for(int i=0 ; i<wds.size() ; i++){
            ans += wds[i].second;
            if(i != wds.size()-1)ans += " ";
        }
        // ans = ans - " ";
        return ans;
    }
};


//geek
//0123