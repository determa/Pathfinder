#include "../inc/libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {

	if (big_len >= little_len && big_len > 0 && little_len > 0) {
		unsigned char *s1 = (unsigned char *)big;
		unsigned char *s2 = (unsigned char *)little;
		while (*s1) {
			if (mx_memcmp(s1, s2, little_len - 1) == 0)
				return s1;
			s1++;
		}
	}
	return NULL;
}

