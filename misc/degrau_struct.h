#ifndef DEGRAU_STRUCT_H
#define DEGRAU_STRUCT_H

typedef struct Degrau{
    int pino;
    int pos_lower;
    int pos_upper;
    int estado;
    bool detectado;
    int brilho;
}Degrau;

void initDegrau(Degrau deg);

void checkPos(Degrau deg, float dist);
    
void update(Degrau deg, float dist);


#endif