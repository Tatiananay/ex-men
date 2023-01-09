#include <stdio.h>
#include <Windows.h>

// color a lo que se imprime en consola
void setColor(int Background, int Text){ 
    int colorTexto= Text + (Background * 16);         
    HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);   
    SetConsoleTextAttribute(terminal, colorTexto); 
}
void showProgressBar_a(int velocidad, char correo[])
{
    int saltos = 0;
    int reversa = 0;
    float porcentaje = 0;
    for (int i = 0; i < 24; i++)
    {
        setColor(0,9);
        usleep(60000);
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
                    printf("-");            
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
        usleep(60000);
        printf(" %.0f%%", porcentaje);
        porcentaje +=  (100 / (float) 23);
        usleep(60000);

        setColor(0,10);
        printf("\t\tLoading %i de 23 \t\t", i);

        char numero[4];
        itoa(i, numero, 10);
        usleep(60000);

        setColor(0,4);
        for (int b = 0; b < i; b++)
        {
            printf("%c", correo[b]);
        }

        printf("\n");

        usleep(100000);
    }
}
int main()
{

	char correo[] = "nayeli.leiva@epn.edu.ec";

	showProgressBar_a(3, correo);
	return 1;
}