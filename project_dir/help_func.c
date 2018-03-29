/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:24:00 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/28 18:07:53 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	swap_room(t_room **src, t_room **dst)
{
	t_room	*tmp;

	tmp = *src;
	*src = *dst;
	*dst = tmp;
}

t_ant	*push_ant(int id, char *room, int path, t_ant *a)
{
	t_ant	*tmp;

	tmp = a;
	if (!a)
	{
		a = (t_ant*)ft_memalloc(sizeof(t_ant));
		a->id = id;
		a->room = room;
		a->path = path;
		return (a);
	}
	while (a->next)
		a = a->next;
	a->next = (t_ant*)ft_memalloc(sizeof(t_ant));
	a->next->id = id;
	a->next->room = room;
	a->next->path = path;
	return (tmp);
}

t_ant	*pop_ant(t_ant *a)
{
	t_ant	*tmp;

	if (!a)
		return (NULL);
	if (!a->next)
	{
		free(a);
		return (NULL);
	}
	tmp = a->next;
	free(a);
	return (tmp);
}

void	move_ants(t_ant *a, t_info *info)
{
	int		i;

	while (a)
	{
		i = -1;
		while (ft_strcmp(info->arr[info->path[a->path][++i]]->name, a->room))
		{
			if (!ft_strcmp(info->arr[info->path[a->path][i + 1]]->name,
				a->room))
			{
				a->room = info->arr[info->path[a->path][i + 2]]->name;
				break ;
			}
		}
		a = a->next;
	}
}

void	ants_create(int best_root, t_ant **ant, t_info *info)
{
	int			i;
	static int	ant_id = 0;

	i = -1;
	while (++i < best_root && i < info->ants)
	{
		*ant = push_ant(++ant_id, info->arr[info->path[i][1]]->name, i, *ant);
	}
}
