/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:24:24 by jayi              #+#    #+#             */
/*   Updated: 2021/05/25 23:55:40 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include "define.h"

void	copy_data(int *dest, int *src, unsigned int size);
int		exit_game(void);
void	clear_data(int *data, int width, int height);
void	ft_exit(int no, const char *err_msg);
int		ft_isdigit(char c);
int		ft_isalpha(char c);
int		ft_strcmp(char *dst, char *src);
int		ft_isupper(char symbol);
int		ft_isspace(char symbol);
void	check_file(char *filename, int flag);
int		save_bmp(t_game_model *g, char *filename);
int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
int		get_transparent_color(int color1, int color2);
int		get_transparent_red_color(int color1, int color2);

#endif
