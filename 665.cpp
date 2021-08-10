class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
        int cnt=0,n=arr.size();
        for(int i=1 ; i<n ; i++){
            if(arr[i] < arr[i-1]){
                cnt++;
                if(i > 1 && i<n-1 && arr[i-2] > arr[i] && arr[i+1] < arr[i-1])return false;
            }
            if(cnt>1)return false;
        }
        return true;
    }
};




class Solution {
public:
    bool checkPossibility(vector<int>& N) {
            for (int i = 1, err = 0; i < N.size(); i++)
                if (N[i] < N[i-1])
                    if (err++ || (i > 1 && i < N.size() - 1 && N[i-2] > N[i] && N[i+1] < N[i-1]))
                        return false;
            return true;
        }
};
