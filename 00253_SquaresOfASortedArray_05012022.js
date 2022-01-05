const sortedSquares = nums => {
    const sorted = new Array(nums.length);
    
    let start = 0;
    let end = sorted.length - 1;
    
    for (let insert = end; insert >= 0; insert--) {
        const squaredStart = Math.pow(nums[start], 2);
        const squaredEnd = Math.pow(nums[end], 2);
        
        if (squaredStart > squaredEnd) {
            sorted[insert] = squaredStart;
            start++;
        } else {
            sorted[insert] = squaredEnd;
            end--;
        }
    }
    
    return sorted;
};