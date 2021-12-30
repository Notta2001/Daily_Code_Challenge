var rob = (nums) => {
    let memo = []
    memo[0] = 0;
    memo[1] = nums[0]
    for (let i = 1; i < nums.length; ++i) {
        memo[i+1] = Math.max(memo[i], memo[i+1] + nums[i])
    }
    return memo[nums.length]
}