#include <stdio.h>

int step = 0;

int fib(int n) {
    step++;
    if(n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Fib(%d) = %d\n", n, fib(n));
    printf("Step Count = %d\n", step);
    return 0;
}
