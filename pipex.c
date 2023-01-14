/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjaddad <zjaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:46:53 by zjaddad           #+#    #+#             */
/*   Updated: 2023/01/14 13:50:19 by zjaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	second_fork(char **av, char **env, t_pp pp)
{
	if (pp.pid1 == -1)
	{
		perror("Fork");
		exit(1);
	}
	if(pp.pid1 == 0)
	{
		close(pp.fd[1]);
		if (dup2(pp.fd[0], 0) == -1)
		{
			write(2, "Dup Error1!\n", 12);
			exit(1);
		}
		if (dup2(pp.fd_outf, 1) == -1)
		{
			write(2, "Dup Error2!\n", 12);
			exit(1);
		}
		path_cm2(av, env, pp);
	}
}

void	first_fork(char **av, char **env, t_pp pp)
{
	if (pp.pid == -1)
	{
		perror("Fork");
		exit(1);
	}
	if (pp.pid == 0)
	{
		close(pp.fd[0]);
		if (dup2(pp.fd_inf, 0) == -1)
		{
			write(2, "Dup Error3!\n", 12);
			exit(1);
		}
		if (dup2(pp.fd[1], 1) == -1)
		{
			write(2, "Dup Error4!\n", 12);
			exit(1);
		}
		path_cm1(av, env, pp);
	}
}

void	get_process(char **av, char **env, t_pp pp)
{
	if (pipe(pp.fd) == -1)
	{
		perror("Pipe Error");
		exit(1);
	}
	pp.pid = fork();
	first_fork(av, env, pp);
	pp.pid1 = fork();
	second_fork(av, env, pp);
	close(pp.fd[1]);
	close(pp.fd[0]);
	close(pp.fd_inf);
	close(pp.fd_outf);
	waitpid(pp.pid, NULL, 0);
	waitpid(pp.pid1, NULL, 0);
}

int	main(int ac, char **av, char **env)
{
	t_pp	pp;

	if (ac == 5)
	{
		pp.fd_inf= open(av[1], O_RDWR);
		if (pp.fd_inf == -1)
			perror("ERROR!\n");
		pp.fd_outf = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (pp.fd_outf == -1)
		{
			perror("ERROR!\n");
			exit(1);
		}	
		get_process(av, env, pp);
	}
	else
	{
		write(2, "Error format : ./pipex file1 cmd1 cmd2 file2\n", 46);
		exit(1);
	}
}
