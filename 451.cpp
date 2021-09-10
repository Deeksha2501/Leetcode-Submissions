class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<string> v(n+1);
        map<char , int> mp;
        for(char c : s)mp[c]++;
        for(auto it : mp){
            int n = it.second;
            char c = it.first;
            v[n].append(n , c);
        }
        string res="";
        for(int i=n ; i>=0 ; i--){
            if(v.empty() == false){
                res.append(v[i]);
            }
        }
        return res;
    }
};



class Solution {
public:
    
    static bool cmp(vector<int> a , vector<int> b){
        return a[0] > b[0];
    }
    
    string frequencySort(string s) {
        map<char, int> m;
        int i=0;
        while(i<s.length()){
            m[s[i]]++;
            i++;
        }
        string res = "";
        vector<vector<int> >vec;
        for(auto i : m){
             cout<<i.first<<" "<<i.second<<"\n";
            vec.push_back({i.second, (int)i.first});
           
        }
        sort(vec.begin(), vec.end(), cmp);
        for(int i=0 ; i<vec.size() ; i++){
            while(vec[i][0]--)
            res += vec[i][1];
        }
        return res;
    }
};