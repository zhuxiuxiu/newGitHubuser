/********************************************************************/
/* Copyright software design@USTC, 2014-2015                        */
/*                                                                  */
/*  FILE NAME             :  test.c                                 */
/*  PRINCIPAL AUTHOR      :  Zhuxiuxiu                              */
/*  SUBSYSTEM NAME        :  Test                                   */
/*  MODULE NAME           :  Test                                   */
/*  LANGUAGE              :  C                                      */
/*  TARGET ENVIRONMENT    :  ANY                                    */
/*  DATE OF FIRST RELEASE :  2014/09/21                             */
/*  DESCRIPTION           :  This is a test program                 */
/********************************************************************/

/*
 * Revision log:
 *
 * Created by Zhuxiuxiu,2014/09/21
 * Proovide a test program by Zhuxiuxiu,2014/09/21
 */

#include<stdio.h>
#include<stdlib.h>
#include "menu.h"

main()
{    
    tLinkTable * head = NULL;
    InitMenuData(&head);
    printf("增加命令之前：\n");
    ShowAllCmd(head);
    FindCmd( head, "help");
    InsertCmd(head,"debug", "this is debug", NULL);
    printf("增加命令之后：\n");
    ShowAllCmd(head);
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
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
