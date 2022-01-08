/* We're going to set up a dynamic programming matrix such that dp[i][j][k] 
is the best result if the robots start on row i and columns j and k. 
We're going to work up from the bottom, and then our answer is going 
to be dp[0][0][cols-1].
    After building our empty DP matrix, we can use three nested for 
loops to achive usable values for i, j, and k.
    
    But we can use some logic to reduce the workload here. There is 
no reason that the robots should occupy the same position (j = k), 
nor is there ever a reason for the robots to cross each other ( j > k)
, as in both cases the same results can always be achieved by j < k. 
Also, since the robots can move at most at a 45 degree angle downward, 
we can see that j <= i and k >= cols - 1 - i. Also j < cols - 1 in order 
to leave room for k.

    Putting that all together, we can tailor the for loop conditionals 
appropriately. In order to reduce overall operations, we should use the 
more simple conditional as the end conditional, and thus we should 
iterate j backwards.

    Then, for each of our usable sets of i, j, and k, we need to then
figure out what is the max result based on the next row. To do that we 
can use two more nested for loops to run through the 3x3 possible 
combinations of next moves and check those values in our DP matrix. 
The best result will be added to the current robot grid values and stored 
in the DP matrix.

    To avoid breaking the code with values of i, j, or k that go out of 
bounds, we should use optional chaining when checking those possible next
moves. Then, to deal with undefined results in our Math.max(), we can 
simply use a ~ ~ (double bitwise NOT operator, which acts very much like 
a Math.floor()) in order to convert any undefined result into a 0.

    Finally, once we've completed the DP matrix, we can just return the
necessary start condition of dp[0][0][cols-1]. */

var cherryPickup = (grid) => {
    let rows = grid.length, cols = grid[0].length;
    dp = [...Array(rows)].map(x => [...Array(cols)].map(y => Array(cols)));

    for (let i = rows - 1; i >= 0; --i) {
        for (let j = Math.min(i, cols - 2); j >= 0; --j) {
            for (let k = Math.max(cols - i - 1, j + 1); k < cols; ++k) {
                let best = 0;
                for (let m = -1; m < 2; ++m) {
                    for (let n = -1; n < 2; ++n) {
                        best = Math.max(best, ~~dp[i+1]?.[j+m]?.[k+n]);
                    }
                }
                dp[i][j][k] = grid[i][j] + grid[i][k] + best;
            }
        }
    }
    return dp[0][0][cols-1];
};