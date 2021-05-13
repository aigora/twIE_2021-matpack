#include "calculadora.h"

//Esta función opera dos números.
float operar(float n1,float n2,char operacion)
{
    switch(operacion)
    {
        case '+':
            return n1+n2;
            break;
        case '-':
            return n1-n2;
            break;
        case '*':
            return n1*n2;
            break;
        case '/':
            return n1/n2;
            break;
        case '^':
            return pow(n1,n2);
            break;
    }
}

//Esta función asigna a cada operación un entero en función de su prioridad (primero las potencias, luego las divisiones...).
int orden_operacion(char operacion)
{
    switch(operacion)
    {
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 3;
            break;
        case '^':
            return 4;
            break;
    }
}

//Esta función devuelve la posición del paréntesis de apertura asociado a uno de cierre.
int pos_final(char funcion[],int pos_cerrado)
{
    int i,n_abiertos=0,n_cerrados=0,exis=0;

    for(i=pos_cerrado+1;funcion[i]!='\0';++i)
    {
        if(exis)
        {
            if(funcion[i]==')')
            {
                ++n_cerrados;
            }
            else if(funcion[i]=='(')
            {
                ++n_abiertos;
                if(n_abiertos==n_cerrados)
                {
                    exis=0;
                }
            }
        }
        else
        {
            if(funcion[i]==')')
            {
                n_abiertos=0;
                n_cerrados=1;
                exis=1;
            }
            else if(funcion[i]=='(')
            {
                return i;
            }
        }
    }
}

//Dada un lista de números y otra de números devuelve un número resultado de realizar operaciones repetando las reglas de operacones combinadas.
float resolv_imagen(float imagen[],char operaciones[],int orden,int longitud_imagen)
{
    if(longitud_imagen==1)
    {
        return imagen[0];
    }

    int i,k,j=0,i_op=0,i_im=0,sucesivo=0;
    float n_imagen[51];
    char n_operaciones[29];

    for(k=0;k<longitud_imagen;++k)
    {
        printf("%f ",imagen[k]);
    }
    for(k=0;operaciones[k]!='\0';++k)
    {
        printf("%c ",operaciones[k]);
    }

    printf("\n");

    for(i=0;operaciones[i]!='\0';++i)
    {
        if(orden_operacion(operaciones[i])==orden)
        {
            if(sucesivo)
            {
                --i_im;
                n_imagen[i_im]=operar(imagen[j+1],n_imagen[i_im],operaciones[i]);
                ++i_im;
            }
            else
            {
                n_imagen[i_im]=operar(imagen[j+1],imagen[j],operaciones[i]);
                sucesivo=1;
                ++i_im;
            }
        }
        else
        {
            if(orden_operacion(operaciones[i-1])!=orden)
            {
                n_imagen[i_im]=imagen[j];
                ++i_im;
            }

            n_operaciones[i_op]=operaciones[i];
            ++i_op;
            sucesivo=0;
        }
        ++j;
    }
    n_operaciones[i_op]='\0';

    if(orden_operacion(operaciones[i-1])!=orden)
    {
        n_imagen[i_im]=imagen[j];
        ++i_im;
    }

    return resolv_imagen(n_imagen,n_operaciones,orden-1,i_im);
}

//Esta función obtiene el valor que representa un par de paréntesis.
float resolv_parentesis(char funcion[],int pos_cerrado,float x)
{
    int i,j,contador_unidades=0,i_operaciones=0,i_imagen=0,orden=0,constante=1,producto=0,cons=0;
    float imagen[51],num=1,actual=0,anterior=0;
    char operaciones[29];

    for(i=pos_cerrado+1;funcion[i]!='\0';++i)
    {
        if(funcion[i]==')')
        {
            num=resolv_parentesis(funcion,i,x);
            i=pos_final(funcion,i);
        }
        else if(funcion[i]=='(')
        {
            if(actual==0 && cons)
                    num=0;
            else
                imagen[i_imagen]=num;
            operaciones[i_operaciones]='\0';
            return resolv_imagen(imagen,operaciones,orden,i_imagen+1);
        }
        else if(funcion[i]=='+'||funcion[i]=='-'||funcion[i]=='*'||funcion[i]=='/'||funcion[i]=='^')
        {
            if(funcion[i]=='-' && funcion[i+1]=='(')
            {
                num*=-1;
            }
            else
            {
                if(orden_operacion(funcion[i])>orden)
                    orden=orden_operacion(funcion[i]);
                if(actual==0 && cons)
                    num=0;
                else
                    imagen[i_imagen]=num;
                operaciones[i_operaciones]=funcion[i];
                num=1;
                constante=1;
                cons=0;
                actual=0;
                anterior=0;
                producto=0;
                contador_unidades=0;
                ++i_imagen;
                ++i_operaciones;
            }
        }
        else
        {
            switch(funcion[i]){
                case 'x':
                    producto=1;
                    cons=0;
                    num=x;
                    break;
                case 'l':
                    actual=0;
                    anterior=0;
                    producto=1;
                    cons=0;
                    contador_unidades=0;
                    num=log(num);
                    break;
                case 's':
                    actual=0;
                    anterior=0;
                    producto=1;
                    cons=0;
                    contador_unidades=0;
                    num=sin(num);
                    break;
                case 'c':
                    actual=0;
                    anterior=0;
                    producto=1;
                    cons=0;
                    contador_unidades=0;
                    num=cos(num);
                    break;
                case 't':
                    actual=0;
                    anterior=0;
                    producto=1;
                    cons=0;
                    contador_unidades=0;
                    num=tan(num);
                    break;
                case 'e':
                    actual=0;
                    anterior=0;
                    producto=1;
                    cons=0;
                    contador_unidades=0;
                    num=2.718281828459;
                    break;
                case 'p':
                    actual=0;
                    anterior=0;
                    producto=1;
                    cons=0;
                    contador_unidades=0;
                    num=3.141592653589;
                    break;
                case '.':
                    num/=pow(10,contador_unidades);
                    break;
                default:
                    if(constante && producto)
                    {
                       if(2>orden)
                        orden=2;
                       operaciones[i_operaciones]='*';
                       imagen[i_imagen]=num;
                       num=1;
                       constante=0;
                       ++i_imagen;
                       ++i_operaciones;
                    }

                    actual+=(funcion[i]-48)*pow(10,contador_unidades);

                    if(actual!=0)
                    {
                        if(anterior==0)
                            num*=actual;
                        else
                            num*=actual/anterior;
                    }
                    anterior+=actual;
                    cons=1;
                    ++contador_unidades;
                    break;
            }
        }
    }
}

//Esta función calcula la imagen para un determinado x.
float calc_imagen(char funcion[],float x)
{
    int i,j=1,longitud=strlen(funcion);
    char resultado[53];
    float imagen;

    resultado[0]=')';

    for(i=longitud-1;i>=0;--i)
    {
        resultado[j]=funcion[i];
        ++j;
    }
    resultado[j]='(';
    resultado[j+1]='\0';

    imagen=resolv_parentesis(resultado,0,x);

    return imagen;
}
