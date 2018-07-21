/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 11:52:27 by ahrytsen          #+#    #+#             */
/*   Updated: 2018/07/21 12:24:07 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	ft_usage(void)
{
	ft_dprintf(2, "filein cmd1 ... cmdN fileout\n");
}



int	main(int ac, char **av)
{
	ft_dprintf(1, "hello world %d, %s\n", ac, *av);
}
