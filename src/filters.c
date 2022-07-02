/*
 * filters.c
 *
 *  Created on: Jul 1, 2022
 *      Author: GM
 */

#include <string.h>
#include "Movies.h"

int filtrar_genre_Action(void* pElement){
	eMovie* film = (eMovie*) pElement;
	if(strcmp(film->genero, "Action")==0){
		return 1;
	}else{
		return 0;
	}
}

int filtrar_genre_Adventure(void* pElement){
	eMovie* film = (eMovie*) pElement;
	if(strcmp(film->genero, "Adventure")==0){
		return 1;
	}else{
		return 0;
	}
}


int filtrar_genre_Animation(void* pElement){
	eMovie* film = (eMovie*) pElement;
	if(strcmp(film->genero, "Animation")==0){
		return 1;
	}else{
		return 0;
	}
}



int filtrar_genre_Comedy(void* pElement){
	eMovie* film = (eMovie*) pElement;
	if(strcmp(film->genero, "Comedy")==0){
		return 1;
	}else{
		return 0;
	}
}


int filtrar_genre_Documentary(void* pElement){
	eMovie* film = (eMovie*) pElement;
	if(strcmp(film->genero, "Documentary")==0){
		return 1;
	}else{
		return 0;
	}
}


int filtrar_genre_Drama(void* pElement){
	eMovie* film = (eMovie*) pElement;
	if(strcmp(film->genero, "Drama")==0){
		return 1;
	}else{
		return 0;
	}
}


int filtrar_genre_Horror(void* pElement){
	eMovie* film = (eMovie*) pElement;
	if(strcmp(film->genero, "Horror")==0){
		return 1;
	}else{
		return 0;
	}
}

int filtrar_genre_Musical(void* pElement){
	eMovie* film = (eMovie*) pElement;
	if(strcmp(film->genero, "Musical")==0){
		return 1;
	}else{
		return 0;
	}
}

int filtrar_genre_Romance(void* pElement){
	eMovie* film = (eMovie*) pElement;
	if(strcmp(film->genero, "Romance")==0){
		return 1;
	}else{
		return 0;
	}
}

int filtrar_genre_Thriller(void* pElement){
	eMovie* film = (eMovie*) pElement;
	if(strcmp(film->genero, "Thriller")==0){
		return 1;
	}else{
		return 0;
	}
}

int filtrar_genre_Western(void* pElement){
	eMovie* film = (eMovie*) pElement;
	if(strcmp(film->genero, "Western")==0){
		return 1;
	}else{
		return 0;
	}
}
