class Solution {
public:
    string toGoatLatin(string sen) {
        unordered_set<char> v{'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        
        istringstream words(sen);
        string s;
            
        vector<string> w;
        
        while(words>>s){
            w.push_back(s);
        }
        string res = "";
        
        for(int i=0 ; i<w.size() ; i++)   {
            if(v.find(w[i][0]) != v.end()){
                w[i] += "ma";
                
            }else{
                 w[i] = w[i] + w[i][0];
                w[i] = w[i].substr(1 , w[i].length());
               
                w[i] += "ma";
            }
            int j=i+1;
            while(j--){
                w[i]+= 'a';
            }
            if(i == w.size()-1)res += w[i];
            else res += w[i] + " ";
        }
        return res;
        
    }
};