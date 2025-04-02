/*#include <iostream>
#include <iomanip>
using namespace std;

__int16 A1 = 0x1234, A2 = 0x5678, A3 = 0x9ABC, B1 = 0x4321, B2 = 0x8765, B3 = 0xCDEF, C1, C2, C3;

int main() {
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

    cout << "HEX: "
         << hex << uppercase
         << setw(4) << setfill('0') << (unsigned)C3 << " "
         << setw(4) << setfill('0') << (unsigned)C2 << " "
         << setw(4) << setfill('0') << (unsigned)C1 << "\n";

    unsigned long long result = ((unsigned long long)C3 << 32)
                                | ((unsigned long long)C2 << 16)
                                | C1;
    cout << "DEC: " << dec << result << "\n";
    return 0;
}
*/

#include <iostream>
using namespace std;

int main()
{
    int array[5];
    for (int i = 0; i < 5; ++i)
    {
        array[i] = 0;
    }


__asm { 
    mov array[0] , 1
    mov 4[array] , 2
    mov [array + 2*4] , 3
    mov array[12] , 4
    mov array[4*4] , 5

    mov eax, 5
  beg:
    inc array[ecx*4-4]  
    loop beg // цикл от 1 до 5
    


    lea  eax, array
    mov [dword ptr eax], -1
    add eax, 4
    mov [dword ptr eax], -17


    mov eax, 5
    lea eax, array
  /*beg2:
    mov [dword ptr eax][8], 25
    add eax, 4
    loop beg2

    lea  eax, array
    mov [dword ptr eax], -17*/
}

for (int i = 0; i < 5; ++i)
{
    cout << array[i] << endl;
}

}