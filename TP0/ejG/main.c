#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void getNumIngresado(char*);

int main()
{
    int parteEntera,parteFraccionaria;
    char signo;
    char numIngresado[5];
    getNumIngresado(numIngresado);
    printf("\n Procesado: %s",numIngresado);
    return 0;
}

void getNumIngresado(char* numIngresado)
{
    printf("Ingrese un numero en formato 0xHHHH: 0x");
    fgets(numIngresado,5*sizeof(char),stdin);

    if(numIngresado[4] == '\n')
        numIngresado[4] = '\0';

    int cumple = 1;
    for(int i = 0; i < 4; i++)
    {
        numIngresado[i] = toupper(numIngresado[i]);
        if(!cumple)
            break;
        if(!( (numIngresado[i] >= '0' && numIngresado[i] <= '9') || (numIngresado[i] >= 'A' && numIngresado[i] <= 'F')
             ))
            cumple = 0;
    }
    if(!cumple)
    {
        printf("\nError, los numeros deben ser hexadecimales.");
        getNumIngresado(numIngresado);
    }



}
