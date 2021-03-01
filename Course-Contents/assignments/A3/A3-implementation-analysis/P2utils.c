# ifndef P2UTILS_H
# include "P2utils.h"
# endif

void get_text_P2(char* datapath, char* T)
{
    FILE* fptr = fopen(datapath, "r");
    
    char buffer[MAX_SIZE];
    strcpy(T, "\0");
    int t = 0;
    while(fgets(buffer, MAX_SIZE, fptr))
    {
        // strcat(T, buffer); // changed it for efficient file reading
        for(int i=0; i < strlen(buffer); i++)
        {
            T[t++] = buffer[i];
        }
        T[t] = '\0';
    }

    fclose(fptr);
}

int max(int a, int b)
{
    if(b>a)
        return b;
    return a;
}

