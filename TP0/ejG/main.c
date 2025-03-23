#include <stdio.h>
#include <stdlib.h>

void getNumIngresado(int*);
char procesarNum(unsigned int*,unsigned int*, int);
void imprimirNumero(char,unsigned int, unsigned int);

int main()
{
    unsigned int parteEntera,parteFraccionaria;
    char signo;
    int numIngresado;
    getNumIngresado(&numIngresado);
    signo = procesarNum(&parteEntera,&parteFraccionaria,numIngresado);
    printf("\n Num ingresado: %X",numIngresado);

    printf("\nParte entera: %X, parte fraccionaria: %X, signo: %c",parteEntera,parteFraccionaria,signo);

    imprimirNumero(signo,parteEntera,parteFraccionaria);

    return 0;
}

void getNumIngresado(int* numIngresado)
{
    do
    {
        printf("Ingrese un numero en formato 0xHHHH: 0x");
        scanf("%x",numIngresado);
    }while(*numIngresado < 0 || * numIngresado > 0xFFFF );

}

char procesarNum(unsigned int* entera,unsigned int* fracc,int numIngresado)
{
    char signo;
    int bitSignificativo = numIngresado & 0x8000;
    if(bitSignificativo)
        signo = '-';
    else
        signo = '+';
    *entera = numIngresado & 0x7F00;
    *entera = *entera >> 8;
    *fracc = numIngresado & 0x00FF;

    return signo;

}

void imprimirNumero(char signo,unsigned int entero, unsigned int fracc)
{
    fracc *= 10000;
    fracc /= 256;
    int ifNegativo;
    //Iba a chequear rangos aca, pero con formato 0xHHHH es imposible ingresar algo fuera de rango.

    if(signo == '+')
        printf("\nSu numero es %c%d.%04d",signo,entero,fracc);
    else
    {
        ifNegativo = -(int)entero;
        printf("\nSu numero es %d.%04d",ifNegativo,fracc);
    }
}


