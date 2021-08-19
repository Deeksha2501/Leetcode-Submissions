class Solution {
public:
    int kthLargestValue(vector<vector<int>>& arr, int k) {
        priority_queue <int, vector<int>, greater<int> > pq;
        int n = arr.size() , m = arr[0].size();
        for(int i=0 ; i<n ; i++){
            for(int j=1 ; j<m ; j++){
                arr[i][j] = arr[i][j] ^ arr[i][j-1];
            }
        }
        for(int j=0 ; j<m ; j++){
            for(int i=1 ; i<n ; i++){
                arr[i][j] ^= arr[i-1][j];
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                pq.push(arr[i][j]);
                while(pq.size() > k)pq.pop();
            }
        }
        return pq.top();
    }
};