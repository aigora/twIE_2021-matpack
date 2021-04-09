#include <stdio.h>
#include <string.h>
int main ()
{
    //creo la variable de tipo char para identificar las operaciones
   char funcion[16];
   char suma[15] = "SUMA";
   char resta[15] = "RESTA";
   char multiplicacion[15] = "MULTIPLICACION";
   char division[15]= "DIVISION";
   char basicas[15] = "BASICAS";
   float solresta ;
   //etsa variuable servira para asignar el numero de datos que se van a introducir
   int ndatos ;
   //creo el vector que servira para las operaciones basicas
   float operacionesbasicas[10];
   //variable para mostrar la solucion
   float solucion=0 ;
   printf( " \n\n\n                                           Diccionario de las Matematicas\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n     - pulsa enter para empezar\n\n");
   printf("     escribe que tipo de operacion quiueres realizar \n\n");
   scanf("%s15[^\n]" , funcion);
   strupr(funcion);
   //para escoger funciones basicas
   if((strcmp(basicas , funcion))== 0){
    do{
       printf("\nintroduce el numero de datos con los que vas a operar (maximo 10) \n\n\n");
       //para indicar el numero de datos con los que se va a operar
       scanf("%d" , &ndatos);
       //en caso de no ser valido , advertimos al usuario de ello y se inicvia de nuevo el bucle do while
       if((ndatos==0)||(ndatos>=11)){
       printf("\nel numero introducido no es valido, introduzca un numero mayor que cero y menor que 11 \n\n");
       }
    }
    while((ndatos== 0) || (ndatos>= 11));
       //pasamos a la selecciopn de operaciones basicas
       printf("\nintroduce los valores uno a uno\n\n\n");
       //introduzco una variable para crear el vector que almacenara los datos introducidos por el usuario
       int vectorbasicas ;
       //haciendo uso del for almaceno lops datos
       for(vectorbasicas=0 ; vectorbasicas < ndatos ; vectorbasicas++ )
       {
           scanf("%f" , &operacionesbasicas[vectorbasicas]);
           printf("%f" , operacionesbasicas [vectorbasicas]);
       }
       printf(" \n\n\n escribe que tipo de operacion basica quieres lleva a cabo \n\n\n\n");
       printf("             suma                     resta                     multiplicacion                     division \n\n\n");
       scanf("%s15[^\n]" , funcion);
       strupr(funcion);
       //escoger suma e introduzco una variable para hacerla con una funcion for
       int sumafor;
       if((strcmp(suma , funcion))== 0)
       {
      for (sumafor=0; sumafor<ndatos ; sumafor++)
      solucion=solucion + operacionesbasicas[sumafor];
        }
       if((strcmp(resta , funcion))== 0)
       {
      int restafor ;
      for (restafor=0; restafor<(ndatos -1 ) ; restafor++)
      solresta=solresta - operacionesbasicas[restafor + 1];
      solucion= operacionesbasicas[0] + solresta;
        }
      int multfor ;
      if((strcmp(multiplicacion , funcion))== 0)
       {
      solucion=1;
      for (multfor=0; multfor<ndatos ; multfor++){
      solucion=solucion * operacionesbasicas[multfor];
        }
        }
       int divfor;
       int soldiv;
       if((strcmp(division , funcion))== 0)
       {
      soldiv=1;
      for (divfor=0; divfor<ndatos - 1 ; divfor++){
      soldiv=soldiv * operacionesbasicas[divfor + 1];
      solucion = operacionesbasicas[ 0] / soldiv;
        }
        }
        printf("la solucion es %f" ,  solucion);
   }
        else{
            printf(" \n\n\n error , operacion no detectada");
        }

   return 0 ;

}
