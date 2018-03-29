/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:31:16 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/30 19:52:11 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <limits.h>

# define END !info->end

typedef struct		s_room
{
	int				id;
	int				begin;
	int				end;
	char			*name;
	int				x;
	int				y;
	int				*connect;
	struct s_room	*next;
}					t_room;

typedef struct		s_info
{
	t_room			*room;
	int				ants;
	int				end;
	int				rooms;
	int				**matrix;
	int				**path;
	int				path_count;
	int				*visit;
	t_room			**arr;
}					t_info;

typedef	struct		s_pair
{
	int				l;
	int				q;
}					t_pair;

typedef struct		s_queue
{
	t_pair			p;
	struct s_queue	*front;
	struct s_queue	*rear;
}					t_queue;

typedef	struct		s_ant
{
	int				id;
	char			*room;
	int				path;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_bfs
{
	int				j;
	t_pair			u;
	t_queue			*q;
	t_pair			*dis;
}					t_bfs;

/*
** Parsing functions
*/

void				parse_input(int fd);
void				set_room(char *line, int start, int end, t_info *info);
int					valid_rooms(t_room *tmp);
void				order_rooms(t_info *info);
void				check_dubl(t_room *room, t_info *info);
void				parse_start(int fd, char **line, t_info *info);
void				parse_end(int fd, char **line, t_info *info);

/*
** Validation
*/

int					check_digit(char *str);
int					check_connect(char const *line);
void				check_input_info(char *line, t_info *info);

/*
**  ERRORS PRINT
*/

void				print_error(char *str);
void				print_info(t_info *info);

/*
** Free functions
*/

void				free_arr(char **arr);
void				free_arr_int(int **arr, int size);
void				free_rooms(t_room **room, int size);
void				free_info(t_info *info);
t_ant				*dell_middle(t_ant *a, char *find);

/*
** Finding path
*/

void				find_path(t_info *info);
void				check_path(t_info *info);
void				set_path_count(t_info *info);

/*
** Moving ants
*/

void				moving(t_info *info);
int					find_ant_moves(int ants, int *path_length);
void				set_path_length(int y, int **path, int **path_length);
int					find_best_root(int path_count, int **path, int ants);
void				print_ants(t_ant *a);

/*
** helping functions
*/

void				swap_room(t_room **src, t_room **dst);
t_ant				*push_ant(int id, char *room, int path, t_ant *a);
t_ant				*pop_ant(t_ant *a);
void				move_ants(t_ant *a, t_info *info);
void				ants_create(int best_root, t_ant **ant, t_info *info);
void				init_bfs(t_pair **dis, t_queue **q, t_info *info);
t_queue				*pop_queue(t_queue *q);
t_pair				front_queue(t_queue *q);
t_queue				*push_front_q(int dis, int v, t_queue *q);
t_queue				*push_queue(int dis, int v, t_queue *q);
void				swap_int(int **src, int **dst);

#endif
