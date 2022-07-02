/*
 * Movies.c
 *
 *  Created on: Jul 1, 2022
 *      Author: GM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Movies.h"
#include "my_ctype.h"

#define SUCCESS 1
#define FAILURE 0

eMovie* Movie_new(void){
	eMovie* newMovie = (eMovie*) malloc(sizeof(eMovie));
	if(newMovie != NULL){
		newMovie->id = 0;
		strcpy(newMovie->titulo,"");
		strcpy(newMovie->genero, "");
		newMovie->duracion = 0;
	}
	return newMovie;
}


eMovie* Movie_newParametros(int id, char* titulo, char* genero, int duracion){
	eMovie* newMovie = Movie_new();

	if((Movie_setId(newMovie, id)
	   && Movie_setTitulo(newMovie, titulo)
	   && Movie_setGenero(newMovie, genero)
	   && Movie_setDuracion(newMovie, duracion))){
	}else{
		free(newMovie);
		newMovie = NULL;
	}
	return newMovie;
}


void Movie_delete(eMovie* this){
	free(this);
}


int Movie_setId(eMovie* this, int id){
	int outcome = FAILURE;
	if(this != NULL){
		this->id = id;
		outcome = SUCCESS;
	}
	return outcome;
}


int Movie_getId(eMovie* this, int* id){
	int outcome = FAILURE;
	if(this != NULL){
		*id = this->id;
		outcome = SUCCESS;
	}
	return outcome;
}


int Movie_setTitulo(eMovie* this, char* titulo){
	int outcome = FAILURE;
	if(this != NULL && titulo != NULL){
		totitle(titulo);
		strcpy(this->titulo, titulo);
		outcome = SUCCESS;
	}
	return outcome;
}


int Movie_getTitulo(eMovie* this, char* titulo){
	int outcome = FAILURE;
	if(this != NULL && titulo != NULL){
		strcpy(titulo, this->titulo);
		outcome = SUCCESS;
	}
	return outcome;
}


int Movie_setGenero(eMovie* this, char* genero){
	int outcome = FAILURE;
	if(this != NULL && genero != NULL){
		totitle(genero);
		strcpy(this->genero, genero);
		outcome = SUCCESS;
	}
	return outcome;
}


int Movie_getGenero(eMovie* this, char* genero){
	int outcome = FAILURE;
	if(this != NULL && genero != NULL){
		strcpy(genero, this->genero);
		outcome = SUCCESS;
	}
	return outcome;
}


int Movie_setDuracion(eMovie* this, int duracion){
	int outcome = FAILURE;
	if(this != NULL){
		this->duracion = duracion;
		outcome = SUCCESS;
	}
	return outcome;
}


int Movie_getDuracion(eMovie* this, int* duracion){
	int outcome = FAILURE;
	if(this != NULL){
		*duracion = this->duracion;
		outcome = SUCCESS;
	}
	return outcome;
}


void* Movie_randomizeDuration(void* element){
	int duration;
	int min = 100;
	int max = 240;

	eMovie* new_element = (eMovie*) element;
	int i = new_element->id;
	srand(i*time(NULL));
	duration = (rand() % (max - min + 1) + min);
	Movie_setDuracion(new_element, duration);

	printf("   Film: %2d. %-30s | Duración: %d.\n", new_element->id, new_element->titulo, new_element->duracion);

	return (void*) new_element;
}
