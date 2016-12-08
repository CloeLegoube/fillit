/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:16:37 by clegoube          #+#    #+#             */
/*   Updated: 2016/12/06 22:13:42 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_grid(t_list *list, size_t loop)
{
	char	**grid;
	size_t	j;
	size_t	h;

	h = 0;
	j = ft_count_list(list) * 4;
	while (ft_sqrt(j) == 0)
		j--;
	if (j > 0 && j < 4)
		loop++;
	grid = (char**)malloc(sizeof(char*) * (j + loop + 1));
	while (h < (ft_sqrt(j) + loop))
	{
		grid[h] = (char*)malloc(sizeof(char) * (ft_sqrt(j) + loop));
		grid[h] = ft_memset((char*)grid[h], '.', (ft_sqrt(j) + loop));
		grid[h++][ft_sqrt(j) + loop + 1] = '\0';
	}
	return (grid);
}

char	**ft_loop(t_list *coor, size_t loop)
{
	char	**grid;

	grid = ft_grid(coor, loop);
	while (!ft_solve(coor, grid))
	{
		loop++;
		free(grid);
		grid = ft_grid(coor, loop);
	}
	return (grid);
}

int		ft_place_if(char **grid, int i, int j, t_list *coor)
{
	int		*tmpx;
	int		*tmpy;
	int		h;

	tmpx = CONTENT->x;
	tmpy = CONTENT->y;
	h = 0;
	while (h < 4)
	{
		if (grid[i + tmpx[h]][j + tmpy[h]] != '.')
			return (0);
		h++;
	}
	return (1);
}

int		ft_place(t_list *coor, char **grid, int i, int j)
{
	int		*tmpx;
	int		*tmpy;
	size_t	size;
	int		h;

	size = ft_strlen(*grid);
	h = -1;
	if (grid[i][j] != '.')
		return (0);
	tmpx = CONTENT->x;
	tmpy = CONTENT->y;
	while (++h < 4)
	{
		if (i + tmpx[h] >= (int)size)
			return (0);
		if (j + tmpy[h] >= (int)size)
			return (0);
	}
	if (ft_place_if(grid, i, j, coor) == 0)
		return (0);
	h = -1;
	while (++h < 4)
		grid[i + tmpx[h]][j + tmpy[h]] = CONTENT->letter;
	return (1);
}

int		ft_solve(t_list *coor, char **grid)
{
	int		i;
	int		j;

	i = 0;
	if (coor == NULL)
		return (1);
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (ft_place(coor, grid, i, j))
			{
				if (ft_solve(coor->next, grid))
					return (1);
				ft_backup(grid, coor, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}
