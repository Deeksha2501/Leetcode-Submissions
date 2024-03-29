class Solution {
public:
    string s;
    int get(int i , int j , int n){
        int cnt=0;
        while(i >=0 && j < n){
            if(s[i] == s[j]){
                cnt++;
            }else return cnt;
            i--;
            j++;
        }
        return cnt;
    }
    
    int countSubstrings(string s) {
        this->s = s;
        int res=0;
        int n = s.length();
        for(int i=0 ; i<n ; i++){
            res += get(i , i+1 , n);
            res += get(i , i , n);
        }
        return res;
    }
};



struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
public:
    unordered_set<pair<int , int>,  pair_hash > m;
    int count=0;
    
    void fun(int st , int end , string s){
        if(st < 0 || end >= s.length())return;
        while(st >= 0 && end < s.length() && s[st] == s[end]){
            st--;
            end++;
            count++;
        }
//         int a = st+1;
//         int b = end-1;
//         if(m.find({a , b}) == m.end()){
//             cout<<"\na = "<<a;
//             cout<<" b = "<<b;
//             count++;
//             m.insert({a , b});
//         }
       
    }
    
    int countSubstrings(string s) {
        for(int i=0 ; i<s.length() ; i++){
            fun(i , i , s);
            fun(i , i+1 , s);
        }
        return count;
    }
};