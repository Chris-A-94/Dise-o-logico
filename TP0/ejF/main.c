#include <stdio.h>
#include <stdlib.h>

void getPartesEnteras(char*, int*, int*,char*);
int validarRango(int,int,char);
void imprimirHex(int,int,char);
void getNumIngresado(char*);

int main()
{
    int parteEntera,parteFraccionaria;
    char signo;
    char numIngresado[10];
    getNumIngresado(numIngresado);

    getPartesEnteras(numIngresado,&parteEntera,&parteFraccionaria,&signo);
    if(validarRango(parteEntera,parteFraccionaria,signo))
    {
        printf("Fuera de rango.\n");
        return 0;
    }


    imprimirHex(parteEntera,parteFraccionaria,signo);

    return 0;
}

void getNumIngresado(char* numIngresado)
{
    printf("\nIngrese numero en formato +eee.ffff o -eee.ffff: ");
    fgets(numIngresado,10*sizeof(char),stdin);

    if(numIngresado[9] == '\n')
        numIngresado[9] = '\0';

    int cumple = 1;
    if(!(numIngresado[0] == '+' || numIngresado[0] == '-') || !(numIngresado[4] == '.' || numIngresado[4] == ','))
        cumple = 0;
    for(int i = 1; i < 9; i++)
    {
        if(!cumple)
            break;
        if(i == 4)
            continue;
        if(numIngresado[i] < 48 || numIngresado[i] > 57)
            cumple = 0;
    }
    if(!cumple)
    {
        printf("\nPor favor, asegurese de ingresar un numero con el simbolo negativo o positivo primero, tres enteros, coma, y cuatro decimales.");
        getNumIngresado(numIngresado);
    }

}

void getPartesEnteras(char* numIngresado, int* parteEntera, int* parteFraccionaria,char* signo)
{

    *signo = numIngresado[0];
    *parteEntera = 0;
    *parteFraccionaria = 0;

    for(int i = 1; i < 4; i++)
    {
        *parteEntera *= 10;
        *parteEntera += numIngresado[i] - 48;
    }

    for(int i = 5; i < 9; i++)
    {
        *parteFraccionaria *= 10;
        *parteFraccionaria += numIngresado[i] - 48;
    }

}

int validarRango(int entero,int fracc,char signo)
{
    if(fracc >= 9922)
    {
        printf("La parte fraccionaria debe ser menor a 0.9921875.\n");
        return 1;
    }

    if(signo == '+')
    {
       if(entero > 127)
        {
            printf("El numero positivo maximo es 127.\n");
            return 1;
        }
    }
    else
    {
       if(entero > 128)
        {
            printf("El numero negativo maximo es 128\n");
            return 1;
        }
    }

    return 0;
}

void imprimirHex(int entero,int fracc,char signo)
{
    entero *= 256;
    //el +5000 es para que redondee al numero mas cercano, en vez de simplemente quedarse siempre con la parte entera
    //tipo, pasa 2.9 a 3, en vez de 2
    fracc = (fracc * 256 + 5000 )/ 10000;


    int impreso = entero + fracc;

    if(signo == '+')
       printf("\nNumero hexadecimal: 0x%04X",impreso);
    else
       printf("\nNumero hexadecimal: -0x%04X",impreso);

}
