#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
    char label[] = "\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\xC3"; //this is the shellcode, you could grab this by using a GET request for example
    unsigned char *p = (unsigned char *)VirtualAlloc( NULL, sizeof(label), MEM_COMMIT, PAGE_EXECUTE_READWRITE );
    memcpy ( p, label, strlen(label)+1 );
    DWORD var = p;
    system("pause");
    asm volatile("call *%0" : : "r" (var));
    return 0;
}
