/*
 * Validaciones.h
 *
 *  Created on: 15 nov. 2022
 *      Author: nicolas
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


int esNumerica(char cadena[]);
int getInt(int *pResultado);
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroShort(short *pResultado, char *mensaje, char *mensajeError,int minimo, int maximo, int reintentos);
int getFloat(float* pResultado);
int esFlotante(char* cadena);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int getString(char* cadena, int longitud);
int esDescripcion(char* cadena,int longitud);
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int esNombre(char* cadena,int longitud);
int getNombre(char* pResultado, int longitud);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int isValidDNI(char* stringRecibido);
int getStringg(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
int utn_getTarjetaCredito(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input);

#endif /* VALIDACIONES_H_ */
