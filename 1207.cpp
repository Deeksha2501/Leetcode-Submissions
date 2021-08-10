class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size() , cnt=1;
        unordered_set<int> st;
        for(int i=1 ; i<n ; i++){
            if(arr[i] == arr[i-1])cnt++;
            else{
                if(st.find(cnt) != st.end())return false;
                st.insert(cnt);
                cnt=1;
            }
        }
        if(st.find(cnt) != st.end())return false;
        return true;
    }
};