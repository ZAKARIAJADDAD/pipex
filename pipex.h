/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:21:19 by zjaddad           #+#    #+#             */
/*   Updated: 2023/01/14 21:34:42 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<fcntl.h>

///STRUCT////////////////////////////
typedef struct pip
{
	char	*link1;
	char	*link2;
	char	**cmd;
}	t_data;

typedef struct pipex{
	int		fd[2];
	int		pid;
	int		pid1;
	int		av_x;
	int		av_y;
	int		fd_inf;
	int		fd_outf;
	t_data	p_data;
}	t_pp;
///STRUCT////////////////////////////

void	path_cm2(char **av, char **env, t_pp pp);
void	path_cm1(char **av, char **env, t_pp pp);
char	**path_split(char **env);

///LIBFT////////////////////////////
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(char *str, int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	**ft_split(char const *s, char c);
///LIBFT////////////////////////////

#endif