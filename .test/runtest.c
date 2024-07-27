/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:45:31 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/25 15:23:44 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "acutest.h"
#include "structures/double_linked_list/test_double_linked_list_essentials.h"
#include "structures/double_linked_list/test_double_linked_list_head.h"
#include "structures/double_linked_list/test_double_linked_list_tail.h"
#include "utils/checker/test_checker_all.h"
#include "utils/checker/test_checker_double_pipe.h"
#include "utils/checker/test_checker_infile.h"
#include "utils/checker/test_checker_infile_heredoc.h"
#include "utils/checker/test_checker_new_line.h"
#include "utils/checker/test_checker_outfile.h"
#include "utils/checker/test_checker_outfile_append.h"
#include "utils/checker/test_checker_pipe.h"
#include "utils/parser/test_internal_dollar.h"
#include "utils/parser/test_internal_outfiles.h"
#include "utils/parser/test_internal_parser.h"
#include "utils/parser/test_internal_string.h"
#include <stdio.h>

// Run TESTs
TEST_LIST = {
	//
	{"Double Linked List Essentials", test_double_linked_list_essentials},
	{"Double Linked List Head", test_double_linked_list_head},
	{"Double Linked List Tail", test_double_linked_list_tail},
	{"Checker Pipe", test_check_syntax_pipe_all},
	{"Checker Double Pipe", test_check_syntax_double_pipe_all},
	{"Checker Infile", test_check_syntax_infile_all},
	{"Checker Infile Heredoc", test_check_syntax_infile_heredoc_all},
	{"Checker Outfile", test_check_syntax_outfile_all},
	{"Checker Outfile Append", test_check_syntax_outfile_append_all},
	{"Checker New Line", test_check_syntax_new_line_all},
	{"Checker All", test_check_syntax_no_error_all},
	{"Parser Internal", test_split_internal_parser},
	{"Parser Internal with dollars", test_apply_dollars_all},
	{"Parser Internal with string", test_apply_strings_all},
	{"Parser Internal with outfiles", test_outfiles_all},
	{NULL, NULL} //
};
