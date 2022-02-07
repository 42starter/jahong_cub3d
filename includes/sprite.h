/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:14:02 by jayi              #+#    #+#             */
/*   Updated: 2021/05/25 23:23:42 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include "define.h"

void	draw_sprite(t_game_model *game_model);
void	sort_sprite(t_game_model *g);
void	calc_dist(t_game_model *g);

#endif
