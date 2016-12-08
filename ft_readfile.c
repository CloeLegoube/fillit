/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:55:55 by clegoube          #+#    #+#             */
/*   Updated: 2016/12/07 18:33:55 by jjaouen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (new && *alst)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*alst = new;
}

void	del(void *content, size_t content_size)
{
	free(content);
	content_size = 0;
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

t_list	*ft_read(int argc, char **argv)
{
	t_var	*vari;
	t_list	*list;
	t_list	*new;
	t_list	*coor;
	char	buff[22];

	list = NULL;
	coor = NULL;
	vari = (t_var*)malloc(sizeof(t_var));
	if (argc == 2)
	{
		vari->fd = open(argv[1], O_RDONLY);
		if (vari->fd == -1)
			ft_error();
		while ((vari->ret = read(vari->fd, buff, 21)) && (vari->n += vari->ret))
		{
			new = ft_lstnew(ft_strsub(buff, 0, 20), 20);
			ft_lstadd_end(&list, new);
		}
		((vari->n) + 1) % 21 != 0 ? ft_error() : NULL;
		if (ft_checkfile(list, buff) != 1)
			ft_error();
		coor = ft_coordo(list);
	}
	return (coor);
}
