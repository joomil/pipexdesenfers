/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:04:09 by jmilesi           #+#    #+#             */
/*   Updated: 2023/11/04 12:51:41 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		errno = EINVAL;
		perror("Dr Vinklestein says: enter 4 arguments");
		exit(EXIT_FAILURE);
	}
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child(av, p_fd, env);
	parent(av, p_fd, env);
	return (0);
}

void	child(char **av, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(av[1], 0);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[0]);
	exec(av[2], env);
}

void	parent(char **av, int *p_fd, char **env)
{
	int		fd;

	fd = open_file(av[4], 1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[1]);
	exec(av[3], env);
}

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = ft_get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
	{
		perror("Shpongolese not spoken here, enter correct commands");
		ft_free_tab(s_cmd);
		exit(EXIT_FAILURE);
	}
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY, 0444);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ret == -1)
	{
		perror("Are you Shpongled?");
		exit(EXIT_FAILURE);
	}
	return (ret);
}

char	*ft_get_env(char **env)
{
	while (*env++)
		if (ft_strncmp(*env, "PATH", 4) == 0)
			return (*env + 5);
	return (NULL);
}

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	**s_cmd;

	
	i = -1;
	allpath = ft_split(ft_get_env(env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		exec = ft_strjoin(ft_strjoin(allpath[i], "/"), s_cmd[0]);
		if (access(exec, F_OK | X_OK) == 0)
			break;
		free(exec);
	}
	ft_free_tab(allpath);
	ft_free_tab(s_cmd);
	if (access(exec, F_OK | X_OK) == 0)
		return(exec);
	return (cmd);
}