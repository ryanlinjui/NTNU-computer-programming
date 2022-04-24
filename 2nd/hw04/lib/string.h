#pragma once
#include "cstd.h"

//string compare
#define is_str_same(str1, str2) !strcmp(str1, str2)

//string copy
#define str_copy(dest,str) strncpy(dest,str,strlen(str))

//get string length
#define get_str_length(str) strlen(str)

//string replace

//string insert
void str_insert(char **str,char *insert_str,uint32_t index) //only support allocated string
{
    char *new_str = calloc(strlen(*str)+strlen(insert_str)+1,sizeof(char));   
    for(int i=0,c=0;i<strlen(*str)+strlen(insert_str);)
    {
        if(i==index)
        {
            for(int j=0;j<insert_str[j];j++)
            {
                new_str[i] = insert_str[j];
                i++;
            }
        }
        else
        {
            new_str[i] = (*str)[c];
            c++;
            i++;
        }
    }
    *str = realloc(*str,(strlen(new_str)+1)*sizeof(char*));
    strncpy(*str,new_str,strlen(new_str));
    free(new_str);
}

//string to_lower_case

//string to_upper_case

//string trim by string

//string trim by index

//string split

//string find
uint32_t str_find(char *str, char *target,uint32_t **index) //return row number of index array
{
    uint32_t count = 0;
    for(int i=0; str[i]; i++)
    {
        for(int j=0; target[j]; j++)
        {
            if(str[i+j] != target[j])
            {
                break;
            }
            if(j==strlen(target)-1)
            {   
                *index = (uint32_t*)realloc(*index,sizeof(uint32_t*)*(count+1));
                (*index)[count] = i;
                count++; 
            }
        }
    }
    return count;
}

//string connect

//string index

