/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompteur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 07:12:41 by hsoysal           #+#    #+#             */
/*   Updated: 2024/08/10 07:13:47 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
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
	write(1, PROMPT, 11);
}
