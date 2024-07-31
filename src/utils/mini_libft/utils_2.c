/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 03:03:27 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/31 12:03:56 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"
#include <stdbool.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
