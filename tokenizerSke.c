#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*For delim_character, checks if c is delimeter*/
bool delim_character(char c, char delim)
{
    if(c == delim){
        return 1;
    } else{
        return 0;
    }
}

/*For non_delim_character, checks if c is not a delimeter*/
bool non_delim_character(char c, char delim)
{
    if (c != delim){
        return 1;
    } else {
        return 0;
    }
}

/*The method throws in a while loop and when it traverses through
 any delimeter, it keeps going until it finds a letter, and returns its address. */
char *word_start(char* str,char delim) {
    if (strlen(str) == 0){
        return NULL;
    }

    int i = 0;

    while(str[i] == delim){ // checks if string element is the same as delimeter
        i++;
    }
    return &str[i]; //returns address
}

/*Similar to word_start, however, it goes backwards to see if there are any delimeters,
 as delimeters are at the end of word strings. */
char *end_word(char* str,char delim) {
    if (strlen(str) == 0){ //checks if string is empty
        return NULL;
    }

    int i =0; // gets last element of string

    while(str[i] != delim){ //checks if string elements are NOT delimeters. If they aren't, it goes backwards
        i++;
    }
    return &str[i]; //returns address of delimeter.
}

/*Counts number of words by counting the delimeters appending to it, and adding 1, so it equals to
  the number of strings.*/
int count_tokens(char* str,char delim)
{
    int word_count = 0;
    int i;
    for (i = 0; i < strlen(str); i++){
        if(str[i] == delim){
            word_count++;
        }
    }
    return word_count+1;
}

/*Copies elements by taking in the elements of a string and inserting
  them */
char *copy_str(char *inStr, short len, char delim)
{

    char* new_string = (char*)malloc((len + 1)* sizeof(char));

    int i = 0;
    for (i = 0; i < len; i++){
        new_string[i] = inStr[i]; //inserts inStr to the new string
    }
    new_string[len] = '\0';
    return new_string;

}


/*Tokenizes strings by adding all the tokens in a string to another string*/
char** tokenize(char* str, char delim)
{
    int tokens = count_tokens(str, delim);
    char* first = word_start(str, delim);
    char* last = end_word(str, delim);

    char** new_string = malloc((tokens + 1)* sizeof(char*)); //initialize new string to tokenize strings
    for(int i = 0; i < tokens; i++){
        last = end_word(first, delim);
        new_string[i] = copy_str(first, last - first, delim);//traverse using the length between first letter and delimeter
        first = word_start(last, delim);

    }
    new_string[strlen(str)-1] = '\0';
    return new_string;
}

/*loops through the tokenized string and prints all tokens*/
void print_all_tokens(char** tokens)
{
    for (int i = 0; tokens[i] != 0; i++){
        printf("Token[%d]:", i);
        printf("%s\n", tokens[i]);
    }
}


int main()
{
    char input[]  = "Hello,World";
    char deli = ',';
    char *x = word_start(input, deli);
    char *z = end_word(input,deli);
    printf("The first letter is: %c\n", *x);
    printf("The last letter is: %c\n", *z);
    int count = count_tokens(input, deli);
    printf("%d\n", count);
    char** tokens = tokenize(input, deli);
    print_all_tokens(tokens);

}