/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:32:17 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/25 15:32:09 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_H
# define TEST_UTILS_H

# include "../../acutest.h"
# include <stdio.h>

void	assert_equals(char const *expected, char const *actual)
{

	TEST_CHECK(expected != NULL && actual != NULL);
	TEST_CHECK(strcmp(expected, actual) == 0);
	if (strcmp(expected, actual) != 0)
	{
		dprintf(2, "           \033[31mExpected:\033[0m %s\n", expected);
		dprintf(2, "           \033[31mActual:\033[0m %s\n", actual);
	}
}

void	free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

#endif // TEST_UTILS_H
