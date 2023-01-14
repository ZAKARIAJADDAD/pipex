/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:44:50 by zjaddad           #+#    #+#             */
/*   Updated: 2023/01/14 12:10:10 by zjaddad          ###   ########.fr       */
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
