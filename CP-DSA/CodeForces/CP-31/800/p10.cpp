// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;               // number of test cases

    while (t--)
    {
        char arr[10][10];   // 10x10 grid, each cell contains '.' or 'X'

        // take input for the grid
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cin >> arr[i][j];
            }
        }

        int points = 0;     // total score for this test case

        // traverse each cell of the grid
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                // only score if the cell contains 'X'
                if (arr[i][j] == 'X')
                {
                    // outermost border (row 0/9 or column 0/9)
                    if (i == 0 || i == 9 || j == 0 || j == 9)
                        points += 1;

                    // second layer from the border
                    else if (i == 1 || i == 8 || j == 1 || j == 8)
                        points += 2;

                    // third layer
                    else if (i == 2 || i == 7 || j == 2 || j == 7)
                        points += 3;

                    // fourth layer
                    else if (i == 3 || i == 6 || j == 3 || j == 6)
                        points += 4;

                    // center layer (i and j are between 4 and 5)
                    else
                        points += 5;
                }
            }
        }

        // output the final score
        cout << points << endl;
    }

    return 0;
}
