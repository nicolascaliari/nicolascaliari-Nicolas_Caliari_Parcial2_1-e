/*
 * Parser.h
 *
 *  Created on: 15 nov. 2022
 *      Author: nicolas
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_AutoFromBinary(FILE* pFile, LinkedList* pArrayListJugador);
int parser_AutoFromText(FILE* pFile , LinkedList* pArrayListAuto);
#endif /* PARSER_H_ */
