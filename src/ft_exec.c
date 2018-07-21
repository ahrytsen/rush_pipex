/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:45:08 by ahrytsen          #+#    #+#             */
/*   Updated: 2018/07/21 15:06:41 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static int	ft_exec_bypath(t_cmd *cmd, char *path)
{
	extern char	**environ;
	struct stat	tmp;

	if (path && !access(path, F_OK) && !access(path, X_OK)
		&& !stat(path, &tmp) && S_ISREG(tmp.st_mode))
	{
		if ((cmd->pid = fork()) > 0)
			return (0);
		else if (cmd->pid < 0)
			return (ft_dprintf(2, "%s: fork error\n", *(cmd->argv)));
		execve(path, cmd->argv, environ);
		exit(1);
	}
	if (access(path, F_OK)
		&& ft_dprintf(2, "%s: No such file or directory\n", *cmd))
		return (1);
	S_ISDIR(tmp.st_mode) ? ft_dprintf(2, "%s: is a directory\n", *cmd)
		: ft_dprintf(2, "%s: permission denied\n", *cmd);
	return (1);
}

static char	**ft_get_path(void)
{
	extern char	**environ;
	char		*path;
	int			i;

	i = 0;
	while (environ[i] && ft_strcmp(environ[i], "PATH") != '=')
		i++;
	path = environ[i];
	return (path ? ft_strsplit(path, ':') : NULL);
}

static char	*ft_search_bin(char *bin_name)
{
	int				i;
	char			*exec_path;
	char			**path;

	i = 0;
	exec_path = NULL;
	if (!(path = ft_get_path()))
		return (NULL);
	while (path[i])
	{
		if (!(exec_path = malloc(ft_strlen(path[i]) + ft_strlen(bin_name) + 2)))
			break ;
		ft_strcpy(exec_path, path[i]);
		ft_strcat(exec_path, "/");
		ft_strcat(exec_path, bin_name);
		if (!access(exec_path, F_OK))
			break ;
		ft_memdel((void**)&exec_path);
	}
	ft_strarr_free(path);
	return (exec_path);
}

int			ft_exec(t_cmd *cmd)
{
	char	*bin_path;
	int		st;

	bin_path = NULL;
	if (ft_strchr(*(cmd->argv), '/'))
		st = ft_exec_bypath(cmd, *(cmd->argv));
	else if ((bin_path = ft_search_bin(*(cmd->argv))))
		st = ft_exec_bypath(cmd, bin_path);
	else
		st = ft_dprintf(2, "%s: command not found\n", *(cmd->argv));
	free(bin_path);
	return (st);
}
