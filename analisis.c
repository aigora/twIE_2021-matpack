#include <string.h>
#include "analisis.h"

void invertir(char func[] , char resultado[] ){
//creo una cadena vacia a la que irer añadiendo el contenido de la funcion inversa
    char invert[25] = "";
//creo dos variables para invertir una constante, una para el abrir y otra para cerrar de forma que la inversa ce una constante quede "*(1/K)
    char cons[10]="*(1/" ;
    char cerrarcons[10]=")";
     char nse[10];
//variables para bucles for
    int m ;
    int q;
    int r ;
    int v =1;
//creo cadenas de caracteres para añadir a la funcion inversa con una funcion if
    char e[4] = "e^(";
    char i[3] = "i(";
    char o[3] = "o(";
    char a[3] = "a(";
    char s[3] = "s(";
    char c[3] = "c(";
    char t[3] = "t(";
    char men[3] = "-";
    char equis[3] = "x";
    char partentesis[3] = ")";
    strupr(func);
//la variable par aumenta con cada funcion que se detecta para asi saber el numero de parentesis de cierre necesarios
    int par = 0 ;
//creo un bucle for que cuente cuantas funciones hay antes de la x para luego eliminarlas y aislar la constante
    for (r=0 ; func[r]!= 'X'  ; r++){
            q++;
        }
//bucle for que vaya pegando en una cadena vacia lasx ionversas de las funciones detectadas hasta llegar a la x
    int n = r+1;
    for(n=r+1 ; n>=0 ; n--){
        if(func[n]=='L'){
            strcat(invert , e );
            par=par + 1;
        }
        if(func[n]=='S'){
            strcat(invert , i );
            par=par + 1;
        }
        if(func[n]=='C'){
            strcat(invert , o );
            par=par + 1;
        }
        if(func[n]=='T'){
            strcat(invert , a );
            par=par + 1;
        }
        if(func[n]=='I'){
            strcat(invert , s );
            par=par + 1;
        }
        if(func[n]=='O'){
            strcat(invert , c );
            par=par + 1;
        }
        if(func[n]=='A'){
            strcat(invert , t );
            par=par + 1;
        }
        if(func[n]=='-'){
            strcat(invert , men );
            par=par + 1;
        }
//en caso de detectarse una constante se copia la funcion a la cadena de caracteres "nse"
//y se eliminan todos los caracteres menos las constantes y se le da un valor de 0 a n para acabar con el bucle for
//a la variable v se le asigna un valor de 0 , el cual se usara para saber que la funcion tiene una constante
       if((func[n]== '9')||(func[n]== '8')||(func[n]== '7')||(func[n]== '6')||(func[n]== '5')||(func[n]== '4')||(func[n]== '3')||(func[n]== '2')||(func[n]== '1')||(func[n]== '0')||(func[n]== 'E')||(func[n]== 'P')){
            strcpy(nse , func);
            for(q=r;q>n; q--){
                nse[q]=0;

            }
            n= 0;
            v= 0;
       }
    }
//si se detecta que la funcion tiene una constante, que ya ha sido almacenada en "nse"
//con el comando strcat se juntaran las cadenas del inicio de constante, la de la constante y la de el fin d3e constante
//se pega la constante sobre la funcion "equis" cuyo contenido es la x de la funcion inversa
    if (v==0){
        strcat(cons , nse); strcat(cons , cerrarcons);  strcat(equis , cons);
        strcat(invert, equis);
//usamos la variable "par" en un bucle for para añadir tantos parentesis de cierre como funciones se hayan usado
        for (m=0 ; m<par ; m++){
        strcat(invert , partentesis);
    }
       strcpy(resultado,invert ) ;
    }
//en caso de no haberse detectado ninguna constante se pegara la funcion equis a la funcion y se añaden parentesis de cierre
    else{
          strcat(invert , equis);
          for (m=0 ; m<par ; m++){
          strcat(invert,partentesis);
    }
//la cadena resultado, que sera la devuelta por la funcion , toma el valor de "invertida" que ya es la funcion inversa ya terminada
     strcpy(resultado,invert ) ;
}
}

void traducir(char func[] , char devolver[] ){
int i ;
//esta variable se usa para detectar si hay una constante, ya que al pasar de una funbcion , por ejemplo C(s(x*(1/2))) a cos(sen(x/2))
// se ha de eliminar un par de parentesis y la constante nos ayuda a ello
int b=0;
char resultado[30]="";
strcat(func , ";");
strupr(func);
//se copian sobre una cadena vacia segun corresponda a cada funcion
for(i=0 ; func[i]!=';' ; i++){

  if((func[i]=='^')){
    strcat(resultado , "^");
  }
  if((func[i]=='(')){
    strcat(resultado , "(");
  }
  if((func[i]==')')){
//en caso de b tomar el valor de 0 sabemos que no ha habido ninguna constante o que ya se ha eliminado el par de parentesis sobrantes

    if(b==0){
    strcat(resultado , ")");}
//si b tiene un valor distinto de 0 quiere decir que ha habido una constante por lo que no se agregara parentesis de cierre pero de dara a  b el valor de 0 para que estos si se agreguen mas tarde
    else{
        b=0;}

  }
  if((func[i]=='L')){
    strcat(resultado , "ln");
  }
  if(func[i]=='S'){
    strcat(resultado , "sen");
  }
  if((func[i]=='C')){
    strcat(resultado , "cos");
  }
  if((func[i]=='T')){
    strcat(resultado , "tan");
  }
  if((func[i]=='A')){
    strcat(resultado , "arctan");
  }
  if((func[i]=='O')){
    strcat(resultado , "arccos");
  }
  if((func[i]=='I')){
    strcat(resultado , "arcsen");
    }
  if((func[i]=='-')){
    strcat(resultado , "-");
  }
  if((func[i]=='X')){
    strcat(resultado , "x");
  }
//si se detecta el signo * quiere decir que hay una constante del tipo *(1/k) po lo que se aumentara en 3 cifras el valor de la 1 de forma que el parentesis de apertura sobrante se borre
//al igual que el signo * y el 1 , para asi quedarnos con una funcion del estilo x/k
  if((func[i]=='*')){
    b=1;
    i=i+3;
}
//condicionales if para ir añadiendo a la cadena vacia los valores de la constante
 if((func[i]=='1')){strcat(resultado , "1");} if((func[i]=='2')){strcat(resultado , "2");}
 if((func[i]=='3')){strcat(resultado , "3");} if((func[i]=='4')){strcat(resultado , "4");}
 if((func[i]=='5')){strcat(resultado , "5");} if((func[i]=='6')){strcat(resultado , "6");}
 if((func[i]=='7')){strcat(resultado , "7");} if((func[i]=='8')){strcat(resultado , "8");}
 if((func[i]=='9')){strcat(resultado , "9");} if((func[i]=='0')){strcat(resultado , "0");}
 if((func[i]=='E')){strcat(resultado , "e");} if((func[i]=='P')){strcat(resultado , "pi");}

 if((func[i]=='/')){
    strcat(resultado , "/");
  }
}
//se le otorga a la cadena devolver (que es la cadena que devolvera la funcion) la secuencia de caracteres de la cadena resultado,la cual contiene ya
//la funcion que se habia introducido pero reescrita de una forma que resulte mas visual y facil de entender
strcpy(devolver , resultado);
}

