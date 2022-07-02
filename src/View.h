/*
 * View.h
 *
 *  Created on: Jul 1, 2022
 *      Author: GM
 */

#ifndef VIEW_H_
#define VIEW_H_

#include "Movies.h"

#endif /* VIEW_H_ */


void view_pause(void);
int view_mainMenu(void);
void view_movieTable_header();
void view_movieTable_footer();
void view_printMovieRow(eMovie* movie);
int view_printFilterMenu(int* option);
