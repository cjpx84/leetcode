/*
char* longestPalindrome(char* s) {
    int len = strlen(s);
    int palin[1000][1000] = {0};
    int start = 0;
    int end = 0;
    int i,j;
    int maxlen = 0;
    char * substr;
    
    if (len <= 1)
        return s;
    
    for(i = len -1; i >= 0; i--) {
        for(j = i; j < len; j++) {
           if ((s[i] == s[j]) && ((j - i <= 2) || palin[i+1][j-1])) {
               palin[i][j] = 1;
               if (maxlen < (j -i +1)) {
                   maxlen = j - i + 1;
                   start = i;
                   end = j;
               }  
           } 
            
        }
        
    }
    substr = (char*) malloc(maxlen+1);
    strncpy(substr, &s[start], maxlen);
    substr[maxlen] = '\0';
    return substr;
    

}
*/

int search_palindrome(char* s, int len, int start, int end)
{
    while((s[start] == s[end]) && (start >=0) && (end < len))
          {
              start--;
              end++;
          }
    printf("end %d start %d\n", end, start);
    return end - start - 1;
    
}
char* longestPalindrome(char* s) {

    int len = strlen(s);
    int slen = 0;
    int i = 0;
    int start = 0;
    int end = 0;
    int slen1 = 0;
    int slen2 = 0;
    
    if (len <= 1)
        return s;
    
    for (i = 0; i < len; i++) {
        slen1 = search_palindrome(s, len, i, i);    
        slen2 = search_palindrome(s, len, i, i + 1);
        slen = (slen1 > slen2) ? slen1 : slen2;
        printf("slen1 %d slen2 %d slen %d \n", slen1, slen2, slen);
        if (slen > (end - start)) {
            start = i - (slen - 1) / 2;
            end = i + slen / 2;
        }
        
    }
    
    s[end + 1] = '\0';
    return &s[start];
    
}
