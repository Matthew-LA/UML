#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "my_string.h"
#include "status.h"
#include "generic.h"





void fill_array(GENERIC_VECTOR hVector[], int SIZE, int pass);
void print_from_array(GENERIC_VECTOR hVector[], int SIZE);
int game_ON(GENERIC_VECTOR hVector[], int SIZE, int* word_length, int* number_of_guesses);
int test_word_length(GENERIC_VECTOR hVector[], int length, int SIZE);
void hangman(GENERIC_VECTOR hVector[], int number_of_guesses, int word_length, int fair_or_not);
char make_a_guess(char letters[], int letters_guessed);
Boolean new_guess(char letters[], char guess, int letters_guessed);
int compare_keys(MY_STRING current_word_family, MY_STRING new_key);
GENERIC_VECTOR return_largest_bin(GENERIC_VECTOR hVector, MY_STRING current_word_family,
                                  MY_STRING new_key, MY_STRING word, char guess);
Status conditions_are_met(int guesses, MY_STRING family);
Boolean player_wishes_to_continue(void);

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    const int SIZE = 30;
    GENERIC_VECTOR array_of_vectors_of_hStrings[SIZE];
    int fair_or_not = 0;
    int word_length, number_of_guesses, i;
    int pass = 0;

    srand((unsigned int)time(NULL));

    printf("\n\n\tGreetings, adventurer! Ready yourself for the BBEFG!!!\n\n\t...THE EVIL HANGMAN...\n\n\n\n");

    printf(
           "\n\t_______"
           "\n\t|     |"
           "\n\t|"
           "\n\t|"
           "\n\t|"
           "\n\t|"
           "\n\t|");

    do
    {
        fill_array(array_of_vectors_of_hStrings, SIZE, pass);
        fair_or_not = game_ON(array_of_vectors_of_hStrings, SIZE, &word_length, &number_of_guesses);
        hangman(array_of_vectors_of_hStrings[word_length], number_of_guesses, word_length, fair_or_not);
        pass ++;
    }while(player_wishes_to_continue());
    
    for(i=0; i<SIZE; i++){
        generic_vector_destroy(&array_of_vectors_of_hStrings[i]);
    }

    return 0;
}

void fill_array(GENERIC_VECTOR hVector[], int SIZE, int pass){
    Status status = FAILURE;
    MY_STRING hString = my_string_init_default();
    int i;
    FILE* fp = NULL;
    fp = fopen("dictionary.txt", "r");
    if(fp == NULL){
        printf("File failed to open.\n");
        exit(1);
    }
    if(pass > 0){
        for(i=0; i<SIZE; i++){
            generic_vector_destroy(&hVector[i]);
        }
    }
    for (i=0; i<SIZE; i++){
        hVector[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
    }
    status = my_string_extraction(hString, fp);
    while(status == SUCCESS){
        generic_vector_push_back(hVector[my_string_get_size(hString)], hString);
        status = my_string_extraction(hString, fp);
    }
    fclose(fp);
    my_string_destroy(&hString);
}

void print_from_array(GENERIC_VECTOR hVector[], int SIZE){
    int i;
    ITEM* pItem;
    int j;
    
    for(i=0; i< SIZE; i++){
        for(j=0; j<generic_vector_get_size(hVector[i]); j++){
            pItem = generic_vector_at(hVector[i], j);
            printf("%s\n", my_string_c_str(*pItem));
        }
    }

    for(i = 0; i<SIZE; i++){
    printf("vector[%d] size = %d\n", i, generic_vector_get_size(hVector[i]));
    }
}

int game_ON(GENERIC_VECTOR hVector[], int SIZE, int* word_length, int* number_of_guesses){
    char c;
    int noc;

    printf("\tEnter your word length: ");
    noc = fscanf(stdin, "%d", word_length);
    clear_keyboard_buffer();
    while(!test_word_length(hVector, *word_length, SIZE) || noc != 1){
        printf("\tEnter your word length: ");
        noc = fscanf(stdin, "%d", word_length);
        clear_keyboard_buffer();
    }
    printf("\n");
    printf("\tEnter number of guesses: ");
    noc = fscanf(stdin, " %d", number_of_guesses);
    clear_keyboard_buffer();
    while(*number_of_guesses < 0 || noc != 1){
        printf("\tEnter number of guesses: ");
        noc = fscanf(stdin, "%d", number_of_guesses);
        clear_keyboard_buffer();
    }
    printf("\n");
    printf("\tAdd running total of remain words (yes/no)? ");
    fscanf(stdin, " %c", &c);
    clear_keyboard_buffer();
    while(c != 'y' && c != 'Y' && c != 'n' && c != 'N'){
        printf("\tAdd running total of remaining words (yes/no)? ");
        fscanf(stdin, "%c", &c);
        clear_keyboard_buffer();
    }

    if(c == 'n' || c == 'N'){
        return 0;
    }
    return 1;
}

void hangman(GENERIC_VECTOR hVector[], int number_of_guesses, int word_length, int fair_or_not){
    MY_STRING current_word_family, new_key, word;
    char guess;
    int i, j, largest_index= 0, largest_value= 0, value;
    int exists = 0;
    int capacity = 400;
    int size_of_keys = 0;
    Status status;
    GENERIC_VECTOR keys[capacity];
    char letters[26];
    int letters_guessed = 0;

    current_word_family = my_string_init_default();
    new_key = my_string_init_default();
    word = my_string_init_default();

    printf("\n\tword: ");
    for(i = 0; i<word_length; i++){
        my_string_push_back(current_word_family, '-');
    }
    printf("%s\n", my_string_c_str(current_word_family));

    do{
        keys[0] = generic_vector_init_default(my_string_assignment, my_string_destroy);
        generic_vector_push_back(keys[0], current_word_family);
        size_of_keys ++;
        guess = make_a_guess(letters, letters_guessed);
        number_of_guesses --;
        letters_guessed ++;

        for(i = 0; i < generic_vector_get_size(hVector); i ++){
            exists = 0;
            my_string_assignment(&new_key, current_word_family);
            my_string_assignment(&word, *generic_vector_at(hVector, i));
            get_word_key_value(current_word_family, new_key, word, guess);

            for(j=0; j<size_of_keys; j++){
                if(compare_keys(*generic_vector_at(keys[j], 0), new_key)){
                    exists = 1;
                    generic_vector_push_back(keys[j], word);
                }
            }
            if(exists == 0 && generic_vector_get_size(hVector) > 0){
                keys[size_of_keys] = generic_vector_init_default(my_string_assignment, my_string_destroy);
                generic_vector_push_back(keys[size_of_keys], new_key);
                generic_vector_push_back(keys[size_of_keys], word);
                size_of_keys++;
            }
        }
        for(i = 0; i<size_of_keys; i++){
            value = generic_vector_get_size(keys[i]);
            if (value > largest_value){
                largest_value = value;
                largest_index = i;
            }
        }
        if(!compare_keys(current_word_family, *generic_vector_at(keys[largest_index], 0))){
            number_of_guesses ++;
        }
        my_string_assignment(&current_word_family, *generic_vector_at(keys[largest_index], 0));

        status = generic_vector_pop_back(hVector);
        while(status == SUCCESS){
            status = generic_vector_pop_back(hVector);
        }
        for(i=1; i<generic_vector_get_size(keys[largest_index]); i++){
            generic_vector_push_back(hVector, *generic_vector_at(keys[largest_index], i));
        }
        printf("\n");
        if(fair_or_not == 1 && number_of_guesses > 0){
            printf("\tword: %s %d\n", my_string_c_str(current_word_family), generic_vector_get_size(hVector));
            printf("\tNumber of guess's left: %d\n", number_of_guesses);
        }
        if(fair_or_not == 0 && number_of_guesses > 0){
            printf("\tword: %s\n", my_string_c_str(current_word_family));
            printf("\tNumber of guess's left: %d\n", number_of_guesses);
        }
        for(i=0; i<size_of_keys; i++){
            generic_vector_destroy(&keys[i]);
        }
        largest_value = 0;
        largest_index = 0;
        size_of_keys = 0;
        
    }while(conditions_are_met(number_of_guesses, current_word_family));
    if(number_of_guesses <= 0){
        printf("\n-------------------------------------------------------------------------");
        printf("\n\t\tYou ran out of guess's!\n"
               "\t\t.....and.....\n"
               "\t\tThe EVIL HANGMAN had his way!\n");
        printf("\n\t\tcorrect word: %s\n", my_string_c_str(*generic_vector_at(hVector,rand()%generic_vector_get_size(hVector))));
        printf(
                "\n\t_______"
                "\n\t|     |"
                "\n\t|     o"
                "\n\t|    /|\\"
                "\n\t|    //"
                "\n\t|"
                "\n\t|");
        printf("\tDo you wish to be resurrected! "
               "\n\t\tTo once again challenge the EVIL HANGMAN (yes/no): ");
    }
    else{
        printf("\n-------------------------------------------------------------------------");
        printf("\n\n\n\t\tCongratulations!"
               "\n\t\tYou have defeated the EVIL HANGMAN!!!\n"
               "\n\t\tCorrect word: %s\n", my_string_c_str(current_word_family));
        printf(
               "\n\t_______"
               "\n\t|     |"
               "\n\t|"
               "\n\t|"
               "\n\t|"
               "\n\t|"
               "\n\t|");
        printf("\tDo you wish to fight again (yes/no): ");
    }
    my_string_destroy(&current_word_family);
    my_string_destroy(&new_key);
    my_string_destroy(&word);
}


char make_a_guess(char letters[], int letters_guessed){
    char guess;
    int noc;

    do{
        printf("\tEnter guess: ");
        noc = fscanf(stdin, " %c", &guess);
        clear_keyboard_buffer();
        while (noc != 1 || isalpha(guess)==0){
            printf("\tEnter guess: ");
            noc = fscanf(stdin, "%c", &guess);
            clear_keyboard_buffer();
        }
    }while(!new_guess(letters, guess, letters_guessed));
    
    letters[letters_guessed] = guess;
    return guess;
}

Boolean new_guess(char letters[], char guess, int letters_guessed){
    int i,
        j;

    for(i=0; i<letters_guessed; i++){
        if(letters[i] == guess){
            printf("\n\tAlready picked: ");

            printf("{%c", letters[0]);
            for(j=1;j<letters_guessed;j++){
                printf(", %c", letters[j]);
            }
                printf("}\n");
            return FALSE;
        }
    }
    return TRUE;
}

Status conditions_are_met(int guesses, MY_STRING family){
    int i;
    int size = my_string_get_size(family);

    if(guesses <= 0){
        return FAILURE;
    }

    for(i=0; i<size; i++){
        if(!isalpha(*my_string_at(family, i))){
            return SUCCESS;
        }
    }

    return FAILURE;
}


int compare_keys(MY_STRING current_word_family, MY_STRING new_key){
    int size = my_string_get_size(current_word_family);
    int i;
    int current=0, new=0;

    for(i=0; i< size; i++){
        if(isalpha((char)*my_string_at(current_word_family, i))){
            current += 1<<i;
        }
        if(isalpha((char)*my_string_at(new_key, i))){
            new += 1<<i;
        }
    }
    if (new == current){
        return 1;
    }
    return 0;
}

int test_word_length(GENERIC_VECTOR hVector[], int length, int SIZE){
    if (length < SIZE && length > 0){
        if(generic_vector_get_size(hVector[length]) != 0){
            return 1;
        }
    }
    return 0;
    
}

Boolean player_wishes_to_continue(void){
    char c;

    fscanf(stdin, " %c", &c);
    clear_keyboard_buffer();
    while(c != 'y' && c != 'Y' && c != 'n' && c != 'N'){
        printf("\n\tDo you wish to fight again (yes/no): ");
        fscanf(stdin, "%c", &c);
        clear_keyboard_buffer();
    }
    printf("\n");
    if(c == 'n' || c == 'N'){
        return FALSE;
    }
    return TRUE;
}

void clear_keyboard_buffer(void){
    char c;
    
    scanf("%c", &c);
    while(c != '\n'){
        scanf("%c", &c);
    }
}
