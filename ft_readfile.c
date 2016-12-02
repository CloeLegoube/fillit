/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:55:55 by clegoube          #+#    #+#             */
/*   Updated: 2016/12/02 19:55:45 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *temp;

	temp = *alst;
	if (new && *alst)
	{
			while(temp->next)
				temp = temp->next;
			temp->next = new;
	}
	else
		*alst = new;
}

void del(void *content, size_t content_size)
{
		free(content);
		content_size = 0;
}

int	ft_read(int argc, char **argv)
{
	int		fd;
	int		ret;
	t_list	*list;
	t_list	*new;
	t_list	*coor;
	char	buff[BUFF_SIZE + 1];

	list = NULL;
	if ((argc < 2) || (argc > 2))
		ft_putstr("usage : ./fillit source_file\n");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = read(fd, buff, 21)))
		{
			new = ft_lstnew(ft_strsub(buff, 0, 20), 20);
			ft_lstadd_end(&list, new);
		}
		if (ft_checkfile(list, buff) != 1)
			exit(1);
		coor  = ft_coordo(list);
		ft_solve(coor);


		// while (list)
		// {
		// 	ft_print_words_tables(list->content);
		// 	list = list->next;
		// }
//		ft_transform_point(list);
//		ft_transform_point_line(list);
//		ft_transform_point_col(list);
//		ft_transform_letter(list);
//		ft_remove_star(list);
//		ft_stock_struct(list, ft_remove_star(list));
	}
	return (1);
}
