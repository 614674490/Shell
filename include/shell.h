/*
 * @Author: Ken Kaneki
 * @Date: 2021-12-13 09:06:58
 * @LastEditTime: 2021-12-15 14:55:20
 * @Description: README
 */
#ifndef SHELL_H_INCLUDED
#define SHELL_H_INCLUDED

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>

#define CLOSE "\001\033[0m\002"                        // �ر���������
#define BLOD "\001\033[1m\002"                         // ǿ�����Ӵ֡�����
#define BEGINSHELL(x, y) "\001\033[" #x ";" #y "m\002" // x: ������y: ǰ��

#define MAX_CMD 10      // �����������
#define BUFFSIZE 255    // ������������ַ���
#define MAX_CMD_LEN 100 // ÿ���������󳤶�

typedef struct
{
    char *cmdline;       // ���ܼ�������Ĳ�������
    char *argv[MAX_CMD]; // ����ָ������
    char argc;           // �����е���Ч��������
} Shell;

char *setPrompt();
int add_argv(char *str, Shell *shell); //��������ӵ���������
int do_list_cmd(char *argv[]);
int do_pipe_cmd(char argc, char *argv[]);
int do_simple_cmd(char argc, char *argv[], int prepipe[2], int postpipe[2]);
void reset_args(Shell *shell);

int callCd(char argc, char *argv[]);      // ִ��cdָ��
int ShowHistory(char argc, char *argv[]); //ִ��historyָ��

// �ض���ָ��
int commandWithOutputRedi(char argc, char *argv[], int division); // ִ������ض���
int commandWithInputRedi(char argc, char *argv[], int division);  // ִ�������ض�������
int commandWithReOutputRedi(char argc, char *argv[], int division);
int commandWithPipe(char buf[BUFFSIZE]);                        // ִ�йܵ�����
int commandInBackground(char argc, char *argv[], int division); //ִ�к�̨����ָ��

#endif
