/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:00:28 by jjaouen           #+#    #+#             */
/*   Updated: 2016/12/07 18:31:55 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define CAAR (((char**)(list->content))[vari->line][vari->col])
# define COOR (((char**)(list->content))[line][col])
# define TAB ((char**)(list->content))[x][y]
# define CONTENT ((t_coor *)(coor->content))

# include "libft/libft.h"
# include <fcntl.h>

typedef struct		s_coor
{
	char			letter;
	int				*x;
	int				*y;
	struct s_coor	*next;
}					t_coor;

typedef struct		s_var
{
	int				fd;
	int				ret;
	size_t			loop;
	size_t			x_first;
	size_t			y_first;
	char			letter;
	size_t			line;
	size_t			col;
	size_t			i;
	t_list			*new;
	int				*y;
	int				*x;
	int				n;
}					t_var;

void				ft_lstadd_end(t_list **alst, t_list *new);
void				del(void *content, size_t content_size);
char				**ft_grid(t_list *list, size_t loop);
t_list				*ft_read(int argc, char **argv);
int					ft_transform_letter(t_list *list);
int					ft_number_symbol(t_list *list);
int					ft_checkconnexion(char **tab, size_t x, size_t y);
int					ft_connexion(char **tab);
int					ft_checkfile(t_list *list, char *buff);
int					*ft_first_coordo(t_list *list);
t_coor				*ft_lstnewcoor(char letter, int *x, int *y);
t_list				*ft_coordo(t_list *list);
void				ft_initialize_vari(t_var *vari, t_list *list);
void				ft_create_coor(t_list *list, t_var *vari);
void				ft_free(char **tab);
int					ft_solve(t_list *coor, char **grid);
void				ft_backup(char **grid, t_list *coor, int i, int j);
int					ft_place(t_list *coor, char **grid, int i, int j);
int					ft_place_if(char **grid, int i, int j, t_list *coor);
char				**ft_loop(t_list *coor, size_t loop);
void				ft_error(void);

#endif
