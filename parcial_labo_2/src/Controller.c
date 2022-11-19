#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Autos.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"
#include "Controller.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListVenta)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

	if(path != NULL && pArrayListVenta != NULL)
	{
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			if(parser_AutoFromText(pArchivo, pArrayListVenta) == 0)
			{
				printf("\nEl archivo se leyo corrrectamente\n");
				retorno = 0;
			}else
			{
				printf("\nError al leer al archivo");
			}
		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
//int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
//{
//	int retorno = -1;
//	FILE* pArchivo;
//
//	if(path != NULL && pArrayListJugador != NULL)
//	{
//		pArchivo = fopen(path, "rb");
//		if(pArchivo != NULL)
//		{
//			if(parser_AutoFromBinary(pArchivo, pArrayListJugador))
//			{
//				printf("\nEl archivo se leyo corrrectamente\n");
//				retorno = 0;
//			}else
//			{
//				printf("\nError al leer al archivo");
//			}
//		}
//		fclose(pArchivo);
//	}
//    return retorno;
//}




/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */

int controller_listarJugadores(LinkedList* pArrayListVenta)
{
	int retorno = -1;
	Venta* pJugador = NULL;

    	if(pArrayListVenta != NULL)
    	{
    		printf("|%5s|%10s|%20s|%20s|%20s|%20s|\n", "ID", "Fecha_venta", "Modelo",
    															"Cantidad", "Precio_Unitario", "Tarjeta de credito");
    		for(int i = 0; i < ll_len(pArrayListVenta); i++)
    		{
    			pJugador = (Venta*)ll_get(pArrayListVenta, i);

    			if(pJugador != NULL)
    			{
    				if(imprimirAuto(pArrayListVenta,i) == 0)
    				{
    					retorno = 0;
    				}
    			}
    		}
    	}else
    	{
    		printf("No funciono bien");
    	}

    return retorno;
}


/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListVenta , int* contadorID)
{
	int retorno = -1;
	int id;
	int fecha_dia;
	int fecha_mes;
	int fecha_anio;
    char axuModelo[30];
    int cantidad;
//    char auxPrecio[30];
    char tarjeta_credito[30];
    Venta* pJugador = NULL;

	if(pArrayListVenta != NULL && ll_len(pArrayListVenta) >= 0)
	{
		if(utn_getNumero(&fecha_dia, "\nIngrese el dia", "\nError",1, 30, 2) == 0
		 && utn_getNumero(&fecha_mes, "\nIngrese el mes", "\nError",1, 12, 2) == 0
		 && utn_getNumero(&fecha_anio, "\nIngrese el anio", "\nError",1000, 2023, 2) == 0
		 && utn_getNombre(axuModelo, 30, "\nIngrese modelo del auto", "\nError", 2) == 0
		 && utn_getNumero(&cantidad, "\nIngrese la cantidad", "\nError",1, 30, 2) == 0
		 && utn_getDescripcion(tarjeta_credito, 16 , "\nIngrese su tarjeta", "\nError", 2) == 0)
		{

		printf("%s", tarjeta_credito);
			(*contadorID)++;
			id = *contadorID;

			pJugador = venta_new();

			if(pJugador != NULL)
			{
				if(venta_setId(pJugador, id)
					&& venta_setModelo(pJugador,  axuModelo)
					&& venta_setFecha_dia(pJugador, fecha_dia)
					&& venta_setFecha_mes(pJugador, fecha_mes)
					&& venta_setFecha_anio(pJugador, fecha_anio)
					&& venta_setCantidad(pJugador, cantidad)
					&& venta_setTarjeta_credito(pJugador, tarjeta_credito))
				{
					if(ll_add(pArrayListVenta, pJugador) == 0)
					{
						retorno = 0;
						printf("\nJugador cargado correctamente");
					}
				}else
				{
					printf("\nAlgo salio mal");
				}
			}
		}else
		{
			printf("\nNo es posible cargar los empleados");
		}
	}
    return retorno;
}





/** \brief Guarda los datos de los libros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListVenta)
{
    FILE* f;
    int retorno = -1;
    int len;
    int cantidad;
    int cantidad2;
    int cantidadUnidadesVendidas;
    int cantidadVentaPorModelo;

    f = fopen(path, "w");
    if(f != NULL && ll_len(pArrayListVenta) > 0)
    {
        len = ll_len(pArrayListVenta);
        fprintf(f, "******************");
        fprintf(f, "INFORMES DE VENTA");
        fprintf(f, "******************");

        controller_contarPorPrecio(pArrayListVenta ,  &cantidad , &cantidad2, &cantidadUnidadesVendidas, &cantidadVentaPorModelo);

        fprintf(f, "\n-Cantidad de unidades vendidas totales: %d",cantidadUnidadesVendidas);
        fprintf(f, "\n-Cantidad de ventas por un monto mayor a $10000: %d",cantidad);
        fprintf(f, "\n-Cantidad de ventas por un monto mayor a $20000: %d",cantidad2);
        fprintf(f, "\n-Cantidad de unidades vendidas para la ram 3500: %d",cantidadVentaPorModelo);

        printf("\n--Archivo guardado--\n");
        retorno = 0;
    }
    else
    {
        printf("\n--No se pudo guardar el archivo--\n");
    }
    fclose(f);
    return retorno;
}




int controller_contarPorPrecio(LinkedList* pArrayListVenta, int* cantidad, int* cantidad2, int* cantidadVendidos, int* cantidadModelo)
{
	int cantidadTotal1 = 0;
	int cantidadTotal2 = 0;
	int cantidadUnidadesVendidas = 0;
	int cantidadModelos = 0;
	int retorno = -1;
	int len;
	len = ll_len(pArrayListVenta);

	if(pArrayListVenta != NULL && len > 0)
	{
		cantidadTotal1 = ll_count(pArrayListVenta, ventaContadorMayorADiezMil);
		cantidadTotal2 = ll_count(pArrayListVenta, ventaContadorMayorAVeinteMil);
		cantidadUnidadesVendidas = ll_count(pArrayListVenta, ventaAcumuladorUnidadesVendidas);
		cantidadModelos = ll_count(pArrayListVenta, ventaAcumuladorVentasDeModelo);
		if(cantidadTotal1 > 0){
			*cantidad = cantidadTotal1;
		}

		if(cantidadTotal2 > 0)
		{
			*cantidad2 = cantidadTotal2;
		}

		if(cantidadUnidadesVendidas > 0)
		{
			*cantidadVendidos = cantidadUnidadesVendidas;
		}

		if(cantidadModelos > 0)
		{
			*cantidadModelo = cantidadModelos;
		}
	}
	return retorno;
}


//
///** \brief Modificar datos del jugador
// *
// * \param path char*
// * \param pArrayListJugador LinkedList*
// * \return int
// *
// */
//int controller_editarJugador(LinkedList* pArrayListJugador)
//{
//	int opcion;
//	int menu;
//	int indice;
//	int retorno = -1;
//	char auxiliarNombre[30];
//	int auxiliarEdad;
//	char auxiliarPosicion[30];
//	char auxiliarNacionalidad[30];
//	Jugador* pJugador = NULL;
//
//	if(pArrayListJugador != NULL && ll_len(pArrayListJugador) != 0)
//	{
//
//		if(controller_listarJugadores(pArrayListJugador) == 0)
//		{
//
//			if(utn_getNumero(&opcion, "\nIngrese el ID que desea modificas", "\nError al ingresar ID a modificar", 1, 10000, 2) == 0)
//			{
//
//				indice = encontrarjugador(pArrayListJugador, opcion);
//
//				if(indice != 1)
//				{
//					pJugador = (Jugador*)ll_get(pArrayListJugador, indice);
//
//					if(pJugador != NULL)
//					{
//
//						if(utn_getNumero(&menu, "\n          Menu de modificar"
//													"\n1-Modificar nombre"
//													"\n2-Modificar edad"
//													"\n3-Modificar posicion"
//													"\n4-Modificar nacionalidad"
//													,"Error ingrese las opciones que se muestran en el menu", 1,4, 2)==0)
//						{
//							switch(menu)
//							{
//							case 1:
//								if(utn_getNombre(auxiliarNombre, 30, "\nIngrese el nuevo nombre", "\nError", 2) == 0)
//								{
//									jug_setNombreCompleto(pJugador, auxiliarNombre);
//									retorno = 0;
//								}
//								break;
//							case 2:
//								if(utn_getNumero(&auxiliarEdad, "\nIngrese la nueva edad", "\nError al ingresar nueva edad", 18, 50, 2) == 0)
//								{
//									jug_setEdad(pJugador, auxiliarEdad);
//									retorno = 0;
//								}
//								break;
//							case 3:
//								if(utn_getNombre(auxiliarPosicion, 30, "\nIngrese la nueva posicion", "\nError", 2) == 0)
//								{
//									jug_setPosicion(pJugador, auxiliarPosicion);
//									retorno = 0;
//								}
//								break;
//							case 4:
//								if(utn_getNombre(auxiliarNacionalidad, 30, "\nIngrese la nueva nacionalidad", "\nError al ingresar la nueva nacionalidad", 2) == 0)
//								{
//									jug_setNacionalidad(pJugador, auxiliarNacionalidad);
//									retorno = 0;
//								}
//								break;
//
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//
//		return retorno;
//}
//
//
///** \brief Baja del jugador
// *
// * \param path char*
// * \param pArrayListJugador LinkedList*
// * \return int
// *
// */
int controller_removerJugador(LinkedList* pArrayListVenta)
{
	int retorno = -1;
	Venta* pJugador = NULL;
	int idBuscado;
	int indice;

		if(pArrayListVenta != NULL && ll_len(pArrayListVenta) >= 0)
		{

			if(controller_listarJugadores(pArrayListVenta) == 0)
			{

				utn_getNumero(&idBuscado, "\nIngrese el ID que desea eliminar", "\nError al eliminar el id", 1, 10000, 2);

				indice = encontrarVenta(pArrayListVenta, idBuscado);

				if(indice != -1)
				{
					pJugador = (Venta*)ll_get(pArrayListVenta, indice);
					ll_remove(pArrayListVenta, indice);
					venta_delete(pJugador);
					printf("\nEmpleado eliminado correctamente\n");
					retorno = 0;
				}else
				{
					printf("\nUsted no dio a nadie de baja");
				}
			}

		}
    return retorno;
}

