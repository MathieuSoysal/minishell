/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_internal_string.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:09:06 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/19 01:26:33 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_INTERNAL_STRING_H
# define TEST_INTERNAL_STRING_H

# include "../../acutest.h"
# include "internal_parser.h"
# include "test_ultis.h"

void	test_apply_strings1(void)
{
	char	*str;
	char	*expected;
	char	*actual;

	str = ft_strdup("Hello World");
	expected = ft_strdup("Hello World");
	actual = apply_strings(str);
	assert_equals(expected, actual);
	free(expected);
	free(actual);
}

void	test_apply_strings2(void)
{
	char	*str;
	char	*expected;
	char	*actual;

	str = ft_strdup("\"Hello World\"");
	expected = ft_strdup("Hello World");
	actual = apply_strings(str);
	assert_equals(expected, actual);
	free(expected);
	free(actual);
}

void	test_apply_strings3(void)
{
	char	*str;
	char	*expected;
	char	*actual;

	str = ft_strdup("\"Hello\'\' World\"");
	expected = ft_strdup("Hello\'\' World");
	actual = apply_strings(str);
	assert_equals(expected, actual);
	free(expected);
	free(actual);
}

void	test_apply_strings_all(void)
{
	test_apply_strings1();
	test_apply_strings2();
	test_apply_strings3();
}

#endif // TEST_INTERNAL_STRING_H
