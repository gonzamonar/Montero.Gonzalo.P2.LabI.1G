/*
 * Controller.h
 *
 *  Created on: Jul 1, 2022
 *      Author: GM
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */


int controller_loadFromText(char* path, LinkedList* pMovieList);
int controller_saveAsText(char* path , LinkedList* pMovieList);
int controller_ListMovies(LinkedList* pMovieList);
int controller_filterMovies(LinkedList* pMovieList);
int controller_exit(LinkedList* pMovieList, int* selection);
