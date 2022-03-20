#ifndef BOARD_H
#define BOARD_H

#include "libft.h"
#include <stdbool.h>
#include "struct.h"

#define BORDER_PAIR		1
#define VALUE2_PAIR		2
#define VALUE4_PAIR		4
#define VALUE8_PAIR		8
#define VALUE16_PAIR	16
#define VALUE32_PAIR	32
#define VALUE64_PAIR	64
#define VALUE128_PAIR	128
#define VALUE256_PAIR	256
#define VALUE512_PAIR	512
#define VALUE1024_PAIR	1024
#define VALUE2048_PAIR	2048

void init_board(t_game *game);
void update_board(t_game *game);
void print_board(t_game *game);

#endif
