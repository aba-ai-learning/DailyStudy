def cal_const_matrix(matrix):
    w = len(matrix)
    h = len(matrix[0])
    for j in range(1,h):
        matrix[0][j] = matrix[0][j] + matrix[0][j-1]
    for i in range(1,w):
        matrix[i][0] = matrix[i][0] + matrix[i-1][0]
    for i in range(1,w):
        for j in range(1,h):
            matrix[i][j] = -matrix[i-1][j-1] + matrix[i-1][j]+matrix[i][j-1] +matrix[i][j]

    return matrix

def sub_sum_matrix(matrix, col, row, h, w):
    col = col-1
    row = row -1
    sum_all = matrix[row+w][col+h]
    sum_l_t = matrix[row][col]
    sum_left = matrix[row][col+h]
    sum_top = matrix[row+w][col]
    return sum_all +  sum_l_t - sum_left - sum_top

if __name__ == "__main__":
    matrix = [
        [1,2,3,4],
        [2,3,4,5],
        [3,4,5,6],
        [4,5,6,7]
    ]
    matrix_sum = cal_const_matrix(matrix)
    print(matrix_sum)

    sum_sub = sub_sum_matrix(matrix_sum, 2, 2, 2, 2)
    print(sum_sub)



