/*
 ============================================================================
 Name        : parcial_labo_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include "Controller.h"
#include "Ventas.h"



int main(void) {
	setbuf(stdout,NULL);
    int option = 0;
    LinkedList* listaVentas = ll_newLinkedList();



    do{
    	if(utn_getNumero(&option, "\n          Bienvenido al menu principal"
									"\n1-Cargar los datos de los autos "
									"\n2-Alta de auto"
									"\n3-Modificacion de auto"
									"\n4-Baja de auto"
									"\n5-Listados"
									"\n6-Generar informes venta"
									"\n7-Guardar archivo .csv"
									"\n8-Guarda archivo en binario"
    								"\n9-Salir", "Error ingrese las opciones que se muestran en el menu",1, 9, 2)==0)
    	{


        switch(option)
        {
            case 1:
            	if(controller_cargarJugadoresDesdeTexto("MOCK_DATA.csv",listaVentas)== 0)

            	{
            		printf("\nLos archivos  se leyeron correctamente");
            	}else
            	{
            		printf("\nLos archivos no se leyeron correctamente");
            	}
                break;
            case 2:
            	if(controller_agregarJugador(listaVentas) == 0)
            	{
            		printf("\nTodo salio bien al agregar un jugador");
            	}else
            	{
            		printf("\nAlgo salio mal");
            	}
             	break;
            case 3:
            	if(ll_isEmpty(listaVentas) == 0)
            	{
                	if(controller_editarJugador(listaVentas) == 0)
                	{
                		printf("\nTodo salio bien");
                	}else
                	{
                		printf("\nAlgo salio mal");
                	}
            	}else
            	{
            		printf("\nDebes cargar alguna venta primero");
            	}
                break;
            case 4:
            	if(ll_isEmpty(listaVentas) == 0)
            	{
                	if(controller_removerVenta(listaVentas) == 0)
                	{
                		printf("\nTodo salio bien");
                	}else
                	{
                		printf("\nAlgo salio mal");
                	}
            	}else
            	{
            		printf("\nDebes cargar alguna venta primero");
            	}
                break;
            case 5:
            	if(ll_isEmpty(listaVentas) == 0)
            	{
                    if(controller_listarVentas(listaVentas)== 0)
                    {
                    	printf("Todo ok");
                    }
            	}else
            	{
               		printf("\nDebes cargar alguna venta primero");
            	}
                break;
            case 6:
            	if(ll_isEmpty(listaVentas) == 0)
            	{
                	if(controller_GuardarComoTexto("Informes.txt" , listaVentas) == 0)
                	{
                		printf("\nTodo salio bien");
                	}else
                	{
                		printf("\nAlgo salio mal");
                	}
            	}else
            	{
               		printf("\nDebes cargar alguna venta primero");
            	}
                break;
            case 7:
            	if(ll_isEmpty(listaVentas) == 0)
            	{
                	if(controller_guardarVentasModoTexto("MOCK_DATA.csv" , listaVentas) == 0)
                	{
                		printf("\nSe guardo bien el archivo en modo texto");
                	}else
                	{
                		printf("\nNo se pudo guardar en modo texto");
                	}
            	}else
            	{
               		printf("\nDebes cargar alguna venta primero");
            	}
                break;
            case  8:
            	if(ll_isEmpty(listaVentas) == 0)
            	{
                	if(controller_guardarVentasModoBinario("MOCK_DATA.bin", listaVentas) == 0)
                	{
                		printf("\nTodo salio bien");
                	}else
                	{
                		printf("\nAlgo salio mal");
                	}
            	}else
            	{
               		printf("\nDebes cargar alguna venta primero");
            	}
            	break;
            case 9:
                break;
        }
    }
    }while(option != 9);

	return EXIT_SUCCESS;
}
