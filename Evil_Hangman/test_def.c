#include <string.h>
#include "my_string.h"

Status test_manaya_init_default_returns_nonNULL(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_default();

    if(hString == NULL){
        my_string_destroy((Item*)&hString);
        strncpy(buffer, "test_manaya_init_default_returns_nonNULL\n" "my_string_init_default returns NULL", length);

        return FAILURE;
    }
    else {
        my_string_destroy((Item*)&hString);
        strncpy(buffer, "\ttest_manaya_init_default_returns_nonNULL\n", length);
        
        return SUCCESS;
    }
}

Status test_manaya_get_size_on_init_default_returns_0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();

    if(my_string_get_size(hString) != 0){
        status = FAILURE;
        printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_manaya_get_size_on_init_default_returns_0\n" "Did not receive 0 from get_size after init_default\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_manaya_get_size_on_init_default_returns_0\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_manaya_my_string_get_size_return_0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();

    if(my_string_get_size(hString)!=0){
        status = FAILURE;
        strncpy(buffer, "test_manaya_get_size_on_init_default_return_0\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_manaya_get_size_on_init", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_manaya_my_string_init_c_string_returns_NULL(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("Hangman");

    if(hString == NULL){
        my_string_destroy((Item*)&hString);
        strncpy(buffer, "test_manaya_MY_STRING my_string_init_c_string_returns_NULL\n" "my_string_init_c_string returns NULL", length);
        return FAILURE;
    }
    else{
        my_string_destroy((Item*)&hString);
        strncpy(buffer, "\ttest_manaya_MY_STRING my_string_init_c_string_returns_NULL\n", length);

        return SUCCESS;
    }
}

Status test_manaya_my_string_get_capacity_returns_0(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();
    if(my_string_get_capacity(hString) != 7){
        status = FAILURE;
        strncpy(buffer, "test_manaya_my_string_get_capacity_returns_0\n" "my_string_get_capacity returns 0",        length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "\ttest_manaya_my_string_get_capacity_returns_0\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_manaya_my_string_compare_returns_0(char* buffer, int length){ MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;
    hString1 = my_string_init_c_string("Hangman");
    hString2 = my_string_init_c_string("Hangman");

    if(my_string_compare(hString1 , hString2) == 0){
        status = SUCCESS;
        strncpy(buffer, "test_manaya_my_string_compare_returns_0\n" "my_string_compare returns 0", length);
    }
    else{
        status = FAILURE;
        strncpy(buffer, "\ttest_manaya_my_string_compare_returns_0\n",length);
    }

    my_string_destroy((Item*)&hString1);
    my_string_destroy((Item*)&hString2);
    return status;
}

Status test_manaya_my_string_extraction_returns_SUCCESS(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    FILE *fp;
    hString = my_string_init_default();
    fp = fopen("simple.txt","r");

    if(my_string_extraction(hString, fp)){
        if(my_string_insertion(hString,fp)){
            status = SUCCESS;
            strncpy(buffer, "test_manaya_my_string_insertion_returns_SUCCESS\n" "my_string_insertion returns SUCCESS", length);
        }
        else{
            status = FAILURE;
            strncpy(buffer, "\ttest_manaya_my_string_insertion_returns_SUCCESS\n", length);
        }
    }
    else{
        status = FAILURE;
        printf("fail");
    }

    my_string_destroy((Item*)&hString);
    fclose(fp);
    return status;
}
Status test_manaya_my_string_push_back_returns_SUCCESS(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_default();

    if(my_string_push_back(hString, 'a')){
        status = SUCCESS;
        strncpy(buffer, "test_manaya_my_string_push_back_returns_SUCCESS\n" "my_string_push_back returns SUCCESS", length);
    }
    else{
        status = FAILURE;
        strncpy(buffer, "\ttest_my_string_push_back_returns_SUCCESS\n", length);
    }
    my_string_destroy((Item*)&hString);
    return status;
}

Status test_manaya_my_string_pop_back_returns_SUCCESS(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("abcdef");

    if(my_string_pop_back(hString)){
        status = SUCCESS;
        strncpy(buffer, "test_manaya_my_string_pop_back_returns_SUCCESS\n" "my_string_pop_back returns SUCCESS", length);
    }
    else{
        status = FAILURE;
        strncpy(buffer, "\ttest_manaya_my_string_pop_back_returns_SUCCESS\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_manaya_my_string_at_returns_c(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("abcde");

    if(my_string_at(hString, 0) == NULL){
        status = FAILURE;
        strncpy(buffer, "test_manaya_my_string_at_returns_c\n" "my_string_at returns SUCCESS", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "\ttest_manaya_my_string_at_returns_c\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_manaya_my_string_c_str_returns_c(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("Hangman");

    if(my_string_c_str(hString) == NULL){
        status = FAILURE;
        strncpy(buffer, "test_manaya_my_string_c_str_returns_c\n" "my_string_c_str returns SUCCESS", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "\ttest_manaya_my_string_c_str_returns_c\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}
Status test_manaya_my_string_concat_returns_0(char* buffer, int length){
    MY_STRING hString1 = NULL;
    MY_STRING hString2 = NULL;
    Status status;
    hString1 = my_string_init_c_string("abcd");
    hString2 = my_string_init_c_string("efgh");
    
    if(my_string_concat(hString1, hString2)){
        status = SUCCESS;
        strncpy(buffer, "test_manaya_my_string_concat_returns_0\n" "my_string_concat returns 0", length);
    }
    else{
        status = FAILURE;
        strncpy(buffer, "\ttest_manaya_my_string_concat_returns_0\n", length);
    }

    my_string_destroy((Item*)&hString1);
    my_string_destroy((Item*)&hString2);

    return status;

}
Status test_manaya_my_string_empty_returns_SUCCESS(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    hString = my_string_init_c_string("Hangman");
    if(!my_string_empty(hString)){
        status = SUCCESS;
        strncpy(buffer, "test_manaya_my_string_empty_returns_SUCCESS\n" "my_string_empty returns SUCCESS", length);
    }
    else{
        status = FAILURE;
        strncpy(buffer, "\ttest_manaya_my_string_empty_returns_SUCCESS\n", length);
    }
    my_string_destroy((Item*)&hString);
    return status;
}
Status test_manaya_my_string_destroy_returns_SUCCESS(char* buffer, int length){
    MY_STRING hString = NULL;
    hString = my_string_init_default();
    my_string_destroy((Item*)&hString);

    if(hString == NULL){
        strncpy(buffer, "test_manaya_my_string_destroy_returns_SUCCESS\n" "my_string_destroy returns SUCCESS", length);

        return SUCCESS;
    }
    else{
        strncpy(buffer, "\ttest_manaya_my_string_destroy_returns_SUCCESS\n", length);

        return FAILURE;
    }
}
Status test_manaya_compare_returns_negative_1_if_left_string_is_smaller(char* buffer, int length){
    MY_STRING hLeft = NULL;
    MY_STRING hRight = NULL;
    int value;

    hLeft = my_string_init_c_string("s");
    hRight = my_string_init_c_string("bigger");

    if (hLeft == NULL || hRight == NULL){
        printf("failed to allocate memory for one of the two strings\n");
        return FAILURE;
    }

    value = my_string_compare(hLeft, hRight);
    if(value != -1){
        printf("Got a value of %d\n", value);
        strncpy(buffer, "test_manaya_compare_returns_negative_1_if_left_string_is_smaller\n"
              "Failed because it did not return -1\n", length);
        return FAILURE;
    }
    else{
        strncpy(buffer, "test_manaya_compare_returns_negative_1_if_left_string_is_smaller\n", length);
    }

    my_string_destroy((Item*)&hLeft);
    my_string_destroy((Item*)&hRight);

    return SUCCESS;
}

Status test_manaya_compare_returns_1_if_right_string_is_smaller(char* buffer, int length){
    MY_STRING hLeft = NULL;
    MY_STRING hRight = NULL;
    int value;

    hLeft = my_string_init_c_string("bigger");
    hRight = my_string_init_c_string("s");

    if (hLeft == NULL || hRight == NULL){
        printf("failed to allocate memory for one of the two strings\n");
        return FAILURE;
    }

    value = my_string_compare(hLeft, hRight);
    if(value != 1) {
        printf("got value of %d\n", value);
        strncpy(buffer, "test_manaya_compare_returns_1_if_right_string_is_smaller\n"
              "Failed to get value of 1\n", length);
        return FAILURE;
    }
    else{
      strncpy(buffer, "test_manaya_compare_returns_1_if_right_string_is_smaller\n", length);
    }

    my_string_destroy((Item*)&hLeft);
    my_string_destroy((Item*)&hRight);
    
    return SUCCESS;
}

Status test_manaya_compare_returns_0_if_the_two_strings_are_the_same_size(char* buffer, int length){
    MY_STRING hLeft = NULL;
    MY_STRING hRight = NULL;
    int value;

    hLeft = my_string_init_c_string("same");
    hRight = my_string_init_c_string("same");

    if (hLeft == NULL || hRight == NULL){
        printf("failed to allocate memory for one of the two strings\n");
        return FAILURE;
    }

    value = my_string_compare(hLeft, hRight);
    if (value != 0) {
        printf("got value of %d\n", value);
        strncpy(buffer, "test_manaya_compare_returns_0_if_the_two_strings_are_the_same_size\n"
              "Failed to get value of 0\n", length);
        return FAILURE;
    }
    else{
        strncpy(buffer, "test_manaya_compare_returns_0_if_the_two_strings_are_the_same_size\n", length);
        }

    my_string_destroy((Item*)&hLeft);
    my_string_destroy((Item*)&hRight);

    return SUCCESS;
}
Status test_manaya_push_back_800_characters(char* buffer, int length){
    MY_STRING hString;
    Status status;
    int i;

    hString = my_string_init_default();

    for(i = 0; i < 800; i ++){
        status = my_string_push_back(hString, 'a');
        if (status == FAILURE){
            printf("Push_back failed to allocate memory\n");
            strncpy(buffer, "test_manaya_push_back_800_characters\n"
              "Failed to allocate memory while creating string\n", length);
            return FAILURE;
        }
    }

    if(my_string_get_size(hString) != 800){
        status = FAILURE;
        printf("Expected to push_back 800 characters but only pushed back %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_manaya_push_back_800_characters\n"
            "Did not have a size of 800 after get_size\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_800_push_back_800_characters\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}




Status test_manaya_push_back_800_characters_then_pop_back_them_all(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;
    int i;

    hString = my_string_init_default();

    for(i = 0; i < 800; i ++){
        status = my_string_push_back(hString, 'a');
        if (status == FAILURE){
            printf("Push_back failed to allocate memory for string of 800 characters\n");
            strncpy(buffer, "test_manaya_push_back_800_characters_then_pop_back_them_all\n"
              "Failed to allocate memory while creating string\n", length);
            return FAILURE;
        }
    }

    if (my_string_get_size(hString) != 800){
        printf("String has a size of %d after running get_size\n", my_string_get_size(hString));
        strncpy(buffer, "test_manaya_push_back_800_characters_then_pop_back_them_all\n"
            "Does not have a string of size 800 after creating the string\n", length);
        return FAILURE;
    }

    for(i = 0; i < 800; i++){
        status = my_string_pop_back(hString);
        if(status == FAILURE){
            strncpy(buffer, "test_manaya_push_back_800_characters_then_pop_back_them_all\n"
              "Failed during pop_back operations\n", length);
            return FAILURE;
        }
    }

    if (!my_string_empty(hString)){
        status = FAILURE;
        strncpy(buffer, "test_mana_push_back_800_characters_then_pop_back_them_all\n"
            "Failed, string is not empty\n", length);
    }
    else{
        status = SUCCESS;
        strncpy(buffer, "test_manaya_push_back_800_characters_then_pop_back_them_all\n", length);
    }

    my_string_destroy((Item*)&hString);
    return status;
}

Status test_manaya_insertion_successfully_prints_COMPII_to_stdout(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_c_string("COMPII");
    if (hString == NULL){
        printf("failed to allocate memory for hString\n");
        return FAILURE;
    }

    status =  my_string_insertion(hString, stdout);
    if(status != SUCCESS){
        strncpy(buffer,"test_manaya_insertion_successfully_prints_COMPII_to_stdout\n"
              "Failed and returned FAILURE after insertion\n", length);
        return FAILURE;
    }
    else{
        strncpy(buffer, "test_manaya_insertion_successfully_prints_COMPII_to_stdout\n", length);
    }

    my_string_destroy((Item*)&hString);

    return SUCCESS;
}


Status test_manaya_insertion_returns_FAILURE_if_string_is_empty(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status;

    hString = my_string_init_default();
    if(hString == NULL){
        printf("failed to allocate memory for hString\n");
        return FAILURE;
    }

    status =  my_string_insertion(hString, stdout);
    if(status == SUCCESS){
        strncpy(buffer,"test_manaya_insertion_returns_FAILURE_if_string_is_empty\n"
              "Failed and returned SUCCESS after insertion on empty string\n", length);
        return FAILURE;
    }
    else{
        strncpy(buffer, "test_manaya_insertion_returns_FAILURE_if_string_is_empty\n", length);
        }

    my_string_destroy((Item*)&hString);

    return SUCCESS;
}

Status test_manaya_insertion_successfully_prints_COMPII_to_known_file(char* buffer, int length){
    MY_STRING hString = NULL;
    FILE* fp = NULL;
    Status status;

    hString = my_string_init_c_string("COMPII");
    if (hString == NULL){
        printf("failed to allocate memory for hString\n");

        return FAILURE;
    }

    fp = fopen("test.txt", "w");
    if(fp == NULL){
        printf("failed to open file\n");

        return FAILURE;
    }

    status =  my_string_insertion(hString, fp);
    if(status != SUCCESS){
        strncpy(buffer,"test_manaya_insertion_successfully_prints_COMPII_to_known_file\n"
              "Failed and returned FAILURE after insertion\n", length);

        return FAILURE;
    }
    else{
        strncpy(buffer, "test_manaya_insertion_successfully_prints_COMPII_to_known_file\n", length);
    }

    fclose(fp);
    my_string_destroy((Item*)&hString);

    return SUCCESS;
}

Status test_manaya_insertion_returns_FAILURE_when_directed_to_file_that_does_not_exist(char* buffer, int length){
    MY_STRING hString = NULL;
    Status status = FAILURE;
    FILE* fp = NULL;

    hString = my_string_init_c_string("COMPII");
    if (hString == NULL){
        printf("failed to allocate memory for hString\n");
        return FAILURE;
    }

    status =  my_string_insertion(hString, fp);
    if(status == SUCCESS){
        strncpy(buffer,"test_manaya_insertion_returns_FAILURE_when_directed_to_file_that_does_not_exist\n"
              "Failed and returned SUCCESS after insertion on unknown FILE\n", length);
        return FAILURE;
    }
    else{
        strncpy(buffer, "test_manaya_insertion_returns_FAILURE_when_directed_to_file_that_does_not_exist\n", length);
    }

    my_string_destroy((Item*)&hString);
    return SUCCESS;
}

Status test_manaya_c_str_returns_valid_address_on_init_default(char* buffer, int length){
    MY_STRING hString = NULL;
    char* value = NULL;

    hString = my_string_init_default();
    if(hString == NULL){
        printf("failed to allocate memory for hString\n");
        return FAILURE;
    }

    value = my_string_c_str(hString);
    if (value == NULL){
        strncpy(buffer, "test_manaya_c_str_returns_valid_address_on_init_default\n" "Failed and returned NULL after c_str\n", length);
        return FAILURE;
    }
    else{
        strncpy(buffer, "test_manaya_c_str_returns_valid_address_on_init_default\n", length);
    }

    my_string_destroy((Item*)&hString);
    return SUCCESS;
}





