/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:16:35 by jayi              #+#    #+#             */
/*   Updated: 2022/02/05 14:45:58 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "color.h"
#include "define.h"
#include "vector.h"
#include "sprite.h"

void	sort_sprite(t_game_model *g)
{
	t_node		*cur;
	t_node		*target;
	t_sprite	*temp;
	t_sprite	*cur_value;
	t_sprite	*target_value;

	cur = g->sprites;
	while (cur != NULL)
	{
		target = cur->next;
		while (target != NULL)
		{
			cur_value = cur->value;
			target_value = target->value;
			if (cur_value->dist < target_value->dist)
			{
				temp = cur->value;
				cur->value = target->value;
				target->value = temp;
				target = cur;
			}
			target = target->next;
		}
		cur = cur->next;
	}
}

void	calc_dist(t_game_model *g)
{
	t_node		*cur;
	t_sprite	*sp;

	cur = g->sprites;
	while (cur != NULL)
	{
		sp = cur->value;
		sp->dist = pow((g->pl.pos.x - sp->pos.x), 2)
			+ pow((g->pl.pos.y - sp->pos.y), 2);
		cur = cur->next;
	}
}
