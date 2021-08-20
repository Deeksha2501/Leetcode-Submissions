class Solution {
public:
    string sortString(string s) {
        
        int cnt[26] = {};
        for (auto ch: s)
            ++cnt[ch - 'a'];
        string res="";
        while (s.size() != res.size()) {
            for (auto i = 0; i < 26; ++i)
                res += string(--cnt[i] >= 0 ? 1 : 0, 'a' + i); 
            for (int i = 25; i >=0; --i)
                res += string(--cnt[i] >= 0 ? 1 : 0, 'a' + i);          
        }
        return res;
        
        
        map<int , int> st;
        for(char c:s)st[c-'a']++;

        int flag=1;
        while(st.size() > 0){
            string temp="";
            for(auto [key , val] : st){
                cout<<"\nkey = "<<key;
                temp += key + 'a';
                st[key]--;
                if(st[key] == 0)st.erase(key);
            }
            for(auto [key , val] : st){
                if(st[key] == 0)st.erase(key);
            }
            
            cout<<"\ntemp = "<<temp;
            if(flag == 0)reverse(temp.begin() , temp.end());
            flag = !flag;
            res += temp;
        }
        return res;
    }
};

// c - 1
// d - 1
// e - 3
// l - 1
// o - 1
// t - 1
    
// cdetol

