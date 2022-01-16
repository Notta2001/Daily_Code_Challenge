var maxDistToClosest = (seats) => {
    let max = 0, count = 0, seen = false;

    for (let i = 0; i < seats.length; ++i) {
        if (seats[i] == 1) {
            max = seen ? Math.max(max, count/2) : Math.max(count, max);
            seen = true;
            count = 0;
        } else {
            count ++;
        }
    }

    return Math.max(count, max);
};

// https://leetcode.com/problems/maximize-distance-to-closest-person/