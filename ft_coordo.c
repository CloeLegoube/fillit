/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:41:58 by jjaouen           #+#    #+#             */
/*   Updated: 2016/12/05 20:53:34 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			*ft_first_coordo(t_list *list)
{
	int		*tab;
	size_t	col;
	size_t	line;

	tab = (int *)malloc(2 * sizeof(*tab));
	tab[0] = 0;
	tab[1] = 0;
	line = 0;
	while (((char**)(list->content))[line])
	{
		col = 0;
		while (COOR)
		{
			if (COOR != '.')
			{
				tab[0] = line;
				tab[1] = col;
				col = 4;
				line = 3;
			}
			col++;
		}
		line++;
	}
	return (tab);
}

t_coor		*ft_lstnewcoor(char letter, int *x, int *y)
{
	t_coor	*lst;

	if (!(lst = (t_coor *)malloc(sizeof(*lst))))
		return (NULL);
	lst->letter = letter;
	lst->x = x;
	lst->y = y;
	lst->next = NULL;
	return (lst);
}

void		ft_initialize_vari(t_var *vari, t_list *list)
{
	vari->y = (int *)malloc(4 * sizeof(vari->y));
	vari->x = (int *)malloc(4 * sizeof(vari->x));
	vari->x_first = ft_first_coordo(list)[0];
	vari->y_first = ft_first_coordo(list)[1];
	vari->line = 0;
	vari->i = 0;
}

void		ft_create_coor(t_list *list, t_var *vari)
{
	(vari->letter) = CAAR;
	(vari->x)[vari->i] = (vari->line) - (vari->x_first);
	(vari->y)[vari->i] = (vari->col) - (vari->y_first);
	vari->i++;
}

t_list		*ft_coordo(t_list *list)
{
	t_var	*vari;
	t_list	*coor;

	vari = (t_var*)malloc(sizeof(t_var));
	coor = NULL;
	while (list)
	{
		ft_initialize_vari(vari, list);
		while (((char**)(list->content))[vari->line])
		{
			vari->col = 0;
			while (CAAR)
			{
				if (CAAR != '.')
					ft_create_coor(list, vari);
				vari->col++;
			}
			vari->line++;
		}
		(*vari).new = ft_lstnew(ft_lstnewcoor(vari->letter, vari->x, vari->y),
				sizeof(t_coor));
		ft_lstadd_end(&coor, (*vari).new);
		list = list->next;
	}
	return (coor);
}
