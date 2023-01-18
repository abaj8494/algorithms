#include <stdio.h>
#include <math.h>

int karatsuba(unsigned int a, unsigned int b, unsigned int s) {
    if (a == b && a == 1) return a * b;
    else
    {

    unsigned int a0, a1, b0, b1, u, v, w, x, y;

    a1 = a >> s;
    a0 = (a << s) >> s;
    b1 = b >> s;
    b0 = (b << s) >> s;

    u = a1 + a0;
    v = b1 + b0;

    w = karatsuba(a1, b1, s/2);
    x = karatsuba(u, v, s/2);
    y = karatsuba(a0, b0, s/2);

    return w * pow(2, s) + (x - w - y) * pow(2, s / 2) + x;

    }
    
}
