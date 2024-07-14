
#ifndef TEST_CHECKER_NEWLINE_H
# define TEST_CHECKER_NEWLINE_H

# include "../../acutest.h"
# include "checker.h"
# include <stdio.h>

void	test_check_syntax_newline(void)
{
	t_syntax_error	error;

	error = check_syntax("cat <<\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_NEWLINE);
	error = check_syntax("cat >>\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_NEWLINE);
	error = check_syntax(">>echo>>\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_NEWLINE);
	error = check_syntax("<echo<\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_NEWLINE);
	error = check_syntax(">\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_NEWLINE);
	error = check_syntax("<\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_NEWLINE);
	error = check_syntax(">>\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_NEWLINE);
	error = check_syntax("<<\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_NEWLINE);
	error = check_syntax("<>\n");
	TEST_CHECK(error == SE_UNEXPECTED_TOKEN_NEWLINE);
}

void	test_check_syntax_new_line_all(void)
{
	test_check_syntax_newline();
}

#endif // TEST_CHECKER_NEWLINE_H
