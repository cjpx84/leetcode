/**
  * 0 |      8 
  * 1 |   7/ 9
  * 2 |  6/  10
  * 3 | 5/   11 
  * 4 /      12  
  *
  **/
char* convert(char* s, int numRows) {
    int len = strlen(s);
    int i,j;
    char *res;
    int k,l;
    /* zigzag size, for example, r=5, the zigzag size is 8*/
    int size = 2*(numRows - 1);
    if (numRows < 2)
        return s;
    
    res = (char *)malloc(len + 1);
    res[len] = '\0';
    l = 0;
    for (i = 0; i < numRows; i++){
        for (j = i; j < len; j += size) {
            
            res[l++] = s[j];
            k = (j -i) + (size - i);
            if ((i != 0 ) && (i != numRows -1) && (k < len))
                res[l++] = s[k];        
        }
    }

    return res;
}
