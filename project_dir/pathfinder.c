/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 12:04:00 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/28 18:17:47 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_path(t_pair **dis, t_info *info)
{
	int		i;
	t_queue *q;

	q = NULL;
	i = info->rooms - 1;
	while (i && (*dis)[i].l != INT_MAX)
	{
		q = push_front_q(0, i, q);
		i = (*dis)[i].q;
	}
	i = 0;
	while (q && ++i)
	{
		info->path[info->path_count][i] = front_queue(q).q;
		q = pop_queue(q);
	}
	free(*dis);
}

void	bfs_if(t_bfs *b, t_info *info)
{
	if (info->matrix[b->u.q][b->j] > 0
			&& b->dis[b->j].l > b->dis[b->u.q].l + 1)
	{
		b->dis[b->j].l = b->dis[b->u.q].l + 1;
		b->dis[b->j].q = b->u.q;
		b->q = push_queue(b->dis[b->j].l, b->j, b->q);
	}
}

void	ft_bfs(int v, t_info *info)
{
	t_bfs	b;

	init_bfs(&b.dis, &b.q, info);
	b.q = push_queue(0, v, b.q);
	while (b.q)
	{
		b.u = front_queue(b.q);
		b.q = pop_queue(b.q);
		if (b.u.l > b.dis[b.u.q].l)
			continue ;
		b.j = -1;
		while (++b.j < info->rooms)
			bfs_if(&b, info);
	}
	set_path(&b.dis, info);
}

void	clear_matrix(int *path, t_info *info)
{
	int		i;

	i = 1;
	while (path[i] != 0 && i < info->rooms)
	{
		info->matrix[path[i]][path[i - 1]] = 0;
		info->matrix[path[i - 1]][path[i]] = 0;
		i++;
	}
}

void	find_path(t_info *info)
{
	int		i;

	info->visit = (int *)ft_memalloc(sizeof(int) * info->rooms);
	info->path_count = 0;
	info->path = (int **)ft_memalloc(sizeof(int*) * (info->rooms + 1));
	i = -1;
	while (++i < info->rooms)
		info->path[i] = (int *)ft_memalloc(sizeof(int) * (info->rooms + 1));
	i = -1;
	while (++i < info->rooms)
	{
		ft_bfs(0, info);
		info->path_count += 1;
		ft_bzero(info->visit, (size_t)info->rooms);
		clear_matrix(info->path[info->path_count - 1], info);
	}
	print_info(info);
	check_path(info);
	set_path_count(info);
	moving(info);
}
