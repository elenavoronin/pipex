/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: evoronin <evoronin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/06 15:09:33 by evoronin      #+#    #+#                 */
/*   Updated: 2023/02/06 16:58:43 by evoronin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// "../../usr/bin"
#include "pipex.h"
#include "ft_printf.h"

int	pipex(int argc, char **argv)
{
	 //error handling first (no arguments or < 4 arguments,
	if (argc < 5)
	{
		ft_printf("Not enough arguments entered");
		return (0);
	}
	//commands are not bash commands, no files input or output)
	if argv
}

int main(void)
{
	pipex;
	return (0);
}