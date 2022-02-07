/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:35:00 by jayi              #+#    #+#             */
/*   Updated: 2022/02/03 18:53:13 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "ft_type.h"
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_DESTROY_NOTIFY 17
# define TITLE_NAME "CUB3D"
# define MAP_EMPTY 0
# define MAP_WALL 1
# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define RAY_SIDE_X 0
# define RAY_SIDE_Y 1
# define PLAYER_WALL_GAP 0.01
# define PLAYER_JUMP		48
# define ERROR_MSG		"Error\n"
# define CHECKED_MAP		10
# define IDX_R 0
# define IDX_G 1
# define IDX_B 2
# define DEBUG 1
# define PLAYER_ROTATE 3.5
# define BITMAPFILEHEADER 14
# define BITMAPINFOHEADER 40
# define OP_R 0
# define OP_NO 1
# define OP_SO 2
# define OP_WE 3
# define OP_EA 4
# define OP_S 5
# define OP_F 6
# define OP_C 7
# define FLAG_RESOLUTION "R"
# define FLAG_NORTH "NO"
# define FLAG_SOUTH "SO"
# define FLAG_WEST "WE"
# define FLAG_EAST "EA"
# define FLAG_SPRITE "S"
# define FLAG_FLOOR "F"
# define FLAG_CELLING "C"
# define TEX_WALL_N 0
# define TEX_WALL_S 1
# define TEX_WALL_W 2
# define TEX_WALL_E 3
# define TEX_GHOST 4
# define FLAG_MAP_N 0
# define FLAG_MAP_E 1
# define FLAG_MAP_W 2
# define FLAG_MAP_S 3
# define FLAG_MAP_ERROR -1

t_game_model	*get_g(void);
void			parse(char *filename);
void			follow_player(t_game_model *game_model);

#endif
