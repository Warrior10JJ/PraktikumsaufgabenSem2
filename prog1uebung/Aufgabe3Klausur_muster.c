#include <stdio.h>
//wahheitstabelle als binäraddition
//2hoch3 für 3variablen, 2hoch 4 für 4 etc
void printTerm(int n, int row, int forkndf) {
for (int var = 0; var <n; var++) {}//läuft bei 3 variabeln 3 mal
    int bit = (row >> (n- 1 -var));
    char name = "a" +var;
    if (forkndf == 1) {//kdnf oder kknf
        if (bit == 0) {
            printf("!");
        }
        printf("%c", name);
    }
}


int main () {
    //zecihenkette
    //jede zeile 1 oder 0
    //kdnf 0er negieren
    //bsp zeile 2 !a + !b + c = 1
}












