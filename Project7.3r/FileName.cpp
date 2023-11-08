#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// ������� ��� ��������� ����� � ����������� �������
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

// ������� ��� ��������� ��� ����� � �������
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, Low, High, rowNo + 1);
}

// ������� ��� ��������� �����
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

// ������� ��� ��������� ��� �����
void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, rowNo + 1);
    else
        cout << endl;
}

// ������� ��� ��������� ���� �������� � ����� ��� ��'����� �������
int SumRowsWithoutNegatives(int** a, const int rowCount, const int colCount, int currentRow = 0, int sum = 0) {
    // ������� �������: ���� ���������� �� �����, ��������� ����
    if (currentRow == rowCount) {
        return sum;
    }

    // ����������, �� � � ��������� ����� ��'��� ��������
    bool hasNegative = false;
    for (int j = 0; j < colCount; j++) {
        if (a[currentRow][j] < 0) {
            hasNegative = true;
            break;
        }
    }

    // ���� � ����� ���� ��'����� ��������, ������ ���� ����� �� �������� ����
    if (!hasNegative) {
        for (int j = 0; j < colCount; j++) {
            sum += a[currentRow][j];
        }
    }

    // ���������� ���������� �� ���������� �����
    return SumRowsWithoutNegatives(a, rowCount, colCount, currentRow + 1, sum);
}

int CalculateMinDiagonalSum(int** a, const int rowCount, const int colCount, int i, int j, int minSum) {
    // ������� �������: ���� ����� �� ���� �������, ��������� �������� ����
    if (i == rowCount) {
        return minSum;
    }

    int sum = 0;
    for (int k = 0; k < colCount && i + k < rowCount; k++) {
        sum += a[i + k][k];
    }

    // ��������� ������� ���� � ��������� �����
    if (sum < minSum) {
        minSum = sum;
    }

    // ���������� ���������� �� ���������� �����
    return CalculateMinDiagonalSum(a, rowCount, colCount, i + 1, j, minSum);
}


int main()
{
    srand((unsigned)time(NULL));
    int N;
    cout << "N = "; cin >> N;
    cout << endl;
    int** a = new int* [N];
    for (int i = 0; i < N; i++)
        a[i] = new int[N];
    int Low = -9, High = 9;
    CreateRows(a, N, Low, High, 0);
    PrintRows(a, N, 0);

    int result = SumRowsWithoutNegatives(a, N, N);
    cout << "Sum of rows without negatives: " << result << endl;

    int minDiagonalSums = CalculateMinDiagonalSum(a, N, N,0,0,0);
    cout << "Minimum sum of parallel diagonal elements: " << CalculateMinDiagonalSum << endl;

    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
