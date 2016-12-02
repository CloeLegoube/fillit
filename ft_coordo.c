/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaouen <jjaouen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:41:58 by jjaouen           #+#    #+#             */
/*   Updated: 2016/12/02 19:54:18 by clegoube         ###   ########.fr       */
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

t_coor	*ft_lstnewcoor(char letter, int *x, int *y)
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

t_list  *ft_coordo(t_list *list)
{
	int		x[4];
	int		y[4];
	size_t	line;
	size_t	col;
	size_t	i;
	size_t	x_first;
	size_t	y_first;
	char	letter;
	t_list	*coor;
	t_list 	*new;

	coor = NULL;
	while (list)
	{
		x_first = ft_first_coordo(list)[0];
		y_first = ft_first_coordo(list)[1];
		line = 0;
		while (((char**)(list->content))[line])
		{
			col = 0;
			i = 0;
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
					printf("y : %d (i:%zu)\n", y[i], i);
					i++;
				}
				col++;
			}
			line++;



		}

		new = ft_lstnew(ft_lstnewcoor(letter, x, y), sizeof(t_coor));
		ft_lstadd_end(&coor, new);
		printf("CONTENT : %c", ((t_coor *)(new->content))->letter);
		printf("\n");
		list = list->next;
	}
	return (coor);
}
