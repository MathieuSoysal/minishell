/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ultis.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:32:17 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/15 16:35:42 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_ULTIS_H
# define TEST_ULTIS_H

# include "../../acutest.h"
# include <stdio.h>

void	assert_equals(char const *expected, char const *actual)
{
	TEST_CHECK(strcmp(expected, actual) == 0);
	if (strcmp(expected, actual) != 0)
	{
		dprintf(2, "           \033[31mExpected:\033[0m %s\n", expected);
		dprintf(2, "           \033[31mActual:\033[0m %s\n", actual);
	}
}

#endif // TEST_ULTIS_H
