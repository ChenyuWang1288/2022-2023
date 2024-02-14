#include <iostream>
#include <cmath>

using namespace std;

int power_mod(int a, int b, int p) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

// DH算法函数
void dh_algorithm(int p, int g, int a, int b, int &A, int &B, int &K) {
    A = power_mod(g, a, p);
    B = power_mod(g, b, p);
    K = power_mod(B, a, p);
}

int main() {
    int p;
    int g; 
    int a; 
    int b; 
    int A, B, K; 
    cin >> p;
    cin >> g;
    cin >> a;
    cin >> b;
    dh_algorithm(p, g, a, b, A, B, K);

    cout << A << endl;
    cout << B << endl;
    cout << K << endl;
    system("pause");
    return 0;
}
