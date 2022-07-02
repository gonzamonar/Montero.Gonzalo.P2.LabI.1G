/*
 * Controller.c
 *
 *  Created on: Jul 1, 2022
 *      Author: GM
 */


#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Movies.h"
#include "View.h"
#include "parser.h"
#include "IO.h"
#include "filters.h"

#define SUCCESS 1
#define FAILURE 0



/** \brief Carga los datos de las películas desde el archivo movies.csv (modo texto).
 *
 * \param path char*
 * \param pMovieList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pMovieList)
{
	int outcome = FAILURE;

	FILE* f = fopen(path, "r");
	if(f==NULL){
		printf("   No se pudo abrir el archivo.\n");
	}else{
		parser_MovieFromText(f, pMovieList);
		outcome = SUCCESS;
		printf("\n  Carga exitosa.");
	}
	fclose(f);
    return outcome;
}



/** \brief Guarda los datos de los pasajeros en el archivo movies.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pMovieList)
{
	int outcome = FAILURE;

	FILE* f = fopen(path, "w");
	eMovie* buffer = NULL;

	if(f!=NULL)
	{
		int len = ll_len(pMovieList);
		fprintf(f, "id_peli,titulo,genero,duracion\n");
		for(int i=0; i<len; i++)
		{
			buffer = (eMovie*) ll_get(pMovieList, i);
			fprintf(f, "%d,%s,%s,%d\n", buffer->id,buffer->titulo,buffer->genero,buffer->duracion);
		}
		outcome = SUCCESS;
		printf("\n  Archivo guardado exitosamente.");
	}
	else
	{
		printf("   No se pudo acceder al archivo.\n");
	}
	fclose(f);
	view_pause();
    return outcome;
}


int controller_ListMovies(LinkedList* pMovieList)
{
	int outcome = FAILURE;
	if(pMovieList != NULL)
	{
		eMovie* movie;
		view_movieTable_header();
		int len = ll_len(pMovieList);
		for(int i=0; i<len; i++)
		{
			movie = (eMovie*) ll_get(pMovieList, i);
			view_printMovieRow(movie);
		}
		view_movieTable_footer();
		outcome = SUCCESS;
	}
    return outcome;
}



/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_filterMovies(LinkedList* pMovieList)
{
	int criteria = 12;

	system("cls");
	view_printFilterMenu(&criteria);
	if(criteria != 12)
	{
		LinkedList* ListaFiltrada;
		switch(criteria)
		{
			case 1: // Acción
					ListaFiltrada = ll_filter(pMovieList, filtrar_genre_Action);
					controller_saveAsText("films_accion.csv", ListaFiltrada);
					break;

			case 2: // Aventuras
					ListaFiltrada = ll_filter(pMovieList, filtrar_genre_Adventure);
					controller_saveAsText("films_aventuras.csv", ListaFiltrada);
					break;

			case 3: // Animación
					ListaFiltrada = ll_filter(pMovieList, filtrar_genre_Animation);
					controller_saveAsText("films_animacion.csv", ListaFiltrada);
					break;

			case 4: // Comedia
					ListaFiltrada = ll_filter(pMovieList, filtrar_genre_Comedy);
					controller_saveAsText("films_comedia.csv", ListaFiltrada);
					break;

			case 5: // Documental
					ListaFiltrada = ll_filter(pMovieList, filtrar_genre_Documentary);
					controller_saveAsText("films_documental.csv", ListaFiltrada);
					break;

			case 6: // Drama
					ListaFiltrada = ll_filter(pMovieList, filtrar_genre_Drama);
					controller_saveAsText("films_drama.csv", ListaFiltrada);
					break;

			case 7: // Horror
					ListaFiltrada = ll_filter(pMovieList, filtrar_genre_Horror);
					controller_saveAsText("films_horror.csv", ListaFiltrada);
					break;

			case 8: // Musical
					ListaFiltrada = ll_filter(pMovieList, filtrar_genre_Musical);
					controller_saveAsText("films_musical.csv", ListaFiltrada);
					break;

			case 9: // Romance
					ListaFiltrada = ll_filter(pMovieList, filtrar_genre_Romance);
					controller_saveAsText("films_romance.csv", ListaFiltrada);
					break;

			case 10: // Thriller
					ListaFiltrada = ll_filter(pMovieList, filtrar_genre_Thriller);
					controller_saveAsText("films_thriller.csv", ListaFiltrada);
					break;

			case 11: // Western
					ListaFiltrada = ll_filter(pMovieList, filtrar_genre_Western);
					controller_saveAsText("films_western.csv", ListaFiltrada);
					break;
		}
		ll_deleteLinkedList(ListaFiltrada);
	}
	fflush(stdin);
    return SUCCESS;
}



int controller_exit(LinkedList* pMovieList, int* selection)
{
	char confirmation;
	int outcome = FAILURE;

	IO_getConfirm(&confirmation, "\n  ¿Confirma que desea salir? S/N: ", "  Opción inválida.", 1);
	if(confirmation == 'S')
	{
		*selection = 7;
		ll_deleteLinkedList(pMovieList);
		printf("\n  Ejecución concluida.");
		outcome = SUCCESS;
	}
	return outcome;
}
