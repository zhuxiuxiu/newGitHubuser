/********************************************************************/
/* Copyright (C) software design@USTC, 2014-2015                    */
/*                                                                  */
/*  FILE NAME             :  menu.c                                 */
/*  PRINCIPAL AUTHOR      :  Zhuxiuxiu                              */
/*  SUBSYSTEM NAME        :  Menu                                   */
/*  MODULE NAME           :  Menu                                   */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2014/09/21                             */
/*  DESCRIPTION           :  This is a menu program                 */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by zhuxiuxiu,2014/09/21
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

tLinkTable *head = NULL;

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(char * cmd)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(!strcmp(pNode->cmd, cmd))
        {
            return  pNode;  
        }
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return NULL;
}

int ExecuteMenu()
{
    /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler();
        }
   
    }
}

/* show all cmd in listlist */
int ShowAllCmd()
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int InitMenuData()
{
    head = CreateLinkTable();
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "Menu List:";
    pNode->handler = Help;
    AddLinkTableNode(head,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "version";
    pNode->desc = "Menu Program V1.0";
    pNode->handler = NULL; 
    AddLinkTableNode(head,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "Quit from Menu Program V1.0";
    pNode->handler = Quit; 
    AddLinkTableNode(head,(tLinkTableNode *)pNode);
 
    return 0; 
}
int InsertCmd(char* cmd, char* desc, int (*handler)())
{
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = cmd;
    pNode->desc = desc;
    pNode->handler = handler;
    AddLinkTableNode(head,(tLinkTableNode *)pNode);
}

int Help()
{
    ShowAllCmd(head);
    return 0; 
}

int Quit()
{
    exit(0);
}
