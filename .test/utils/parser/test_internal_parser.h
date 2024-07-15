/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_internal_parser.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:42:01 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/15 16:50:30 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_INTERNAL_PARSER_H
# define TEST_INTERNAL_PARSER_H

# include "../../acutest.h"
# include "internal_parser.h"
# include "test_ultis.h"

void	test_split_by_pipe(void)
{
	char	**result;

	result = split_by_pipe("ls | cat | wc");
	assert_equals("ls ", result[0]);
	assert_equals(" cat ", result[1]);
	assert_equals(" wc", result[2]);
}

#endif // TEST_INTERNAL_PARSER_H
