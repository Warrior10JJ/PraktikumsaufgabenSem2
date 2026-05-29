
#include <stdlib.h>
#include <stdio.h>
//void printf(char * str, char c);

//für 1=1 2=4 3=8 4=16 usw
int main (int argc, char**argv) { //uebergabe anzahl zeichenm, uebergabe zeichenkettem
    int zeichenanzahl = argc; //wenn ich wüsste wie das geht = zeichenm
    char* zeichenkette = argv;//hier das gleiche nur mit = zeichenkteem
    size_t n = sizeof(zeichenkette)/sizeof(zeichenkette[0]);
    for (int i = 0; i < zeichenanzahl; i++) {
            printf("%c\n", 97+i);
    }
    for (int i = 0; i < n; i++) {}


}