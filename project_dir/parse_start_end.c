/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 21:24:00 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/30 19:48:51 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_start(int fd, char **line, t_info *info)
{
	while (get_next_line(fd, line))
	{
		if (!ft_strcmp("##start", *line) || !ft_strcmp("##end", *line))
			print_error("Imposible to use command");
		else if (*line[0] == '#')
			continue;
		else
		{
			set_room(*line, 1, 0, info);
			break ;
		}
	}
}

void	parse_end(int fd, char **line, t_info *info)
{
	while (get_next_line(fd, line))
	{
		if (!ft_strcmp("##start", *line) || !ft_strcmp("##end", *line))
			print_error("Imposible to use command");
		else if (*line[0] == '#')
			continue;
		else
		{
			set_room(*line, 0, 1, info);
			break ;
		}
	}
}

void	swap_int(int **src, int **dst)
{
	int		*tmp;

	tmp = *src;
	*src = *dst;
	*dst = tmp;
}

t_ant	*dell_middle(t_ant *a, char *find)
{
	t_ant	*begin;
	t_ant	*tmp;
	t_ant	*prev;

	begin = a;
	prev = a;
	while (a->next)
	{
		a = a->next;
		if (!ft_strcmp(a->room, find))
		{
			tmp = a;
			a = prev;
			a->next = tmp->next;
			free(tmp);
		}
		prev = a;
	}
	if (!a->next && prev != a && !ft_strcmp(a->room, find))
	{
		free(a);
		prev->next = NULL;
	}
	return (begin);
}
