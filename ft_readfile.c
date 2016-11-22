/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegoube <clegoube@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 20:55:55 by clegoube          #+#    #+#             */
/*   Updated: 2016/11/20 20:17:43 by clegoube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_open(int fd)
{
	if (fd == -1)
	{
		ft_putstr("Open failed \n");
		return (1);
	}
	return (0);
}

int	ft_close(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr("Close failed \n");
		return (1);
	}
	return (0);
}

int	ft_read(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	if (argc < 2)
		ft_putstr("File name missing.\n");
	if (argc > 2)
		ft_putstr("Too many arguments.\n");
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (ft_open(fd) == 1)
			return (1);
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
		//ft_checkfile(buff);
		ft_putstr(buff);
		if (ft_close(fd) == 1)
			return (1);
	}
	return (0);
}
