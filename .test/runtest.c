/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:45:31 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/10 14:46:23 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "acutest.h"
#include "structures/double_linked_list/test_double_linked_list_essentials.h"
#include "structures/double_linked_list/test_double_linked_list_head.h"
#include "structures/double_linked_list/test_double_linked_list_tail.h"
#include <stdio.h>

// Run TESTs
TEST_LIST = {
	//
	{"Double Linked List Essentials", test_double_linked_list_essentials},
	{"Double Linked List Head", test_double_linked_list_head},
	{"Double Linked List Tail", test_double_linked_list_tail},
	{NULL, NULL} //
};
