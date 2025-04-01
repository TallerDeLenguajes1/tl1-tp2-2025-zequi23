#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu { 
    int velocidad;      
    // Velocidad de procesamiento en GHz (valor entre 1 y 3) 
    int anio;           
    // Año de fabricación (valor entre 2015 y 2024) 
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8) 
    char *tipo_cpu;     // Tipo de procesador (apuntador a cadena de caracteres) 
    };
    typedef struct compu * PC;

int main(){

    srand(time(NULL));

    PC maquina[5];
    for (int i = 0; i < 5; i++)
    {
       maquina[i]->velocidad = 1 + rand()%3;
       maquina[i]->anio = 2015 + rand()%2024;
       maquina[i]->cantidad_nucleos = 1 + rand()%8;
       
    }
    

    return 0;
}