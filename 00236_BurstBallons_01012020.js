var maxCoins = (nums) => {
    nums.push(1)
    nums.unshift(1)

    const memo = [...Array(nums.length)].map(() => Array(nums.length).fill(0))

    for (let windowSize = 1; windowSize < nums.length-1; windowSize ++) {
        for (let start = 1, end = windowSize; end < nums.length-1; end++, start++) {
            for (let i = start; i <= end; ++i) {
                const currBurst = nums[start-1]*nums[i]*nums[end+1]
                const coins = memo[start][i-1] + currBurst + memo[i+1][end]
                dp[start][end] = Math.max(memo[start][end], coins)
            }
        }
    }
    return memo[1][nums.length-2]
}