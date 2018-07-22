/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:55:48 by ahrytsen          #+#    #+#             */
/*   Updated: 2018/07/22 13:27:16 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct s_cmd	t_cmd;
struct					s_cmd
{
	pid_t	pid;
	int		std_in;
	int		std_out;
	int		to_close;
	int		ret;
	char	**argv;
};

int						ft_exec(t_list *cmds);

#endif
