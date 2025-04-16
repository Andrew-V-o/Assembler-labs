#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    cout << fixed << setprecision(15);

    // A
    double sum_a = 0.0, pi_a;
    int n_a = 100000;
    for (int k = 1; k <= n_a; ++k)
    {
        double term;
        __asm {
         fild k
         fmul st, st
        fld1
        fdiv
          fstp term
        }
        if (k % 2 == 1)
            sum_a += term;
        else sum_a -= term;
    }

    __asm {
        fld sum_a
        fld1
        mov eax, 12
        push eax
        fild dword ptr [esp]
        add esp, 4
        fmul
        fsqrt
        fstp pi_a
    }

    cout << "Pi (a): " << pi_a << endl;

    // B
    double sum_b = 0.0, pi_b;
    int n_b = 100000;
    for (int k = 1; k <= n_b; ++k)
    {
        int denom = 2 * k - 1;
        double term;
        __asm {
            fild denom
            fmul st, st
            fld1
            fdiv
            fstp term
        }
        sum_b += term;
    }
    __asm {
            fld sum_b
            fld1
            mov eax, 8
            push eax
            fild dword ptr [esp]
            add esp, 4
            fmul st, st(1)
            fsqrt
            fstp pi_b
    }

    cout << "Pi (b): " << pi_b << endl;

    return 0;
}