#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return ((a) >= (b)) ? (a) : ( b);
}

int lengthOfLongestSubstring(char *s)
{
    int slen = strlen(s);
    int start = 0;
    int end = 0;
    int len = 0;
    int is_used[256]  = {0};
    
    printf("slen = %d \n ", slen);

    for(end = 0; end < slen; end++) {
        printf("end = %d\n", end);
        if( is_used[s[end]] == 0) {
            is_used[s[end]] = 1;
            printf("yyyy\n");
        }
        else {
            /*find a substring in [start,end)*/
            len = max(len, end - start);

            /*clear the used flag*/
            for(; s[start] != s[end]; start++) {
                printf("xxxx\n");
                is_used[s[start]] = 0;
            }

            start++;
            is_used[s[end]] = 1;
            printf("start %d end %d\n", start, end);
        }
    }

    len = max(len, end - start);
    return len;
}

int main()
{
    char *s1="abcabcab";
    char *s2="bbbbb";
    int len = 0;
    len = lengthOfLongestSubstring(s1);
    printf("len=%d\n", len);

    len = lengthOfLongestSubstring(s2);
    printf("len=%d\n", len);
    return 0;

}

