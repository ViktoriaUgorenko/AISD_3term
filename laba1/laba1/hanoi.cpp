#include <iostream>
using namespace std;

void hanoyskayaBashnya(int n, int i, int k) {
    if (n == 1) {
        cout << "����������� ���� 1 � " << i << " �� " << k << " ��������" << endl;
    }
    else {
        int temp = 6 - i - k; 
        hanoyskayaBashnya(n - 1, i, temp);
        cout << "����������� ���� " << n << " � " << i << " �� " << k << " ��������" << endl;
        hanoyskayaBashnya(n - 1, temp, k);
    }
}

int main() {
    setlocale(LC_ALL, "");

    int n, i, k;

    cout << "���-�� ������ n: ";
    cin >> n;

    if (n < 1) {
        cout << "n ������ ���� >= 1" << endl;
        return 1;
    }

    cout << "����� ���������� ������� i (�� 1 �� 3): ";
    cin >> i;

    if (i < 1 , i > 3) {
        cout << "����� ������� ������ ���� �� 1 �� 3" << endl;
        return 1;
    }

    cout << "����� ��������� ������� k (�� 1 �� 3): ";
    cin >> k;

    if (k < 1,  k > 3) {
        cout << "����� ������� ������ ���� �� 1 �� 3" << endl;
        return 1;
    }

    if (i == k) {
        cout << "��������� � �������� ������� �� ������ ���������" << endl;
        return 1;
    }

    hanoyskayaBashnya(n, i, k);

    return 0;
}