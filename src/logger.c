#include "logger.h"

char* time_now(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    char*txt=asctime (timeinfo);
    txt[strlen(txt) - 1] = 0;
    return txt;
}