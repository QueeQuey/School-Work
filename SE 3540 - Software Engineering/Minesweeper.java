package minesweeper;

import java.util.StringTokenizer;
import java.util.*;
import java.io.*;

public class Minesweeper {
    public class Plot {
        char symbol;
        boolean isVisible = false;
        int localValue = -1;

        public Plot(char symbol) {
            this.symbol = symbol;
        }

        public void makeVisible() {
            this.isVisible = true;
        }
    }

    Plot[][] mineField;
    int rows = 0;
    int columns = 0;
    int numberOfBombs;
    boolean valid;

    public Minesweeper() {
        //TODO: implement
        //new Minesweeper();
        //setMinefield(String s);
    }

    //THIS MAIN IS FOR TESTING. NEEDS TO BE REMOVED BEFORE THE FINAL PUSH

    public static void main(String[] args) {
        boolean test;
        String s = "**100\n" +
                ".....\n" +
                ".*...\n"; //+
                //"....";
        test = new Minesweeper().setMinefield(s);
        System.out.println(test);
    }






    /**
     * Initializes the minefield from given multiline string representation
     * A line represents a row of the field
     * All lines must have the same number of characters, which is the number of columns of the field
     * A character can be either '*' for a mine cell, or '.' for an empty cell
     * The number of rows must be smaller than or equal to the number of columns
     * Rows are indexed top-down with the top row index equal to zero.
     *
     * @param s the string
     * @return true if initialization succeeds, i.e., field is valid, or false otherwise.
     */


    public boolean setMinefield(String s) {

        String lineSeperator = System.lineSeparator();
        //I assume this needs to be changed, is it possible to seperate all of the lines THEN pass as tokens?
        StringTokenizer rowsAndColumns = new StringTokenizer(s, lineSeperator);
        String plotValues = s;

        // determines the number of rows and columns to then set the size of the array
        while (rowsAndColumns.hasMoreTokens()) {
            String line = rowsAndColumns.nextToken();
            System.out.println("Line: " + line);
            // tests for the number of columns once
            if (columns == 0) {
                for (int i = 0; i < line.length(); i++) {
                    columns++;
                }
            }
            rows++;
            //Testing of rows, columns and line
            System.out.println("Number of rows: " + rows);
            System.out.println("Number of columns: " + columns);
            System.out.println("Line length: " + line.length());
        }
        // set the field with the identified no. rows and columns
        mineField = new Plot[rows][columns];
        // check it is a valid plot
        if (rows > 0 || columns > 0 && columns >= rows) {
            // assign all spots in the minefield with a plot object
            // split string into its individual components
            char[] plotValuesChar = plotValues.toCharArray();
            int index = 0;
            int rowCounter = 0;
            int columnCounter = 0;

            // iterate through all characters in the array and add them to their assigned plot
            for (int i = 0; i < plotValues.length(); i++) {
                System.out.println("Current char:" + plotValuesChar[index]);
                if (plotValuesChar[index] == '\n') {
                    // move to start of next row
                    rowCounter++;
                    columnCounter = 0;
                } else {
                    System.out.println("Current i: " + i + " length goal: " + (plotValues.length() - (rows * 1) + 1));
                    System.out.println("Current index: " + index);
                    System.out.println("Current plot: " + rowCounter + "," + columnCounter);
                    char current = plotValuesChar[index];
                    // add value to the next empty plot in minefield
                    mineField[rowCounter][columnCounter] = new Plot(current);
                    // increment to get to the next empty plot
                    // resetting row and column counter when necessary
                    columnCounter++;
                }
                // calculates the number of bombs in the minefield as they are assgined their plots
                if (plotValuesChar[index] == '*') {
                    this.numberOfBombs++;
                }
                index++;
            }
            rowCounter = 0;
            columnCounter = 0;
            valid = true;
            //System.out.println("Number of bombs: " + this.numberOfBombs);

            //  Printing the 2D array
            System.out.println("The minefield: ");
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    if (mineField[i][j] == null) {
                        valid = false;
                        return valid;
                    }
                    else{
                        System.out.print(mineField[i][j].symbol);
                    }
                }
                System.out.println();
            }
            System.out.println();
        } else {
            valid = false;
        }
        return valid;
    }

    /**
     * @return the number of bombs in the field, or -1 if the field is invalid
     */
    public int getNumberOfBombs() {
        if (this.valid == true) {
            return this.numberOfBombs;
        } else {
            return -1;
        }
    }

    /**
     * Returns the hint at coordinate (row, column)
     *
     * @param row
     * @param col
     * @return the hint (>=0) if successful and cell has no bomb, -1 otherwise
     */
    public int getHintAt(int row, int col) {
        //int hintNumber = mineField[row][col].localValue;
        if (mineField[row][col].symbol == '*') {
            return -1;
        }
        //TEMPORARY CODE - We may have to create a localValue for each cell for the 0-6 while the symbol is a ","
        // IF we do, the following code can be deleted and the above comment can become the return value.
        else if (mineField[row][col].symbol == '1') {
            return 1;
        } else if (mineField[row][col].symbol == '2') {
            return 2;
        } else if (mineField[row][col].symbol == '3') {
            return 3;
        } else if (mineField[row][col].symbol == '4') {
            return 4;
        } else if (mineField[row][col].symbol == '5') {
            return 5;
        } else if (mineField[row][col].symbol == '6') {
            return 6;
        } else {
            return 0;
        }
    }

    /**
     * Checks the visibility of a cell.
     *
     * @param row
     * @param col
     * @return true if the cell (row,column) is visible, false otherwise
     */
    public boolean isVisible(int row, int col) {
        if (mineField[row][col].isVisible == true) {
            return true;
        } else
            return false;
    }


    /**
     * Simulates a user click on a cell. If this is a bomb cell, all the bomb cells in the entire field become visible.
     * Otherwise only this cell becomes visible.
     *
     * @param row
     * @param col
     * @return true if the cell has no bomb, false if it's a bomb cell
     */
    public boolean clickOn(int row, int col) {
        //Int input of the location check - IF IT RETURNS FALSE GAME IS OVER
        if (mineField[row][col].symbol == '*') {
            //Setting entire field to visible and returning False
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    mineField[i][j].isVisible = true;
                }
            }
            return false;
        } else {
            return true;
        }
    }

    /**
     * @return the number of rows of the field
     */
    //Returns the amount of rows in the field
    public int getHeight() {
        return this.rows;
    }

    /**
     * @return the number of columns of the field
     */
    //Returns the amount of columns in the field
    public int getWidth() {
        return this.columns;
    }
}
