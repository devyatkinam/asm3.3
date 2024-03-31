#include <iostream>

int main() {
    int a[50] = { 0, 1 };
    int n = 2;

    _asm {
        lea esi, a
        mov ebx, 2
        mov eax, [esi]
        mov[esi + 8], eax
        add eax, [esi + 4]

        jo _loop2
        mov[esi + 12], eax
        inc n
        jmp _loop1

        _loop1 :
        add eax, [esi + ebx * 4 - 8]
            jo _loop2
            mov[esi + ebx * 4], eax
            inc ebx
            inc n
            cmp ebx, 50
            je _loop2
            jmp _loop1

            _loop2 :
        mov n, ebx
    }


    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    return 0;
}
