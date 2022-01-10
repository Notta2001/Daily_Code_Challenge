var addBinary = (a, b) => {
    const arrA = a.split("").reverse();
    const arrB = b.split("").reverse();
    let carry = 0;
    let answer = [];
    let idx = 0;

    const len = a.length > b.length ? a.length : b.length;

    while (idx < len) {
        const x = arrA[idx] ? +arrA[idx] : 0;
        const y = arrB[idx] ? +arrB[idx] : 0;
        const sum = carry + x + y;
        carry = Math.floor(sum/2); // round down
        answer.unshift(sum % 2);
        idx++;
    }

    if (carry > 0) answer.unshift(carry);

    return answer.join("");
};

// https://leetcode.com/problems/add-binary/