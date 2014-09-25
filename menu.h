/********************************************************************/
/* Copyright (C) software design@USTC, 2014-2015                    */
/*                                                                  */
/*  FILE NAME             :  menu.h                                 */
/*  PRINCIPAL AUTHOR      :  Zhuxiuxiu                              */
/*  SUBSYSTEM NAME        :  Menu                                   */
/*  MODULE NAME           :  Menu                                   */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2014/09/21                             */
/*  DESCRIPTION           :  This is a menu interface               */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by zhuxiuxiu,2014/09/21
 *
 */
#include "linktable.h"

int Help();
int Quit();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10
/* data struct and its operations */

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char  *cmd;
    char  *desc;
    int   (*handler)();
} tDataNode;

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable * head, char * cmd);
/* show all cmd in listlist */
int ShowAllCmd();

int InitMenuData(tLinkTable ** ppLinktable);

int InsertCmd(tLinkTable * head,char* cmd, char* desc, int (*handler)());
