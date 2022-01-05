var partition = (s) => {
    let result = [];

    const backtrack = (i, partitions) => {
        if (i >= s.length) {
            result.push([...partitions]);
            return;
        }
        for (let j = i; j < s.length; ++j) {
            if (isPalindrome(i, j)) {
                partitions.push(s.substring(i, j+1));
                backtrack(j+1, partitions);
                partitions.pop();
            }
        }
    }

    const isPalindrome = (left, right) => {
        while (left < right) {
            if (s[left] !== s[right]) {
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
    backtrack(0, []);
    return result;
}