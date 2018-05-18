#include <stdio.h>
#include <stdlib.h>
#define TI 5
#define TC 10
/*
1- canciones con el interprete
2- interprete y todos sus temas
3- canciones de artistas argentinos
4- La duracion de todos los temas del artista ingresado
5- El artista con mas canciones (Puede ser mas de uno)
*/


typedef struct
{
    int idCancion;//PK
    char titulo[50];
    int interprete;//FK
    int duracion;
} eCancion;
typedef struct
{
    int idInterprete;//PK
    char nombre[50];
    char nacionalidad[50];
} eInterprete;

void inicializarCanciones(eCancion [], int );
void inicializarInterpretes(eInterprete [], int );

void listarCanciones(eCancion [], int );
void listarInterpretes(eInterprete [], int );
void listarCancionesConInterpretes(eCancion[], int , eInterprete[], int);
void listarCancionesInterpretesArgentinos(eCancion[], int , eInterprete[], int);
void listarCancionesPorInterprete(eCancion[], int , eInterprete[], int);
void mostrarCancion(eCancion, eInterprete);

int main()
{
    eInterprete listaInterpretes[TI];
    eCancion listaCanciones[TC];

    inicializarInterpretes(listaInterpretes,TI);
    inicializarCanciones(listaCanciones,TC);

    listarInterpretes(listaInterpretes,TI);
    listarCanciones(listaCanciones,TC);
    system("pause");
    system("cls");
    listarCancionesConInterpretes(listaCanciones, TC, listaInterpretes, TI);
    system("pause");
    system("cls");
    listarCancionesInterpretesArgentinos(listaCanciones, TC, listaInterpretes, TI);
     system("pause");
    system("cls");
    listarCancionesPorInterprete(listaCanciones, TC, listaInterpretes, TI);
    return 0;
}

void inicializarInterpretes(eInterprete lista[], int tam)
{
    int id[]= {1,2,3,4,5};
    char nombre[][50]= {"Shakira","Adele","Karina, la princesita","Bruno Mars","Sara Bareilles"};
    char nacionalidad[][30]= {"Colombia","RUGB","Argentina","EEUU","EEUU"};
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].idInterprete=id[i];
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].nacionalidad, nacionalidad[i]);
    }
}

void inicializarCanciones(eCancion lista[], int tam)
{
    int id[]= {1011,1012,1013,1014,1015,1016,1017,1018,1019,1020};
    char titulo[][30]= {"Melt my heart to stone","La bicicleta","When i was your man","Mentiroso","Los dias sin ti","Gravity","Con la misma moneda","When he sees me","She used to be mine","Treasure"};
    int interprete[]= {2, 1,4,3,1, 5, 3, 5, 5,4 };
    int duracion[]= {6, 4,4,3,5, 5, 5, 8, 2,7};
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].idCancion=id[i];
        lista[i].interprete=interprete[i];
        lista[i].duracion=duracion[i];
        strcpy(lista[i].titulo, titulo[i]);

    }
}

void listarCanciones(eCancion lista[], int tam)
{
    int i;
    printf("CANCIONES\n");
    for(i=0; i<tam; i++)
    {
        printf("%d-%s-%d--%d\n",lista[i].idCancion, lista[i].titulo, lista[i].interprete, lista[i].duracion);
    }
}
void listarInterpretes(eInterprete lista[], int tam)
{
    int i;
    printf("INTERPRETES\n");
    for(i=0; i<tam; i++)
    {
        printf("%d-%s-%s\n",lista[i].idInterprete, lista[i].nombre, lista[i].nacionalidad);
    }
}

void listarCancionesConInterpretes(eCancion listaCanciones[], int tamC, eInterprete listaInterpretes[], int tamI)
{
    int i;
    int j;
    eInterprete auxInterprete;
    printf("CANCIONES C/ INTERPRETE\n");
    printf("Id\tTitulo\t\t\t\tInterprete\tDuracion\n");
    for(i=0; i<tamC; i++)
    {
        for(j=0; j<tamI; j++)
        {
            if(listaCanciones[i].interprete==listaInterpretes[j].idInterprete)
            {
                //auxInterprete = listaInterpretes[j];
                mostrarCancion(listaCanciones[i], listaInterpretes[j]);
                break;
            }
        }

    }
}

void listarCancionesPorInterprete(eCancion listaCanciones[], int tamC, eInterprete listaInterpretes[], int tamI)
{
 int i;
    int j;
    int idArgentino;

    for(i=0; i<tamI; i++)
    {

            idArgentino = listaInterpretes[i].idInterprete;
            for(j=0; j<tamC; j++)
            {
                if(idArgentino==listaCanciones[j].interprete)
                {
                    mostrarCancion(listaCanciones[j], listaInterpretes[i]);
                }

            }

    }
}

void listarCancionesInterpretesArgentinos(eCancion listaCanciones[], int tamC, eInterprete listaInterpretes[], int tamI)
{
    //Primero Busco id de argentinos

    int i;
    int j;
    int idArgentino;

    for(i=0; i<tamI; i++)
    {
        if(strcmp(listaInterpretes[i].nacionalidad,"EEUU")==0)
        {
            idArgentino = listaInterpretes[i].idInterprete;
            for(j=0; j<tamC; j++)
            {
                if(idArgentino==listaCanciones[j].interprete)
                {
                   mostrarCancion(listaCanciones[j], listaInterpretes[i]);
                }

            }
        }
    }


}
void mostrarCancion(eCancion c, eInterprete i)
{
      printf("%4d\t%20s\t%20s\t%4d\n",c.idCancion, c.titulo, i.nombre, c.duracion);
}
