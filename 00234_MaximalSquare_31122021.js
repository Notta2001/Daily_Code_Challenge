var maximalSquare = (matrix) => {
    let maxLength = 0

    for (let i = 0; i < matrix.length; ++i) {
        for (let j = 0; j < matrix[i].length; ++j) {
            if (matrix[i][j] == 1) {
                if (i > 0 && j > 0) {
                    matrix[i][j] = Math.min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]) + 1
                }
                maxLength = Math.max(maxLength, matrix[i][j])
            }
        }
    }
    
    return maxLength**2
}

// https://leetcode.com/problems/maximal-square/