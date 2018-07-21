/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:52:27 by ahrytsen          #+#    #+#             */
/*   Updated: 2018/07/21 15:07:16 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	ft_usage(char *name)
{
	ft_dprintf(2, "usage:\n%s filein cmd1 cmd2 [... cmdN] fileout\n", name);
}

static int	ft_check_argv(int ac, char **av)
{
	if (ac < 5 && ft_dprintf(2, "error: Wrong number of arguments\n"))
		ft_usage(*av);
	else
		return (0);
	return (-1);

}

t_cmd		*ft_makecmd(int ac, char **av)
{
	int	in_fd;
	int	out_fd;

	if ((access(av[1], F_OK)
			&& ft_dprintf(2, "%s: no such file: %s\n", av[0], av[1]))
		|| (access(av[1], R_OK)
			&& ft_dprintf(2, "%s: permission danied: %s\n", av[0], av[1]))
		|| (!access(av[ac - 1], F_OK) && access(av[ac - 1], W_OK)
			&& ft_dprintf(2, "%s: permission danied: %s\n", av[0], av[ac - 1]))
		|| ((in_fd = open(av[1], O_RDONLY)) < 0
			&& ft_dprintf(2, "%s: open error: %s\n", av[0], av[1]))
		|| ((out_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC,
						S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0
			&& ft_dprintf(2, "%s: open error: %s\n", av[0], av[ac - 1])))
		return (NULL);
	return (NULL);
}

int			main(int ac, char **av)
{
	if (ft_check_argv(ac, av))
		return (1);
	ft_makecmd(ac, av);
}
