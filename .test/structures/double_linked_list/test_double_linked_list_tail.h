
#ifndef TEST_DOUBLE_LINKED_LIST_TAIL_H
# define TEST_DOUBLE_LINKED_LIST_TAIL_H

# include "../../acutest.h"
# include "double_linked_list.h"
# include <stdio.h>

void	test_double_linked_list_add_last_content1(void)
{
	t_double_linked_list	*list;
	int						data;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_last(list, &data);
	TEST_CHECK(list->tail != NULL);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_add_last_content2(void)
{
	t_double_linked_list	*list;
	int						data;
	int						data2;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_last(list, &data);
	TEST_CHECK(*(int *)list->tail->content == 42);
	data2 = 21;
	double_linked_list_add_last(list, &data2);
	TEST_CHECK(*(int *)list->tail->content == 21);
	TEST_CHECK(*(int *)list->head->content == 42);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_peak_last_content1(void)
{
	t_double_linked_list	*list;
	int						data;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_last(list, &data);
	TEST_CHECK(*(int *)double_linked_list_peak_last(list) == 42);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_peak_last_content2(void)
{
	t_double_linked_list	*list;
	int						data;
	int						data2;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_last(list, &data);
	data2 = 21;
	double_linked_list_add_last(list, &data2);
	TEST_CHECK(*(int *)double_linked_list_peak_last(list) == 21);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_pop_last_content1(void)
{
	t_double_linked_list	*list;
	int						data;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_last(list, &data);
	TEST_CHECK(*(int *)double_linked_list_pop_last(list) == 42);
	TEST_CHECK(double_linked_list_peak_last(list) == NULL);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_pop_last_content2(void)
{
	t_double_linked_list	*list;
	int						data;
	int						data2;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_last(list, &data);
	data2 = 21;
	double_linked_list_add_last(list, &data2);
	TEST_CHECK(*(int *)double_linked_list_pop_last(list) == 21);
	TEST_CHECK(*(int *)double_linked_list_peak_last(list) == 42);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_remove_last1(void)
{
	t_double_linked_list	*list;
	int						data;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_last(list, &data);
	double_linked_list_remove_last(list, NULL);
	TEST_CHECK(list->tail == NULL);
	TEST_CHECK(list->head == NULL);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_remove_last2(void)
{
	t_double_linked_list	*list;
	int						data;
	int						data2;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_last(list, &data);
	data2 = 21;
	double_linked_list_add_last(list, &data2);
	double_linked_list_remove_last(list, NULL);
	TEST_CHECK(*(int *)list->tail->content == 42);
	TEST_CHECK(*(int *)list->head->content == 42);
	double_linked_list_remove_last(list, NULL);
	TEST_CHECK(list->tail == NULL);
	TEST_CHECK(list->head == NULL);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_remove_last3(void)
{
	t_double_linked_list	*list;
	int						data;
	int						data2;

	list = double_linked_list_create();
	data = 42;
	double_linked_list_add_last(list, &data);
	data2 = 21;
	double_linked_list_add_last(list, &data2);
	double_linked_list_remove_last(list, NULL);
	TEST_CHECK(*(int *)list->tail->content == 42);
	TEST_CHECK(*(int *)list->head->content == 42);
	double_linked_list_remove_last(list, NULL);
	TEST_CHECK(list->tail == NULL);
	TEST_CHECK(list->head == NULL);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_tail(void)
{
	test_double_linked_list_add_last_content1();
	test_double_linked_list_add_last_content2();
	test_double_linked_list_peak_last_content1();
	test_double_linked_list_peak_last_content2();
	test_double_linked_list_pop_last_content1();
	test_double_linked_list_pop_last_content2();
	test_double_linked_list_remove_last1();
	test_double_linked_list_remove_last2();
	test_double_linked_list_remove_last3();
}

#endif // TEST_DOUBLE_LINKED_LIST_TAIL_H
