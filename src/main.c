/*
 ============================================================================
 Name        : SP_Laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include "LinkedList.h"
#include "Movies.h"
#include "IO.h"
#include "View.h"
#include "Controller.h"
#include "sorters.h"

/****************************************************
    Menu:
     1. Cargar archivo CSV
     2. Imprimir lista
     3. Asignar Tiempos
     4. Filtrar por tipo
     5. Mostrar duraciones
     6. Guardar películas
     7. Salir
*****************************************************/

int main(void) {
	int selection;
	int loadFlag = 0;

	setbuf(stdout, NULL);
	setlocale(LC_ALL, "");
	chdir("..");
	char filename[20];

	LinkedList* listaPeliculas = ll_newLinkedList();

    do{
        switch(view_mainMenu())
        {
			case 1: //Cargar archivo data.csv
					if(IO_getString(filename, 20, 20, 1, "  Ingrese el nombre del archivo que desea cargar (sin la extensión \".csv\"): ", "  Nombre inválido.\n", 3, "")){
						strcat(filename, ".csv");
						if(controller_loadFromText(filename, listaPeliculas)){
							loadFlag = 1;
						}
					}
					view_pause();
					break;

			case 2: //Imprimir lista
					(loadFlag) ? ll_sort(listaPeliculas, sorter_ID, 1) , controller_ListMovies(listaPeliculas) : printf("\n  Debe cargar un archivo antes de imprimir la lista.");
					view_pause();
					break;

			case 3: //Asignar tiempos
					if(loadFlag){
						listaPeliculas = ll_map(listaPeliculas, Movie_randomizeDuration);
					}else{
						printf("\n  Debe cargar un archivo antes de asignar duración.");
					}
					view_pause();
					break;

			case 4: //Filtrar por tipos
					controller_filterMovies(listaPeliculas);
					break;

			case 5: //Mostrar duraciones
					(loadFlag) ? ll_sort(listaPeliculas, sorter_genre_durationDES, 1) , controller_ListMovies(listaPeliculas) : printf("\n  Debe cargar un archivo antes de imprimir la lista.");
					view_pause();
					break;

			case 6: //Guardar peliculas
					if(IO_getString(filename, 20, 20, 1, "  Ingrese el nombre para guardar el archivo (sin la extensión \".csv\"): ", "  Nombre inválido.\n", 3, "")){
						strcat(filename, ".csv");
						controller_saveAsText(filename, listaPeliculas);
					}
					break;

			case 7: //salir
					controller_exit(listaPeliculas, &selection);
					view_pause();
					break;

			default:
					view_pause();
					break;
        }
    }while(selection != 7);
    return 0;
}
