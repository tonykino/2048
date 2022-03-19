#ifndef VECTOR_CONVERSIONS_H
# define VECTOR_CONVERSIONS_H
# include "board_movement.h"


//fonction qui prends un enum en entrée et donne un vector contenant les incréments à appliquer à des coordonnés
//pour parcourir le tableau
t_vector enum_to_vector(enum_dir direction);
//fonction qui donne les coordonnées de départ du check en fonction de la direction
t_vector get_start(enum_dir direction, t_board * board);

#endif
