#include "funciones_puntos.h"
float signopendiente (cordspunto vec1 , cordspunto vec2){
float res ;
int ret;
res = (vec1.cordx - vec2.cordx) * (vec1.cordy - vec2.cordy);
if (res>0){
    ret=1;
}
if (res<0){
    ret=-1;
}

return ret ;
}
float pendiente (cordspunto vec1 , cordspunto vec2){
float pend ;
if (vec1.cordx>vec2.cordx){
    pend= (vec1.cordy-vec2.cordy)/(vec1.cordx - vec2.cordx);
}
if (vec1.cordx<vec2.cordx){
    pend= (vec2.cordy-vec1.cordy)/(vec2.cordx - vec1.cordx);
}
return pend ;
}
