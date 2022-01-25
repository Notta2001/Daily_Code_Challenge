/**
 * @param {number[]} arr
 * @return {boolean}
 */
 var validMountainArray = function(arr) {
    if (arr.length < 3) return false;

    for(var i = 0; i < arr.length; i++){
        if (arr[i] === arr[i + 1]) return false; 
        if (arr[i] > arr[i + 1]) break;   
    }

    for(var j = arr.length - 1; j > 0; j--){
        if (arr[j - 1] === arr[j]) return false; 
        if (arr[j - 1] < arr[j]) break; 
    }

    if (i > 0 && i === j) return true;
    return false;
};

// https://leetcode.com/problems/valid-mountain-array/