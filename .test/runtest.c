/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:45:31 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/14 21:52:16 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "acutest.h"
#include "structures/double_linked_list/test_double_linked_list_essentials.h"
#include "structures/double_linked_list/test_double_linked_list_head.h"
#include "structures/double_linked_list/test_double_linked_list_tail.h"
#include "utils/checker/test_checker_double_pipe.h"
#include "utils/checker/test_checker_infile.h"
#include "utils/checker/test_checker_pipe.h"
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
	{NULL, NULL} //
};
