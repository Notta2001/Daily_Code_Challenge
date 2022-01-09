var isRobotBounded = (instructions) => {
    var dir = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    let k = 0, x = 0, y = 0;

    for (let i = 0; i < instructions.length; ++i) {
        if (instructions[i] == 'R') {
            k = (k + 1) % 4;
        }
        else if (instructions[i] == 'L') {
            k = (k + 3) % 4;
        } else {
            x += dir[k][0];
            y += dir[k][1];
        }
    };

    return x == 0 && y == 0 || k > 0;
};