/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:52:27 by ahrytsen          #+#    #+#             */
/*   Updated: 2018/07/22 13:26:40 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void		lst_del(void *content, size_t size)
{
	t_cmd	*cmd;

	(void)size;
	cmd = content;
	ft_strarr_free(cmd->argv);
	free(cmd);
}

static t_list	*ft_makecmd(int ac, char **av, int in_out[2])
{
	int		i;
	t_cmd	tmp;
	t_list	*cmd;

	i = 1;
	while (++i < ac - 1)
	{
		ft_bzero(&tmp, sizeof(t_cmd));
		i == 2 ? (tmp.std_in = in_out[0]) : 0;
		i == ac - 2 ? (tmp.std_out = in_out[1]) : 0;
		if (!(tmp.argv = ft_strsplit(av[i], ' '))
			|| !ft_lstpush_back(&cmd, &tmp, sizeof(tmp)))
		{
			ft_dprintf(2, "%s: allocation error\n", av[0]);
			ft_lstdel(&cmd, lst_del);
			return (NULL);
		}
	}
	return (cmd);
}

static int		ft_open_files(int ac, char **av, int in_out[2])
{
	if ((ac < 5 && ft_dprintf(2, "error: Wrong number of arguments\n")
			&& ft_dprintf(2, "usage:\n%s file_in cmd1 cmd2 "
							"[... cmdN] file_out\n", av[0]))
		|| (access(av[1], F_OK)
			&& ft_dprintf(2, "%s: no such file: %s\n", av[0], av[1]))
		|| (access(av[1], R_OK)
			&& ft_dprintf(2, "%s: permission danied: %s\n", av[0], av[1]))
		|| (!access(av[ac - 1], F_OK) && access(av[ac - 1], W_OK)
			&& ft_dprintf(2, "%s: permission danied: %s\n", av[0], av[ac - 1]))
		|| ((in_out[0] = open(av[1], O_RDONLY)) < 0
			&& ft_dprintf(2, "%s: open error: %s\n", av[0], av[1]))
		|| ((in_out[1] = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC,
							S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0
			&& ft_dprintf(2, "%s: open error: %s\n", av[0], av[ac - 1])))
		return (-1);
	return (0);
}

int				main(int ac, char **av)
{
	int		in_out[2];
	t_list	*cmds;

	if (ft_open_files(ac, av, in_out)
		|| !(cmds = ft_makecmd(ac, av, in_out)))
		return (1);
	return (ft_exec(cmds));
}
