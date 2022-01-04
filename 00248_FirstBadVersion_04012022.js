var solution = (isBadVersion) => {
    return function(n) {
        let right = n, left = 1;
        
        while(left < right){
           let mid = Math.floor(left + (right - left)/2);
           isBadVersion(mid) ? right = mid : left = mid + 1;
        }
        return right;
    };    
};

// https://leetcode.com/problems/first-bad-version/submissions/