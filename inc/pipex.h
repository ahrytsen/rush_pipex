/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:55:48 by ahrytsen          #+#    #+#             */
/*   Updated: 2018/07/21 15:05:27 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PIPEX_H
# define	PIPEX_H

# include <libft.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct s_cmd	t_cmd;
struct					s_cmd
{
	pid_t	pid;
	char 	**argv;
	int		std_in;
	int		std_out;
	t_cmd	*next;
	t_cmd	*prev;
};

#endif
