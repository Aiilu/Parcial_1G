#include "cliente.h"

void harcodeoClientes(eCliente cli[], int tamCli)
{
    eCliente hardcode[]=
    {
        {1, "Mauro",'m'},
        {2, "Josefina",'f'},
        {3, "Luis",'m'},
        {4, "Andrea",'f'},
        {5, "Pedro",'m'},
        {6, "Marta",'f'}
    };


    for(int i=0; i<tamCli; i++)
    {
        cli[i]=hardcode[i];
    }
}


void mostrarCliente(eCliente cliente)
{

    printf("     %d   %s   %c\n", cliente.id,cliente.nombre,cliente.sexo);

}



void mostrarClientes(eCliente x[], int tam)
{

    for(int i=0; i < tam; i++)
    {

            mostrarCliente(x[i]);
    }

}
