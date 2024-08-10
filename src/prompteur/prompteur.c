/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompteur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 07:12:41 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 09:45:42 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minishell.h"
#include "internal.h"
#include <stdbool.h>
#include <unistd.h>

void	prompt(void)
{
	if (get_exit_status(_LAST_STATUS) == 0)
		write(1, "\033[1;32m", 8);
	else
		write(1, "\033[1;31m", 8);
	write(1, "⇒ ", 5);
	write(1, "\033[1;30m", 8);
	if (!is_in_git_repo())
	{
		ft_putstr_fd(getcwd(NULL, 0), 1);
	}
	if (get_exit_status(_LAST_STATUS) == 0)
		write(1, "\033[1;32m", 8);
	else
		write(1, "\033[1;31m", 8);
	ft_putstr_fd(" ▷ \033[40;0m", 1);
}
