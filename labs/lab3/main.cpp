#include <iostream>
using namespace std;

// ЗАДАЧА 1

unsigned int expression(unsigned int a_asm)
{
    unsigned int result;

    __asm {
        mov eax, a_asm
        mov ebx, eax         ; ebx = a
        
        mul ebx
        mov ecx, eax         ; ecx = a^2
        mul ecx
        mov esi, eax         ; esi = a^4
        
        mul eax
        mov edi, eax         ; edi = a^8
        
        mov eax, esi         ; eax = a^4
        mul edi              ; eax = a^12
        
        add eax, edi         ; + a^8
        add eax, ebx         ; + a
        
        mov result, eax

    }
    return result;
}

// ЗАДАЧА 3

void fibonacci()
{
    unsigned int prev = 0;
    unsigned int curr = 1;
    unsigned int next;
    bool overflow_detected = false;

    cout << prev << endl;
    cout << curr << endl;

    while (!overflow_detected)
    {

        __asm {
            mov eax, curr
            add eax, prev
            setc bl
            movzx ebx, bl
            mov next, eax
            mov overflow_detected, bl
        }

        if (!overflow_detected)
        {
            cout << next << endl;
            prev = curr;
            curr = next;
        }
    }
}

int main()
{
    // Задачи 1
    unsigned int a;
    cout << "a^12 + a^8 + a" << endl;
    cout << "Enter a positive integer a: ";
    cin >> a;

    if (a > 0)
    {
        unsigned int result_task1 = expression(a);

        cout << "asm Result = " << result_task1 << endl;
    }
    else
    {
        cout << "Input must be a positive integer" << endl;
    }

    // Задачи 3
    cout << "\nFiboncci numbers:" << endl;

    fibonacci();

    return 0;
}