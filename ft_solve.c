/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:16:37 by clegoube          #+#    #+#             */
/*   Updated: 2016/12/04 11:30:32 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_grid(size_t loop)
{
	char	**grid;
	size_t	j;
	size_t	h;

	h = 0;
	// j = ft_count_list(list);
	j = 5;
	if (j == 1)
		loop++;
	grid = (char**)malloc(sizeof(char*) * (j + loop + 1));
	while (h < (j + loop))
	{
		grid[h] = (char*)malloc(sizeof(char) * (j + loop));
		grid[h] = ft_memset((char*)grid[h], '.', (j + loop));
		grid[h++][j + loop + 1] = '\0';
	}
	ft_print_words_tables(grid);
	return (grid);
}

char	**ft_solve(t_list *list, size_t loop)
{
	char	**grid;
	size_t	i;
	// size_t	j;

	grid = NULL;
	i = 0;
	if (loop == 0)
		grid = ft_grid(loop);
//	while (i < 3)
//	{
//		loop++;
//		ft_grid(list, loop);
//		printf("\n");
//		i++;
//	}
	while (list)
	{
		i = 0;
		printf("letter_solve : %c\n", ((t_coor *)(list->content))->letter);
		printf("size : %zu\n", ((t_coor *)(list->content))->size);
		while (i < 4)
		{
			printf("x : %d - ", ((t_coor *)(list->content))->x[i]);
			printf("y : %d \n", ((t_coor *)(list->content))->y[i]);
			i++;
		}
		printf("\n");

		list = list->next;
	}

	//ft_solve(list, loop);
	return (grid);
}
