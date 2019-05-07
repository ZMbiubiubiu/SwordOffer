#include <iostream>

using namespace std;

bool find(int* matrix, int rows, int columns, int target) {
    bool flag = false;
    if (matrix == NULL or rows < 0 or columns < 0) return flag;
    int row = 0;
    int column = columns - 1;
    while (column >= 0 && row < rows) {
        if (matrix[row*columns + column] == target) {
            flag = true;
            break;
        } else if (matrix[row*columns + column] < target) {
            ++row;
        } else {
            --column;
        }
    }
    return flag;
}

int main()
{
    int matrix[16] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};
    cout << "result:" << find(matrix, 4, 4, 1) << endl;
    return 0;
}