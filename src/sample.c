#include <stdio.h>
#include "log.h"

int main()
{
    char x[100];
    char xe[100];
    sprintf(x, "test.log");
    sprintf(xe, "test.err");
    LOG_INIT(x, xe, 1);
    DEBUG("This is testing debugging message from sample program \n");
    ERROR("Error message from sample program\n");
    LOG_CLOSE();
    return 0;
}
