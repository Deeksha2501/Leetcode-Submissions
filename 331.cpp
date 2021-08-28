class Solution {
public:
    bool isValidSerialization(string preorder) {
        int degree=1;
        stringstream ss(preorder);
        string temp;

        while(getline(ss , temp , ',')){
            degree--;
            if(degree<0)return false;
            if(temp[0] != '#')degree += 2;
        }
        return degree == 0;
    }
};
