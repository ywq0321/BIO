#include <iostream>
using namespace std;
int len, n1 = 0, n2 = 0;

int reverse(int n) {
    int rem, reverse = 0;
    while (n != 0) {
        rem = n % 10;
        reverse = reverse * 10 + rem;
        n /= 10;
    }
    return reverse;
}

int main() {
    string num;
    int i, j, mid, cnt = 0, flag = 0;
    string a;
    cin >> num;
    len = num.length();
    for (i = 0; i < len; i++) {
        if (num[i] != '9') {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        cout << 1;
        for (i = 0; i < len - 1; i++) {
            cout << 0;
        }
        cout << 1;
        return 0;
    }
    if (len == 1) {
        if (num[0] - 48 == 9) cout << 11;
        else cout << num[0] - 47;
        return 0;
    }
    if (len % 2 != 0) {
        mid = len / 2 + 1;
        for (i = 0; i < len / 2; i++) {
            n2 += (num[len - i - 1] - 48) * pow(10, i);
            n1 += (num[mid - i - 2] - 48) * pow(10, i);
        }
        if (num[mid - 1] - 48 == 9) {
            n1++;
            num[mid - 1] = '0'; //
        }
        if (reverse(n1) == n2) { // reverse n1 not n2 for cases like 1001
            if (n1 % 10 == 0) {
                int nT;
                nT = n1;
                while (1) {
                    if (n1 % 10 == 0) {
                        cnt += 1;
                        nT /= 10;
                    }
                    else {
                        break;
                    }
                }
                cout << n1 << num[mid - 1] - 47;
                for (i = 0; i < cnt - 1; i++) {
                    cout << '0';
                }
                cout << reverse(n1);
            }
            cout << n1 << num[mid - 1] - 47 << n2; return 0;
        }
        if (reverse(n1) > n2) {
            cout << n1;
            if (n1 % 10 == 0) {
                cout << "00" << reverse(n1); return 0;
            }
            cout << num[mid - 1] - 48 << reverse(n1);
            return 0;
        }
        if (reverse(n1) < n2) {
            cout << n1;
            if (n1 % 10 == 0) {
                cout << "00" << reverse(n1); return 0;
            }
            cout << num[mid - 1] - 47 << reverse(n1);
        }
    }
    else {
        mid = len / 2;
        for (i = 0; i < len / 2; i++) {
            n2 += (num[len - i - 1] - 48) * pow(10, i);
            n1 += (num[mid - i - 1] - 48) * pow(10, i);
        }
        if (reverse(n1) == n2) {
            n1 += 1;
            if (num[mid - 1] == 9) {
                int nT;
                nT = n1;
                while (1) {
                    if (n1 % 10 == 0) {
                        cnt += 1;
                        nT /= 10;
                    }
                    else {
                        break;
                    }
                }
                cout << n1;
                for (i = 0; i < cnt - 1; i++) {
                    cout << '0';
                }
                cout << reverse(n1);
                return 0;
            }
            cout << n1 << reverse(n1); return 0;
        }
        if (reverse(n1) > n2) {
            cout << n1;
            if (n1 % 10 == 0) {
                cout << '0' << reverse(n1);
            }
            cout << reverse(n1);
            return 0;
        }
        if (reverse(n1) < n2) {
            n1 += 1;
            cout << n1;
            if (n1 % 10 == 0) {
                cout << "0" << reverse(n1);
            }
            cout << reverse(n1);
            return 0;
        }
    }
    return 0;
}