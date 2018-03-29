/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ants_rooms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:48:34 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/28 17:53:58 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_ant(char *line, t_info *info)
{
	char	**arr;

	arr = ft_strsplit(line, ' ');
	if (arr[0] && !arr[1])
	{
		if (info->ants)
			print_error("Ants alredy set!");
		!check_digit(arr[0]) ? print_error("Wrong input") : 0;
		if (!arr[1])
		{
			if ((info->ants = ft_atoi(arr[0])) < 1)
				print_error("Wrong ants value");
		}
	}
	else
	{
		free_arr(arr);
		return (1);
	}
	free_arr(arr);
	return (0);
}

void	set_m(char *line, int i, size_t len_fst, t_info *info)
{
	int		a;
	int		disconnect;
	size_t	len_lst;

	a = -1;
	disconnect = 0;
	while (++a < info->rooms)
	{
		len_lst = ft_strlen(info->arr[a]->name);
		if (!ft_strncmp(info->arr[a]->name, line + len_fst, len_lst)
				&& !line[len_lst + len_fst])
		{
			info->matrix[info->arr[a]->id][info->arr[i]->id] += 1;
			info->matrix[info->arr[i]->id][info->arr[a]->id] += 1;
		}
		else
			disconnect++;
	}
	if (disconnect == info->rooms)
		print_error("Impossible to set connection");
}

void	set_matrix(char *line, t_info *info)
{
	int		i;
	int		disconnect;
	size_t	len;

	i = -1;
	disconnect = 0;
	while (++i < info->rooms)
	{
		len = ft_strlen(info->arr[i]->name);
		if (!ft_strncmp(info->arr[i]->name, line, len) && line[len] == '-')
			set_m(line, i, len + 1, info);
		else
			disconnect++;
	}
	if (disconnect == info->rooms)
		print_error("Impossible to set connection");
}

void	set_connect(char *line, t_info *info)
{
	int		i;
	t_room	*tmp;

	if (!info->end)
	{
		info->rooms = valid_rooms(info->room);
		info->matrix = (int **)ft_memalloc(sizeof(int *) * info->rooms);
		info->arr = (t_room **)ft_memalloc(sizeof(t_room *) * info->rooms);
		i = -1;
		tmp = info->room;
		while (++i < info->rooms)
		{
			info->matrix[i] = (int *)ft_memalloc(sizeof(int) * info->rooms);
			info->arr[i] = tmp;
			tmp = tmp->next;
		}
		order_rooms(info);
	}
	info->end = 1;
	set_matrix(line, info);
}

void	parse_input(int fd)
{
	char	*line;
	t_info	*info;

	line = NULL;
	info = (t_info *)ft_memalloc(sizeof(t_info));
	while (get_next_line(fd, &line))
	{
		if (!ft_strcmp("##start", line))
			parse_start(fd, &line, info);
		else if (!ft_strcmp("##end", line))
			parse_end(fd, &line, info);
		else if (line[0] == '#')
			continue ;
		else if (!line[0])
			break ;
		else if (check_connect(line) && info->ants)
			set_connect(line, info);
		else if (info->end)
			print_error("Impossible to set rooms or ants after connections");
		else
			(find_ant(line, info)) ? set_room(line, 0, 0, info) : 0;
	}
	check_input_info(line, info);
}
