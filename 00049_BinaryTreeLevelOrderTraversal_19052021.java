import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class TreeNode{
	int val;
	TreeNode left;
	TreeNode right;
	
	TreeNode () {
		
	}
	
	TreeNode (int val) {
		this.val = val;
	}
	
	TreeNode (int val, TreeNode left, TreeNode right){
		this.val = val;
		this.left = left;
		this.right = right;
	}
}
public class BinaryTreeLevelOrderTraversal {
	public static List<List<Integer>> levelOrder (TreeNode root){
		List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(root == null) return ans;
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        while(!q.isEmpty()){
            int curLength = q.size();
            List<Integer> curList = new ArrayList<Integer>();
            for(int i = 0; i < curLength; ++i){
                TreeNode curNode = q.poll();
                curList.add(curNode.val);
                if(curNode.left != null){
                    q.offer(curNode.left);
                }
                if(curNode.right != null){
                    q.offer(curNode.right);
                }
            }
            ans.add(curList);
        }
        return ans;
	}
	
	public static void print(List<List<Integer> > ans) {
		System.out.print("[");
		for(int i = 0; i < ans.size(); ++i) {
			System.out.print("[");
			for(int j = 0; j < ans.get(i).size(); ++j) {
				System.out.print(" " + ans.get(i).get(j) + " ");
			}
			System.out.print("]");
		}
		System.out.print("]");
		System.out.println("");
	}
	
	public static void main(String[] args) {
		TreeNode a1 = new TreeNode(3);
		TreeNode a2 = new TreeNode(9);
		TreeNode a3 = new TreeNode(20);
		TreeNode a4 = new TreeNode(15);
		TreeNode a5 = new TreeNode(7);
		
		a1.left = a2;
		a2.left = null; 
		a2.right = null;
		a1.right = a3;
		a3.left = a4;
		a3.right = a5;
		a4.left = null;
		a4.right = null;
		a5.left = null;
		a5.right = null;
		
		List<List<Integer> > ans = levelOrder(a1);
		print(ans);
		
		List<List<Integer> > ans1 = levelOrder(a3);
		print(ans1);
		
	}
}
