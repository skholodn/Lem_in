/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:27:34 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/28 18:30:01 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	dell_ants(t_ant **a, t_info *info)
{
	t_ant	*tmp;

	tmp = (*a);
	while (tmp)
	{
		if (!ft_strcmp(tmp->room, info->arr[info->rooms - 1]->name))
		{
			*a = (tmp == (*a)) ? pop_ant(*a) : dell_middle(*a, tmp->room);
			tmp = *a;
		}
		else if (tmp)
			tmp = tmp->next;
	}
}

void	print_path(t_info *info)
{
	int		i;
	int		x;

	i = -1;
	while (++i < info->path_count)
	{
		x = 0;
		while (info->path[i][++x])
			ft_printf("%s-%s\n", info->arr[info->path[i][x - 1]]->name,
					info->arr[info->path[i][x]]->name);
	}
}

void	print_matrix(t_info *info)
{
	int		i;
	int		x;

	i = -1;
	while (++i < info->rooms)
	{
		x = -1;
		while (++x < info->rooms)
		{
			if (info->matrix[i][x])
			{
				ft_printf("%s-%s\n", info->arr[x]->name, info->arr[i]->name);
				info->matrix[i][x] = 0;
				info->matrix[x][i] = 0;
			}
		}
	}
}

void	print_info(t_info *info)
{
	int		i;

	ft_printf("%d\n", info->ants);
	i = -1;
	while (++i < info->rooms)
	{
		if (info->arr[i]->begin)
			ft_printf("##start\n");
		else if (info->arr[i]->end)
			ft_printf("##end\n");
		ft_printf("%s %d %d\n", info->arr[i]->name,
				info->arr[i]->x, info->arr[i]->y);
	}
	print_path(info);
	print_matrix(info);
	ft_printf("\n");
}

void	moving(t_info *info)
{
	t_ant	*ant;
	int		best_root;

	ant = NULL;
	!(info->path[0][1]) ? print_error("No path found") : 0;
	while (info->ants > 0 || ant)
	{
		best_root = find_best_root(info->path_count, info->path, info->ants);
		if (ant)
			move_ants(ant, info);
		ants_create(best_root, &ant, info);
		print_ants(ant);
		dell_ants(&ant, info);
		info->ants -= best_root;
	}
	free_info(info);
}
