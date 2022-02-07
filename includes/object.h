/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42.kr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:13:12 by jayi              #+#    #+#             */
/*   Updated: 2021/05/25 23:13:19 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "define.h"
# include "input.h"
# include "vector.h"

void	add_speed(t_player *object, int direction);
void	add_pos_z(t_player *object, int value, int do_jump);

#endif
