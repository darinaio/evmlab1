#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <intrin.h>
#define N 1690000000

double exp_maclaurin(double x) {
    double sum = 0.0;
    double term = 1;
    for (double n = 0; n < N; n++) {
        sum += term;
        term = term * x / (n + 1.0);
    }
    return sum;
}

int main() {
    double x;
    scanf("%lf", &x);

    long double time = (long double)__rdtsc();
    double result = exp_maclaurin(x);
    long double frequency = 2300000000.0;
    time = (long double)__rdtsc() - time;
    printf("%.10lf", time / frequency);
    return 0;
}
