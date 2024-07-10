/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_double_linked_list_head.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:45:08 by hsoysal           #+#    #+#             */
/*   Updated: 2024/07/10 14:45:16 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_DOUBLE_LINKED_LIST_HEAD_H
# define TEST_DOUBLE_LINKED_LIST_HEAD_H

# include "../../acutest.h"
# include "double_linked_list.h"
# include <stdio.h>

void	test_double_linked_list_add_first1(void)
{
	t_double_linked_list	*list;
	int						data;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_first(list, &data);
	TEST_CHECK(list->head != NULL);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_add_first2(void)
{
	t_double_linked_list	*list;
	int						data;
	int						data2;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_first(list, &data);
	TEST_CHECK(*(int *)list->head->content == 42);
	data2 = 21;
	double_linked_list_add_first(list, &data2);
	TEST_CHECK(*(int *)list->head->content == 21);
	TEST_CHECK(*(int *)list->tail->content == 42);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_peak_first_content1(void)
{
	t_double_linked_list	*list;
	int						data;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_first(list, &data);
	TEST_CHECK(*(int *)double_linked_list_peak_first(list) == 42);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_peak_first_content2(void)
{
	t_double_linked_list	*list;
	int						data;
	int						data2;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_first(list, &data);
	data2 = 21;
	double_linked_list_add_first(list, &data2);
	TEST_CHECK(*(int *)double_linked_list_peak_first(list) == 21);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_pop_first_content1(void)
{
	t_double_linked_list	*list;
	int						data;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_first(list, &data);
	TEST_CHECK(*(int *)double_linked_list_pop_first(list) == 42);
	TEST_CHECK(double_linked_list_peak_first(list) == NULL);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_pop_first_content2(void)
{
	t_double_linked_list	*list;
	int						data;
	int						data2;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_first(list, &data);
	data2 = 21;
	double_linked_list_add_first(list, &data2);
	TEST_CHECK(*(int *)double_linked_list_pop_first(list) == 21);
	TEST_CHECK(*(int *)double_linked_list_peak_first(list) == 42);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_remove_first1(void)
{
	t_double_linked_list	*list;
	int						data;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_first(list, &data);
	double_linked_list_remove_first(list, NULL);
	TEST_CHECK(list->head == NULL);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_remove_first2(void)
{
	t_double_linked_list	*list;
	int						data;
	int						data2;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_first(list, &data);
	data2 = 21;
	double_linked_list_add_first(list, &data2);
	double_linked_list_remove_first(list, NULL);
	TEST_CHECK(*(int *)list->head->content == 42);
	TEST_CHECK(list->head->next == NULL);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_head(void)
{
	test_double_linked_list_add_first1();
	test_double_linked_list_add_first2();
	test_double_linked_list_peak_first_content1();
	test_double_linked_list_peak_first_content2();
	test_double_linked_list_pop_first_content1();
	test_double_linked_list_pop_first_content2();
	test_double_linked_list_remove_first1();
	test_double_linked_list_remove_first2();
}

#endif // TEST_DOUBLE_LINKED_LIST_HEAD_H
