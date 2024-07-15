/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_internal_parser.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:42:01 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/15 20:00:01 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_INTERNAL_PARSER_H
# define TEST_INTERNAL_PARSER_H

# include "../../acutest.h"
# include "internal_parser.h"
# include "test_ultis.h"

static void	free_all(char **result)
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

void	test_split_by_pipe1(void)
{
	char	**result;

	result = split_by_pipe("ls | cat | wc");
	assert_equals("ls ", result[0]);
	assert_equals(" cat ", result[1]);
	assert_equals(" wc", result[2]);
    free_all(result);
}

void	test_split_by_pipe2(void)
{
	char	**result;

	result = split_by_pipe("ls | cat | wc | grep");
	assert_equals("ls ", result[0]);
	assert_equals(" cat ", result[1]);
	assert_equals(" wc ", result[2]);
	assert_equals(" grep", result[3]);
    free_all(result);
}

void	test_split_by_pipe3(void)
{
	char	**result;

	result = split_by_pipe("   echo \"Salut || test\"  | cat | wc | grep");
	assert_equals("   echo \"Salut || test\"  ", result[0]);
	assert_equals(" cat ", result[1]);
	assert_equals(" wc ", result[2]);
	assert_equals(" grep", result[3]);
    free_all(result);
}

void	test_split_by_pipe4(void)
{
	char	**result;

	result = split_by_pipe("   echo \"Salut || test\"  || cat | wc | grep");
	assert_equals("   echo \"Salut || test\"  ", result[0]);
	assert_equals(" cat ", result[1]);
	assert_equals(" wc ", result[2]);
	assert_equals(" grep", result[3]);
    free_all(result);
}

void	test_split_by_pipe(void)
{
	test_split_by_pipe1();
	test_split_by_pipe2();
    test_split_by_pipe3();
    test_split_by_pipe4();
}

#endif // TEST_INTERNAL_PARSER_H
