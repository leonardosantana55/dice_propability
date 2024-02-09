
//animates the matrix printing it with a new value on each cell#include <stdio.h>
#include <unistd.h>

//init the matrix with zeros
void init_matrix(int rows, int columns, int matrix[rows][columns])
{    
    for (int i = 0; i<columns; i++){
        for (int j = 0; j<rows; j++){
            matrix[i][j] = 0;
        }
    }
}

//print a matrix
void print_matrix(int rows, int columns, int matrix[rows][columns])
{
    for (int i = 0; i<columns; i++){
            for (int j = 0; j<rows; j++){
                printf("%i ", matrix[i][j]);
            }
            printf("\n");
        }

}

//animates the matrix printing it with a new value on each cell
void matrix_changer(int rows, int columns, int matrix[rows][columns])
{
    int flicker = 1;
    int row_index = 0;
    int column_index = 0;

    while(1)
    {
        system("cls");
        matrix[row_index][column_index] = 0;
        
        //changes row and column indexes to point to the next value on the matrix
        if (column_index != columns)
        {
            if (row_index < rows-1)
            {
                row_index++;
            }
            else
            {
                row_index= 0;
                column_index++;
            }
        }
        else
        {
            row_index = 0;
            column_index = 0;  
        }

        matrix[row_index][column_index] = flicker;
        print_matrix(rows, columns, matrix);
        usleep(500000);
    }
}

int main(void) 
{
int rows = 9;
int columns = 9;
int matrix[rows][columns];
init_matrix(rows, columns, matrix);
matrix_changer(rows, columns, matrix);
return 0;

}