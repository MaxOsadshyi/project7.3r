#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Функція для створення рядка з випадковими числами
void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

// Функція для створення всіх рядків в матриці
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, Low, High, rowNo + 1);
}

// Функція для виведення рядка
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

// Функція для виведення всіх рядків
void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, rowNo + 1);
    else
        cout << endl;
}

// Функція для підрахунку суми елементів у рядах без від'ємних значень
int SumRowsWithoutNegatives(int** a, const int rowCount, const int colCount, int currentRow = 0, int sum = 0) {
    // Базовий випадок: коли перевіряємо всі рядки, повертаємо суму
    if (currentRow == rowCount) {
        return sum;
    }

    // Перевіряємо, чи є в поточному рядку від'ємні елементи
    bool hasNegative = false;
    for (int j = 0; j < colCount; j++) {
        if (a[currentRow][j] < 0) {
            hasNegative = true;
            break;
        }
    }

    // Якщо в рядку немає від'ємних елементів, додаємо суму рядка до загальної суми
    if (!hasNegative) {
        for (int j = 0; j < colCount; j++) {
            sum += a[currentRow][j];
        }
    }

    // Рекурсивно переходимо до наступного рядка
    return SumRowsWithoutNegatives(a, rowCount, colCount, currentRow + 1, sum);
}

int CalculateMinDiagonalSum(int** a, const int rowCount, const int colCount, int i, int j, int minSum) {
    // Базовий випадок: коли дійшли до кінця матриці, повертаємо мінімальну суму
    if (i == rowCount) {
        return minSum;
    }

    int sum = 0;
    for (int k = 0; k < colCount && i + k < rowCount; k++) {
        sum += a[i + k][k];
    }

    // Порівнюємо поточну суму з мінімальною сумою
    if (sum < minSum) {
        minSum = sum;
    }

    // Рекурсивно переходимо до наступного рядка
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
