#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getNumIngresado(int*);
char procesarNum(unsigned int*,unsigned int*, int);
void imprimirNumero(char,unsigned int, unsigned int);

int main()
{
    unsigned int parteEntera,parteFraccionaria;
    char signo;
    int numIngresado;

    if(getNumIngresado(&numIngresado))
        return 1;

    signo = procesarNum(&parteEntera,&parteFraccionaria,numIngresado);

    imprimirNumero(signo,parteEntera,parteFraccionaria);

    return 0;
}

int getNumIngresado(int* numIngresado)
{
    char entryStream[5];
    int booleano;
    do
    {
        booleano = 1;
        printf("Ingrese un numero en formato 0xHHHH: 0x");

        if(scanf("%04s",entryStream) != 1)
        {
            printf("Formato erroneo. Reingresar.\n");
            while(getchar() != '\n')
                continue;
            continue;
        }

        entryStream[4] = '\0';

        if (strlen(entryStream) != 4)
        {
            printf("Error: El formato de entrada es HHHH.\n");
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            if (!isxdigit(entryStream[i]))
            {
                booleano = 0;
                break;
            }
        }
        if(!booleano)
        {
            printf("\nIngrese digitos del 0 - 9 y letras del A - F");
            continue;
        }
        else
            break;

    }while(1);


    booleano = sscanf(entryStream, "%X", numIngresado);

    if(booleano)
    {
        printf("Conversion exitosa.\n Numero hexa ingresado: %X",*numIngresado);
        return 0;
    }
    else
    {
        printf("Error critico.");
        return 1;
    }
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


