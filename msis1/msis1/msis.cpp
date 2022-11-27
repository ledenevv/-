#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int M = 8, N = 8, k, q;
    int** matrix = new int* [M]; // создание динмаческой матрицы
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < M; i++) { // заполнение матрицы
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 201 + (-100);
        }
    }

    for (int i = 0; i < M; i++) { // Вывод матрицы
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
    int min = 100;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                k = i;
                q = j;
            }
        }
    }
    cout << "минимальное значение матрицы - " << min << " в строке: "<<k+1<<" столбце: "<<q+1<< endl;
    if (min < 0) {
        for (int i = 0; i < M; i++) {
            int buf;
            buf = matrix[i][i];
            matrix[i][i] = matrix[i][7 - i];
            matrix[i][7 - i] = buf;
        }
        cout << "тк минимальное значение в матрице отрицательное, то главная и побочная диагональ меняются местами."<< endl << "Матрица с измененными местами главной и побочной диагонали" << endl;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << matrix[i][j] << '\t';
            }
            cout << endl;
        }
        
    }
}