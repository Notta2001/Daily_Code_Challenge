class TreeNode:
    def __init__(self, val=0, left=None, right=None) :
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int :
        stack = []
        ans = [0]
    
        def preorder(root: TreeNode):
            if root: 
                stack.append(root.val)
                if max(stack) == root.val:
                    ans[0] += 1
                preorder(root.left)
                preorder(root.right)
                stack.pop()

        preorder(root)
        return ans[0]


a1 = TreeNode(1)
a2 = TreeNode(5)
a3 = TreeNode(4, a1, a2)
a4 = TreeNode(3)
a5 = TreeNode(1, a4, None)
a6 = TreeNode(3, a5, a3)
obj = Solution()

print(obj.goodNodes(a6))

#https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3899/

