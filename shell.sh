###
 # @Author: Ken Kaneki
 # @Date: 2021-12-16 06:54:13
 # @LastEditTime: 2021-12-16 07:00:08
 # @Description: README
###

#! /bin/bash
#����ִ�г���Ŀ¼
cd bin
#���빤��
gcc -g ../source/*.c -I ../include -lreadline -o Shell
#ִ�п�ִ�г���
./Shell
