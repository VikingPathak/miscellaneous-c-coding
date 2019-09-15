//Created by Amit Pathak apathak092@gmail.com

#include <regex.h>
#include <stdio.h>

int main() {

  regex_t preg;
  char *string = "ALIGN_QWERTY_KEY_UI; cd";
  char *pattern1 = "(^[A-Z])(([A-Z_]+_)?SK(_[A-Z_]+)?(;|$))";
  int rc;
  size_t nmatch = 2;
  regmatch_t pmatch[2];

  if ((rc = regcomp(&preg, pattern1, REG_EXTENDED)) == 0) {
    if ((rc = regexec(&preg, string, nmatch, pmatch, 0)) != 0) {
       printf("Match not present");
    }else{
       printf("Match present");
  }

  regfree(&preg);
}
