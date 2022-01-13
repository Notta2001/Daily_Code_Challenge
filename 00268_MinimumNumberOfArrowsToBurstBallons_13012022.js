var findMinArrowShots = (points) => {
    points.sort(([s1, f1], [s2, f2]) => s1 - s2);
    
    let curr = Number.NEGATIVE_INFINITY, arrows = 0;

    for (let i = 0; i < points.length; ++i) {
        if (curr < points[i][0]) {
            arrows ++;
            curr = points[i][1];
        } else {
            curr = Math.min(curr, points[i][1]);
        }
    }

    return arrows;
};