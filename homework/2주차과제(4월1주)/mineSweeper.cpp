#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
using namespace std;

int** create_map(int& row, int& col, int& mine); // map을 만들어주는 함수
char** check_map(int& row, int& col, int& mine); // map의 해당 index를 open했는지 check해주는 함수
void show_map(int** map, char** check, int& row, int& col); // map을 출력해주는 함수
void play_game(int** map, char** check, int& row, int& col, int& mine); // 전체적인 게임 진행을 해주는 함수
int win_check(int** map, char** check, int& row, int& col);
void delete_map(int** map, char** check, int row, int col); // 동적할당한 map과 check를 delete

int main() {
    srand((unsigned)time(NULL));
    int ROW, COL, mine;
    cout << "INSERT YOUR MAP SIZE (EX: 10 10): ";
    cin >> ROW >> COL;
    cout << "INSERT YOUR MINE : ";
    cin >> mine;

    int** map = create_map(ROW, COL, mine);  
    char** check = check_map(ROW, COL, mine);  

    play_game(map, check, ROW, COL, mine);
    
    int is_win = win_check(map, check, ROW, COL);
    if (is_win == mine) {
        cout << "WIN!" << endl;
        delete_map(map, check, ROW, COL);
    } else {
        system("clear");
        show_map(map, check, ROW, COL);
        cout << "LOSE..." << endl;
        delete_map(map, check, ROW, COL);
    }
    return 0;
}

int** create_map(int& row, int& col, int& mine) {
    int** map = new int*[row];
    for (int i=0; i<row; i++) {
        map[i] = new int[col];
    }

    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            map[i][j] = 0;
        }
    }

    for (int i = 0; i < mine; i++) {
		int x = rand() % row;
		int y = rand() % col;
		if (map[x][y] != 0) {
			i--;
			continue;
		}
		map[x][y] = -1;
	}

    return map;
}

char** check_map(int& row, int& col, int& mine) {
    char** check = new char*[row];
    for (int i=0; i<row; i++)
        check[i] = new char[col];
    
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            check[i][j] = 'x';
    
    return check;
}

void show_map(int** map, char** check, int& row, int& col) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (map[i][j] == -99) cout << "💣";
            else if (check[i][j] == 'x') cout << "⚪️";
            else if (check[i][j] == 'o') {
                if (map[i][j] == 0) cout << "🟢";
                else if (map[i][j] == -1) cout << "💣";
            }
        }
        cout << endl;
    }
}

void play_game(int** map, char** check, int& row, int& col, int& mine) {
    while (1) {
        if (win_check(map, check, row, col) == mine) break;

        system("clear");
        show_map(map, check, row, col);
        cout << "PLEASE ENTER THE ROW, COL (EX: 3, 5) => ";
        int x, y;
        cin >> x >> y;

        if ((x > row || x <= 0 || y > col || y <= 0) || check[x-1][y-1] == 'o') {
            cout << "MISTYPE. RETRY" << endl;
            sleep(2);
            continue;
        } else {
            check[x-1][y-1] = 'o';
            if (map[x-1][y-1] == -1) {
                system("clear");
                show_map(map, check, row, col);
                cout << "YOU STEPPED ON A MINE" << endl;
                sleep(1);
                
                for (int i=0; i<row; i++)
                    for (int j=0; j<col; j++)
                        if (map[i][j] == -1) map[i][j] = -99;

                break;
            }
        }
    }
}

int win_check(int** map, char** check, int& row, int& col) {
    int count = 0;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            if (check[i][j] == 'o' && map[i][j] == 0) {
                count++;
            }
        }
    }

    int total = (row*col) - count;
    return total;
}

void delete_map(int** map, char** check, int row, int col) {
    for (int i=0; i<row; i++)
        delete[] map[i];
    delete[] map;

     for (int i=0; i<row; i++)
        delete[] check[i];
    delete[] check;
}