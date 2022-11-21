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
#include "Autos.h"
#include "Validaciones.h"
#include "Controller.h"



int main(void) {
	setbuf(stdout,NULL);
    int option = 0;
    int bandera_cargar_datos = 0;
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
            	if(controller_cargarJugadoresDesdeTexto("MOCK_DATA.csv",listaVentas)== 0
            		&& controller_cargarJugadoresDesdeBinario("MOCK_DATA.csv" , listaVentas) == 0)

            	{
            		printf("\nLos archivos  se leyeron correctamente");
            		bandera_cargar_datos = 1;
            	}else
            	{
            		printf("\nLos archivos no se leyeron correctamente");
            	}
                break;
            case 2:
            	controller_agregarJugador(listaVentas);
             	break;
            case 3:
            	controller_editarJugador(listaVentas);
                break;
            case 4:
            	controller_removerVenta(listaVentas);
                break;
            case 5:
                	if(controller_listarJugadores(listaVentas)== 0)
                	{
                		printf("Todo ok");
                	}
                break;
            case 6:
            	controller_saveAsText("Informes.txt" , listaVentas);
                break;
            case 7:
            	if(controller_guardarVentasModoTexto("MOCK_DATA.csv" , listaVentas) == 0)
            	{
            		printf("\nSe guardo bien el archivo en modo texto");
            	}else
            	{
            		printf("\nNo se pudo guardar en modo texto");
            	}
                break;
            case  8:
            	controller_guardarVentasModoBinario("MOCK_DATA", listaVentas);
            	break;
            case 9:
                break;
        }
    }
    }while(option != 9);

	return EXIT_SUCCESS;
}
