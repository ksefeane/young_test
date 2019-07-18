/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksefeane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 10:49:32 by ksefeane          #+#    #+#             */
/*   Updated: 2019/07/17 14:12:49 by ksefeane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "young_test.h"

int		ft_writer(const int fd, const int fd2)
{
	char	*w;

	w = NULL;
	get_next_line(fd, &w);
	write(fd2, w, ft_strlen(w));
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	int		fd2;

	fd2 = 0;
	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	if (ac == 1)
	{
		fd = 1;
		fd2 = (fd2 == 0) ? open("sample.txt", O_CREAT | O_RDWR):
			open("sample.txt", O_RDWR | O_APPEND);
		ft_writer(fd, fd2);
	}
	else if (ac == 2)
	{
		ft_reader(fd, 0);
	}
	else if (ac == 3)
	{
		ft_reader(fd, ft_atoi(av[2]));
	}
	else
		ft_putendl("please select text file to read from");
	return (0);
}
