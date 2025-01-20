// Author: Dorian Knight
// Date: January 20th 2025
// Description: First Completely Painted Row or Column
// Rank: Medium
// Topics: Array || Hash Table || Matrix

public class coordinate {
    public int rowNum { get; set; }
    public int colNum { get; set; }
    public coordinate(int rowNumArg, int colNumArg) {
        rowNum = rowNumArg;
        colNum = colNumArg;
    }
}

public class Solution {
    public int FirstCompleteIndex(int[] arr, int[][] mat) {
        // Iterate through matrix and add all values and their associated coordinate to a hashmap
        Dictionary<int, coordinate> matVals = new Dictionary<int, coordinate>();
        int value;
        for (int i=0; i<mat.Length; i++) {
            for (int j=0; j<mat[0].Length; j++) {
                value = mat[i][j];
                coordinate valuePos = new coordinate(rowNumArg: i, colNumArg: j);
                matVals.Add(value, valuePos);
            }
        }

        // Iterate through arr, "paint" values and store values in lists that correspond to the row/column
        // Each list will be stored in a hashmap for easy access

        List<int>[] paintedRow = new List<int>[mat.Length];
        List<int>[] paintedCol = new List<int>[mat[0].Length];

        int valOfInterest;
        coordinate coordOfInterest;
        for (int k=0; k<arr.Length; k++) {
            valOfInterest = arr[k];

            // Find value of interest in the matrix hashmap
            coordOfInterest = matVals[valOfInterest];

            // Add value to painted row
            if (paintedRow[coordOfInterest.rowNum] == null) {
                // index contains null reference | initialize list
                paintedRow[coordOfInterest.rowNum] = new List<int>();
            }
            paintedRow[coordOfInterest.rowNum].Add(valOfInterest);

            if (paintedRow[coordOfInterest.rowNum].Count == mat[0].Length) {
                // Row is completely painted, return index of array for which this happens
                // Each painted row's maximum length is equal to the column size
                return k;
            }

            if (paintedCol[coordOfInterest.colNum] == null) {
                // Index contains null reference | Initialize list
                paintedCol[coordOfInterest.colNum] = new List<int>();
            }
            paintedCol[coordOfInterest.colNum].Add(valOfInterest);
            if (paintedCol[coordOfInterest.colNum].Count == mat.Length) {
                // Column is completely painted, return index of array for which this happens
                // Each painted column's maximum length is equal to the row size
                return k;
            }
        }
        return 0; // Dummy return
    }
}
