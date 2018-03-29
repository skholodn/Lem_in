/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:19:00 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/28 18:26:58 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_ant_moves(int ants, int *path_length)
{
	int		x;
	int		tmp;
	int		a;
	int		i;

	x = 0;
	tmp = 0;
	a = 0;
	while (x < ants && ++a)
	{
		i = -1;
		while (path_length[++i] && ++x <= ants)
			tmp += a * path_length[i];
	}
	return (tmp);
}

void	set_path_length(int y, int **path, int **path_length)
{
	int		x;

	x = 0;
	while (path[y][++x])
		(*path_length)[y] += 1;
}

int		find_best_root(int path_count, int **path, int ants)
{
	int		y;
	int		best_roots;
	int		roots_id;
	int		*path_length;
	int		tmp;

	y = -1;
	roots_id = 0;
	best_roots = INT_MAX;
	path_length = ft_memalloc(sizeof(int) * (path_count + 1));
	while (++y < path_count)
	{
		set_path_length(y, path, &path_length);
		tmp = find_ant_moves(ants, path_length);
		if (tmp < best_roots)
		{
			best_roots = tmp;
			roots_id = y + 1;
		}
	}
	free(path_length);
	return (roots_id);
}

void	print_ants(t_ant *a)
{
	while (a)
	{
		ft_printf("L%d-%s ", a->id, a->room);
		a = a->next;
	}
	ft_printf("\n");
}
