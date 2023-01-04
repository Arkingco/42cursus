#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>

#define EMPTY_STRING "this is empty input re write please!"
#define WRONG_STRING "please input vaild cmd!"

int  is_cin_success();
void print_error(std::string error_msg);

#endif
