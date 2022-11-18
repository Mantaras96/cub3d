#include <stdio.h>

void save_nums(int i, char *str)
{
    while(str[i])
    {
        if (str[i] == ' ')
            i++;
        if(str[i] != ' ')
        {
            printf("%c", str[i]);
            i++;
        }
    }
}


int main()
{
    char *str = "F 255,146,146";
    char *str2 = "C 138,242,221";
    char letter;
	int j = 0;
    int i = 0;
	while(str[i])
	{
	    if(str[i] == ' ')
			i++;
		else
		{
			letter = str[i];
			printf("%c", letter);
            save_nums(i + 1, str);
			break ;
		}
		i++;
	}
    return (0);
}