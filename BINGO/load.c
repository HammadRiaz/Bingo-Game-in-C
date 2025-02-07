#include<stdio.h>
#include<windows.h>
#include<strings.h>
void main()

{

    COORD c;
    c.X=21;
    c.Y=32;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
