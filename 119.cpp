vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        queue<TreeNode* >q;
        q.push(root);
        q.push(NULL);
        TreeNode *prev;
        while(q.size()>1){
            TreeNode *curr = q.front();
            if(curr == NULL){
                q.pop();
                // cout<<prev->val;
                // cout<<"\n";
                res.push_back(prev->val);
                q.push(NULL);
                continue;
            }
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
            prev = curr;
            q.pop();
        }
        
        res.push_back(prev->val);
        return res;
    }