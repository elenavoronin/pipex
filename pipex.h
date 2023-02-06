/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 15:12:46 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/06 16:58:52 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>

// typedef struct s_list
// {
// 	int	argc;
// 	int	**argv;
// }		t_list;

int	pipex(int argc, char **argv);

#endif