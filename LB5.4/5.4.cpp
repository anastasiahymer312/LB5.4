#include <iostream>
#include <cmath>

using namespace std;

double S0(int N) {
    double S = 0;
    for (int i = 1; i <= N; i++) {
        S += (1. + (i * 1.0 / N)) / (i * i);
    }
    return S;
}


double S1(int N, int i) {
    if (i == 0)
        return 0;
    else
        return (1. + (i * 1.0 / N)) / (i * i) + S1(N, i - 1);
}


double S2(int N, int i) {
    if (i > N)
        return 0;
    else
        return (1. + (i * 1.0 / N)) / (i * i) + S2(N, i + 1);
}

double S3(int N, int i, double S) {
    S += (1. + (i * 1.0 / N)) / (i * i);
    if (i == 1)
        return S;
    else
        return S3(N, i - 1, S);
}


double S4(int N, int i, double S) {
    S += (1. + (i * 1.0 / N)) / (i * i);
    if (i == N)
        return S;
    else
        return S4(N, i + 1, S);
}

int main() {
    int N;
    cout << "N = ";
    cin >> N;


    cout << "(iter) S0 = " << S0(N) << endl;
    cout << "(rec down --) S1 = " << S1(N, N) << endl;
    cout << "(rec down ++) S2 = " << S2(N, 1) << endl;
    cout << "(rec up --) S3 = " << S3(N, N, 0) << endl;
    cout << "(rec up ++) S4 = " << S4(N, 1, 0) << endl;

    return 0;
}
