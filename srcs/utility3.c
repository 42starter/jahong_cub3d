/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:41:32 by jayi              #+#    #+#             */
/*   Updated: 2022/02/07 19:18:46 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "utility.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

t_game_model	*get_g(void)
{
	static t_game_model	game_model;

	return (&game_model);
}

int	is_map_symbol(char c)
{
	if (c == '0' || c == ' ' || c == '1' || c == 'E' || \
		c == '2' || c == 'W' || c == 'S' || c == 'N')
		return (1);
	else
		return (0);
}
