var search = (nums, target) => {
    let left = 0;
    let right = nums.length - 1;
    
    while (left <= right){
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] === target) return mid;
        else if (target > nums[mid]) left = mid + 1;
        else right = mid - 1;
    }
    
    return -1;
};

var search2 = (nums, target) => {
    let left = 0, right = nums.length - 1;
    
    const binarySearch = (nums, target, left, right) => {
        if (left > right) return -1;
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] === target) return mid;
        else if (target < nums[mid]) return binarySearch(nums, target, left, mid - 1);
        else return binarySearch(nums, target, mid+1, right);
    }
}

// https://leetcode.com/problems/binary-search/submissions/