var moveZeroes = (nums) => {
    let l = 0;
    let r = 1; // right pointer is the fast one and always ahead

    while (r < nums.length) {
        if (nums[r] === 0 || l >= r) { // r points to first non zero num, and is always ahead of L
            r++;
        } else if (nums[i] === 0) {
            [nums[l], nums[r]] = [nums[r], [nums[l]]]; // if L ever points to zero swap it with next non zero number
        } else {
            l++; // if L non zero, no swap necessary
        }
    }
};