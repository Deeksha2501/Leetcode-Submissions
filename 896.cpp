class Solution {
public:
        bool isMonotonicIncreasing(vector<int>& A) {
        for (int i = 1; i < A.size(); ++ i) {
            if (A[i] < A[i - 1]) {
                return false;
            }
        }
        return true;
    }
 
    bool isMonotonicDecreasing(vector<int>& A) {
        for (int i = 1; i < A.size(); ++ i) {
            if (A[i] > A[i - 1]) {
                return false;
            }
        }
        return true;
    }
    
    bool isMonotonic(vector<int>& a) {
        return isMonotonicDecreasing(a) || isMonotonicIncreasing(a);
        
    }
};