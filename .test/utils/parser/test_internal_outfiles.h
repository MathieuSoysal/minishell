/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_internal_outfiles.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:12:09 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/27 11:04:59 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_INTERNAL_OUTFILES_H
# define TEST_INTERNAL_OUTFILES_H

# include "../../acutest.h"
# include "apply_outfiles.h"
# include "test_utils.h"

static char	**clone(char **command_line)
{
	char	**clone;
	int		i;

	i = 0;
	while (command_line[i])
		i++;
	clone = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (command_line[i])
	{
		clone[i] = ft_strdup(command_line[i]);
		i++;
	}
	clone[i] = NULL;
	return (clone);
}

void	test_extract_outfiles1(void)
{
	char	**result;
	char	**command_line;

	command_line = clone((char *[]){"ls", ">", "file", NULL});
	result = extract_outfiles(command_line);
	assert_equals("file", result[0]);
	free_all(result);
}

void	test_extract_outfiles2(void)
{
	char	**result;
	char	**command_line;

	command_line = clone((char *[]){"ls", ">", "file", ">", "file2", NULL});
	result = extract_outfiles(command_line);
	assert_equals("file", result[0]);
	assert_equals("file2", result[1]);
	free_all(result);
}

void	test_extract_outfiles3(void)
{
	char	**result;
	char	**command_line;

	command_line = clone((char *[]){"ls", ">", "file", ">", "file2", ">",
			"file3", NULL});
	result = extract_outfiles(command_line);
	assert_equals("file", result[0]);
	assert_equals("file2", result[1]);
	assert_equals("file3", result[2]);
	free_all(result);
}

void	test_outfiles_all(void)
{
	test_extract_outfiles1();
	test_extract_outfiles2();
	test_extract_outfiles3();
}

#endif // TEST_INTERNAL_OUTFILES_H
