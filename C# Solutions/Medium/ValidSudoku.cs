// Author: Dorian Knight
// Date: January 16th 2025
// Description: Valid Sudoku C# solution
// Rank: Medium
// Topics: Array || Hash Table || Matrix

public class Solution {
    public bool IsValidSudoku(char[][] board) {
        // Check if individual row has duplicate
        bool rowValid;
        bool columnValid;
        bool squareValid;
        for (int i=0; i<board.Length; i++) {
            rowValid = checkRow(board[i]);

            if (!rowValid) {
                return false;
            }
        }

        for (int j=0; j<board[0].Length; j++) {
            columnValid = checkColumn(board, j);

            if (!columnValid) {
                return false;
            }
        }

        for (int k=0; k<3; k++) {
            for (int l=0; l<3; l++) {
                // Squares are always 3 by 3
                squareValid = checkSquares(board, k, l);

                if (!squareValid) {
                    return false;
                }
            }
        }

        // Rows, columns and squares are all valid
        return true;
    }

    private bool checkRow(char[] row) {
        Dictionary<char, int> rowHist = new Dictionary<char, int>();
        char val;
        for (int l=0; l<row.Length; l++) {
            val = row[l];
            if (val != '.' && rowHist.ContainsKey(val)) {
                // Number has already been used in this row
                return false;
            }

            else if (val != '.') {
                rowHist.Add(val, 1); // 1 is a dummy value and never used
            }
        }

        return true;
    }

    private bool checkColumn(char[][] board, int column) {
        Dictionary<char, int> colHist = new Dictionary<char, int>();
        char val;
        for (int m=0; m<board[0].Length; m++) {
            val = board[m][column];
            if (val != '.' && colHist.ContainsKey(val)) {
                // Number has already been seen in this column
                return false;
            }

            else if (val != '.') {
                // Add number to hash table of seen numbers
                colHist.Add(val, 1); // 1 is a dummy value and never used
            }
        }

        return true;
    }

    private bool checkSquares(char[][] board, int squareX, int squareY) {
        // Iterate over every value in the square and check if there are duplicates
        Dictionary<char, int> squareHist = new Dictionary<char, int>();
        char val;
        int offsetX;
        int offsetY;
        for (int n=0; n<3; n++) {
            for (int o=0; o<3; o++) {
                offsetX = squareX*3;
                offsetY = squareY*3;

                val = board[n+offsetX][o+offsetY];

                if (val != '.' && squareHist.ContainsKey(val)) {
                    // Value has been seen before, square is not valid
                    return false;
                }

                else if (val != '.') {
                    // Add value to history
                    squareHist.Add(val, 1); // 1 is a dummy value never used
                }
            }
        }

        return true;
    }
}
