#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"
#include "Controller.h"
#include "Ventas.h"

/** \brief Carga los datos de las ventas desde el archivo MOCK_DATA.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
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
				printf("\nEl archivo de texto se leyo corrrectamente\n");
				retorno = 0;
			}else
			{
				printf("\nError al leer al archivo  texto");
			}
		}
		fclose(pArchivo);
	}
    return retorno;
}



/** \brief Listar ventas
 *
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */

int controller_listarVentas(LinkedList* pArrayListVenta)
{
	int retorno = -1;
	Venta* pJugador = NULL;

    	if(pArrayListVenta != NULL)
    	{
    		printf("|%5s|%10s|%20s|%20s|%20s|%20s|\n", "ID", "Fecha_venta", "Modelo",
    															"Cantidad", "Precio_Unitario", "Tarjeta de credito");

    		 ll_sort(pArrayListVenta , ordenarID, 1);
    		for(int i = 0; i < ll_len(pArrayListVenta); i++)
    		{
    			pJugador = (Venta*)ll_get(pArrayListVenta, i);

    			if(pJugador != NULL)
    			{
    				if(imprimirVenta(pArrayListVenta,i) == 0)
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



/** \brief Alta de venta
 *
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListVenta)
{
	int retorno = -1;
	int id;
	int fecha_dia;
	int fecha_mes;
	int fecha_anio;
    char axuModelo[200];
    int cantidad;
    float auxPrecio;
    char tarjeta_credito[30];
    Venta* pJugador = NULL;

	if(pArrayListVenta != NULL && ll_len(pArrayListVenta) >= 0)
	{
		if(utn_getNumero(&fecha_dia, "\nIngrese el dia del 1 al 30", "\nError",1, 30, 2) == 0
		 && utn_getNumero(&fecha_mes, "\nIngrese el mes del 1 al 12", "\nError",1, 12, 2) == 0
		 && utn_getNumero(&fecha_anio, "\nIngrese el anio del 2000 al 2023", "\nError",1000, 2023, 2) == 0
		 && elegirModeloDeAuto(axuModelo) == 0
		 && utn_getNumero(&cantidad, "\nIngrese la cantidad del 1 al 30", "\nError",1, 30, 2) == 0
		 && utn_getNumeroFlotante(&auxPrecio, "\nIngrese el precio del 2000 al 40000", "\nError", 1, 800000, 2) == 0
		 && utn_getTarjetaCredito("\nIngrese 16 numeros de su tarjeta de credito", "\nError", 16, 17, 2, tarjeta_credito) == 0)
		{

		id =idAutoincremental();
			pJugador = venta_new();

			if(pJugador != NULL)
			{
				if(venta_setId(pJugador, id)
					&& venta_setModelo(pJugador,  axuModelo)
					&& venta_setFecha_dia(pJugador, fecha_dia)
					&& venta_setFecha_mes(pJugador, fecha_mes)
					&& venta_setFecha_anio(pJugador, fecha_anio)
					&& venta_setCantidad(pJugador, cantidad)
					&& venta_setPrecio_unitario(pJugador, auxPrecio)
					&& venta_setTarjeta_credito(pJugador, tarjeta_credito))
				{
					if(ll_add(pArrayListVenta, pJugador) == 0)
					{
						retorno = 0;
						printf("\nVenta cargado correctamente");
					}
				}else
				{
					printf("\nAlgo salio mal");
				}
			}
		}else
		{
			printf("\nNo es posible cargar la venta");
		}
	}
    return retorno;
}




//
///** \brief Modificar datos de la venta
// *
// * \param path char*
// * \param pArrayListVenta LinkedList*
// * \return int
// *
// */
int controller_editarJugador(LinkedList* pArrayListVenta)
{
	int opcion;
	int menu;
	int indice;
	int retorno = -1;
	char auxiliarModelo[30];
	int auxiliarCantidad;
	int fechaDia;
	int fechaMes;
	int fechaAnio;
	float auxPrecio;
	Venta* pVenta = NULL;

	if(pArrayListVenta != NULL && ll_len(pArrayListVenta) != 0)
	{

		if(controller_listarVentas(pArrayListVenta) == 0)
		{

			if(utn_getNumero(&opcion, "\nIngrese el ID que desea modificas", "\nError al ingresar ID a modificar", 1, 10000, 2) == 0)
			{

				indice = encontrarVenta(pArrayListVenta, opcion);

				if(indice != 1)
				{
					pVenta = (Venta*)ll_get(pArrayListVenta, indice);

					if(pVenta != NULL)
					{

						if(utn_getNumero(&menu, "\n          Menu de modificar"
													"\n1-Modificar fecha"
													"\n2-Modificar modelo de auto"
													"\n3-Modificar cantidad"
													"\n4-Modificar precio unitario"
													"'n5-Modificar tarjeta de credito"
													,"Error ingrese las opciones que se muestran en el menu", 1,4, 2)==0)
						{
							switch(menu)
							{
							case 1:
								if(utn_getNumero(&fechaDia,"\nIngrese el dia a modificar", "\nError", 1, 30, 2) == 0
								&& 	utn_getNumero(&fechaMes,"\nIngrese el mes a modificar", "\nError", 1, 12, 2) == 0
								&& utn_getNumero(&fechaAnio,"\nIngrese el dia a modificar", "\nError", 1000, 2023, 2) == 0)
								{
									venta_setFecha_dia(pVenta, fechaDia);
									venta_setFecha_mes(pVenta, fechaMes);
									venta_setFecha_anio(pVenta, fechaAnio);
									retorno = 0;
								}
								break;
							case 2:
								if(utn_getNombre(auxiliarModelo, 30, "\nIngrese el nuevo nombre", "\nError", 2) == 0)
								{
									venta_setModelo(pVenta, auxiliarModelo);
									retorno = 0;
								}
								break;
							case 3:
								if(utn_getNumero(&auxiliarCantidad, "\nIngrese la nueva cantidad", "\nError al ingresar nueva cantidad", 1, 50, 2) == 0)
								{
									venta_setCantidad(pVenta, auxiliarCantidad);
									retorno = 0;
								}
								break;
							case 4:
								if(utn_getNumeroFlotante(&auxPrecio, "\nIngrese el nuevo precio", "\nError", 1, 30000, 2) == 0)
								{
									venta_setPrecio_unitario(pVenta, auxPrecio);
									retorno = 0;
								}
								break;

							}
						}
					}
				}
			}
		}
	}

		return retorno;
}






///** \brief Baja de venta
// *
// * \param path char*
// * \param pArrayListVenta LinkedList*
// * \return int
// *
// */
int controller_removerVenta(LinkedList* pArrayListVenta)
{
	int retorno = -1;
	Venta* pVenta = NULL;
	int idBuscado;
	int indice;

		if(pArrayListVenta != NULL && ll_len(pArrayListVenta) >= 0)
		{

			if(controller_listarVentas(pArrayListVenta) == 0)
			{

				if(utn_getNumero(&idBuscado, "\nIngrese el ID que desea eliminar", "\nError al eliminar el id", 1, 10000, 2) == 0)
				{

					indice = encontrarVenta(pArrayListVenta, idBuscado);

						if(indice != -1)
						{
							pVenta = (Venta*)ll_get(pArrayListVenta, indice);
							if(pVenta != NULL)
							{
								ll_remove(pArrayListVenta, indice);
								venta_delete(pVenta);
								printf("\nEmpleado eliminado correctamente\n");
								retorno = 0;
							}
						}else
						{
							printf("\nUsted no dio a nadie de baja");
						}
				}
			}

		}
    return retorno;
}





/** \brief Guarda los datos de las ventas en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_GuardarComoTexto(char* path, LinkedList* pArrayListVenta)
{
    FILE* f;
    int retorno = -1;
    int cantidadDiezMil;
    int cantidadVeinteMil;
    int cantidadUnidadesVendidas;
    int cantidadVentaPorModelo;

    f = fopen(path, "w");
    if(f != NULL && ll_len(pArrayListVenta) > 0)
    {
        fprintf(f, "******************");
        fprintf(f, "INFORMES DE VENTA");
        fprintf(f, "******************");

       if( controller_contarPorPrecio(pArrayListVenta ,  &cantidadDiezMil , &cantidadVeinteMil, &cantidadUnidadesVendidas, &cantidadVentaPorModelo) == 0)
       {
           fprintf(f, "\n-Cantidad de unidades vendidas totales: %d",cantidadUnidadesVendidas);
           fprintf(f, "\n-Cantidad de ventas por un monto mayor a $10000: %d",cantidadDiezMil);
           fprintf(f, "\n-Cantidad de ventas por un monto mayor a $20000: %d",cantidadVeinteMil);
           fprintf(f, "\n-Cantidad de unidades vendidas para la ram 3500: %d",cantidadVentaPorModelo);

           printf("\n--Archivo guardado--\n");
           retorno = 0;
       }
       else
       {
    	   printf("\nAlgo salio mal");
       }
    }
    else
    {
        printf("\n--No se pudo guardar el archivo--\n");
    }
    fclose(f);
    return retorno;
}




int controller_contarPorPrecio(LinkedList* pArrayListVenta, int* cantidadDiez, int* cantidadVeinte, int* cantidadVendidos, int* cantidadModelo)
{
	int cantidadDiezMil = 0;
	int cantidadVeinteMil = 0;
	int cantidadUnidadesVendidas = 0;
	int cantidaVendidasUndModelo = 0;
	int retorno = -1;
	int len;
	len = ll_len(pArrayListVenta);

	if(pArrayListVenta != NULL && len > 0)
	{
		cantidadDiezMil = ll_count(pArrayListVenta, ventaContadorMayorADiezMil);

		cantidadVeinteMil = ll_count(pArrayListVenta, ventaContadorMayorAVeinteMil);

		cantidadUnidadesVendidas = ll_count(pArrayListVenta, ventaAcumuladorUnidadesVendidas);

		cantidaVendidasUndModelo = ll_count(pArrayListVenta, ventaAcumuladorVentasDeModelo);

		if(cantidadDiezMil < 0 && cantidadVeinteMil < 0 && cantidadUnidadesVendidas < 0 && cantidaVendidasUndModelo < 0)
		{
			printf("\nAlgo salio mal");
		}else
		{
			*cantidadDiez = cantidadDiezMil;
			*cantidadVeinte = cantidadVeinteMil;
			*cantidadVendidos = cantidadUnidadesVendidas;
			*cantidadModelo = cantidaVendidasUndModelo;
			retorno = 0;
		}

	}
	return retorno;
}







/** \brief Guarda los datos de las ventas en el archivo MOCK_DATA.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_guardarVentasModoTexto(char* path , LinkedList* pArrayListVenta)
{
	int retorno = -1;
	int limite;
	Venta* auxiliarJugador = NULL;
	FILE* pArchivo;
	int axuId;
	int fecha_dia;
	int fecha_mes;
	int fecha_anio;
    char axuModelo[30];
    int cantidad;
    float auxPrecio;
    char tarjeta_credito[30];
	int i;

		if(path != NULL && pArrayListVenta !=NULL)
		{
			pArchivo = fopen(path, "w");

			if(pArchivo != NULL)
			{
				limite = ll_len(pArrayListVenta);
				fprintf(pArchivo, "id,fecha_venta,modelo,cantidad,precio_unitario,tarjeta_de_credito\n");
				for(i=0 ; i < limite; i++)
				{
					auxiliarJugador = ll_get(pArrayListVenta, i);

					if(auxiliarJugador != NULL)
					{
						if(venta_getId(auxiliarJugador, &axuId) == 1
								&& venta_getFecha_dia(auxiliarJugador, &fecha_dia) == 1
								&& venta_getFecha_mes(auxiliarJugador, &fecha_mes) == 1
								&& venta_getFecha_anio(auxiliarJugador, &fecha_anio) == 1
								&& venta_getCantidad(auxiliarJugador, &cantidad)== 1
								&& venta_getModelo(auxiliarJugador, axuModelo) == 1
								&& venta_getPrecio_unitario(auxiliarJugador, &auxPrecio)==1
								&& venta_getTarjeta_credito(auxiliarJugador, tarjeta_credito) == 1)
						{
						fprintf(pArchivo, "%d, %d/%d/%d , %s, %d , %f , %s\n", axuId, fecha_dia, fecha_mes, fecha_anio, axuModelo, cantidad,auxPrecio ,tarjeta_credito );
						retorno = 0;
						}


					}else
					{
						printf("Algo salio mal");
					}
				}
				fclose(pArchivo);
			}
		}
    return retorno;
}


/** \brief Guarda los datos de las ventas en el archivo binario.
 *
 * \param path char*
 * \param pArrayListVenta LinkedList*
 * \return int
 *
 */
int controller_guardarVentasModoBinario(char* path , LinkedList* pArrayListVenta)
{
	int retorno = -1;
	int limite = ll_len(pArrayListVenta);
	Venta* auxiliarVenta = NULL;
	FILE* pArchivo;
	int retornoWrite;
	int i;

		if(path != NULL && pArrayListVenta !=NULL)
		{
			pArchivo = fopen(path, "wb");

			if(pArchivo != NULL)
			{
				for(i = 0 ; i < limite; i++)
				{
					auxiliarVenta = (Venta*)ll_get(pArrayListVenta, i);

				if(auxiliarVenta != NULL)
				{
					retornoWrite = fwrite(auxiliarVenta, sizeof(Venta), 1, pArchivo);

					if(retornoWrite == 1)
					{
						retorno = 0;
					}else
					{
						break;
					}
				}
			}
				fclose(pArchivo);
		}

	}

    return retorno;
}


/**
 * \brief carga los datos del ultimo id generado en el archivo ID.csv (modo texto).
 * \param char* path
 * \param char* auxiliarID
 * \return 0 bien, -1 ERROR.
**/
int controllerCargarId(char* path, char* auxiliarID)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

		if(path != NULL && auxiliarID != NULL)
		{
			pArchivo = fopen(path,"r");

			if(pArchivo != NULL)
			{
				if(parser_ID(pArchivo, auxiliarID )== 0)
				{
					printf("\nEl archivo se leyo correctamente");
					retorno = 0;
				}else
				{
					printf("\nEl archivo se leyo mal");
				}

			}
		}
	return retorno;
}

