/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:55:55 by clegoube          #+#    #+#             */
/*   Updated: 2016/12/04 11:36:29 by clegoube         ###   ########.fr       */
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
	size_t	loop;
	size_t	i;
	t_list	*list;
	t_list	*new;
	t_list	*coor;
	char	buff[BUFF_SIZE + 1];

	loop = 0;
	list = NULL;
	coor = NULL;
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
		while (coor)
		{
			i = 0;
			printf("letter_read : %c\n", ((t_coor *)(coor->content))->letter);
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


		ft_solve(coor, loop);


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
