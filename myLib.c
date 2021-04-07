#include "Area.h"
float Circumferencia(float radio)
{
    float a;
  a=2*PI*radio;
  return a;
}
float AreaCirculo(float radio)
{
    float a;
  a=PI*radio*radio;
  return a;
}
float AreaCuadrado(float lado)
{
    float a;
  a=lado*lado;
  return a;
}
float AreaRectangulo(float base, float altura)
{
    float a;
  a=base*altura;
  return a;
}
float VolumenEsfera(float radio)
{
    float a;
  a=(4/3)*PI*radio*radio*radio;
  return a;

}

float VolumenCilindro(float radio, float altura)
{
    float a;
  a=PI*radio*radio*altura;
  return a;
}
float VolumenCubo(float lado)
{
    float a;
  a=lado*lado*lado;
  return a;
}
float VolumenCono(float radio, float altura)
{
    float a;
  a=(1/3)*PI*radio*radio*altura;
  return a;
}
float VolumenPrismaRectangular(float base, float altura,float grosor)
{
    float a;
  a=base*altura*grosor;
  return a;
}
float DistanciaPuntosA1B1(int a1,int b1)
{
    float a;
  a=(b1-a1);
  return a;
}
float DistanciaPuntosA2B2(int a2,int b2)
{
    float a;
  a=(b2-a2);
  return a;
}
float Modulo2Puntos(int a1, int a2, int b1, int b2)
{
   float a;
  a=sqrt(pow(DistanciaPuntosA1B1(a1,b1),2)+pow(DistanciaPuntosA2B2(a2,b2),2));
  return a;
}


