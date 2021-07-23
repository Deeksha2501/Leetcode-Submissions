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
            // while(i.second--){
            //     res += i.first;
            // }
           
        }
        sort(vec.begin(), vec.end(), cmp);
        for(int i=0 ; i<vec.size() ; i++){
            while(vec[i][0]--)
            res += vec[i][1];
        }
        return res;
    }
};