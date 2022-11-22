/*test case 모두 통과했습니다.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (char *str1, char *str2);
int main(void){
    char *str1 = (char *)malloc(sizeof(char) * 100);
    char *str2 = (char *)malloc(sizeof(char) * 100);

    scanf("%s", str1);
    scanf("%s", str2);

    if (compare(str1, str2) == 0){
        printf("%s, %s\n", str1, str2);
    }

    else if (compare(str1, str2) == 1){
        printf("%s, %s\n", str2, str1);
    }

    else{
        printf("%s, %s\n", str1, str2);
    }


    free(str1);
    free(str2);
    return 0;
}

int compare (char *str1, char *str2){
    
    if (*str1 > *str2)
    {
        return 1;
    }
    else if (*str1 < *str2)
    {
        return -1;
    }
    else if (*str1 == '\0' &&  *str2 == '\0')
    {
        return 0;
    }
    else
    {
        return compare(str1+1, str2+1);
    }
    
    
    

    
    
}

    
   
    
