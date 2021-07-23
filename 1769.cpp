class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> v, ans(boxes.length());
        for(int i=0 ; i<boxes.length() ; i++){
            if(boxes[i] == '1')v.push_back(i);
        }
        for(int i=0 ; i<boxes.length() ; i++){
            for(int j=0 ; j<v.size() ; j++){
                ans[i] += abs(v[j]-i);
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> minOperations(string b) {
        vector<int> v, ans(b.length() , 0);
        
        int n = b.length();
        int total_cnt = 0 , total_sum = 0;
        for(int i=0 ; i<n ; i++){
            if(b[i] == '1'){
                total_cnt++;
                total_sum += i;
            }
        }
        
        int left_cnt = 0, right_cnt = 0, left_sum = 0, right_sum = 0;
        
        for(int i=0 ; i<n ; i++){

            if(b[i] == '1'){
                left_cnt++;
                left_sum += i;
            }
            right_cnt = total_cnt - left_cnt;
            right_sum = total_sum - left_sum;
            
            ans[i] += (left_cnt*i - left_sum);
            ans[i] += (right_sum - right_cnt*i);
        }
        
        return ans;
        
    }
};