int myAtoi(char* str) 
{
    unsigned long long ret = 0;
    char *p = str;
    int sign = 1;
    
    /*skip whitespace*/
       while ((*p != '\0') && isspace(*p)){
        p++;     
     }

    sign = (*p == '-') ? -1 : 1;
    
    if (*p == '-' || (*p == '+')) {
        p++;
    }

    while (*p != '\0' && isdigit(*p)) {
        ret = ret * 10 + *p - '0';
        if (ret > INT_MAX)
            break;
        p++;
    }
    
    if(ret > INT_MAX)
        return sign == 1 ? INT_MAX : INT_MIN;

    return ret * sign;    
}
