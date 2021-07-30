/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    vector<int> arr;
    
    
    void endfs(TreeNode* root){
        if(root == NULL){
            arr.push_back(-1);
            return;
        }
        arr.push_back(root->val);
        endfs(root->left);
        endfs(root->right);
    }
    
    string serialize(TreeNode* root) {
        arr.clear();
        endfs(root);
        string data="";
        for(int i=0 ; i<arr.size() ; i++){
            string ss= "";
            if(arr[i] == -1)ss = "&";
            else ss = to_string(arr[i]);
            data = data + ss + ",";
        }
        // cout<<data<<endl;
        return data;
    }
    
    int i;
    string s;
    
    TreeNode* dec(){
        // cout<<"\ni = "<<i<;
        if(i >= arr.size())return NULL;
        if(arr[i] == -1){
            i++;
            return NULL;
        }
        TreeNode* root = new TreeNode(arr[i]);
        i++;
        root->left = dec();
        root->right = dec();
        return root;
    }
    
    // void print(){
    //     for(int i=0 ; i<arr.size() ; i++){
    //         cout<<arr[i]<<" ";
    //     }
    // }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        arr.clear();
        for(int i=0 ; i<data.length() ; i++){
            if(data[i] == '&'){
                arr.push_back(-1);
            }else if(data[i] == ',')continue;
            else{
                string s="";
                while(data[i] != '&' && data[i] != ','){
                    s += data[i];
                    i++;
                }
                int x = stoi(s);
                arr.push_back(x);
                if(data[i] == '&')arr.push_back(-1);
            }
        }
        // print();
        int i=0;
        return dec();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;