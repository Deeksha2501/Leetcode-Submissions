class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        st.push(arr[0]);
        for(int i=1 ; i<arr.size() ; i++){
            if(!st.empty() && st.top() > 0 && arr[i] < 0){
                if(abs(arr[i]) > abs(st.top())){
                    st.pop();
                    i--;
                    continue;
                }else if(abs(arr[i]) == abs(st.top()))st.pop();
            }else st.push(arr[i]);
        }
        arr.clear();
        while(st.empty()==false){
            arr.insert(arr.begin() , st.top());
            st.pop();
        }
        return arr;
    }
};