var getAllElements = function(root1, root2) {
    // Initialize an empty
    var ans = [];
    
    // Pre-Order traversal using Depth-First Search
    function dfs(root) {
        if (root == undefined) return;
        ans.push(root.val);
        dfs(root.left);
        dfs(root.right);
    }
    dfs(root1);
    dfs(root2);
    
    // Sort in increasing order
    ans.sort((a, b) => a - b);
    return ans;
};

// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/