/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 03:03:27 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/31 14:44:43 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"
#include <stdbool.h>
#include <stdlib.h>

char	*get_word_until(char const *command_line, size_t *i,
		char const delimiter)
{
	char	*word;
	size_t	j;

	j = *i;
	while (command_line[j] && command_line[j] != delimiter)
		j++;
	word = ft_strndup(command_line + *i, j - *i);
	*i = j;
	return (word);
}

char	*concatenate(t_double_linked_list *list)
{
	char	*result;
	char	*new_word;
	char	*temp;

	new_word = NULL;
	result = ft_strdup("");
	if (!result)
		return (NULL);
	while (list->size > 0)
	{
		free(new_word);
		new_word = double_linked_list_pop_first(list);
		if (!new_word)
			return (free(result), NULL);
		temp = result;
		result = ft_strjoin(temp, new_word);
		free(temp);
		if (!result)
			return (NULL);
	}
	free(new_word);
	free(list);
	list = NULL;
	return (result);
}

bool	equals(const char *s1, const char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s2)) == 0);
}
