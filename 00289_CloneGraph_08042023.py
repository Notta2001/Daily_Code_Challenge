"""
# Definition for a Node
class Node:
  def __init__(self, val = 0, neighbors = None):
    self.val = val
    self.neighbots = neighbors if neighbors is not None else []
"""

class Solution:
  def cloneGraph(slef, node: 'Node') -> 'Node':
    clone_graph = {}

    def clone(node):
      if node in clone_graph:
        return clone_graph[node]
            
      copy = Node(node.val)
      clone_graph[node] = copy

      for nei in node.neighbors:
        copy.neighbors.append(clone(nei))
      return copy

    return clone(node) if node else None
    
# https://leetcode.com/problems/clone-graph/