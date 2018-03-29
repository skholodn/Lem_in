/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <skholodn@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:21:00 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/28 17:36:30 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_digit(char *str)
{
	int		i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int		check_connect(char const *line)
{
	int		i;

	i = -1;
	while (line[++i])
		if (line[i] == ' ')
			return (0);
	return (1);
}

int		search_connections(int **matrix, int size)
{
	int		i;
	int		a;
	int		connections;

	i = -1;
	while (++i < size)
	{
		a = -1;
		connections = 0;
		while (++a < size)
		{
			if (a == i && matrix[a][i] > 0)
				return (1);
			connections += matrix[a][i];
		}
		if (!connections)
			return (1);
	}
	return (0);
}

void	check_input_info(char *line, t_info *info)
{
	if (line)
		free(line);
	if (!info->ants)
		print_error("There is no ants, impossible to move farther");
	if (!info->matrix)
		print_error("There is no rooms, impossible to move farther");
	if (search_connections(info->matrix, info->rooms))
		print_error("Wrong connections, impossible to move farther");
	find_path(info);
}
