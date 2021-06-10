import java.util.TreeMap;

class MyCalendarI {
    class Node {
    	private int start;
    	private int end;
    	private Node left;
    	private Node right;
    	
    	public Node(int start, int end) {
    		this.start = start;
    		this.end = end;
    	}
    }
    
    private Node root;
    
    MyCalendarI (){
    	this.root = null;
    }
    
    public boolean book(int start, int end) {
    	if(root == null) {
    		root = new Node(start, end);
    		return true;
    	}
    	
    	Node node = root;
    	while(node != null) {
    		if(end <= node.start) {
        		if(node.left == null) {
        			node.left = new Node(start, end);
        			return true;
        		}
        		node = node.left;
    		}
    		else if (start >=  node.end) {
    			if(node.right == null) {
    				node.right = new Node(start, end);
    				return true;
    			}
    			node = node.right;
    		}
    		else {
    			return false;
    		}
    	}
    	return true;
    }
}