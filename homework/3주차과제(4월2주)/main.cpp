#include "Calculator.h"

int main() {
    Add a(1, 3);
    Sub s(1, 3);
    Mul m(1, 3);
    Div d(1, 3);

    while (1) {
        cout << "두 정수와 연산자를 입력하세요>> ";
        int x, y;
        char c;
        cin >> x >> y >> c;

        switch (c) {
            case '+':
                a.setValue(x, y);
                cout << a.calculate() << endl;
                break;
            case '-':
                s.setValue(x, y);
                cout << s.calculate() << endl;
                break;
            case '*':
                m.setValue(x, y);
                cout << m.calculate() << endl;
                break;
            case '/':
                d.setValue(x, y);
                cout << d.calculate() << endl;
                break;
        }
    }
    return 0;
}
