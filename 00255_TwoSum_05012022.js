var twoSum = function(nums, target) {
    const map = {};
    let result = []
    
    for(let i = 0; i < nums.length; i++){
		// Compute the difference between the target and the current number
        const diff = target - nums[i];
		// If the hashmap contains the number, then we can return the indexes.
		// It's important to use map.hasOwnProperty instead of map[diff]. map[diff] will fail if the index value of the key diff is 0
        if(map.hasOwnProperty(diff)){
            result = [map[diff], i];
			break;
        }
        map[nums[i]] = i;
    }
    
    return result;
};