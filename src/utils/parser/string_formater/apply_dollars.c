/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_dollars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:18:36 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/31 09:36:23 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../structures/double_linked_list/double_linked_list.h"
#include "../internal_parser.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	is_valid_dollar(char c)
{
	return (c == '_' || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}

static char	*get_dollar(char const *command_line, size_t *i,
		bool is_string_mode, char **env)
{
	size_t	j;
	char	*result;

	j = *i;
	if (!is_valid_dollar(command_line[j]))
		return (ft_strndup("$", 1));
	while (command_line[j] && is_valid_dollar(command_line[j]))
		j++;
	result = get_from_env(env, ft_strndup(command_line + *i, j - *i));
	*i = j;
	return (result);
}

char	*apply_dollars(char *command_line, char **env)
{
	t_double_linked_list	*list;
	size_t					i;
	char					*result;

	list = double_linked_list_create();
	i = 0;
	while (command_line[i])
	{
		if (command_line[i] == '$')
		{
			i++;
			double_linked_list_add_last(list, get_dollar(command_line, &i,
					false, env));
		}
		else
			double_linked_list_add_last(list, get_word_until(command_line, &i,
					'$'));
	}
	result = concatenate(list);
	free(command_line);
	return (result);
}
