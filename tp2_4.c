#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CANTIDAD_PC 5

struct compu { 
    int velocidad;      
    // Velocidad de procesamiento en GHz (valor entre 1 y 3) 
    int anio;           
    // Año de fabricación (valor entre 2015 y 2024) 
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8) 
    char *tipo_cpu;     // Tipo de procesador (apuntador a cadena de caracteres) 
    };
    //typedef struct compu * PC;

    void listarPCs(struct compu pcs[], int cantidad);
    void mostrarMasVieja(struct compu pcs[], int cantidad);
    void mostrarMasVeloz(struct compu pcs[], int cantidad);

int main(){

    srand(time(NULL));

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    struct compu pcs[CANTIDAD_PC];
    

    for (int i = 0; i < CANTIDAD_PC; i++) {
        pcs[i].velocidad = rand() % 3 + 1;  
        pcs[i].anio = rand() % 10 + 2015;   
        pcs[i].cantidad_nucleos = rand() % 8 + 1; 
        pcs[i].tipo_cpu = tipos[rand() % 6]; /*el puntro tipo cpu recibe la direccion de memoria de una fila
         que a su vez en ella hay una arreglo, es decir el puntero recibe un arreglo de caracteres*/
    }

    listarPCs(pcs, CANTIDAD_PC);
    mostrarMasVieja(pcs, CANTIDAD_PC);
    mostrarMasVeloz(pcs, CANTIDAD_PC);


    return 0;
}

void listarPCs(struct compu pcs[], int cantidad){

    for (int i = 0; i < cantidad; i++) {
        printf("PC %d:\n", i + 1);
        printf("  Velocidad: %d\n", pcs[i].velocidad);
        printf("  Anio: %d\n", pcs[i].anio);
        printf("  Nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("  Tipo CPU: %s\n\n", pcs[i].tipo_cpu);
    }

}

void mostrarMasVieja(struct compu pcs[], int cantidad){
    
    int antigua = pcs[0].anio;
    int auxin = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if(pcs[i].anio<antigua){
            antigua = pcs[i].anio;
            auxin = i;
        }
    }
    printf("PC mas vieja:\n");
    printf("  Velocidad: %d\n", pcs[auxin].velocidad);
    printf("  Anio: %d\n", pcs[auxin].anio);
    printf("  Nucleos: %d\n", pcs[auxin].cantidad_nucleos);
    printf("  Tipo CPU: %s\n", pcs[auxin].tipo_cpu);
}

void mostrarMasVeloz(struct compu pcs[], int cantidad){
    int maxVelocidad = pcs[0].velocidad;
    int auxin = 0;

    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].velocidad > maxVelocidad) {
            maxVelocidad = pcs[i].velocidad;
            auxin = i;
        }
    }


    printf("PC mas veloz:\n");
    printf("  Velocidad: %d\n", pcs[auxin].velocidad);
    printf("  Anio: %d\n", pcs[auxin].anio);
    printf("  Nucleos: %d\n", pcs[auxin].cantidad_nucleos);
    printf("  Tipo CPU: %s\n\n", pcs[auxin].tipo_cpu);
}