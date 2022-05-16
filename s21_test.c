#include "s21_string.h"

START_TEST(memchr_test) {
  char testUnit1[]  = {"name"};
  char testUnit2[]  = {"ABOBA"};
  char testUnit3[]  = {"543ERRoR76"};
  char testUnit4[]  = {"    nulloutside"};

  ck_assert_str_eq((memchr(testUnit1, 'a', s21_strlen(testUnit1))),
  (s21_memchr(testUnit1, 'a', s21_strlen(testUnit1))));
  ck_assert_str_eq((memchr(testUnit2, 'A', s21_strlen(testUnit2))),
  (s21_memchr(testUnit2, 'A', s21_strlen(testUnit2))));
  ck_assert_str_eq((memchr(testUnit3, '7', s21_strlen(testUnit3))),
  (s21_memchr(testUnit3, '7', s21_strlen(testUnit3))));
  ck_assert_str_eq((memchr(testUnit4, ' ', s21_strlen(testUnit4))),
  (s21_memchr(testUnit4, ' ', s21_strlen(testUnit4))));
} END_TEST

START_TEST(loop_memcmp_test_rav) {
  static const char* mcpmTestUnit[6] = {"BIBA", "name", "ABOBA", "543ERRoR76", "BEAR"};
  static const char* mcpmTestUnit_STR[6] = {"BIBA", "name", "ABOBA", "543ERRoR76", "BEAR"};
  _ck_assert_int(s21_memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3), == ,
  memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3));
} END_TEST

START_TEST(loop_memcmp_test_minus) {
  static const char* mcpmTestUnit[6] = {"BIBA", "name", "ABOBA", "543ERRoR76", "BEAR"};
  static const char* mcpmTestUnit_STR[6] = {"BOBA", "zero", "cuter", "NUMCOLUMN", "USECCRYCHEBEAR"};
  _ck_assert_int(s21_memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3), >= ,
  memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3));
} END_TEST

START_TEST(loop_memcmp_test_plus) {
  static const char* mcpmTestUnit[6] = {"BOBA", "zero", "cuter", "NUMCOLUMN", "USECCRYCHEBEAR"};
  static const char* mcpmTestUnit_STR[6] = {"BIBA", "name", "ABOBA", "543ERRoR76", "BEAR"};
  _ck_assert_int(s21_memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3), <= ,
  memcmp(mcpmTestUnit[_i], mcpmTestUnit_STR[_i], 3));
} END_TEST

START_TEST(loop_memcpy_test) {
  static char* testUnit[5]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", ""};
  char str2[100];
  ck_assert_str_eq(memcpy(str2, testUnit[_i], 2), s21_memcpy(str2, testUnit[_i], 2));
} END_TEST

START_TEST(loop_memmove_test) {
  static char testUnit_memmove[5][20]  = {"name", "ABOBA", "543ERRoR76", "abobish", ""};
  static char testUnit_memmove2[5][20]  = {"name", "ABOBA", "543ERRoR76", "abobish", "shushka"};
  static int numver[5]  = {3, 4, 6, 2, 3};
  static char naibor[50];
  static char naibor2[50];
  memmove(naibor, testUnit_memmove[_i], numver[_i]);
  s21_memmove(naibor2, testUnit_memmove[_i], numver[_i]);
  ck_assert_str_eq(naibor, naibor2);
}END_TEST

START_TEST(loop_memset_test) {
  static char testUnit_memset[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", ""};
  ck_assert_str_eq(memset(testUnit_memset[_i], '*', 2), s21_memset(testUnit_memset[_i], '*', 2));
} END_TEST

START_TEST(loop_strcat_test) {
  static char testUnit_memset[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", ""};
  static char testUnit_memset_MOM[5][20]  = {"NODE", "TUPESCRIPT", "JAVAGOVNO", "PITON_TOJE", "CUM"};
  ck_assert_str_eq(strcat(testUnit_memset[_i], testUnit_memset_MOM[_i]),
  s21_strcat(testUnit_memset[_i], testUnit_memset_MOM[_i]));
} END_TEST

START_TEST(loop_strncat_test) {
  static char testUnit_memset[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", ""};
  static char testUnit_memset_MOM[5][20]  = {"NODE", "TUPESCRIPT", "JAVAGOVNO", "PITON_TOJE", "CUM"};
  static int intarray[5] = {2, 3, 5, 7, 0};
  ck_assert_str_eq(strncat(testUnit_memset[_i], testUnit_memset_MOM[_i], intarray[_i]),
  s21_strncat(testUnit_memset[_i], testUnit_memset_MOM[_i], intarray[_i]));
} END_TEST

START_TEST(loop_strchr_test) {
  static char testUnit_strchr[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside"};
  static char testUnit_char[5] = {'e', 'O', 'o', ' '};
  ck_assert_str_eq(strchr(testUnit_strchr[_i], testUnit_char[_i]),
  s21_strchr(testUnit_strchr[_i], testUnit_char[_i]));
} END_TEST

START_TEST(loop_strcmp_test) {
  static char testUnit_strcmp[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  static char testUnit_strcmp_sec[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", "bibos"};
  ck_assert_int_eq(strcmp(testUnit_strcmp[_i], testUnit_strcmp_sec[_i]),
  s21_strcmp(testUnit_strcmp[_i], testUnit_strcmp_sec[_i]));
} END_TEST

START_TEST(loop_strncmp_test) {
  static char testUnit_strcmp[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  static char testUnit_strcmp_sec[5][20]  = {"name", "ABOBA", "543ERRoR76", "    nulloutside", "bibos"};
  static int sravSumbol[5] = {3, 5, 5, 2, 1};
  ck_assert_int_eq(strncmp(testUnit_strcmp[_i], testUnit_strcmp_sec[_i], sravSumbol[_i]),
  s21_strncmp(testUnit_strcmp[_i], testUnit_strcmp_sec[_i], sravSumbol[_i]));
} END_TEST

START_TEST(loop_strcpy_test) {
  char array[100] = "";
  static char testUnit_strcmp[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  ck_assert_str_eq(strcpy(array, testUnit_strcmp[_i]), s21_strcpy(array, testUnit_strcmp[_i]));
} END_TEST

START_TEST(strncpy_test) {
  char array1[] = "nibba";
  static char array2[] = "ABOBI";
  static char array3[] = "543ERRoR76";
  static char array4[] = "    nul";
  static char array5[] = "";
  char empty_array[] = "";

  ck_assert_str_eq(strncpy(empty_array, array1, 3), s21_strncpy(empty_array, array1, 3));
  ck_assert_str_eq(strncpy(empty_array, array2, 3), s21_strncpy(empty_array, array2, 4));
  ck_assert_str_eq(strncpy(empty_array, array3, 3), s21_strncpy(empty_array, array3, 5));
  ck_assert_str_eq(strncpy(empty_array, array4, 3), s21_strncpy(empty_array, array4, 6));
  ck_assert_str_eq(strncpy(empty_array, array5, 3), s21_strncpy(empty_array, array5, 3));
} END_TEST

START_TEST(loop_strcspn_test) {
  char array[100] = "";
  static char testUnit_strncpy[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  ck_assert_int_eq(strcspn(array, testUnit_strncpy[_i]), s21_strcspn(array, testUnit_strncpy[_i]));
} END_TEST

START_TEST(strerror_test) {
  ck_assert_str_eq(strerror(14), s21_strerror(14));
} END_TEST

START_TEST(strerror_error_test) {
  ck_assert_str_eq(strerror(200), s21_strerror(200));
} END_TEST

START_TEST(loop_strlen_test) {
  static char testUnit_strncpy[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  ck_assert_int_eq(strlen(testUnit_strncpy[_i]), s21_strlen(testUnit_strncpy[_i]));
} END_TEST

START_TEST(loop_strpbrk_test) {
  char testUnit_strncpy[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  char testUnit_memset[5][20]  = {"name", "fdO", "o", " ", "kkp"};
  ck_assert_str_eq(strpbrk(testUnit_strncpy[_i], testUnit_memset[_i]),
  s21_strpbrk(testUnit_strncpy[_i], testUnit_memset[_i]));
} END_TEST

START_TEST(loop_strrchr_test) {
  char testUnit_strncpy[5][20]  = {"nibba", "ABOBI", "543ERRoR76", "    nul", ""};
  char testUnit_char[5] = {'b', 'O', 'o', ' '};
  ck_assert_str_eq(strrchr(testUnit_strncpy[_i], testUnit_char[_i]),
  s21_strrchr(testUnit_strncpy[_i], testUnit_char[_i]));
} END_TEST

START_TEST(loop_strspn_test) {
  char testUnit_strncpy[5][30] =
  {"STRINGNUMISSOGOOD", "ABOBINAMEDISFAIL", "DANIAISNOTCOUNTRY", " IFYOURNAMEITSNIKITATHEYDIE", "POPQUIZER"};
  char testUnit_memset[5][20]  = {"NGSI", "FGDPOUI", "DAROTH", " ", "POPQUIZER"};
  ck_assert_int_eq(strspn(testUnit_strncpy[_i], testUnit_memset[_i]),
  s21_strspn(testUnit_strncpy[_i], testUnit_memset[_i]));
} END_TEST

START_TEST(loop_strstr_test) {
  char testUnit_strncpy[5][30]  =
  {"STRINGNUMISSOGOOD", "ABOBINAMEDISFAIL", "DANIAISNOTCOUNTRY", " IFYOURNAMEITSNIKITATHEYDIE", "POPQUIZER"};
  char testUnit_memset[5][20]  = {"STRING", "DIS", "NOTCO", " ", "POPQUIZER"};
  ck_assert_str_eq(strstr(testUnit_strncpy[_i], testUnit_memset[_i]),
  s21_strstr(testUnit_strncpy[_i], testUnit_memset[_i]));
} END_TEST

START_TEST(strtok_test) {
  char array[] = {"hello, aboba! how is your going?"};
  char array2[] = {"hello aboba, howis your going!"};
  char leksemi[]  = {" ,!"};
  char leksemi2[]  = {", !"};
  ck_assert_str_eq(strtok(array, leksemi), s21_strtok(array2, leksemi2));
} END_TEST

START_TEST(loop_to_upper_test) {
  const char testUnit_toupper[5][25] =
  {"ytuerwti", "abobik", "543ERRoR76", "fghjksdfhksd", "null_ti_konch?"};
  const char stACEPT[5][20]  = {"YTUERWTI", "ABOBIK", "543ERROR76", "FGHJKSDFHKSD", "NULL_TI_KONCH?"};
  ck_assert_str_eq(s21_to_upper(testUnit_toupper[_i]), stACEPT[_i]);
} END_TEST

START_TEST(loop_to_upper_test_p) {
  const char testUnit_toupperp[5][25] =
  {"ytuerwti", "abobik", "543ERRoR76", "fghjksdfhks", "null_ti_konch?"};
  const char stACEPTp[5][20] = {"YTUERWTI", "ABOBIK", "543ERROR76", "FGHJKSDFHKS", "NULL_TI_KONCH?"};
  ck_assert_str_eq(s21_to_upper(testUnit_toupperp[_i]), stACEPTp[_i]);
} END_TEST

START_TEST(loop_to_lower_test) {
  const char testUnit_tolower[5][25] =
  {"ytuerwti", "abobik", "543error76", "fghjksdfhksd", "null_ti_konch?"};
  const char stACEPT[5][20]  = {"YTUERWTI", "ABOBIK", "543ERROR76", "FGHJKSDFHKSD", "NULL_TI_KONCH?"};
  ck_assert_str_eq(s21_to_lower(stACEPT[_i]), testUnit_tolower[_i]);
} END_TEST

START_TEST(loop_to_lower_test_p) {
  const char testUnit_tolower2p[5][25] =
  {"ytuerwti", "abobik", "543error76", "fghjksdfhksd", "null_ti_konch?"};
  const char stACEPT2p[5][20]  = {"YTUERWTI", "ABOBIK", "543ERROR76", "FGHJKSDFHKSD", "NULL_TI_KONCH?"};
  ck_assert_str_eq(s21_to_lower(stACEPT2p[_i]), testUnit_tolower2p[_i]);
} END_TEST

START_TEST(loop_insert_test) {
  const char testUnit_insert[5][45]  = {"num1", "num2", "num3", "num4", "num5"};
  const char testUnit_insert2[5][45]  = {"num1", "num2", "num3", "num4", "num5"};
  const char testElem_insert[5][40] = {"num1", "num2", "num3", "num4", "num5"};
  const int testindex[5] = {2, 2, 2, 2, 2};
  const char stACEPTinsert[5][40]  = {"nunum1m1", "nunum2m2", "nunum3m3", "nunum4m4", "nunum5m5"};
  ck_assert_str_eq(s21_insert(testUnit_insert[_i], testElem_insert[_i], testindex[_i]), stACEPTinsert[_i]);
} END_TEST

START_TEST(trim_test) {
  const char testUnit_TRIM[]= {"*/*num1*/*"};
  const char symbol[] = {"*/*"};
  const char stACEPTtrim[]  = {"num1"};
  ck_assert_str_eq(s21_trim(testUnit_TRIM, symbol), stACEPTtrim);
} END_TEST

START_TEST(SPRINTF_FLOAT) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_FLOAT_PREC) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%.5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_FLOAT_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_FLOAT_H_PREC) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5.5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_FLOAT_MINUS) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_FLOAT_MINUS_DIGIT) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%f";
  float f = -7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_FLOAT_SPACE) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "% f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_FLOAT_PLUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%+5f";
  float f = 7.891233;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_FLOAT_LONG) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%.16f";
  float f = 7.891235551512512321;
  sprintf(result, format_str, f);
  s21_sprintf(result_s21, format_str, f);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_DECIMAL) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%d";
  int d = 5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_DECIMAL_PREC) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5d";
  int d = 5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_DECIMAL_L) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%ld";
  long long d = LONG_MAX;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_DECIMAL_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%hd";
  int d = INT_MAX;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_DECIMAL_MINUS_DIGIT) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%d";
  int d = -5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_DECIMAL_MINUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5d";
  int d = -5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_DECIMAL_PLUS_DIGIT) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%+d";
  int d = 5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_DECIMAL_SPACE) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "% d";
  int d = 5;
  sprintf(result, format_str, d);
  s21_sprintf(result_s21, format_str, d);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_UNSIGNED) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%u";
  unsigned int u = 5;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_UNSIGNED_MINUS_DIGIT) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%u";
  unsigned int u = -5;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_UNSIGNED_LONG) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%lu";
  unsigned long int u = ULONG_MAX;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_UNSIGNED_SHORT) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%hu";
  unsigned long int u = USHRT_MAX;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_UNSIGNED_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5u";
  unsigned int u = 5;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_UNSIGNED_MINUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5u";
  unsigned int u = 5;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_UNSIGNED_SPACE) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "% u";
  unsigned int u = 5;
  sprintf(result, format_str, u);
  s21_sprintf(result_s21, format_str, u);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_CHAR) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%c";
  char c = 'c';
  sprintf(result, format_str, c);
  s21_sprintf(result_s21, format_str, c);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_CHAR_DIGIT) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%c";
  int c = 48;
  sprintf(result, format_str, c);
  s21_sprintf(result_s21, format_str, c);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_CHAR_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5c";
  int c = 48;
  sprintf(result, format_str, c);
  s21_sprintf(result_s21, format_str, c);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_CHAR_MINUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5c";
  int c = 48;
  sprintf(result, format_str, c);
  s21_sprintf(result_s21, format_str, c);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_CHAR_SPACE) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "% c";
  int c = 48;
  sprintf(result, format_str, c);
  s21_sprintf(result_s21, format_str, c);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_STRING) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%s";
  char s[] = "ABOBA";
  sprintf(result, format_str, s);
  s21_sprintf(result_s21, format_str, s);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_STRING_SYMBOLS) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%s";
  char s[] = "A\nB\tO\vB\rA\0C";
  sprintf(result, format_str, s);
  s21_sprintf(result_s21, format_str, s);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_STRING_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5s";
  char s[] = "ABOBA";
  sprintf(result, format_str, s);
  s21_sprintf(result_s21, format_str, s);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_STRING_MINUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5s";
  char s[] = "ABOBA";
  sprintf(result, format_str, s);
  s21_sprintf(result_s21, format_str, s);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_STRING_SPACE) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "% s";
  char s[] = "ABOBA";
  sprintf(result, format_str, s);
  s21_sprintf(result_s21, format_str, s);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_I_DEC) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%i";
  int i = 5;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_I_OCTAL) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_I_HEX) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%i";
  int i = 0xF;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_I_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%5i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_I_MINUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%-5i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_I_PLUS) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%+i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_I_PLUS_H) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "%+5i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
} END_TEST

START_TEST(SPRINTF_I_SPACE) {
  char result[100] = "";
  char result_s21[100] = "";
  char format_str[100] = "% i";
  int i = 05;
  sprintf(result, format_str, i);
  s21_sprintf(result_s21, format_str, i);
  ck_assert_str_eq(result, result_s21);
} END_TEST


Suite * test_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("test");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, SPRINTF_FLOAT);
  tcase_add_test(tc_core, SPRINTF_FLOAT_PREC);
  tcase_add_test(tc_core, SPRINTF_FLOAT_H);
  tcase_add_test(tc_core, SPRINTF_FLOAT_H_PREC);
  tcase_add_test(tc_core, SPRINTF_FLOAT_MINUS);
  tcase_add_test(tc_core, SPRINTF_FLOAT_MINUS_DIGIT);
  tcase_add_test(tc_core, SPRINTF_FLOAT_SPACE);
  tcase_add_test(tc_core, SPRINTF_FLOAT_PLUS_H);
  tcase_add_test(tc_core, SPRINTF_FLOAT_LONG);

  tcase_add_test(tc_core, SPRINTF_DECIMAL);
  tcase_add_test(tc_core, SPRINTF_DECIMAL_PREC);
  tcase_add_test(tc_core, SPRINTF_DECIMAL_L);
  tcase_add_test(tc_core, SPRINTF_DECIMAL_H);
  tcase_add_test(tc_core, SPRINTF_DECIMAL_MINUS_DIGIT);
  tcase_add_test(tc_core, SPRINTF_DECIMAL_PLUS_DIGIT);
  tcase_add_test(tc_core, SPRINTF_DECIMAL_MINUS_H);
  tcase_add_test(tc_core, SPRINTF_DECIMAL_SPACE);

  tcase_add_test(tc_core, SPRINTF_UNSIGNED);
  tcase_add_test(tc_core, SPRINTF_UNSIGNED_MINUS_DIGIT);
  tcase_add_test(tc_core, SPRINTF_UNSIGNED_LONG);
  tcase_add_test(tc_core, SPRINTF_UNSIGNED_SHORT);
  tcase_add_test(tc_core, SPRINTF_UNSIGNED_MINUS_H);
  tcase_add_test(tc_core, SPRINTF_UNSIGNED_H);
  tcase_add_test(tc_core, SPRINTF_UNSIGNED_SPACE);

  tcase_add_test(tc_core, SPRINTF_CHAR);
  tcase_add_test(tc_core, SPRINTF_CHAR_DIGIT);
  tcase_add_test(tc_core, SPRINTF_CHAR_H);
  tcase_add_test(tc_core, SPRINTF_CHAR_MINUS_H);
  tcase_add_test(tc_core, SPRINTF_CHAR_SPACE);

  tcase_add_test(tc_core, SPRINTF_STRING);
  tcase_add_test(tc_core, SPRINTF_STRING_SYMBOLS);
  tcase_add_test(tc_core, SPRINTF_STRING_MINUS_H);
  tcase_add_test(tc_core, SPRINTF_STRING_H);
  tcase_add_test(tc_core, SPRINTF_STRING_SPACE);

  tcase_add_test(tc_core, SPRINTF_I_DEC);
  tcase_add_test(tc_core, SPRINTF_I_OCTAL);
  tcase_add_test(tc_core, SPRINTF_I_HEX);
  tcase_add_test(tc_core, SPRINTF_I_H);
  tcase_add_test(tc_core, SPRINTF_I_MINUS_H);
  tcase_add_test(tc_core, SPRINTF_I_PLUS);
  tcase_add_test(tc_core, SPRINTF_I_PLUS_H);
  tcase_add_test(tc_core, SPRINTF_I_SPACE);

  tcase_add_test(tc_core, memchr_test);
  tcase_add_loop_test(tc_core, loop_memcmp_test_rav, 0, 5);
  tcase_add_loop_test(tc_core, loop_memcmp_test_minus, 0, 5);
  tcase_add_loop_test(tc_core, loop_memcmp_test_plus, 0, 5);
  tcase_add_loop_test(tc_core, loop_memcpy_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_memmove_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_memset_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strcat_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strncat_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strchr_test, 0, 4);
  tcase_add_loop_test(tc_core, loop_strcmp_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strncmp_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strcpy_test, 0, 5);
  tcase_add_test(tc_core, strncpy_test);
  tcase_add_loop_test(tc_core, loop_strcspn_test, 0, 5);
  tcase_add_test(tc_core, strerror_test);
  tcase_add_test(tc_core, strerror_error_test);
  tcase_add_loop_test(tc_core, loop_strlen_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strpbrk_test, 0, 4);
  tcase_add_loop_test(tc_core, loop_strrchr_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strspn_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_strstr_test, 0, 5);
  tcase_add_test(tc_core, strtok_test);

  tcase_add_loop_test(tc_core, loop_to_upper_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_to_upper_test_p, 0, 5);
  tcase_add_loop_test(tc_core, loop_to_lower_test, 0, 5);
  tcase_add_loop_test(tc_core, loop_to_lower_test_p, 0, 5);
  tcase_add_loop_test(tc_core, loop_insert_test, 0, 5);
  tcase_add_test(tc_core, trim_test);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = test_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
