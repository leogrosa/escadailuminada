#include "degrau_struct.h"

void initDegrau(Degrau deg)
{
    deg.estado = 0;
    deg.detectado = 0;
    deg.brilho = 0;
}

void checkPos(Degrau deg, float dist)
{
    if(dist >= deg.pos_lower && dist <= deg.pos_upper)
    {
        deg.detectado = 1;
    }
    else
    {
        deg.detectado = 0;
    }
}

void update(Degrau deg, float dist)
{
    checkPos(deg, dist);

    if(deg.detectado && deg.estado == 0)
    {
        deg.estado = 1;
    }
    
    if(deg.estado == 1){
        deg.brilho++;
        if(deg.brilho == 255){
            deg.estado = 2;
        }
    }

    if(!deg.detectado && deg.estado == 2)
    {
        deg.estado = 3;
    }

    if(deg.estado == 3){
        deg.brilho--;
        if(deg.brilho == 0){
            deg.estado = 0;
        }
    }

}