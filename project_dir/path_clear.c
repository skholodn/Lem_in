/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:30:00 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/30 19:51:18 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		clear(int i, t_info *info)
{
	ft_bzero(info->path[i], (size_t)info->rooms * 4);
	while (info->path[i + 1][1])
	{
		swap_int(&info->path[i], &info->path[i + 1]);
	}
	return (1);
}

void	check_path(t_info *info)
{
	int		y;
	int		x;
	int		z;
	int		i;

	y = 0;
	while (y < info->rooms && info->path[y + 1][1])
	{
		x = 0;
		while (info->path[y][++x] != info->rooms - 1)
		{
			i = 0;
			while (info->path[y + ++i][1])
			{
				z = 0;
				while (info->path[y + i][++z] != info->rooms - 1)
				{
					if (info->path[y][x] == info->path[y + i][z]
							&& clear(y + i, info))
						break ;
				}
			}
		}
		y++;
	}
}

void	set_path_count(t_info *info)
{
	int		y;

	y = -1;
	info->path_count = 0;
	while (info->path[++y][1])
		++info->path_count;
}
