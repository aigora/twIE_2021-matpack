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
        if(Nueva[i]=='s'&&Nueva[i+1]=='e'&&Nueva[i+2]=='n'&&Nueva[i-1]!='c')
           {
               Final[i]='s';
               printf("%c",Final[i]);
           }
           if(Nueva[i]=='c'&&Nueva[i+1]=='o'&&Nueva[i+2]=='s'&&Nueva[i-1]!='c')
           {
               Final[i]='c';
               printf("%c",Final[i]);
           }
            if(Nueva[i]=='t'&&Nueva[i+1]=='a'&&Nueva[i+2]=='n'&&Nueva[i-1]!='c')
           {
               Final[i]='t';
               printf("%c",Final[i]);

           }
           if(Nueva[i]=='l'&&Nueva[i+1]=='n')
           {
               Final[i]='l';
               printf("%c",Final[i]);
           }
           if(Nueva[i]=='a'&&Nueva[i+1]=='r'&&Nueva[i+2]=='c'&&Nueva[i+3]=='s'&&Nueva[i+4]=='e'&&Nueva[i+5]=='n')
           {
               Final[i]='i';
               printf("%c",Final[i]);
           }
           if( Nueva[i]=='a'&&Nueva[i+1]=='r'&&Nueva[i+2]=='c'&&Nueva[i+3]=='c'&&Nueva[i+4]=='o'&&Nueva[i+5]=='s')
           {
               Final[i]='o';
               printf("%c",Final[i]);
           }
           if(Nueva[i]=='a'&&Nueva[i+1]=='r'&&Nueva[i+2]=='c'&&Nueva[i+3]=='t'&&Nueva[i+4]=='a'&&Nueva[i+5]=='n')
           {
               Final[i]='i';
               printf("%c",Final[i]);
           }
            if(Nueva[i]=='n'&&Nueva[i+1]=='^')
           {
               Final[i]='m';
               printf("%c",Final[i]);
            }
            if(Nueva[i]=='e'&&Nueva[i+1]!='n')
           {
               Final[i]='e';
               printf("%c",Final[i]);
           }
           if(Nueva[i]=='p'&&Nueva[i+1]=='i')
           {
               Final[i]='p';
               printf("%c",Final[i]);
            }

            switch(Nueva[i])
    {
    case '+':
        {
            Final[i];
          printf("+");
        }
      break;
    case '-':
      {
            Final[i];
          printf("-");
        }
      break;
      case '*':
      {
            Final[i];
          printf("*");
        }
      break;
      case '/':
      {
            Final[i];
          printf("/");
        }
      break;
      case '1':
      {
            Final[i];
          printf("1");
        }
      break;
      case '2':
      {
            Final[i];
          printf("2");
        }
      break;
      case '3':
      {
            Final[i];
          printf("3");
        }
      break;
      case '4':
      {
            Final[i];
          printf("4");
        }
      break;
      case '5':
      {
            Final[i];
          printf("5");
        }
      break;
      case '6':
      {
            Final[i];
          printf("6");
        }
      break;
      case '7':
      {
            Final[i];
          printf("7");
        }
      break;
      case '8':
      {
            Final[i];
          printf("8");
        }
        break;
        case '9':
      {
            Final[i];
          printf("9");
        }
      break;
    }
}
printf("\n");
for(i=0;i<=50;i++)
    printf("%c",Final[i]);
return 0;
}




