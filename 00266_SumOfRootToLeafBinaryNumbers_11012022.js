/*
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
*/

var sumRootToLeaf = function(root) {
    let ans = 0;
    let currArray = []
    var binaryToInteger = (s) => {
        let res = 0;
        let base = 1;
        for (let i = s.length - 1; i >= 0; --i) {
            res += base * s[i];
            base *= 2;
        };
        return res;
    }
    
    var dfs = (currNode) => {
        currArray.push(currNode.val);
        if (currNode.left === null && currNode.right === null) {
            ans += binaryToInteger(currArray);
        } 
        if (currNode.left !== null)
            dfs (currNode.left);
        if (currNode.right !== null)
            dfs (currNode.right);
        currArray.pop();
    }
    
    dfs(root);
    return ans;
};