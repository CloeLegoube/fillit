/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:11:32 by clegoube          #+#    #+#             */
/*   Updated: 2016/12/01 18:23:57 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_stock_struct(t_list *list, char ** tab)
{
	int		i;
	t_list	*new;

	i = 0;
	new = list;
	while (tab[i])
	{
		(*list).content = ft_strsplit(tab[i], '*');
		list = list->next;
		i++;
	}
	list = new;
	// while (list)
	// {
	// 	ft_print_words_tables((char **)(list->content));
	// 	list = list->next;
	// }
}
