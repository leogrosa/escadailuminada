#include "degrau.h"

void degrau::setPino(int pino){
    this->pino = pino;
}

int degrau::getPino(){
    return this->pino;
}

void degrau::setEstado(int estado){
    this->estado = estado;
}

int degrau::getEstado(){
    return this->estado;
}

void degrau::setBrilho(int brilho){
    this->brilho = brilho;
}

int degrau::getBrilho(){
    return this->brilho;
}

void degrau::setPos(float pos_lower, float pos_upper){
    this->pos_lower = pos_lower;
    this->pos_upper = pos_upper;
}


void degrau::checkPos(float dist){
    if(dist >= this->pos_lower && dist <= this->pos_upper)
    {
        this->detectado = 1;
    }
    else
    {
        this->detectado = 0;
    }
}

void degrau::update(float dist){
    this->checkPos(dist);

    if(detectado && this->estado == 0)
    {
        this->estado = 1;
    }
    
    if(this->estado == 1){
        this->brilho++;
        if(this->brilho == 255){
            this->estado = 2;
        }
    }

    if(detectado == 0 && this->estado == 2)
    {
        this->estado = 3;
    }

    if(this->estado == 3){
        this->brilho--;
        if(this->brilho == 0){
            this->estado = 0;
        }
    }

}


