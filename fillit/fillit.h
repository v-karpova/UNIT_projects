/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaslova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:26:48 by omaslova          #+#    #+#             */
/*   Updated: 2018/06/08 19:06:17 by omaslova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>

typedef struct		s_list
{
	int				arr[4][2];
	char			c;
	char			**tetriminos;
	struct s_list	*next;
}					t_list;

char				**arr_fill(char *buff);
int					check(char **arr);
t_list				*map_check(char **arr, char c);
void				tetris(t_list *list);
int					map_read(int fd, t_list *list);
void				print(char **arr, int dim);
t_list				*create_node(char **tetris, char c);
void				push_back(t_list **list, t_list *elem, char c);
void				find_coords(char **arr, int *pos_i, int *pos_j);
char				**move(char **arr);
char				**empty_map(int dim);
char				**delete(char **tetris, char c, int dim);
void				insert(char **tetris, t_list *list, int *indx);
int					check_point(char **tetris, t_list *list, int *indx, \
					int dim);
int					make_map(char **tetris, t_list *list, int dim);

#endif
