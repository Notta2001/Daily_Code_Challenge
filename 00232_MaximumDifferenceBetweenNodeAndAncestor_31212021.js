/*
Top Down
DFS takes us from root to each leaf node
    While travelling, maintain min & max values
    On reaching leaf, max-min will give maxDifference of any two nodes that path of root to leaf
    Do above for all leaves in DFS
    Return the max of all maxDifference
*/

var maxAncestorDiff = (root) => {
    const dfs = (n, minVal, maxVal) => {
        if(n === null) {
            return Math.max(maxVal - minVal) // root to leaf
        }

        minVal = Math.min(minVal, n.val)
        maxVal = Math.max(maxVal, n.val)

        return Math.max(
            dfs(n.left, minVal, maxVal),
            dfs(n.right, minVal, maxVal)
        )
    }

    return dfs(root, Infinity, -Infinity)
}