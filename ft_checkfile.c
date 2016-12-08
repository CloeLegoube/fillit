/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 21:24:17 by clegoube          #+#    #+#             */
/*   Updated: 2016/12/07 18:32:42 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_transform_letter(t_list *list)
{
	size_t	x;
	size_t	y;
	char	letter;

	letter = 'A';
	while (list)
	{
		x = 0;
		while (((char**)(list->content))[x])
		{
			y = 0;
			while (TAB)
			{
				if (TAB == '#')
					TAB = letter;
				y++;
			}
			x++;
		}
		list = list->next;
		letter++;
	}
	return (0);
}

int		ft_number_symbol(t_list *list)
{
	size_t i;
	size_t count_point;
	size_t count_dieze;
	size_t n;

	i = 0;
	n = 0;
	count_point = 0;
	count_dieze = 0;
	while (*(char *)((*list).content + i))
	{
		if (*(char *)((*list).content + i) == '.')
			count_point++;
		if (*(char *)((*list).content + i) == '#')
			count_dieze++;
		if (*(char *)((*list).content + i) == '\n')
			n++;
		i++;
	}
	if ((i != 20) || ((count_dieze) != 4) || ((count_point) != 12) || (n) != 4)
	{
		ft_putstr("error\n");
		return (42);
	}
	return (1);
}

int		ft_checkconnexion(char **tab, size_t x, size_t y)
{
	size_t	coco;

	coco = 0;
	if (y > 0 && tab[x][y - 1] == '#')
		coco++;
	if (y < 3 && tab[x][y + 1] == '#')
		coco++;
	if (x > 0 && tab[x - 1][y] == '#')
		coco++;
	if (x < 3 && tab[x + 1][y] == '#')
		coco++;
	return (coco);
}

int		ft_connexion(char **tab)
{
	size_t	x;
	size_t	y;
	size_t	coco;

	x = 0;
	coco = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[x][y] == '#')
				coco += ft_checkconnexion(tab, x, y);
			y++;
		}
		x++;
	}
	if (coco != 6 && coco != 8)
	{
		ft_putstr("error\n");
		return (42);
	}
	return (1);
}

int		ft_checkfile(t_list *list, char *buff)
{
	char	**tab;
	size_t	count;
	t_list	*tmp;

	count = 0;
	tmp = list;
	buff = NULL;
	while (list && ++count)
	{
		if (ft_number_symbol(list) == 42)
			exit(1);
		tab = ft_strsplit((char *)list->content, '\n');
		(*list).content = tab;
		if (ft_connexion(list->content) == 42)
			exit(1);
		list = list->next;
	}
	list = tmp;
	ft_transform_letter(list);
	return (1);
}
