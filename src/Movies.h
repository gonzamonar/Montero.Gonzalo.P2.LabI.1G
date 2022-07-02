/*
 * Movies.h
 *
 *  Created on: Jul 1, 2022
 *      Author: GM
 */

#ifndef MOVIES_H_
#define MOVIES_H_

typedef struct
{
	int id;
	char titulo[50];
	char genero[30];
	int duracion;
}eMovie;

#endif /* MOVIES_H_ */


eMovie* Movie_new(void);
eMovie* Movie_newParametros(int id, char* titulo, char* genero, int duracion);
void Movie_delete(eMovie* this);
int Movie_setId(eMovie* this, int id);
int Movie_getId(eMovie* this, int* id);
int Movie_setTitulo(eMovie* this, char* titulo);
int Movie_getTitulo(eMovie* this, char* titulo);
int Movie_setGenero(eMovie* this, char* genero);
int Movie_getGenero(eMovie* this, char* genero);
int Movie_setDuracion(eMovie* this, int duracion);
int Movie_getDuracion(eMovie* this, int* duracion);
void* Movie_randomizeDuration(void* element);
