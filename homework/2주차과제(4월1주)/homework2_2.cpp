#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int** arr = new int*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[M];
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    cout << endl;

    int avg = sum / (N*M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
           if (arr[i][j] < avg) arr[i][j] = 0;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
           cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < N; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}
