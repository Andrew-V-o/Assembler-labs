#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x1;
    cout << "Enter an integer value for x for Task 1: ";
    cin >> x1;

    int result_asm1;
    double result_cpp1;

    __asm {
        mov eax, dword ptr [x1]
        shl eax, 1
        sub eax, 1
        mov ebx, dword ptr [x1]
        shl ebx, 1
        add ebx, 1
        imul ebx
        mov ecx, dword ptr [x1]
        add ecx, 3
        imul ecx
        mov esi, dword ptr [x1]
        shl esi, 1
        mov ebx, esi
        cdq
        idiv ebx
        mov dword ptr [result_asm1], eax
    }

    result_cpp1 = floor((2.0 * x1 - 1) * (2.0 * x1 + 1) * (x1 + 3) / (2.0 * x1));

    cout << "Result (assembly): " << result_asm1 << endl;
    cout << "Result (C++): " << static_cast<int>(result_cpp1) << endl;

    cout << endl;

    unsigned int n2;
    cout << "Enter a natural number for Task 2: ";
    cin >> n2;

    unsigned int count_asm2 = 0;

    __asm {
        mov eax, dword ptr [n2]
        mov ecx, 0
    count_loop:
        test eax, eax
        jz end_count
        shr eax, 1
        adc ecx, 0
        jmp count_loop
    end_count:
        mov dword ptr [count_asm2], ecx
    }

    cout << "Number of set bits (assembly): " << count_asm2 << endl;

    return 0;
}