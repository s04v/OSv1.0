
char *strcpy(char *l, const char *r)
{
    while(*r) *l++ = *r++;
    l++ ;
    *l = '\0';
    return l;
}