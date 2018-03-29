/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:09:00 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/28 18:14:25 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*push_queue(int dis, int v, t_queue *q)
{
	t_queue	*tmp;

	tmp = q;
	if (!q)
	{
		q = (t_queue*)ft_memalloc(sizeof(t_queue));
		q->p.l = dis;
		q->p.q = v;
		return (q);
	}
	while (q->rear)
		q = q->rear;
	q->rear = (t_queue*)ft_memalloc(sizeof(t_queue));
	q->rear->p.l = dis;
	q->rear->p.q = v;
	return (tmp);
}

t_queue	*push_front_q(int dis, int v, t_queue *q)
{
	t_queue	*tmp;

	tmp = q;
	if (!q)
	{
		q = (t_queue*)ft_memalloc(sizeof(t_queue));
		q->p.l = dis;
		q->p.q = v;
		return (q);
	}
	q = (t_queue*)ft_memalloc(sizeof(t_queue));
	q->p.l = dis;
	q->p.q = v;
	q->rear = tmp;
	return (q);
}

t_pair	front_queue(t_queue *q)
{
	return (q->p);
}

t_queue	*pop_queue(t_queue *q)
{
	t_queue	*tmp;

	if (!q)
		return (NULL);
	if (!q->rear)
	{
		free(q);
		return (NULL);
	}
	tmp = q->rear;
	free(q);
	return (tmp);
}

void	init_bfs(t_pair **dis, t_queue **q, t_info *info)
{
	int		i;

	i = 0;
	*dis = (t_pair *)ft_memalloc(sizeof(t_pair) * info->rooms);
	while (++i < info->rooms)
		(*dis)[i].l = INT_MAX;
	*q = NULL;
}
