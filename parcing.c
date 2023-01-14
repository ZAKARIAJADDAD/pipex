/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:44:50 by zjaddad           #+#    #+#             */
/*   Updated: 2023/01/14 02:20:45 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

char	**path_split(char **env)
{
	int		i;
	char	*pth;
	char	**pt;

	i = 0;
	pt = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			pth = ft_strchr(env[i], '/');
			pt = ft_split(pth, ':');
		}
		i++;
	}
	return (pt);
}

char	**path(char **av, char **env, t_pp pp)
{
	int		i;
	char	**s_path;

	s_path = path_split(env);
	pp.p_data.cmd = ft_split(av[pp.av_x], ' ');
	if (av[pp.av_x][0] == '/')
	{
		execve(av[pp.av_x], pp.p_data.cmd, env);
		perror("Error");
		exit(1);
	}
	if (s_path)
	{
		i = 0;
		while (s_path[i])
		{
			pp.p_data.link1 = ft_strjoin(s_path[i], "/");
			pp.p_data.link2 = ft_strjoin(pp.p_data.link1, av[pp.av_x]);
			if (access(pp.p_data.link2, X_OK) == 0)
				execve(pp.p_data.link2, pp.p_data.cmd, env);
			// free(pp.p_data.link1);
			// free(pp.p_data.link2);
			i++;
		}
	}
	return (s_path);
}