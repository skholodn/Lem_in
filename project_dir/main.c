/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:23:30 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/28 17:32:58 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_error(char *str)
{
	ft_printf("{red}ERROR : %s\n{eoc}", str);
	exit(1);
}

int		main(int ac, char **av)
{
	int		fd;

	if (ac > 2)
		print_error("Wrong parameters, usage: ./lem-in <filename>"
				" | ./lem-in (for stdin)");
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			print_error("Wrong file");
		parse_input(fd);
	}
	else
		parse_input(0);
	return (0);
}
