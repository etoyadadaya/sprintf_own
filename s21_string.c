#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    void *p = s21_NULL;
    c = (unsigned char)c;

    if (n > 0) {
        while (--n) {
        if (*(unsigned const char*)str++ == c) {
          p = (unsigned char*)--str;
          break;
        }
      }
        if (c == '\0') {
          p = (char*)str;
        }
    }

  return p;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *p = str1;
    const unsigned char *q = str2;
    int charCompareCheck = 0;
    if (str1 == str2) {
        return charCompareCheck;
    }

    while (n > 0) {
        if (*p != *q) {
            if (*p > *q) {
                charCompareCheck = 1;
            } else {
                charCompareCheck = -1;
            }
            break;
        }
        n--;
        p++;
        q++;
    }
    return charCompareCheck;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char* d = dest;
    const char* s = src;
    for (int i = 0; i < (int)n; i++) {
        d[i] = s[i];
    }
    return dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *pDest = (char*)dest;
    const char *pSrc = (const char*)src;

    if ((pSrc == s21_NULL) || (pDest == s21_NULL)) {
        return s21_NULL;
    }

    if ((pSrc < pDest) && (pDest < pSrc + n)) {
        for (pDest += n, pSrc +=n; n--;) {
            *--pDest = *--pSrc;
        }
    } else {
        while (n--) {
            *pDest++ = *pSrc++;
        }
    }
    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char* p = str;

    while (n--) {
        *p++ = (unsigned char)c;
    }

    return str;
}

char* s21_strcat(char *dest, const char* src) {
    int i, j;

    for (i = 0; dest[i] != '\0'; i++) {}

    for (j = 0; src[j] != '\0'; j++) {
        dest[i + j] = src[j];
    }

    dest[i + j] = '\0';

    return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    int i, j;

    for (i = 0; dest[i] != '\0'; i++) {
    }

    for (j = 0; src[j] != '\0' && j < (int)n; j++) {
        dest[i + j] = src[j];
    }

    dest[i + j] = '\0';

    return dest;
}

char *s21_strchr(const char *str, int c) {
    char *p = NULL;
    if (c == 256) {
        int str_len = s21_strlen(str);
        p = (char*)str + str_len;
    } else {
        c = (unsigned char)c;
    }
    while (*str && !p) {
        if (*str == c) {
            p = (char*)str;
        }
        str++;
    }

    return p;
}

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1) {
        if (*str1 != *str2) {
            break;
        }
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    while (--n && *str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }

    return (unsigned char)*str1 - (unsigned char)*str2;
}

char *s21_strcpy(char *dest, const char *src) {
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t i = 0;
    while (n > 0 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
        n--;
    }
    if (src[i] == '\0') {
        dest[i] = '\0';
        i++;
        n--;
        s21_size_t m = s21_strlen(&dest[i]);
        while (m > 0) {
            dest[i] = ' ';
            i++;
            m--;
        }
    }
    return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    int count = 0;
    for (int i = 0; str1[i] != '\0'; i++) {
        for (int j = 0; j < str2[j] && str2[j]!= '\0'; j++) {
            if (str1[i] == str2[j]) {
                count = i++;
                break;
            }
        }
        if (count > 0) {
            break;
        }
    }
    return count;
}

char *int_to_char(int number) {
    static char str1[20];
    char part_number;
    int temp_number = number, i = 0;

    if (number < 0) {
        temp_number *= -1;
    } else if (number == 0) {
        str1[i++] = '0';
    }

    for (; temp_number; i++) {
        part_number = (char)(temp_number%10) + '0';
        str1[i] = part_number;
        temp_number /= 10;
    }

    if (number < 0) {
        str1[i++] = '-';
    }

    for (int temp, j = 0; j < (i + (i%2))/2; j++) {
        temp = str1[j];
        str1[j] = str1[i-1-j];
        str1[i-1-j] = temp;
    }

    str1[i] = '\0';

    return str1;
}

char *s21_strerror(int errnum) {
    char *error_code, *p;

    if (Mac) {
        if (errnum >= MIN && errnum <= MAX) {
            p = STRERROR_ERRORS[errnum];
        } else {
            char error_unknown[50] = "Unknown error: ";
            error_code = int_to_char(errnum);
            s21_strcat(error_unknown, error_code);
            p = error_unknown;
        }
    } else if (Linux) {
        if (errnum >= MIN && errnum <= MAX) {
            p = STRERROR_ERRORS[errnum];
        } else {
            char error_unknown[50] = "Unknown error ";
            error_code = int_to_char(errnum);
            s21_strcat(error_unknown, error_code);
            p = error_unknown;
        }
    }

    return p;
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; str[len]; len++) {}
    return len;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    if ((str1 == s21_NULL) || (str2 == s21_NULL)) {
        return s21_NULL;
    }

    while (*str1) {
        if (s21_strchr(str2, *str1)) {
            return (char*)str1;
        } else {
            str1++;
        }
    }
    return s21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  char *p = NULL;

  c = (unsigned char)c;
  while (*str) {
    if (*str == c) {
      p = (char*)str;
    }
    str++;
  }
  if (c == '\0') {
    p = (char*)str;
  }

  return p;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    unsigned int len = 0;

    if ((str1 == s21_NULL) || (str2 == s21_NULL)) {
        return len;
    }

    while (*str1 && s21_strchr(str2, *str1++)) {
        len++;
    }
    return len;
}

int compare(const char *haystack, const char *needle) {
    while (*haystack && *needle) {
        if (*haystack != *needle) {
            return 0;
        }
        haystack++;
        needle++;
    }
    return (*needle == '\0');
}

char *s21_strstr(const char *haystack, const char *needle) {
    while (*haystack != '\0') {
        if ((*haystack == *needle) && compare(haystack, needle)) {
            return (char*)haystack;
        }
        haystack++;
    }
    return s21_NULL;
}

char *s21_strtok(char *str, const char *delim) {
    static char * ptr = NULL;
    int ptr_is_null = 1;

    if (str) {
        for (ptr = str; s21_strchr(delim, *ptr); ) {
            ++ptr;
        }
    }

    if (ptr == NULL || *ptr == '\0') {
        ptr_is_null = 0;
        ptr = NULL;
    }

    str = ptr;

    while (ptr_is_null && *ptr && !s21_strchr(delim, *ptr)) {
        ++ptr;
    }

    while (ptr_is_null && *ptr && s21_strchr(delim, *ptr)) {
        *ptr++ = '\0';
    }

    return str;
}

//  sprintf

int s21_isdigit(int c) {
    if ((c < '0') || (c > '9'))
        return (0);
    return (1);
}

int s21_isspace(int c) {
    return (c == ' ' || (c > 8 && c < 14));
}

int s21_len(long nb) {
    int len = 0;

    if (nb == 0) {
        len = 1;
    }
    if (nb < 0) {
        nb = nb * -1;
        len++;
    }
    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return (len);
}

void s21_strreverse(char *str, int len) {
    int i = 0, j = len - 1, temp;

    while (i < j) {
        temp = (int)str[i];
        str[i] = str[j];
        str[j] = (char)temp;
        i++;
        j--;
    }
}

void s21_utoa(unsigned long long num, char *str, int base) {
    int i = 0;

    if (num == 0) {
        str[i++] = 48;
        str[i] = 0;
        return;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 97 : rem + 48;
        num = num / base;
    }

    str[i] = 0;

    s21_strreverse(str, (int)s21_strlen(str));
}

long long s21_pow(int x, unsigned n) {
    long long pow = 1;
    for (unsigned long i = 0; i < n; i++) {
        pow = pow * x;
    }
    return pow;
}

char* s21_strdup(const char *s1) {
    size_t i;
    char *new;

    i = 0;
    new = NULL;
    if ((new = (char *)malloc(sizeof(const char *) * s21_strlen(s1) + 1))) {
        while (i < s21_strlen(s1)) {
            new[i] = s1[i];
            i++;
        }
        new[i] = 0;
    }
    return (new);
}

char* s21_strjoin(char const *s1, char const *s2) {
    size_t i;
    size_t i2;
    size_t len1;
    size_t len2;
    char *new;

    i = 0;
    len1 = s21_strlen(s1);
    len2 = s21_strlen(s2);
    if (!(new = (char *)malloc(sizeof(char) * (len1 + len2) + 1))) {
        return (NULL);
    }
    while (i < len1) {
        new[i] = s1[i];
        i++;
    }
    i2 = 0;
    while (i < len1 + len2) {
        new[i] = s2[i2];
        i++;
        i2++;
    }
    new[i] = 0;
    return (new);
}

static int get_return(unsigned long long ret, int neg, const char *nptr) {
    int count = 0;
    while (*nptr <= 49 || *nptr >= 57)
        nptr++;
    while (s21_isdigit(*(nptr + count)))
        count++;
    if (count >= 19) {
        return (neg == -1 ? 0 : -1);
    }
    if (ret > 9223372036854775807) {
        return (neg == -1 ? 0 : -1);
    } else {
        return (int)(ret * neg);
    }
}

int s21_atoi(const char *nptr) {
    unsigned long long ret;
    int len;
    int x;
    int neg;

    neg = 1;
    x = -1;
    len = 0;
    ret = 0;
    while (s21_isspace(*nptr))
        nptr++;
    while (nptr[len])
        len++;
    while (++x <= len) {
        if (s21_isdigit(nptr[x])) {
            ret = (ret * 10) + (nptr[x] - 48);
        } else if (x == 0 && (nptr[x] == 45 || nptr[x] == 43)) {
            neg = nptr[x] == 45 ? -1 : 1;
        } else {
            return (get_return(ret, neg, nptr));
        }
    }
    return (get_return(ret, neg, nptr));
}

void s21_ftoa(long double f, char * buf, int precision) {
    char * ptr = buf;
    char * p = ptr;
    char * p1;
    char c;
    long intPart;

    if (f < 0) {
        f = -f;
        *ptr++ = 45;
    }

    if (precision)
        f += 0.5 / (long double)s21_pow(10, precision);

    intPart = (long)f;
    f -= intPart;

    if (!intPart) {
        *ptr++ = 48;
    } else {
        p = ptr;
        while (intPart) {
            *p++ = (char)(intPart % 10 + 48);
            intPart /= 10;
        }
        p1 = p;
        while (p > ptr) {
            c = *--p;
            *p = *ptr;
            *ptr++ = c;
        }
        ptr = p1;
    }
    if (precision) {
        *ptr++ = 46;
        while (precision--) {
            f *= 10.0;
            c = (char)f;
            *ptr++ = (char)(c + 48);
            f -= c;
        }
    }
    *ptr = 0;
}

char* s21_itoa(long long n) {
    char *str;

    if (n == -2147483648) {
        return (s21_strdup("-2147483648"));
    }
    if (n < 0) {
        return (s21_strjoin("-", s21_itoa(-n)));
    }
    if (!(str = s21_strdup("0"))) {
        return (NULL);
    }
    *str = (char)(*str + (n % 10));
    if (n >= 0 && n <= 9) {
        return (s21_strdup(str));
    } else {
        return (s21_strjoin(s21_itoa(n / 10), str));
    }
}

void s21_putchar(char* str, char c, int len) {
    str[len] = c;
    str[len+1] = 0;
}

int s21_vsprintf(char* str, const char *format, va_list args) {
    int state = 0;
    int is_long = 0;
    int is_short = 0;
    int is_positive = 0;
    int is_negative = 0;
    int is_space = 0;
    int afterPoint = 0;
    int beforePoint = 0;
    int length = 0;

    while (*format) {
        if (state == 0) {
            if (*format == 37) {
                if (format[1] == 37) {
                    s21_putchar(str, 37, length);
                    length++;
                    format++;
                    state = 0;
                } else {
                    state = 1;
                }
            } else {
                s21_putchar(str, *format, length);
                length++;
            }
        }
        if (state == 1) {
            if (beforePoint == 0 && (*format == 37 || *format == 45 || *format == 43)) {
                char tmp[64] = "0";
                int j = 0;
                for (long unsigned int i = 1; i < s21_strlen(format); ++i) {
                    if (s21_isdigit(format[i])) {
                        tmp[j++] = format[i];
                        tmp[j] = 0;
                    } else {
                        beforePoint = s21_atoi(tmp);
                        break;
                    }
                }
            }
            if (afterPoint == 0 && *format == 46) {
                char tmp[64] = "0";
                int j = 0;
                for (long unsigned int i = 1; i < s21_strlen(format); ++i) {
                    if (s21_isdigit(format[i])) {
                        tmp[j++] = format[i];
                        tmp[j] = 0;
                    } else {
                        afterPoint = s21_atoi(tmp);
                        break;
                    }
                }
            }
            switch (*format) {
                case 108: {
                    is_long = 1;
                    is_short = 0;
                    break;
                }
                case 104: {
                    is_short = 1;
                    is_long = 0;
                    break;
                }
                case 43: {
                    is_positive = 1;
                    break;
                }
                case 45: {
                    is_negative = 1;
                    break;
                }
                case 32: {
                    is_space = 1;
                    break;
                }
                case 99: {
                    char ch = va_arg(args, int);
                    if ((beforePoint - 1) > 0 && !is_negative) {
                        for (int i = beforePoint - 1; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    s21_putchar(str, ch, length);
                    length++;
                    if ((beforePoint - 1) > 0 && is_negative) {
                        for (int i = beforePoint - 1; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    is_negative = 0;
                    beforePoint = 0;
                    state = 0;
                    break;
                }
                case 100: {
                    if (is_long) {
                        long long d = va_arg(args, long long);
                        char* buf;
                        buf = s21_itoa(d);
                        if (is_space) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && !is_negative && is_positive && d > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if (is_positive && d > 0) {
                            s21_putchar(str, 43, length);
                            length++;
                        }
                        for (int i = 0; buf[i]; i++) {
                            s21_putchar(str, buf[i], length);
                            length++;
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && is_negative && is_positive && d > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    if (is_short) {
                        short d = va_arg(args, int);
                        char* buf;
                        buf = s21_itoa(d);
                        if (is_space) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && !is_negative && is_positive && d > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if (is_positive && d > 0) {
                            s21_putchar(str, 43, length);
                            length++;
                        }
                        for (int i = 0; buf[i]; i++) {
                            s21_putchar(str, buf[i], length);
                            length++;
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && is_negative && is_positive && d > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    if (!is_short && !is_long) {
                        long int d = va_arg(args, int);
                        char* buf;
                        buf = s21_itoa(d);
                        if (is_space) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && !is_negative && is_positive && d > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if (is_positive && d > 0) {
                            s21_putchar(str, 43, length);
                            length++;
                        }
                        for (int i = 0; buf[i]; i++) {
                            s21_putchar(str, buf[i], length);
                            length++;
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && is_negative && is_positive && d > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    is_negative = 0;
                    beforePoint = 0;
                    is_positive = 0;
                    is_short = 0;
                    is_long = 0;
                    state = 0;
                    break;
                }
                case 105: {
                    int d = va_arg(args, int);
                    if (is_space) {
                        s21_putchar(str, 32, length);
                        length++;
                    }
                    if ((beforePoint - s21_len(d)) > 0 && !is_negative && !is_positive) {
                        for (int i = beforePoint - s21_len(d); i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    if ((beforePoint - s21_len(d) - 1) > 0 && !is_negative && is_positive && d > 0) {
                        for (int i = beforePoint - s21_len(d) - 1; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    if (is_positive && d > 0) {
                        s21_putchar(str, 43, length);
                        length++;
                    }
                    char* buf = s21_itoa(d);
                    for (int i = 0; buf[i]; i++) {
                        s21_putchar(str, buf[i], length);
                        length++;
                    }
                    if ((beforePoint - s21_len(d)) > 0 && is_negative && !is_positive) {
                        for (int i = beforePoint - s21_len(d); i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    if ((beforePoint - s21_len(d) - 1) > 0 && is_negative && is_positive && d > 0) {
                        for (int i = beforePoint - s21_len(d) - 1; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    is_negative = 0;
                    beforePoint = 0;
                    is_positive = 0;
                    state = 0;
                    break;
                }
                case 102: {
                    if (is_space) {
                        s21_putchar(str, 32, length);
                        length++;
                    }
                    double f = va_arg(args, double);
                    char buf[32];
                    if (afterPoint == 0) {
                        s21_ftoa(f, buf, 6);
                    } else {
                        s21_ftoa(f, buf, afterPoint);
                    }
                    if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative && !is_positive) {
                        for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    if ((beforePoint - s21_strlen(buf) - 1) > 0 && !is_negative && is_positive && f > 0) {
                        for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    if (is_positive && f > 0) {
                        s21_putchar(str, 43, length);
                        length++;
                    }
                    for (int i = 0; buf[i]; i++) {
                        s21_putchar(str, buf[i], length);
                        length++;
                    }
                    if ((beforePoint - s21_strlen(buf)) > 0 && is_negative && !is_positive) {
                        for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    if ((beforePoint - s21_strlen(buf) - 1) > 0 && is_negative && is_positive && f > 0) {
                        for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    is_negative = 0;
                    beforePoint = 0;
                    is_positive = 0;
                    afterPoint = 0;
                    state = 0;
                    break;
                }
                case 115: {
                    const char *s = va_arg(args, const char*);
                    s21_size_t len = s21_strlen(s);
                    if ((beforePoint - len) > 0 && !is_negative) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    while (*s) {
                        s21_putchar(str, *s++, length);
                        length++;
                    }
                    if ((beforePoint - len) > 0 && is_negative) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    is_negative = 0;
                    beforePoint = 0;
                    state = 0;
                    break;
                }
                case 117: {
                    if (is_long) {
                        unsigned long u = va_arg(args, long);
                        char buf[32];
                        s21_utoa(u, buf, 10);
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && !is_negative && is_positive && u > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if (is_positive && u > 0) {
                            s21_putchar(str, 43, length);
                            length++;
                        }
                        for (int i = 0; buf[i]; i++) {
                            s21_putchar(str, buf[i], length);
                            length++;
                        }
                        if (afterPoint) {
                            s21_putchar(str, 48, length);
                            length++;
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && is_negative && is_positive && u > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    if (is_short) {
                        unsigned short u = va_arg(args, int);
                        char buf[32];
                        s21_utoa(u, buf, 10);
                        for (int i = 0; buf[i]; i++) {
                            s21_putchar(str, buf[i], length);
                            length++;
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && !is_negative && is_positive && u > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if (is_positive && u > 0) {
                            s21_putchar(str, 43, length);
                            length++;
                        }
                        if (afterPoint) {
                            s21_putchar(str, 48, length);
                            length++;
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && is_negative && is_positive && u > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    if (!is_short && !is_long) {
                        unsigned int u = va_arg(args, unsigned int);
                        char buf[32];
                        s21_utoa(u, buf, 10);
                        if ((beforePoint - s21_strlen(buf)) > 0 && !is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && !is_negative && is_positive && u > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if (is_positive && u > 0) {
                            s21_putchar(str, 43, length);
                            length++;
                        }
                        for (int i = 0; buf[i]; i++) {
                            s21_putchar(str, buf[i], length);
                            length++;
                        }
                        if (afterPoint) {
                            s21_putchar(str, 48, length);
                            length++;
                        }
                        if ((beforePoint - s21_strlen(buf)) > 0 && is_negative && !is_positive) {
                            for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                        if ((beforePoint - s21_strlen(buf) - 1) > 0 && is_negative && is_positive && u > 0) {
                            for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    is_negative = 0;
                    beforePoint = 0;
                    is_positive = 0;
                    is_short = 0;
                    is_long = 0;
                    state = 0;
                    break;
                }
            }
        }
        format++;
    }
    return length;
}

int s21_sprintf(char* str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int len = s21_vsprintf(str, format, args);
    va_end(args);
    return len;
}

//  part 5

void *s21_to_upper(const char *str) {
    char *dest = calloc(sizeof(char), s21_strlen(str));
    int DecSafe;
    for (int i = 0; str[i] != '\0'; i++) {
        DecSafe = (int) str[i];
        if (DecSafe >= 97 && DecSafe <= 122) {
            DecSafe -= 32;
        }
        dest[i] = (char) DecSafe;
    }
    return dest;
}

void *s21_to_lower(const char *str) {
    char *dest = calloc(sizeof(char), s21_strlen(str));
    int DecSafe;
    for (int i = 0; str[i] != '\0'; i++) {
        DecSafe = (int) str[i];
        if (DecSafe >= 65 && DecSafe <= 90) {
            DecSafe += 32;
        }
        dest[i] = (char) DecSafe;
    }
    return dest;
}

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
    char* dest = calloc(sizeof(char), s21_strlen(str));
    int count = 0;
    int count2 = 0;
    for (int i = 0; (long unsigned int)i < start_index; i++) {
        dest[i] = src[i];
        count++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        dest[i + count] = str[i];
        count2++;
    }
    for (int i = start_index; src[i] != '\0'; i++) {
        dest[i + count2] = src[i];
    }
    return dest;
}

static int s21_char_in_set(char c, char const *set) {
    size_t i;

    i = 0;
    while (set[i]) {
        if (set[i] == c)
            return 1;
        i++;
    }
    return 0;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *str;
    size_t i;
    size_t start;
    size_t end;

    start = 0;
    while (src[start] && s21_char_in_set(src[start], trim_chars)) {
        start++;
    }
    end = s21_strlen(src);
    while (end > start && s21_char_in_set(src[end - 1], trim_chars))
        end--;
    str = calloc(sizeof(*src), (end - start + 1));
    if (!str) {
        return (NULL);
    }
    i = 0;
    while (start < end) {
        str[i++] = src[start++];
    }
    str[i] = 0;
    return str;
}
