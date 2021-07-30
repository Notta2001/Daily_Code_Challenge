import java.util.*;

class Node {
	Map<Character, Node> neighbors;
	int sum;
	
	public Node(int sum) {
		this.neighbors = new HashMap<>();
		this.sum = 0;
	}
	
	public boolean contains(char c) {
		return this.neighbors.containsKey(c);
	}
	
	public Node get(char c) {
		return this.neighbors.get(c);
	}
	
	public void addNeighbor(char c) {
		this.neighbors.put(c, new Node(0));
	}
}

class Trie {
	Node root;
	
	public Trie() {
		this.root = new Node(0);
	}
	
	public void insert(String s, int val) {
		char[] ch = s.toCharArray();
		Node curr = root;
		for(int i = 0; i < ch.length; ++i) {
			curr.sum += val;
			char c = ch[i];
			if(!curr.contains(c)) {
				curr.addNeighbor(c);
			}
			curr = curr.get(c);
		}
		
		// ????
		if(curr != null) {
			curr.sum += val;
		}
	}
	
	public int prefixSum(String prefix) {
		char[] ch = prefix.toCharArray();
		Node curr = root;
		for(int i = 0; i < ch.length; ++i) {
			char c = ch[i];
			if(!curr.contains(c))
				return 0;
			curr = curr.get(c);
		}
		return curr.sum;
	}
	
	public void updateSum(String s, int val, int prevVal) {
		char[] ch = s.toCharArray();
		Node curr = root;
		for(int i = 0; i < ch.length; ++i) {
			char c = ch[i];
			curr.sum -= prevVal;
			curr.sum += val;
			if(!curr.contains(c)) {
				return;
			}
			else {
				curr=curr.get(c);
			}
		}
		
		if(curr != null) {
			curr.sum -= prevVal;
			curr.sum += val;
		}
	}
}
public class MapSumPairs {
	Map<String, Integer> map;
	Trie trie;
	
	/** Initialize your data structure here**/
	public MapSumPairs() {
		map = new HashMap<>();
		trie = new Trie();
	}
	
	public void insert(String key, int val) {
		if(!map.containsKey(key)) {
			trie.insert(key, val);
		}
		else {
			trie.updateSum(key, val, map.get(key));
		}
		
		map.put(key, val);
	}
	
	public int sum(String prefix) {
		return trie.prefixSum(prefix);
	}
	
	public static void main(String args[]) {
		MapSumPairs obj = new MapSumPairs();
		obj.insert("apple", 3);
		System.out.println(obj.sum("ap"));
		obj.insert("app", 2);
		System.out.println(obj.sum("ap"));
		System.exit(0);
	}
}

//https://leetcode.com/problems/map-sum-pairs/


