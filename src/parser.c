

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Movies.h"
#include "parser.h"

#define SUCCESS 1
#define FAILURE 0


/** \brief Parsea los datos los datos de las películas desde el archivo movies.csv (modo texto).
 *
 * \param path char*
 * \param pMoviesList LinkedList*
 * \return int
 *
 */
int parser_MovieFromText(FILE* pFile, LinkedList* pMoviesList)
{
	eMovie buffer;
	int outcome = FAILURE;
	int r;
	char id[20];
	char duracion[20];
	char readHeader[512];

	if(pFile != NULL && pMoviesList != NULL)
	{
		outcome = SUCCESS;
		fscanf(pFile, "%s\n", readHeader);
		do{
			r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, buffer.titulo, buffer.genero, duracion);
			buffer.id = atoi(id);
			buffer.duracion = atoi(duracion);
			if(r==4)
			{
				eMovie* movieAux = Movie_newParametros(buffer.id, buffer.titulo, buffer.genero, buffer.duracion);
				ll_add(pMoviesList, (void*) movieAux);
			}
			else
			{
				outcome = FAILURE;
				break;
			}
		}while(!feof(pFile));
	}
    return outcome;
}

