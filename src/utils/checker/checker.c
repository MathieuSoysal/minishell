/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 20:53:59 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/14 21:02:14 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal_checker.h"
#include <aio.h>

t_syntax_error	check_syntax(const char *command_line)
{
	t_syntax_mode	mode;
	t_syntax_error	error;
	size_t			i;

	mode = SM_START_LINE;
	i = 0;
	while (command_line[i])
	{
		if (is_unexpected_character(command_line[i], mode))
		{
			error = get_syntax_error_from_two_chars(command_line[i],
					command_line[i + 1]);
			if (error != NO_ERROR)
				return (error);
		}
		update_syntax_mode(&mode, command_line[i]);
		i++;
	}
	return (NO_ERROR);
}
