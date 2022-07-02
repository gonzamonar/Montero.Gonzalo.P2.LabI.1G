/*
 * View.c
 *
 *  Created on: Jul 1, 2022
 *      Author: GM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "View.h"
#include "IO.h"
#include "Movies.h"


void view_pause(void){
	char c;
	fflush(stdin);
	printf("\n\n  ***** Presione enter para continuar. *****");
	scanf("%c", &c);
	fflush(stdin);
}


int view_mainMenu(void){
	system("cls");
	int selection = 0;
	printf("\n\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n");
	printf(" |--------------------------------------  *** MENÚ PRINCIPAL ***  --------------------------------------|\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" |                                                                                                      |\n");
	printf(" |  1. CARGAR ARCHIVO                                                                                   |\n");
	printf(" |  2. IMPRIMIR LISTADO                                                                                 |\n");
	printf(" |  3. ASIGNAR TIEMPOS                                                                                  |\n");
	printf(" |  4. FILTRAR POR TIPO                                                                                 |\n");
	printf(" |  5. MOSTRAR DURACIONES                                                                               |\n");
	printf(" |  6. GUARDAR PELICULAS                                                                                |\n");
	printf(" |  7. SALIR                                                                                            |\n");
	printf(" |                                                                                                      |\n");
	printf(" |------------------------------------------------------------------------------------------------------|\n");
	printf(" +------------------------------------------------------------------------------------------------------+\n\n");
	fflush(stdin);
	IO_getMenuSelection(&selection, "  Elija una opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.\n", 1, 10);
	return selection;
}



void view_movieTable_header(){
		system("cls");
		printf("\n\n");
		printf(" +----------------------------------------------------------------------------------------------------------+\n");
		printf(" |-------------------------------------  *** LISTADO DE PELICULAS ***  -------------------------------------|\n");
		printf(" |----------------------------------------------------------------------------------------------------------|\n");
		printf("  %5s | %50s | %28s | %10s  \n", "ID ", "Titulo", "Género", "Duración");
		printf(" +----------------------------------------------------------------------------------------------------------+\n");
}


void view_movieTable_footer(){
		printf(" +----------------------------------------------------------------------------------------------------------+\n");
}


void view_printMovieRow(eMovie* movie){
	eMovie buffer;

	Movie_getId(movie, &buffer.id);
	Movie_getTitulo(movie, buffer.titulo);
	Movie_getGenero(movie, buffer.genero);
	Movie_getDuracion(movie, &buffer.duracion);

	printf("  %5d | %50s | %28s | %10d  \n", buffer.id, buffer.titulo, buffer.genero, buffer.duracion);
}


int view_printFilterMenu(int* option){
	int outcome = 1;
	if(option != NULL){
		printf("\n  ¿Por qué género desea filtrar?\n");
		printf("     1. Acción\n");
		printf("     2. Aventuras\n");
		printf("     3. Animación\n");
		printf("     4. Comedia\n");
		printf("     5. Documental\n");
		printf("     6. Drama\n");
		printf("     7. Horror\n");
		printf("     8. Musical\n");
		printf("     9. Romance\n");
		printf("    10. Thriller\n");
		printf("    11. Western\n");
		printf("    *SALIDA*\n");
		printf("    12. Volver al Menú Principal\n");
		if(!IO_getInteger(option, "\n  Elija el nº de opción: ", "\n  Opción de menú incorrecta, inténtelo nuevamente.", 1, 12, 3) || *option == 12){
			outcome = 0;
		}
	}
	return outcome;
}
