class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        int zeroes=0;
        for(int i : arr){
            st.insert(i);
            if(!i)zeroes++;
        }
        for(int i : arr){
            if(!i && zeroes>1)return true;
            else if(i && st.find(2*i) != st.end())return true;
        }
        return false;
    }
};
