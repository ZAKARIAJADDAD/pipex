/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:11:46 by zjaddad           #+#    #+#             */
/*   Updated: 2023/01/14 21:02:42 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_cm1(char **av, char **env, t_pp pp)
{
	int		i;
	char	**s_path;

	s_path = path_split(env);
	pp.p_data.cmd = ft_split(av[2], ' ');
	printf("cmd1 = %s\n", pp.p_data.cmd[0]);
	if (av[2][0] == '/')
	{
		execve(av[2], pp.p_data.cmd, env);
		write(2, "cmd not found!", 15);
		exit(1);
	}
	if (s_path)
	{
		i = 0;
		while (s_path[i++])
		{
			pp.p_data.link1 = ft_strjoin(s_path[i], "/");
			pp.p_data.link2 = ft_strjoin(pp.p_data.link1, pp.p_data.cmd[0]);
			if (access(pp.p_data.link2, X_OK) == 0)
				execve(pp.p_data.link2, pp.p_data.cmd, env);
		}
	}
	write(2, "cmd not found\n", 15);
	exit(127);
}

void	path_cm2(char **av, char **env, t_pp pp)
{
	int		i;
	char	**s_paths;

	s_paths = path_split(env);
	pp.p_data.cmd = ft_split(av[3], ' ');
	if (av[3][0] == '/')
	{
		execve(av[3], pp.p_data.cmd, env);
		perror("Error");
		exit(1);
	}
	if (s_paths)
	{
		i = 0;
		while (s_paths[i])
		{
			pp.p_data.link1 = ft_strjoin(s_paths[i], "/");
			pp.p_data.link2 = ft_strjoin(pp.p_data.link1, pp.p_data.cmd[0]);
			if (access(pp.p_data.link2, X_OK) == 0)
				execve(pp.p_data.link2, pp.p_data.cmd, env);
			i++;
		}
	}
	write(2, "cmd not found\n", 15);
	exit(127);
}
