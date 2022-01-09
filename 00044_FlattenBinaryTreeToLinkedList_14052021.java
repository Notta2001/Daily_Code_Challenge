import java.util.Stack;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x){
		this.val = x;
	}
}

public class FlattenBinaryTree {
	public static void flatten(TreeNode root) {
		print(root);
		if(root == null) return;
        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);
        
        while(!stack.isEmpty()){
            TreeNode current_node = stack.pop();
            if(current_node.right != null){
                stack.push(current_node.right);
            }
            if(current_node.left != null){
                stack.push(current_node.left);
            }
            
            if(!stack.isEmpty()){
                current_node.right = stack.peek();
            }
            current_node.left = null;
        }
        print(root);
	}
	
	public static void print(TreeNode root) {
		if(root == null ) return ;
		Stack<TreeNode> stack = new Stack<TreeNode>();
		stack.push(root);
		System.out.print(root.val);
		while(!stack.isEmpty()) {
			TreeNode current_node = stack.pop();
			if(current_node.left != null) {
				System.out.print(" " + current_node.left.val);
				stack.push(current_node.left);
			}
			if(current_node.right != null) {
				System.out.print(" " + current_node.right.val);
				stack.push(current_node.right);
			}
		}
		System.out.println("");
	}
	
	public static void main(String[] args) {
		TreeNode a1 = new TreeNode(1);
		TreeNode a2 = new TreeNode(2);
		TreeNode a3 = new TreeNode(3);
		TreeNode a4 = new TreeNode(4);
		TreeNode a5 = new TreeNode(5);
		TreeNode a6 = new TreeNode(6);
		a1.left = a2;
		a1.right = a5;
		a2.left = a3;
		a2.right = a4;
		a5.left = null;
		a5.right = a6;
		
		flatten(a1);
	}
}

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/