/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:03:18 by jjaouen           #+#    #+#             */
/*   Updated: 2016/12/07 18:31:29 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_backup(char **grid, t_list *coor, int i, int j)
{
	int		*tmpx;
	int		*tmpy;
	int		g;

	tmpx = CONTENT->x;
	tmpy = CONTENT->y;
	g = 0;
	while (g < 4)
	{
		grid[i + tmpx[g]][j + tmpy[g]] = '.';
		g++;
	}
}

void	ft_free(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_list	*coor;
	char	**fillit;
	t_var	*vari;

	vari = (t_var*)malloc(sizeof(t_var));
	vari->n = 0;
	vari->loop = 0;
	if (argc != 2)
		ft_putstr("usage: ./fillit sample_file\n");
	if (!(coor = ft_read(argc, argv)))
		return (0);
	fillit = ft_loop(coor, vari->loop);
	ft_print_words_tables(fillit);
	return (0);
}
