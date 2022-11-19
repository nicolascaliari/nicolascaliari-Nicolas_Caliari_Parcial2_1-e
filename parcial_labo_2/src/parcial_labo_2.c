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
#include "Autos.h"
#include "Validaciones.h"
#include "Controller.h"



int main(void) {
	setbuf(stdout,NULL);
    int option = 0;
    int bandera_cargar_datos = 0;
    int contadorId = 50;
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
            		bandera_cargar_datos = 1;
            	}else
            	{
            		printf("\nLos archivos no se leyeron correctamente");
            	}
                break;
            case 2:
            	controller_agregarJugador(listaVentas , &contadorId);
            	break;
//            case 3:
//            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0)
//            	{
//                	if(controller_editarJugador(listaJugadores) == 0)
//                	{
//                		printf("\nTodo salio bien al modificar");
//                	}
//            	}else
//            	{
//            		printf("\nDebes ingresar la opcion uno primero");
//            	}
//                break;
            case 4:
            	controller_removerJugador(listaVentas);
                break;
            case 5:
                	if(controller_listarJugadores(listaVentas)== 0)
                	{
                		printf("Todo ok");
                	}
                break;
//            case 6:
//            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0)
//            	{
//                	if(menuConvocarJugadores(listaJugadores, listaSelecciones) == 0)
//                	{
//                		printf("\nTodo ok");
//                	}
//            	}else
//            	{
//            		printf("\nDebes ingresar la opcion uno primero");
//            	}
//                break;
            case 7:
            	controller_saveAsText("Informes.txt" , listaVentas);
                break;
//            case 8:
//            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0)
//            	{
//            		menu_guardar_JugadoresBinario(listaJugadores, listaSelecciones);
//            		bandera_cargar_datos_binarios = 1;
//            	}else
//            	{
//            		printf("\nDebes ingresar la opcion uno primero");
//            	}
//
//                break;
//            case 9:
//            	if(bandera_cargar_datos == 1 && bandera_cargar_datos_binarios == 1)
//            	{
//                	if(menu_cargar_JugadoresBinario(listaJugadores, listaSelecciones) == 0)
//                	{
//                		printf("\nTodo salio bien");
//
//                	}
//            	}else
//            	{
//            		printf("\nDebes ingresar la opcion 1 y 8");
//            	}
//
//                break;
//            case 10:
//            	if(bandera_cargar_datos == 1 && ll_isEmpty(listaJugadores) == 0)
//            	{
//              		if(controller_guardarJugadoresModoTexto("jugadores.csv", listaJugadores) == 0
//                    			&& controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones ) == 0)
//                    		{
//              			ll_clear(listaJugadores);
//              			ll_clear(listaJugadores);
//              					bandera_guardar_archivos = 1;
//                    		}
//            	}else
//            	{
//            		printf("\nDebes ingresar la opcion uno primero");
//            	}
//                break;
//            case 11:
//            	if(bandera_guardar_archivos == 0)
//            	{
//            		utn_getNumero(&option, "\nNo guardatse nada, seguro deseas salir? Ingresa 11 para salir o 1 para seguir.", "\nError", 1, 11, 2);
//
//            	}else{
//            		printf("\nPrograma finalizado");
//            		ll_deleteLinkedList(listaSelecciones);
//            		ll_deleteLinkedList(listaJugadores);
//            	}
//            	break;
        }
    }
    }while(option != 11);

	return EXIT_SUCCESS;
}
