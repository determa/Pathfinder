void mx_str_reverse(char *s) {
    int len = 0;
    char temp;
    while(s[len] != '\0')
        len++;
    for(int i = 0, j = len - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

