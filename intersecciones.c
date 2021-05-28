[22:31, 28/5/2021] Gonzalo Stampa: #include"interseccion.h"
#include"analisis.h"
#include <math.h>
#include <stdio.h>
void corte(char nse[] , float cortex[2] , float cortey[2]){
cortex[0]=0;
cortex[1]=0;
cortey[0]=0;
cortey[1]=0;
int len;
int i = 0;
char inversa[20];
invertir( nse , inversa);
for(len=0; inversa[len]!='x'; len++){ i++;}
    for(len=i ; len!=-1 ; len--){
    if( inversa[len]=='s'){ cortex[0]= sin(cortex[0]);}
    if( inversa[len]=='c'){ cortex[0]= cos(cortex[0]);}
    if( inversa[len]=='t'){ cortex[0]= tan(cortex[0]);}
    if( inversa[len]=='a'){ cortex[0]= atan(cortex[0]);}
    if( inversa[len]=='o'){ cortex[0]= acos(cortex[0]);}
    if( inversa[len]=='i'){ cortex[0]= asin(cortex[0]);}
    if( inversa[len]=='e'){ cortex[0]= pow(2.71828 , cortex[0]);}

}
int lon;
int j = 0;
printf("%s \n" , nse);
for(lon=0; nse[lon]!='X'; lon++){ j++;}
    for(lon=j ; lon!=-1 ; lon--){
    if( nse[lon]=='S'){ cortey[1]= sin(cortey[1]);}
    if( nse[lon]=='C'){ cortey[1]= cos(cortey[1]);}
    if( nse[lon]=='T'){ cortey[1]= tan(cortey[1]);}
    if( nse[lon]=='A'){ cortey[1]= atan(cortey[1]);}
    if( nse[lon]=='O'){ cortey[1]= acos(cortey[1]);}
    if( nse[lon]=='I'){ cortey[1]= asin(cortey[1]);}
    if( nse[lon]=='L'){ cortey[1]= log(cortey[1]);}
}
}
