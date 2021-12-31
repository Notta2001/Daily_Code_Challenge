var canReach = (arr, start) => {
    const check = new Array(arr.length).fill(false)
    const rec = (curr) => {
        //2 base cases
        // 1. If we get outside of the array or if we find a cycle return false
        if (curr > arr.length || curr < 0 || check[curr]) return false

        // 2. If we found a solution just return true
        if (arr[curr] === 0) return true
        else {
            // In any other cases check both options recursively
            check[curr] = true
            return rec(curr + arr[curr]) || rec(curr - arr[curr])
        }
    }
    return rec(start)
}

// https://leetcode.com/problems/jump-game-iii/