
#ifndef TEST_CHECKER_APPEND_H
# define TEST_CHECKER_APPEND_H

# include "../../acutest.h"
# include "checker.h"
# include <stdio.h>

void	test_check_syntax_outfile_append(void)
{
	t_syntax_error	error;

	error = check_syntax(">>>>\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_OUTFILE_APPEND);
	error = check_syntax(">>>>>>>>>>>>>>>\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_OUTFILE_APPEND);
	error = check_syntax(">> >> >> >>\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_OUTFILE_APPEND);
	error = check_syntax(">>>> >> >> >>\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_OUTFILE_APPEND);
}

void	test_check_syntax_outfile_append_all(void)
{
	test_check_syntax_outfile_append();
}

#endif // TEST_CHECKER_APPEND_H
