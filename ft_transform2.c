/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:09:17 by clegoube          #+#    #+#             */
/*   Updated: 2016/12/01 23:02:05 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_checkconnexion_point(char **tab, size_t x, size_t y)
{
 	size_t	coco;

 	coco = 0;

 	if (x == 3 && tab[x][y - 2] == '#' && tab[x][y - 1] == '.')
 		coco++;
 	if (x == 3 && tab[x][y - 2] == '#' && tab[x][y - 1] == '.')
 		coco++;
 	if (y > 0 && tab[x][y - 1] == '#')
 		coco++;
 	if (y < 3 && tab[x][y + 1] == '#')
 		coco++;
 	if (x > 0 && tab[x - 1][y] == '#')
 		coco++;
 	if (x < 3 && tab[x + 1][y] == '#')
 		coco++;
 	if (y == 3 && tab[x][y - 1] == '#')
 		coco++;
 	if (y == 0 && tab[x][y + 1] == '#')
 		coco++;
 	if (x == 3 && tab[x - 1][y] == '#')
 		coco++;
 	if (x >= 2 && tab[x][y - 1] == '#' && tab[x - 1][y - 1] == '#' \
 	&& tab[x - 2][y - 1] == '#' && tab[x][y] == '.' && tab[x - 2][y] == '#')
		coco++;
 	if (x == 0 && tab[x + 1][y] == '#')
 		coco++;
	return (coco);
}

int		ft_transform_point(t_list *list)
{
	size_t	x;
	size_t	y;

	while (list)
	{
		x = 0;
		while (((char**)(list->content))[x])
		{
			y = 0;
			while (TAB)
			{
				if (TAB == '.' && ft_checkconnexion_point(((char**)(list->content)), x, y) < 2)
					TAB = '@';
				y++;
			}
			x++;
		}
		list = list->next;
	}
	return (0);
}

int		ft_transform_point_line(t_list *list)
{
	size_t	x;
	size_t	y;
	size_t	count;


	while (list)
	{
		x = 0;
		while (((char**)(list->content))[x])
		{
			y = 0;
			count = 0;
			while (TAB)
			{
				if (TAB == '.'|| TAB == '@' )
					count++;
				y++;
			}
			if (count == 4)
			{
				y = 0;
				while (TAB)
				{
					if (TAB == '.')
						TAB = '@';
					y++;
				}
			}
			x++;
		}
		list = list->next;
	}
	return (0);
}

int		ft_transform_point_col(t_list *list)
{
	size_t	x;
	size_t	y;
	size_t	count;

	x = 0;
	while (list)
	{
		y = 0;
		while (TAB)
		{
			x = 0;
			count = 0;
			while (x < 3)
			{
				if (TAB == '.'|| TAB == '@' )
					count++;
				x++;
			}
			if (count == 3)
			{
				x = 0;
				while (x < 3)
				{
					if (TAB == '.')
						TAB = '@';
					x++;
				}
			}
			y++;
		}
		list = list->next;
	}
	return (0);
}

int		ft_transform_letter(t_list *list)
{
	size_t	x;
	size_t	y;
	char 	letter;

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

char	**ft_remove_star(t_list *list)
{
	size_t	x;
	size_t	y;
	size_t	i;
	char	*string;
	char	**tab;

	string = (char *)malloc(200 * sizeof(char *));
	i = 0;
	while (list)
	{
		x = 0;
		while (((char**)(list->content))[x])
		{
			y = 0;
			while (TAB)
			{
				if (TAB != '@')
					string[i++] = TAB;
				y++;
			}
			x++;
			string[i++] = '*';
		}
		string[i++] = '/';

		list = list->next;
	}
	tab = ft_strsplit(string, '/');
	// ft_print_words_tables(tab);
	return (tab);
}
