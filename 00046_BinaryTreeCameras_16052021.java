class TreeNode{
	int val;
	TreeNode right;
	TreeNode left;
	
	TreeNode (){};
	
	TreeNode(int val){
		this.val = val;
	}
	
	TreeNode(int val, TreeNode left, TreeNode right){
		this.val = val;
		this.left = left;
		this.right = right;
	}
	
	
}

public class BinaryTreeCameras {
	// 0: it cannot be monitored
	// 1: put a camera here
	// 2: no camera, but can be monitored (a null)
	private static int total = 0;
	
	public static int minCameraCover(TreeNode root) {
		if(helper(root) == 0) {
			total += 1;
		}
		return total;
	}
	
	public static int helper(TreeNode root) {
		if(root == null) return 2;
		
		int left = helper(root.left);
		int right = helper(root.right);
		
		if(left == 0 || right == 0) {
			total += 1;
			return 1;
		}
		
		if(left == 2 && right == 2) {
			return 0;
		}
		return 2;
	}
	
	public static void main(String[] args) {
		TreeNode a1 = new TreeNode(0);
		TreeNode a2 = new TreeNode(0);
		TreeNode a3 = new TreeNode(0);
		TreeNode a4 = new TreeNode(0);
		TreeNode a5 = new TreeNode(0);
		a1.left = a2;
		a1.right = null;
		a2.left = a3;
		a2.right = null;
		a3.left = a4;
		a3.right = null;
		a4.right = a5;
		a4.left = null;
		a5.right = null;
		a5.left = null;
		
		System.out.println(minCameraCover(a1));
	}
}
