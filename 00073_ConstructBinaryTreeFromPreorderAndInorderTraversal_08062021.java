import java.util.LinkedList;
import java.util.Queue;

class TreeNode{
	int val;
	TreeNode left;
	TreeNode right;
	
	TreeNode(){
		
	}
	
	TreeNode(int val){
		this.val = val;
	}
	
	TreeNode(int val, TreeNode left, TreeNode right){
		this.val = val;
		this.left = left;
		this.right = right;
	}
}
public class ConstructBinaryTreeFromPreorderAndInorderTraversal {
	public static TreeNode buildTree(int[] preorder, int[] inorder) {
        int preStart = 0;
        int preEnd = preorder.length-1;
        int inStart = 0;
        int inEnd = inorder.length-1;

        return construct(preorder, preStart, preEnd, inorder, inStart, inEnd);
    }

    public static TreeNode construct(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd){
        if(preStart>preEnd||inStart>inEnd){
            return null;
        }

        int val = preorder[preStart];
        TreeNode p = new TreeNode(val);

        //find parent element index from inorder
        int k=0;
        for(int i=0; i<inorder.length; i++){
            if(val == inorder[i]){
                k=i;
                break;
            }
        }

        p.left = construct(preorder, preStart+1, preStart+(k-inStart), inorder, inStart, k-1);
        p.right= construct(preorder, preStart+(k-inStart)+1, preEnd, inorder, k+1 , inEnd);

        return p;
    }
	
	public static void printTree(TreeNode head) {
		Queue<TreeNode> q = new LinkedList<TreeNode>();
		q.offer(head);
		System.out.print("[ ");
		while(!q.isEmpty()) {
			TreeNode cur = q.poll();
			if(cur != null) {
				System.out.print(cur.val + " ");
				q.offer(cur.left);
				q.offer(cur.right);
			}
			else {
				System.out.print("null ");
			}
		}
		System.out.println("]");
	}
	
	public static void main(String[] args) {
		int[] inorder = { 3,9,20,15,7};
        int[] postorder = { 9,3,15,20,7};
 
        TreeNode head = buildTree(inorder, postorder);
        printTree(head);
	}
}
