/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:46:53 by zjaddad           #+#    #+#             */
/*   Updated: 2023/01/03 19:32:48 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc(char **av, char **env)
{
	int		i;
	int		j;
	char	*pth;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			pth = ft_strchr(env[i], '/');
			path(pth, env);
		}
		i++;
	}
}

void	parent_proc()
{
	
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	pid;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			exit(1);
		pid = fork();
		if (pid == -1)
			exit(1);
		if (pid == 0)
		{
			child_proc(av, env);
			close(fd[0]);
			write(fd[0], &av[4], 1);
			close(fd[1]);
		}
		else
		{
			close(fd[1]);
			read(fd[0], &av[4], 1);
			close(fd[0]);
			wait(NULL);
		}	
	}
	return (0);
}
