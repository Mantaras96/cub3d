#include "../include/cub3d.h"

int ft_is_space(char c){
    if (c == ' ' || c == '\t' || c == '\n'){
        return (1);
    }
    return (0);
}

int count_words(char *str){
    int i;
    int words;

    i = 0;
    words = 0;
    while(str[i]){
        while(str[i] && ft_is_space(str[i]))
            i++;
        if (str[i] && !ft_is_space(str[i])){
            words++;
            while(str[i] && !ft_is_space(str[i])){
                i++;
            }
        }
    }
    return (words);
}

char **ft_split_spaces(char *str)
{
    int i;
    int j;
    int k;
    int size;
    char **buff;

    buff = (char **)malloc(sizeof (char *) * (count_words(str) + 1));
    i = 0;
    j = 0;
    k = 0;
    size = 0;
    while (str[i] && j < count_words(str)){
        while (str[i]  && ft_is_space(str[i])){
            i++;
        }
        while (str[i] && !ft_is_space(str[i])){
            size++;
            i++;
        }
        buff[j] = malloc(sizeof (char) * (size + 1));
        k = 0;
        while(size){
            buff[j][k] = str[i - size];
            size--;
            k++;
        }
        buff[j][k] = '\0';
        j++;
    }
    return (buff);
}