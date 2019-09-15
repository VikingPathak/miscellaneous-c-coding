//Created by Amit Pathak apathak092@gmail.com

#include <regex.h>                                                              
#include <stdio.h>                                                              
                                                                                
int main() {                                                                        
    regex_t    preg;                                                            
    char       *string = "<tst:33fe09dev4 ad9d-583585a-addhyc-48htdf-09rge7e2b3d7;+u.sp!devicename.cytre.com=00245CB0654B4;X-tag=AES_WIFI;";                                     
    char       *pattern1 = "cisco-mra-ha[ ]*=[ ]*WIFI[ ]*(;|$)";  
    char       *pattern2 = "cisco-mra-ha[ ]*=[ ]*[A-Z]+_WIFI[ ]*(;|$)";
    char       *pattern3 = "cisco-mra-ha[ ]*=[ ]*WIFI_[A-Z]+[ ]*(;|$)";
    char       *pattern4 = "cisco-mra-ha[ ]*=[ ]*[A-Z]+_WIFI_[A-Z]+[ ]*(;|$)";
    int        rc;                                                              
    size_t     nmatch = 2;                                                      
    regmatch_t pmatch[2];                                                       
                                                                                
    if ((rc = regcomp(&preg, pattern1, REG_EXTENDED)) == 0) {
        if ((rc = regexec(&preg, string, nmatch, pmatch, 0)) != 0) {                
            if ((rc = regcomp(&preg, pattern2, REG_EXTENDED)) == 0){
                if ((rc = regexec(&preg, string, nmatch, pmatch, 0)) != 0) {                
                    if ((rc = regcomp(&preg, pattern3, REG_EXTENDED)) == 0){
                        if ((rc = regexec(&preg, string, nmatch, pmatch, 0)) != 0) {                
                            if ((rc = regcomp(&preg, pattern4, REG_EXTENDED)) == 0){
                                if ((rc = regexec(&preg, string, nmatch, pmatch, 0)) != 0) {
                                    printf("Match not present");
                                }else{
                                    printf("Match present");
                                }
                            }
                        }
                    }
                }
            }
        }
    }      

    regfree(&preg);                                                             
}           
