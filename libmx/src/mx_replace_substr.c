#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace)
		return NULL;

    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);
	int len = mx_strlen(str) + mx_count_substr(str, sub) * (replace_len - sub_len);
	char *res = mx_strnew(len);
	for (int i = 0; i < len; i++, str++) {
        if (!mx_strncmp((char *)str, (char *)sub, sub_len)) {
            mx_strncpy(&res[i], replace, replace_len);
            i += replace_len - 1;
            str += sub_len - 1;
        }
        else
            res[i] = *str;
    }
    return res;
}

