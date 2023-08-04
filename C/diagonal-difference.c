// From: https://www.hackerrank.com/challenges/diagonal-difference/problem

int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    long firstDiagonal = 0;
    for (int idx = 0; idx < arr_rows; idx++)
    {
        firstDiagonal += arr[idx][idx];
    }

    long secondDiagonal = 0;
    for (int idx = 0; idx < arr_rows; idx++)
    {
        secondDiagonal += arr[arr_rows - idx - 1][idx];
    }

    return labs(firstDiagonal - secondDiagonal);
}
