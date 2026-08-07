#include <stdio.h>

int board[20], n;

int place(int row, int column)
{
    int i;

    for(i = 1; i < row; i++)
    {
        if(board[i] == column ||
           (board[i] - i) == (column - row) ||
           (board[i] + i) == (column + row))
            return 0;
    }

    return 1;
}

void queen(int row)
{
    int column, i;

    for(column = 1; column <= n; column++)
    {
        if(place(row, column))
        {
            board[row] = column;

            if(row == n)
            {
                printf("\nSolution:\n");

                for(i = 1; i <= n; i++)
                    printf("Queen %d -> Column %d\n", i, board[i]);
            }
            else
            {
                queen(row + 1);
            }
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);

    queen(1);

    return 0;
}