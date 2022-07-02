/*
 * sorters.c
 *
 *  Created on: Jun 11, 2022
 *      Author: GM
 */

#include <string.h>
#include "Movies.h"


int sorter_ID(void* A, void* B)
{
	eMovie* a = (eMovie*) A;
	eMovie* b = (eMovie*) B;
	int comparison = 0;
	if(a->id > b->id)
	{
		comparison = 1;
	}
	else if(a->id < b->id)
	{
		comparison = -1;
	}
	return comparison;
}

int sorter_genre(void* A, void* B)
{
	eMovie* a = (eMovie*) A;
	eMovie* b = (eMovie*) B;
	return strcmp(a->genero,b->genero);
}


int sorter_duration(void* A, void* B)
{
	eMovie* a = (eMovie*) A;
	eMovie* b = (eMovie*) B;
	int comparison = 0;
	if(a->duracion > b->duracion)
	{
		comparison = 1;
	}
	else if(a->duracion < b->duracion)
	{
		comparison = -1;
	}
	return comparison;
}


int sorter_genre_durationASC(void* A, void* B)
{
	int comparison = sorter_genre(A, B);
	if(comparison == 0){
		comparison = sorter_duration(A, B);
	}
	return comparison;
}

int sorter_genre_durationDES(void* A, void* B)
{
	int comparison = sorter_genre(A, B);
	if(comparison == 0){
		comparison = sorter_duration(A, B)*-1;
	}
	return comparison;
}
