/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:10:04 by jmilesi           #+#    #+#             */
/*   Updated: 2023/11/04 12:52:05 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

int		open_file(char *file, int in_or_out);
void	child(char **av, int *p_fd, char **env);
void	parent(char **av, int *p_fd, char **env);
void	exec(char *cmd, char **env);
char	*ft_get_path(char *cmd, char **env);
char	*ft_get_env(char **env);

#endif
