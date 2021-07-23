/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isEvenOddTree(TreeNode root) {
        if(root==null)return true;
        Queue<TreeNode> queue=new LinkedList<>();
        queue.add(root);
        int i=1;
        while(!queue.isEmpty()){
            int size =queue.size();
            // if(i==1){
            //     if(size%2==0)return false;
            // }else{
            //     if(size%2==1)return false;
            // }
            int prev=i*Integer.MIN_VALUE;
            for(int ii=0;ii<size;ii++){
                TreeNode node=queue.poll();
                int temp=i*node.val;
                if(i == 1 && temp%2 == 0)return false;
                if(i == -1 && temp%2 != 0)return false;
                if(temp<=prev)return false;
                if(node.left!=null)queue.add(node.left);
                if(node.right!=null)queue.add(node.right);
                prev=temp;
            }
            i=-1*i;
        }
        return true;
    }
}