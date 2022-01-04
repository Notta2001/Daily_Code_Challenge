var containsDuplicate = (nums) => {
    let store = new Set();
    for (let i = 0; i < nums.length; ++i) {
        if (!store.has(nums[i]))
            store.add(nums[i]);
        else
            return true;
    }
    return false;
};