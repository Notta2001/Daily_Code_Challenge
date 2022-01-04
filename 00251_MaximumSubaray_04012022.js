var maxSubArray = (nums) => {
    let sum = 0;
    let max = nums[0];
    for (let i = 0; i < nums.length; ++i) {
        sum += nums[i];
        max = Math.max(max, sum);
        if (sum < 0) 
            sum = 0;
    }
    return max;
};