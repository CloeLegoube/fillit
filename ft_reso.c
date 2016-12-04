#include "fillit.h"




int		ft_draw_while(char ***tab, int *i, int *j, int **tmp)
{
	if (tab[0][*i + tmp[0][0]][*j + tmp[0][1]] != '.')
		return (0);
	if (tab[0][*i + tmp[0][2]][*j + tmp[0][3]] != '.')
		return (0);
	if (tab[0][*i + tmp[0][4]][*j + tmp[0][5]] != '.')
		return (0);
	return (1);
}

int		ft_draw(char **tab, t_list **list, int i, int j)
{
	int		*tmp;
	size_t	size;
	int		x;

	size = ft_strlen(*tab);
	x = 0;
	if (tab[i][j] != '.')
		return (0);
	tmp = (*list)->content;
	while (x < 6)
	{
		if (i + tmp[x] >= (int)size)
			return (0);
		x++;
		if (j + tmp[x] >= (int)size)
			return (0);
		x++;
	}
	if (ft_draw_while(&tab, &i, &j, &tmp) == 0)
		return (0);
	tab[i][j] = (*list)->c;
	tab[i + tmp[0]][j + tmp[1]] = (*list)->c;
	tab[i + tmp[2]][j + tmp[3]] = (*list)->c;
	tab[i + tmp[4]][j + tmp[5]] = (*list)->c;
	return (1);
}



int	ft_resolve(char **tab, t_list **list)
{
	int i;
	int j;

	i = 0;
	if (!*list)
		return (1);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (ft_draw(tab, list, i, j))
			{
				if (ft_resolve(tab, &(*list)->next))
					return (1);
				else
					ft_undraw(tab, list, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}
