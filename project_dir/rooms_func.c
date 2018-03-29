/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:43:00 by skholodn          #+#    #+#             */
/*   Updated: 2017/12/27 18:41:28 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_dubl(t_room *room, t_info *info)
{
	t_room	*tmp;
	int		begin;
	int		end;

	tmp = info->room;
	begin = 0;
	end = 0;
	if (!tmp && (info->room = room))
		return ;
	while (tmp)
	{
		begin += (tmp->begin) ? 1 : 0;
		end += (tmp->end) ? 1 : 0;
		if (tmp->x == room->x && tmp->y == room->y)
			print_error("Impossible to have rooms with same coordinates");
		if (!ft_strcmp(tmp->name, room->name))
			print_error("Impossible to have rooms with same names");
		if (!tmp->next && (tmp->next = room))
			break ;
		tmp = tmp->next;
	}
	begin += (room->begin) ? 1 : 0;
	end += (room->end) ? 1 : 0;
	if (begin > 1 || end > 1)
		print_error("Too many start or end rooms");
}

void	check_room(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		if (arr[i][0] != '#')
			print_error("not comment after room");
		else
			break ;
	}
}

void	set_room(char *line, int start, int end, t_info *info)
{
	char	**arr;
	t_room	*room;

	if (info->ants < 1)
		print_error("Wrong ants value");
	arr = ft_strsplit(line, ' ');
	if (arr[0][0] == 'L' || ((!arr[1] || !check_digit(arr[1]))
							|| (!arr[2] || !check_digit(arr[2]))))
		print_error("Wrong room input");
	room = (t_room	*)ft_memalloc(sizeof(t_room));
	room->begin = start;
	room->end = end;
	room->name = ft_strdup(arr[0]);
	room->x = ft_atoi(arr[1]);
	room->y = ft_atoi(arr[2]);
	check_room(arr + 3);
	free_arr(arr);
	check_dubl(room, info);
}

int		valid_rooms(t_room *tmp)
{
	int		count;
	int		begin;
	int		end;

	count = 0;
	begin = 0;
	end = 0;
	while (tmp)
	{
		begin += tmp->begin;
		end += tmp->end;
		count++;
		tmp = tmp->next;
	}
	if (count == 0)
		print_error("No rooms are to create connections");
	if (end != 1 || begin != 1)
		print_error("Start or end rooms are not settled properly");
	return (count);
}

void	order_rooms(t_info *info)
{
	int		i;

	i = -1;
	while (++i < info->rooms)
	{
		if (info->arr[i]->begin)
			swap_room(&info->arr[i], &info->arr[0]);
		else if (info->arr[i]->end)
			swap_room(&info->arr[i], &info->arr[info->rooms - 1]);
	}
	i = -1;
	while (++i < info->rooms)
		info->arr[i]->id = i;
}
