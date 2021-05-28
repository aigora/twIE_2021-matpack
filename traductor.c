#include <stdio.h>

int main(){
  int i;
  char Nueva[50],Final[50];

  // Abrimos fichero para escritura
  printf("\t\t\t\t\t \t \t\t Calculadora Magica \n");

  printf("ln(x)=lx, sen(x)=sx, cos(x)=cx, tan(x)=tx,arcsen(x)=ix, arcos(x)=ox,arctan(x)=ax,n elevado a m=n^m,e=e, pi=p\n \n");
    printf("Escribe la ecuacion y te la escribo bien\n");
    scanf(" %50[^\n]",Nueva);
    for(i=0;i<50;i++)
    {
        if(Nueva[i]=='s'&&Nueva[i+1]=='e'&&Nueva[i+2]=='n')
           {

               Final[i]='s';

               i=i+2;

           }
           if(Nueva[i]=='c'&&Nueva[i+1]=='o'&&Nueva[i+2]=='s')
           {
               Final[i]='c';

           }
            if(Nueva[i]=='t'&&Nueva[i+1]=='a'&&Nueva[i+2]=='n')
           {
               Final[i]='t';

           }
           if(Nueva[i]=='l'&&Nueva[i+1]=='n')
           {
               Final[i]='l';
               Nueva[i+1]=0;
           }
           if(Nueva[i]=='a'&&Nueva[i+1]=='r'&&Nueva[i+2]=='c'&&Nueva[i+3]=='s'&&Nueva[i+4]=='e'&&Nueva[i+5]=='n')
           {
               Final[i]='i';
           }
           if( Nueva[i]=='a'&&Nueva[i+1]=='r'&&Nueva[i+2]=='c'&&Nueva[i+3]=='c'Nueva[i+4]=='o'&&Nueva[i+5]=='s')
           {
               Final[i]='o';

           }
           if(Nueva[i]=='a'&&Nueva[i+1]=='r'&&Nueva[i+2]=='c'&&Nueva[i+3]=='t'&&Nueva[i+4]=='a'&&Nueva[i+5]=='n')
           {
               Final[i]='i';

           }
            if(Nueva[i]=='n'&&Nueva[i+1]=='^')
           {
               Final[i]='m';

           }
            if(Nueva[i]=='e'&&Nueva[i+1]!='n')
           {
               Final[i]='e';
           }
           if(Nueva[i]=='p'&&Nueva[i+1]=='i')
           {
               Final[i]='p';
            }
            if(Nueva[i]!='\n')
            {
                Final[i]=Nueva[i];
            }

            }
       for(i=0;i<50;i++)
printf("%c",Final[i]);
return 0;
  }
