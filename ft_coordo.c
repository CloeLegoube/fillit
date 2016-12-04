/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:41:58 by jjaouen           #+#    #+#             */
/*   Updated: 2016/12/04 11:30:45 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int  *ft_first_coordo(t_list *list)
{
	int   	*tab;
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

t_coor	*ft_lstnewcoor(char letter, int *x, int *y, size_t size)
{
	t_coor	*lst;
	// size_t	i;


	printf("SIZE : %zu\n", size);
	if (!(lst = (t_coor *)malloc(sizeof(*lst))))
		return (NULL);
	lst->letter = letter;
	lst->size = size;
	lst->x = x;
	lst->y = y;
	lst->next = NULL;
	// i = 0;
	// while (i < 4)
	// {
	// 	printf("XXXXX : %d - ", lst->x[i]);
	// 	printf("YYYY : %d \n", lst->y[i]);
	// 	i++;
	// }
	return (lst);
}

t_list  *ft_coordo(t_list *list)
{
	int		x[4];
	int		y[4];
	size_t	line;
	size_t	col;
	size_t	i;
	size_t	j;
	size_t	x_first;
	size_t	y_first;
	char	letter;
	t_list	*coor;
	t_list 	*new;
	t_list 	*tmp;

	coor = NULL;
	while (list)
	{
		x_first = ft_first_coordo(list)[0];
		y_first = ft_first_coordo(list)[1];
		line = 0;
		i = 0;
		while (((char**)(list->content))[line])
		{
			col = 0;

			while (COOR)
			{
				if (COOR != '.')
				{
					letter = COOR;
					x[i] = line - x_first;
					y[i] = col - y_first;
					printf("COOR : %c  |  ", COOR);
					printf("line : %zu  -  ", line);
					printf("x_first :%zu  =  ",x_first);
					printf("x : %d (i:%zu)  |  ", x[i], i);
					printf("col : %zu  -  ", col);
					printf("y_first :%zu  =  ",y_first);
					printf("y : %d (i:%zu) | ", y[i], i);
					printf("x : %d - y : %d \n", x[i], y[i]);
					i++;
				}
				col++;
			}
			printf("count\n");
			line++;
		}
		new = ft_lstnew(ft_lstnewcoor(letter, x, y, i), sizeof(t_coor));
		ft_lstadd_end(&coor, new);
		printf("CONTENT-Coor : %c\n", ((t_coor *)(coor->content))->letter);
		j = 0;
		while (j < 4)
		{
			printf("XXXXX-coor : %d - ", ((t_coor *)(coor->content))->x[j]);
			printf("YYYY-coor : %d \n", ((t_coor *)(coor->content))->y[j]);
			j++;
		}
		printf("\n");
		list = list->next;
	}
	tmp = coor;
	while (coor)
	{
		i = 0;
		printf("letter_coordo: %c\n", ((t_coor *)(coor->content))->letter);
		printf("size : %zu\n", ((t_coor *)(coor->content))->size);
		while (i < 4)
		{
			printf("x : %d - ", ((t_coor *)(coor->content))->x[i]);
			printf("y : %d \n", ((t_coor *)(coor->content))->y[i]);
			i++;
		}
		printf("\n");

		coor = coor->next;
	}
	coor = tmp;
	return (coor);
}
