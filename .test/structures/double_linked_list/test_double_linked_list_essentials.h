
#ifndef TEST_DOUBLE_LINKED_LIST_ESSENTIALS_H
# define TEST_DOUBLE_LINKED_LIST_ESSENTIALS_H

# include "../../acutest.h"
# include "double_linked_list_essentials.h"
# include <stdio.h>

void	test_double_linked_list_create(void)
{
	t_double_linked_list	*list;

	list = double_linked_list_create();
	TEST_CHECK(list != NULL);
	double_linked_list_free(list, NULL);
}

void	test_double_linked_list_free(void)
{
	t_double_linked_list	*list;

	list = double_linked_list_create();
	double_linked_list_free(list, NULL);
	TEST_CHECK(1);
}

void	test_double_linked_list_essentials(void)
{
	test_double_linked_list_create();
	test_double_linked_list_free();
}

#endif // TEST_DOUBLE_LINKED_LIST_ESSENTIALS_H
