#include <iostream>
using namespace std;
#define N 9
// #define EASY 1
// #define MEDIUM 2
// #define DIFFCULT 3

void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row,
            int col, int num)
{

    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
    int startRow = row - row % 3,
        startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j +
                                   startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[N][N], int row, int col)
{
    if (row == N - 1 && col == N)
        return true;

    if (col == N)
    {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }

    return false;
}

int main()
{

    int grid_easy[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 2},
                           {0, 0, 9, 0, 0, 7, 8, 0, 0},
                           {0, 0, 0, 0, 0, 3, 0, 4, 0},
                           {0, 0, 0, 0, 0, 0, 0, 5, 0},
                           {2, 0, 8, 0, 4, 0, 0, 9, 0},
                           {7, 0, 3, 1, 0, 0, 2, 0, 0},
                           {1, 0, 0, 0, 0, 9, 7, 0, 3},
                           {0, 7, 0, 5, 6, 0, 0, 0, 0},
                           {0, 6, 0, 3, 0, 0, 0, 0, 5}};

    int grid_medium[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 2},
                             {0, 0, 9, 0, 0, 7, 8, 0, 0},
                             {0, 0, 0, 0, 0, 3, 0, 4, 0},
                             {0, 0, 0, 0, 0, 0, 0, 5, 0},
                             {2, 0, 8, 0, 4, 0, 0, 9, 0},
                             {7, 0, 3, 1, 0, 0, 2, 0, 0},
                             {1, 0, 0, 0, 0, 9, 7, 0, 3},
                             {0, 7, 0, 5, 6, 0, 0, 0, 0},
                             {0, 6, 0, 3, 0, 0, 0, 0, 5}};

    int grid_difficult[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 2},
                                {0, 0, 9, 0, 0, 7, 8, 0, 0},
                                {0, 0, 0, 0, 0, 3, 0, 4, 0},
                                {0, 0, 0, 0, 0, 0, 0, 5, 0},
                                {2, 0, 8, 0, 4, 0, 0, 9, 0},
                                {7, 0, 3, 1, 0, 0, 2, 0, 0},
                                {1, 0, 0, 0, 0, 9, 7, 0, 3},
                                {0, 7, 0, 5, 6, 0, 0, 0, 0},
                                {0, 6, 0, 3, 0, 0, 0, 0, 5}};

    int choice;
    while (true)
    {
        cout << "\nEasy->1:\n";
        cout << "Medium->2\n";
        cout << "Difficult->3\n";
        cout << "Choose level : \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            if (solveSudoku(grid_easy, 0, 0))
                print(grid_easy);
            else
            {
                cout << "no solution exists " << endl;
            }
        }
        break;

        case 2:
        {
            if (solveSudoku(grid_medium, 0, 0))
                print(grid_medium);
            else
                cout << "no solution exists " << endl;
        }
        break;

        case 3:
        {

            if (solveSudoku(grid_difficult, 0, 0))
                print(grid_difficult);
            else
                cout << "no solution exists " << endl;
        }
        break;
        }
    }
}
