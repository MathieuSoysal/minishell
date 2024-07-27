/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_internal_parser.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:42:01 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/25 15:20:21 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_INTERNAL_PARSER_H
# define TEST_INTERNAL_PARSER_H

# include "../../acutest.h"
# include "internal_parser.h"
# include "test_utils.h"

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

void	test_split_by_space1(void)
{
	char	**result;

	result = split_by_space("ls -l");
	assert_equals("ls", result[0]);
	assert_equals("-l", result[1]);
	free_all(result);
}

void	test_split_by_space2(void)
{
	char	**result;

	result = split_by_space("ls echo \"|||| hola ceta\" | cat | cat");
	assert_equals("ls", result[0]);
	assert_equals("echo", result[1]);
	assert_equals("\"|||| hola ceta\"", result[2]);
	assert_equals("|", result[3]);
	assert_equals("cat", result[4]);
	assert_equals("|", result[5]);
	assert_equals("cat", result[6]);
	free_all(result);
}

void	test_split_by_space3(void)
{
	char	**result;

	result = split_by_space("ls echo\"|||| hola ceta\" | cat | cat");
	assert_equals("ls", result[0]);
	assert_equals("echo\"|||| hola ceta\"", result[1]);
	assert_equals("|", result[2]);
	assert_equals("cat", result[3]);
	assert_equals("|", result[4]);
	assert_equals("cat", result[5]);
	free_all(result);
}

void	test_split_by_space(void)
{
	test_split_by_space1();
	test_split_by_space2();
    test_split_by_space3();
}

void	test_split_internal_parser(void)
{
	test_split_by_pipe();
	test_split_by_space();
}

#endif // TEST_INTERNAL_PARSER_H
