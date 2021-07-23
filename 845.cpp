class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        bool up=false, down = false;
        int start = 0, end = 1;
        int prev=0, res=0;
        while(start < end && end < n ){
            if(arr[end]<arr[prev]){
                if(up){
                    down = true;
                    // cout<<"\nsetting res at = "<<start<<" "<<end;
                    res = max(res , end-start+1);
                }
                if(down){
                    // cout<<"\nsetting res at = "<<start<<" "<<end;
                    res = max(res , end-start+1);
                    end++;
                    prev++;
                }
                else{
                    end++;
                    prev++;
                    start++;
                }
                up = false;
            }else if(arr[end]>arr[prev]){
                if(up == false || down){
                    start = prev;
                }
                end++;
                prev++;
                up = true;
                down = false;
            }else{
                end++;
                prev++;
                start = prev;
                up=false;
                down = false;
            }
        }
        return res;
    }
};

