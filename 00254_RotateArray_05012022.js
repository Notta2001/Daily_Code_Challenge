var rotate = (nums, k) => {
    if (!nums || !nums.length) return;
    if (nums.length == 1) return nums;
    if (k > nums.length) k = k % nums.length;
    
    if (k > 0) {
        reverse(nums, 0, nums.length-1);
        reverse(nums, 0, k-1); 
        reverse(nums, k, nums.length-1);
    }

    
    const reverse = (array, start, end) => {
        if (!array || !array.length || start >= end) return;
        
        while (start < end) {
            let temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            start++;
            end--;
        }
        return array;
    }

    return nums;    
};

// https://leetcode.com/problems/rotate-array/