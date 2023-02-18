#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <stdio.h>

#define print_help_info(info) printf("[%s]<%d>(%s):%s",__FILE__,__LINE__,__func__,# info)
#define CRASH() {re=-1;goto _func_END;}

#endif