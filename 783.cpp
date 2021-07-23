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
    int min=Integer.MAX_VALUE;
    public int minDiffInBST(TreeNode root) {
        dfs(root);
        return min;
    }
    public void dfs(TreeNode node){
        if(node==null)return;
        if(node.left==null && node.right==null)return;
        if(node.left!=null){
            min=Math.min(min,node.val-node.left.val);
            System.out.println("comparing " + node.val + " and " + node.left.val);
            dfs(node.left);
        }
        if(node.right!=null){
            min=Math.min(min,node.right.val-node.val);
            System.out.println("comparing " + node.val + " and " + node.right.val);
            dfs(node.right);
        }
    }
}