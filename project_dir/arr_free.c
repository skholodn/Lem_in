/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:15:20 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/28 17:40:38 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_arr(char **arr)
{
	int		a;

	a = 0;
	while (arr[a])
	{
		free(arr[a]);
		a++;
	}
	free(arr);
}

void	free_arr_int(int **arr, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		free(arr[i]);
	free(arr);
}

void	free_rooms(t_room **room, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		room[i]->next = NULL;
		free(room[i]->name);
		free(room[i]);
	}
	free(room);
}

void	free_info(t_info *info)
{
	free(info->visit);
	free_arr_int(info->matrix, info->rooms);
	free_arr_int(info->path, info->rooms);
	free_rooms(info->arr, info->rooms);
	free(info);
}
