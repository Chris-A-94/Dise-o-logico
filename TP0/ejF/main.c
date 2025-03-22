#include <stdio.h>
#include <stdlib.h>

void getPartesEnteras(char*, int*, int*,char*);
int validarRango(int,int);
void imprimirHex(int,int);

int main()
{
    int parteEntera,parteFraccionaria;
    char signo;
    char numIngresado[10];

    size_t sizeIngresado;

    do
    {
       printf("Ingrese numero con formato estricto +eee.ffff o -eee.ffff: ");
       fgets(numIngresado,sizeof(numIngresado),stdin);
       sizeIngresado = strlen(numIngresado);
       if(numIngresado[sizeIngresado - 1] == '\n')
        {
            numIngresado[sizeIngresado - 1] = '\0';
            sizeIngresado--;
        }

    }while(!(numIngresado[0] == '+' || numIngresado[0] == '-') || sizeIngresado != 9);

    getPartesEnteras(numIngresado,&parteEntera,&parteFraccionaria,&signo);
    if(validarRango(parteEntera,parteFraccionaria))
    {
        printf("Fuera de rango.\n");
        return 0;
    }


    printf("Signo: %c, Entero: %d, fraccionario: %d",signo,parteEntera,parteFraccionaria);

    imprimirHex(parteEntera,parteFraccionaria);

    return 0;
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

int validarRango(int entero,int fracc)
{
    if(entero > 128)
        return 0;
    else if(entero = 128 && fracc > 0)
        return 0;

    return 1;
}

void imprimirHex(int entero,int fracc)
{
    char* misHex = "0123456789ABCDEF";

    int hexEntero = 0;
    int hexFracc = 0;
    char numImpreso[10];
    int i = 0;
    while(entero != 0)
    {
        hexEntero = entero % 16;
        entero /= 16;
        numImpreso[i] = misHex[hexEntero];
        i++;
    }
    numImpreso[i] = '.';
    printf("\nParte entera en hex: %s",numImpreso);
    char aux;
    for(int j = 0; j < i; j++)
        for(int k = i - 1; k >= i - j - 1; k--)
        {
            aux = numImpreso[j];
            numImpreso[j] = numImpreso[k];
            numImpreso[k] = aux;
        }
    printf("\nParte entera en hex: %s",numImpreso);

}
