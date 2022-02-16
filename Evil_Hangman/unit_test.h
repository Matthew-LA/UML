#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_manaya_init_default_returns_nonNULL(char*buffer, int length);

Status test_manaya_get_size_on_init_default_returns_0(char* buffer, int length);

Status test_manaya_my_string_init_c_string_returns_NULL(char* buffer, int length);

Status test_manaya_my_string_get_size_return_0(char* buffer, int length);

Status test_manaya_my_string_get_capacity_returns_0(char* buffer, int length);

Status test_manaya_my_string_compare_returns_0(char* buffer, int length);

Status test_manaya_my_string_destroy_returns_SUCCESS(char* buffer, int length);

Status test_manaya_my_string_extraction_returns_SUCCESS(char* buffer, int length);

Status test_manaya_my_string_insertion_returns_SUCCESS(char* buffer, int length);

Status test_manaya_my_string_push_back_returns_SUCCESS(char* buffer, int length);

Status test_manaya_my_string_pop_back_returns_SUCCESS(char* buffer, int length);

Status test_manaya_my_string_at_returns_c(char* buffer, int length);

Status test_manaya_my_string_c_str_returns_c(char* buffer, int length);

Status test_manaya_my_string_concat_returns_0(char* buffer, int length);

Status test_manaya_my_string_empty_returns_SUCCESS(char* buffer, int length);

Status test_manaya_compare_returns_negative_1_if_left_string_is_smaller(char* buffer, int length);

Status test_manaya_compare_returns_1_if_right_string_is_smaller(char* buffer, int length);

Status test_manaya_compare_returns_0_if_the_two_strings_are_the_same_size(char* buffer, int length);

Status test_manaya_push_back_800_characters(char* buffer, int length);

Status test_manaya_push_back_800_characters_then_pop_back_them_all(char* buffer, int length);

Status test_manaya_insertion_successfully_prints_COMPII_to_stdout(char* buffer, int length);

Status test_manaya_insertion_returns_FAILURE_if_string_is_empty(char* buffer, int length);

Status test_manaya_insertion_successfully_prints_COMPII_to_known_file(char* buffer, int length);

Status test_manaya_insertion_returns_FAILURE_when_directed_to_file_that_does_not_exist(char* buffer, int length);

Status test_manaya_c_str_returns_valid_address_on_init_default(char* buffer, int length);

#endif

