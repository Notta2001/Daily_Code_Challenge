var insertIntoBST = (root, val) => {
    if (root === null)
        return new TreeNode (val, null, null);
    
    let node = root;
    let prevNode;

    while (node) {
        prevNode = node;
        if (val < node.val) {
            node = node.left;
        } else {
            node = node.right;
        }
    }

    node = new TreeNode(val, null, null);
    
    if (prevNode.val < val) {
        prevNode.right = node;
    } else {
        prevNode.left = node;
    }

    return root;
};