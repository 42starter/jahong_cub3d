/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:08:57 by jayi              #+#    #+#             */
/*   Updated: 2021/05/25 23:13:42 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_H
# define LOGIC_H

# include "define.h"

int		start_game(char *filename);
int		game_loop(t_game_model *g);
void	handle_input_keys(t_game_model *game_model);
void	pre_update(t_game_model *game_model);
void	follow_player(t_game_model *game_model);
void	update_player_pos(t_game_model *game_model);
void	update(t_game_model *game_model);

#endif
