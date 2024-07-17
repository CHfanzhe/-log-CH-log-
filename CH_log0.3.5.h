/*  -----------------------------------------------
    file info
    file name :: CH_log.h
    version :: 0.3.5
    author :: CHfanzhe
    last update :: China time 2024/7/17 16:58
*///-----------------------------------------------

#ifndef CH_LOG_H // 检查是否没有定义宏 :: CH_LOG_H (已定义为假， 未定义为真)
// 情况 :: 真
#define CH_LOG_H // 定义宏 :: CH_LOG_H
    
#include <stdio.h>  // 标准库 | 目前用于输入和输出 和文件处理
#include <stdlib.h> // 标准库 | 用于动态内存分配处理字符串
#include <string.h> // 标准库 | 用于字符串处理
#include <time.h>   // 标准库 | 用于处理时间信息

#define version "0.3.5" 
#define author "CHfanzhe"
#define last_update "China time 2024/7/17 16:58"

short int next_line = 1; // 定义全局变量(CH_bool类型) next_line 为 1(真)， 用于保存是否需要强制换行
FILE* logfile; //创建文件流指针用于IO操作

// info---------------------------------------------------------------------------------
int CH_log_info(){
    FILE* infofile = fopen("info.txt", "a"); // 写入方式打开info文件， 若没有文件则创建文件
    if(infofile == NULL){ // 查看是否打开文件失败
        // 情况 :: 真
        fclose(infofile);
        return -1; // 直接返回 函数在此结束
    }
    time_t now = time(NULL); // 获取当前时间
    char* CH_ctime = ctime(&now); // 将当前时间转换为字符串
    fprintf(infofile, "\nfile: CH log tool\n");// 写入文件信息
    fprintf(infofile, "make time: %s", CH_ctime);
    fprintf(infofile, "version: %s\n", version); // 写入版本信息
    fprintf(infofile, "author: %s\n", author); // 写入作者信息
    fprintf(infofile, "last update: %s\n", last_update); // 写入最后更新时间信息
    fclose(infofile); // 关闭文件
    return 0;
}

// control-------------------------------------------------------------------------------
int CH_log_auto_set(){
    logfile = fopen("log.txt", "a"); // 写入方式打开log文件， 若没有文件则创建文件
}

void CH_set_logfile(FILE* fileptr){ // 定义函数 CH_set_log_path 原型是用于设置字符串路径
    logfile = fileptr; // 将path的值赋给log_path 函数在此结束
}

void CH_next_line_haveto_is(int CHbool){  // 定义函数 CH_next_line_haveto_is 原型是用于强制设置设置next_line的值
    next_line = CHbool; // 将bool的值赋给next_line 函数在此结束
}

void CH_change_next_line(){// 定义函数 CH_change_next_line 是用于取反改变next_line的值
    next_line = !next_line; // 取反next_line的值， 函数在此结束
}

int CH_log_partion(){ // 定义函数 CH_log_partion 是用于分割日志文件
    fprintf(logfile,"\n\n\n"); // 写入分割
    return 0;
}

// main----------------------------------------------------------------------------------------------------
void CH_log_build(char* msg){// Build会使用全局变量的log文件流指针进行IO操作
    time_t now = time(NULL); // 获取当前时间
    char* CH_ctime = ctime(&now); // 将当前时间转换为字符串
    CH_ctime[strlen(CH_ctime)-1] = '\0'; // 去掉字符串末尾的换行符, 并确保末尾是字符串结束符
    fprintf(logfile, "[%s]: %s%s", CH_ctime, msg, ((msg[strlen(msg)-1] != '\n'&&next_line == 1)? "\n" : ""));// 注释在下方
    // 利用三元运算符判断是否需要强制换行，并写入文件 | 函数再此结束
}

int CH_log_use(char *msg, FILE* log_file){// use会使用用户提供的的log文件流指针进行IO操作
    time_t now = time(NULL); // 获取当前时间
    char* CH_ctime = ctime(&now); // 将当前时间转换为字符串
    CH_ctime[strlen(CH_ctime)-1] = '\0'; // 去掉字符串末尾的换行符, 并确保末尾是字符串结束符
    fprintf(logfile, "[%s]: %s%s", CH_ctime, msg, ((msg[strlen(msg)-1] != '\n'&&next_line == 1)? "\n" : ""));// 注释在下方
    // 利用三元运算符判断是否需要强制换行，并写入文件
    return 0;// 返回0 表示成功 函数在此结束
}

#endif // 情况为假跳转到此