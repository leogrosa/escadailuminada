#ifndef DEGRAU_H
#define DEGRAU_H


class degrau
{
    private:
        int pino;
        int pos_lower;
        int pos_upper;
        int estado = 0;
        int detectado = 0;
        int brilho = 0;
    public:
        void setPino(int pino);
        int getPino();

        int getEstado();
        void setEstado(int estado);

        int getBrilho();
        void setBrilho(int brilho);

        void setPos(float pos_lower, float pos_upper);

        void update(float dist);
        void checkPos(float dist);
};

#endif 