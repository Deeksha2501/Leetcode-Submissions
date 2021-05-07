class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int p = 5*n/100;
        sort(arr.begin(), arr.end());
        int i=0;
        while(i<p){
            arr.erase(arr.begin());
            i++;
        }
        i=0;
        while(i<p){
            arr.erase(arr.end()-1);
            i++;
        }
        double mean = 0;
        for(int i=0 ; i<arr.size() ; i++){
            mean += arr[i];
        }
        mean = mean/arr.size();
        return mean;
    }
};