#include "inclibs.h"
#include "../debug/debug.h"

static unsigned int ServerThreadRoutine(void *);
static _i32 OnUserLogin();

_i32 LoadConfig(Config* config,_s configPath)
{
    _i32    re=0;
    _i32    len=0;
    cJSON*  cjson=NULL;
    FILE*   f=NULL;
    _s*     buf=NULL;
    cJSON*  find=NULL;
    if((buf=malloc(BUFSIZE))==NULL)
        CRASH();
    if((f=fopen(configPath,"r"))==NULL)
        CRASH();
    if(fread(buf,BUFSIZE,1,f)==-1)
        CRASH();
    if((cjson=cJSON_Parse(buf))==NULL)
        CRASH();
    
    find=cJSON_GetObjectItem(cjson,"server-name");
    config->server_name=malloc(len=strlen(find->valuestring));
    memcpy(config->server_name,find->valuestring,len);

    find=cJSON_GetObjectItem(cjson,"server-description");
    config->server_description=malloc(len=strlen(find->valuestring));
    memcpy(config->server_description,find->valuestring,len);

    find=cJSON_GetObjectItem(cjson,"DBpath");
    config->DBpath=malloc(len=strlen(find->valuestring));
    memcpy(config->DBpath,find->valuestring,len);

    find=cJSON_GetObjectItem(cjson,"port");
    config->port=find->valueint;

    find=cJSON_GetObjectItem(cjson,"max-conn");
    config->max_conn=find->valueint;

    find=cJSON_GetObjectItem(cjson,"max-reg");
    config->max_reg=find->valueint;

    _func_END:
    if(re==-1)
        print_help_info(Something Wrong);
    if(f!=NULL)fclose(f);
    if(buf!=NULL)free(buf);
    if(cjson!=NULL)cJSON_Delete(cjson);
    if(find!=NULL)cJSON_Delete(find);
    return re;
}