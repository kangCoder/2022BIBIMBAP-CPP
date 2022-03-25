#include <iostream>
using namespace std;

int main() {
    cout << "* 돈을 넣어 주세요 : ";
    int price;
    cin >> price;

    cout << "=============================" << endl;
    
    int choco = 0;
    int coupon = 0;
    for (int i = 1; i <= price; i++) {
        choco++;
        coupon++;
        if (coupon >= 7) {
            coupon = 0;
            choco++;
        }
    }

    cout << "* 초콜릿 " << choco << "개, 쿠폰 " << coupon << "개" << endl;
    return 0;
}