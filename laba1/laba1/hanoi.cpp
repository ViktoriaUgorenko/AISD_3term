#include <iostream>
using namespace std;

void hanoyskayaBashnya(int n, int i, int k) {
    if (n == 1) {
        cout << "переместить диск 1 с " << i << " на " << k << " стержень" << endl;
    }
    else {
        int temp = 6 - i - k; 
        hanoyskayaBashnya(n - 1, i, temp);
        cout << "переместить диск " << n << " с " << i << " на " << k << " стержень" << endl;
        hanoyskayaBashnya(n - 1, temp, k);
    }
}

int main() {
    setlocale(LC_ALL, "");

    int n, i, k;

    cout << "кол-во дисков n: ";
    cin >> n;

    if (n < 1) {
        cout << "n должно быть >= 1" << endl;
        return 1;
    }

    cout << "номер начального стержня i (от 1 до 3): ";
    cin >> i;

    if (i < 1 , i > 3) {
        cout << "номер стержня должен быть от 1 до 3" << endl;
        return 1;
    }

    cout << "номер конечного стержня k (от 1 до 3): ";
    cin >> k;

    if (k < 1,  k > 3) {
        cout << "номер стержня должен быть от 1 до 3" << endl;
        return 1;
    }

    if (i == k) {
        cout << "начальный и конечный стержни не должны совпадать" << endl;
        return 1;
    }

    hanoyskayaBashnya(n, i, k);

    return 0;
}