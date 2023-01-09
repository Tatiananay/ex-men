#include<iostream>
#include <stdio.h>
#include <Windows.h>

// Agrega color a la consola
void setColor(int Background, int Text){ 
    int colorTexto= Text + (Background * 16);         
    HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);   
    SetConsoleTextAttribute(terminal, colorTexto); 
}

void showProgressBar_a(int velocidad, char correo[])   //Procedimiento para la barra.
{
    int saltos = 0;
    int reversa = 0;
    float porcentaje = 0;
    for (int i = 0; i < 24; i++)
    {
        setColor(0,9);
        Sleep(50); //hace que imprima más lento
        printf("[");
        if (reversa == 0)
        {
            for (int a = 0; a < 22; a++)
            {
                if (a < saltos)
                {
                    printf("=");
                }
                else if (a == saltos)
                {
                    printf("-");
                }
                else
                {
                    printf("=");
                }
            }   
        }
        else
        {
            for (int a = 0; a < 22; a++)
            {
                if (a == 23 - saltos)
                {
                    printf("=");
            
                }
                else if (a < 23 - saltos)
                {
                    printf("=");

                }
                else
                {
                    printf("=");
 
                }
            }   
        }
        saltos += velocidad;
        if (saltos > 23 && reversa == 0)
        {
            saltos = velocidad;
            reversa = 1;
        }
        if (saltos > 23 && reversa == 1)
        {
            saltos = velocidad;
            reversa = 0;
        }
        printf("]"); 
        Sleep(50);
        printf(" %.0f%%", porcentaje);
        porcentaje +=  (100 / (float) 23);
        Sleep(50);

        setColor(0,10);
        printf("\t\tLoading %i de 23 \t\t", i);

        char numero[4];
        itoa(i, numero, 10);
        Sleep(50);

        setColor(0,4);
        for (int b = 0; b < i; b++)
        {
            printf("%c", correo[b]);
        }

        printf("\n");

        Sleep(50);
    }
}

    int main(){

    char correo[] = "nayeli.leiva@epn.edu.ec"; //variable global.
    showProgressBar_a(1,correo); //llama al procedimiento.
}

