#include <iostream>
using namespace std;
int main()
{

    int16_t A1 = -1;
    int16_t A2 = -6;
    int16_t A3 = 13;

    int16_t B1 = 1;
    int16_t B2 = -15;
    int16_t B3 = 6;

    int16_t C1 = 0;
    int16_t C2 = 0;
    int16_t C3 = 0;

    __asm {
   
        mov ax, A1
        add ax, B1
        mov C1, ax


        mov ax, A2
        adc ax, B2
        mov C2, ax


        mov ax, A3
        adc ax, B3
        mov C3, ax

    }

    cout << "Result C (in hexadecimal):" << endl;

    cout << "C3 (high word): 0x" << hex << C3 << endl;
    cout << "C2 (middle word) : 0x" << hex << C2 << endl;
    cout << "C1 (low word) : 0x" << hex << C1 << endl;

    int64_t full_result = ((int64_t)C3 << 32) |
                          ((int64_t)C2 << 16) |
                          ((int64_t)C1);

    cout << "Result C (in decimal):" << endl;

    cout << dec << full_result << endl;

    return 0;
}



