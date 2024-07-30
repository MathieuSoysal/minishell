/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_internal_infiles.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:12:09 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/30 17:41:29 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_INTERNAL_INFILES_H
# define TEST_INTERNAL_INFILES_H

# include "../../acutest.h"
# include "infiles/apply_infiles.h"
# include "internal_parser.h"
# include "test_utils.h"
# include <stdlib.h>

static char	**clone2(char **command_line)
{
	char	**clone;
	int		i;

	i = 0;
	while (command_line[i])
		i++;
	clone = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (command_line[i])
	{
		clone[i] = strdup(command_line[i]);
		i++;
	}
	clone[i] = NULL;
	return (clone);
}

void	test_extract_infiles1(void)
{
	t_infile	**result;
	char		**command_line;

	command_line = clone2((char *[]){"ls", "<", "file", NULL});
	result = extract_infiles(command_line);
	assert_equals("file", result[0]->value.file_name_value);
}

void	test_extract_infiles2(void)
{
	t_infile	**result;
	char		**command_line;

	command_line = clone2((char *[]){"ls", "<", "file", "<", "file2", NULL});
	result = extract_infiles(command_line);
	assert_equals("file", result[0]->value.file_name_value);
	assert_equals("file2", result[1]->value.file_name_value);
}

void	test_extract_infiles3(void)
{
	t_infile	**result;
	char		**command_line;

	command_line = clone2((char *[]){"ls", "<", "file", "<", "file2", "<",
			"file3", NULL});
	result = extract_infiles(command_line);
	assert_equals("file", result[0]->value.file_name_value);
	assert_equals("file2", result[1]->value.file_name_value);
	assert_equals("file3", result[2]->value.file_name_value);
}

void	test_extract_infiles4(void)
{
	t_infile	**result;
	char		**command_line;

	command_line = clone2((char *[]){"ls", "<", "file", "<", "file2", "<",
			"file3", "<<", "test", NULL});
	result = extract_infiles(command_line);
	dprintf(1, "salut je suis la\ntest\n");
	assert_equals("file", result[0]->value.file_name_value);
	assert_equals("file2", result[1]->value.file_name_value);
	assert_equals("file3", result[2]->value.file_name_value);
	assert_equals("salut je suis la\n",
		ft_get_next_line(result[3]->value.fd_value));
}

void	test_infiles_all(void)
{
	test_extract_infiles1();
	test_extract_infiles2();
	test_extract_infiles3();
	// test_extract_infiles4();
}

#endif // TEST_INTERNAL_INFILES_H
