/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_internal_dollar.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:20:18 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/18 05:09:45 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_INTERNAL_DOLLAR_H
# define TEST_INTERNAL_DOLLAR_H

# include "../../acutest.h"
# include "internal_parser.h"
# include "test_ultis.h"

void	test_apply_dollars1(void)
{
	char	*command_line;
	char	*expected;
	char	*actual;
	char	**env;

	env = (char *[]){"USER=hsoysal", NULL};
	command_line = ft_strdup("$USER");
	expected = ft_strdup("hsoysal");
	actual = apply_dollars(command_line, env);
	assert_equals(expected, actual);
	free(expected);
	free(actual);
}

void	test_apply_dollars2(void)
{
	char	*command_line;
	char	*expected;
	char	*actual;
	char	*env[] = {"USER=hsoysal", NULL};

	command_line = ft_strdup("\"$\"USER");
	expected = ft_strdup("\"$\"USER");
	actual = apply_dollars(command_line, env);
	assert_equals(expected, actual);
	free(expected);
	free(actual);
}

void	test_apply_dollars3(void)
{
	char	*command_line;
	char	*expected;
	char	*actual;
	char	*env[] = {"USER=hsoysal", NULL};

	command_line = ft_strdup("dsad$USER");
	expected = ft_strdup("dsadhsoysal");
	actual = apply_dollars(command_line, env);
	assert_equals(expected, actual);
	free(expected);
	free(actual);
}

void	test_apply_dollars4(void)
{
	char	*command_line;
	char	*expected;
	char	*actual;
	char	*env[] = {"USER=hsoysal", NULL};

	command_line = ft_strdup("\"$USER\"");
	expected = ft_strdup("\"hsoysal\"");
	actual = apply_dollars(command_line, env);
	assert_equals(expected, actual);
	free(expected);
	free(actual);
}

void	test_apply_dollars5(void)
{
	char	*command_line;
	char	*expected;
	char	*actual;
	char	*env[] = {"USER=hsoysal", NULL};

	command_line = ft_strdup("\"$\"");
	expected = ft_strdup("\"$\"");
	actual = apply_dollars(command_line, env);
	assert_equals(expected, actual);
	free(expected);
	free(actual);
}

void	test_apply_dollars6(void)
{
	char	*command_line;
	char	*expected;
	char	*actual;
	char	*env[] = {"USER=hsoysal", NULL};

	command_line = ft_strdup("\"$s\"");
	expected = ft_strdup("\"\"");
	actual = apply_dollars(command_line, env);
	assert_equals(expected, actual);
	free(expected);
	free(actual);
}

void	test_apply_dollars_all(void)
{
	test_apply_dollars1();
	test_apply_dollars2();
	test_apply_dollars3();
	test_apply_dollars4();
	test_apply_dollars5();
	test_apply_dollars6();
}

#endif // TEST_INTERNAL_DOLLAR_H
