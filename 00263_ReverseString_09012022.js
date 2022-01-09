var reverseString = s => {
    let i = 0, j = s.length - 1;
    while (i <= j) {
        let temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        i ++;
        j --;
    };
};