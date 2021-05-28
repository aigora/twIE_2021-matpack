#include <string.h>
#include "analisis.h"

void invertir(char func[] , char resultado[] ){
    char fin[]={'\0'};
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
     strcat(resultado,fin);
}
}

void traducir_o(char func[] , char resultado[] ){
int i ;
//esta variable se usa para detectar si hay una constante, ya que al pasar de una funbcion , por ejemplo C(s(x*(1/2))) a cos(sen(x/2))
// se ha de eliminar un par de parentesis y la constante nos ayuda a ello
int b=0;
char fin[]={'\0'},agregar[2];

for(i=0 ; i<strlen(func) ; i++){
  agregar[0]=func[i];
  agregar[1]='\0';

  if((func[i]=='l')){
    strcat(resultado , "ln");
  }
  else if(func[i]=='s'){
    strcat(resultado , "sen");
  }
  else if((func[i]=='c')){
    strcat(resultado , "cos");
  }
  else if((func[i]=='t')){
    strcat(resultado , "tan");
  }
  else if((func[i]=='a')){
    strcat(resultado , "arctan");
  }
  else if((func[i]=='o')){
    strcat(resultado , "arccos");
  }
  else if((func[i]=='i')){
    strcat(resultado , "arcsen");
    }
  else{
      strcat(resultado,agregar);
  }
  }
}

void traducir_r(char Nueva[],char Final[])
{
    int i,j=0;

    for(i=0;i<strlen(Nueva);i++)
    {
        if(Nueva[i]=='s'&&Nueva[i+1]=='e'&&Nueva[i+2]=='n')
           {
               Final[j]='s';
               i+=2;
           }
        else if(Nueva[i]=='c'&&Nueva[i+1]=='o'&&Nueva[i+2]=='s')
           {
               Final[j]='c';
               i+=2;
           }
        else if(Nueva[i]=='t'&&Nueva[i+1]=='a'&&Nueva[i+2]=='n')
           {
               Final[j]='t';
               i+=2;
           }
        else if(Nueva[i]=='l'&&Nueva[i+1]=='n')
           {
               Final[j]='l';
               i+=1;
           }
        else if(Nueva[i]=='a'&&Nueva[i+1]=='r'&&Nueva[i+2]=='c'&&Nueva[i+3]=='s'&&Nueva[i+4]=='e'&&Nueva[i+5]=='n')
           {
               Final[j]='i';
               i+=5;
           }
        else if( Nueva[i]=='a'&&Nueva[i+1]=='r'&&Nueva[i+2]=='c'&&Nueva[i+3]=='c'&&Nueva[i+4]=='o'&&Nueva[i+5]=='s')
           {
               Final[j]='o';
               i+=5;
           }
        else if(Nueva[i]=='a'&&Nueva[i+1]=='r'&&Nueva[i+2]=='c'&&Nueva[i+3]=='t'&&Nueva[i+4]=='a'&&Nueva[i+5]=='n')
           {
               Final[j]='i';
               i+=5;
           }

        else
        {
            Final[j]=Nueva[i];
        }
        ++j;
}
Final[i]='\0';
}

//Esta función halla el valor mínimo de un conjunto.
float minimo(float valores_y[],int longitud_x)
{
    int i;
    float min=valores_y[0];

    for(i=1;i<longitud_x;++i)
    {
        if(valores_y[i]<min)
            min=valores_y[i];
    }
    return min;
}


//Esta función halla el valor máximo de un conjunto.
float mayor(float valores_y[],int longitud_x)
{
    int i;
    float max=valores_y[0];

    for(i=1;i<longitud_x;++i)
    {
        if(valores_y[i]>max)
            max=valores_y[i];
    }
    for(i=0;i<longitud_x;++i)
    {
        if(valores_y[i]==max)
            valores_y[i]=minimo(valores_y,longitud_x);
    }
    return max;
}
