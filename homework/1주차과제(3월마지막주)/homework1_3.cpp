#include <iostream>
using namespace std;

int main() {
    int T, O, G, D;
    for (T = 0; T < 10; T++) {
        for (O = 0; O < 10; O++) {
            for (G = 0; G < 10; G++) {
                for (D = 0; D < 10; D++) {
                    if (!(T == 0 || G == 0) && !(T == O || T == G || T == D || O == G || O == D || G == D) && 1000*G - 400*T + 66*O + D == 0) {
                        cout << "T = " << T << ", O = " << O <<  ", G = " << G <<  ", D = " << D << endl;
                    }
                }
            }
        }
    }
    return 0;
}