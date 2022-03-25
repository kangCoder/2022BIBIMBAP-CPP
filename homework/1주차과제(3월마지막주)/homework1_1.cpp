#include <iostream>
using namespace std;

int main() {
    cout << "구매 금액을 입력하세요[0-500] : ";
    int price;
    cin >> price;

    int change = 500 - price;
    cout << change << "원의 거스름돈은 다음과 같다." << endl;
    int hundred = change / 100;
    int fifty = (change % 100) / 50;
    int ten = ((change % 100) % 50) / 10;
    int one = (((change % 100) % 50) % 10);

    cout << "100원짜리 동전 : " << hundred << "개" << endl;
    cout << "50원짜리 동전 : " << fifty << "개" << endl;
    cout << "10원짜리 동전 : " << ten << "개" << endl;
    cout << "1원짜리 동전 : " << one << "개" << endl;
    return 0;
}