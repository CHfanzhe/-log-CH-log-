/*  -----------------------------------------------
    file info
    file name :: CH_log.h
    version :: 0.3.6
    author :: CHfanzhe
    last update :: China time 2024/7/17 23:49
*///-----------------------------------------------

#ifndef CH_LOG_H // 检查是否没有定义宏 :: CH_LOG_H (已定义为假， 未定义为真)
// 情况 :: 真
#define CH_LOG_H // 定义宏 :: CH_LOG_H
    
#include <stdio.h>  // 标准库 | 目前用于输入和输出 和文件处理
#include <stdlib.h> // 标准库 | 用于动态内存分配处理字符串
#include <string.h> // 标准库 | 用于字符串处理
#include <time.h>   // 标准库 | 用于处理时间信息

#define version "0.3.6" 
#define author "CHfanzhe"
#define last_update "China time 2024/7/17 23:49"

short int next_line = 1; // 定义全局变量(CH_bool类型) next_line 为 1(真)， 用于保存是否需要强制换行
FILE* logfile; //创建文件流指针用于IO操作
char nxt[3][2] = {"","","\n"};// 创建字符表 用于替换复杂的比较操作

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
void CH_log_close(){// 仅仅是关闭文件流
    fclose(logfile); // 关闭文件
}

int CH_log_auto_set(){
    logfile = fopen("log.txt", "a"); // 写入方式打开log文件， 若没有文件则创建文件
}

void CH_set_logfile(FILE* fileptr){ // 定义函数 CH_set_log_path 原型是用于设置字符串路径
    logfile = fileptr; // 将path的值赋给log_path 函数在此结束
}

void CH_log_next_line_haveto_is(int CHbool){  // 定义函数 CH_next_line_haveto_is 原型是用于强制设置设置next_line的值
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
    fprintf(logfile, "[%s]: %s%s", CH_ctime, msg, nxt[(msg[strlen(msg)-1] != '\n')+next_line]);// 注释在下方
    // 使用fprintf函数将格式化的字符串写入指定的文件（logfile）
    // 格式化字符串的格式为 "[时间]: 消息内容换行符"
    /*
    fprintf(
        logfile,   指向文件的指针，表示输出目标文件
        "[%s]: %s%s",  格式化字符串，包含三个部分：时间、消息内容、换行符
        CH_ctime,  表示当前时间的字符串，通常由ctime函数生成
        msg,  消息内容，即要记录的主要信息
        nxt[(msg[strlen(msg)-1] != 'n')+next_line] 根据消息内容末尾是否为'n'决定是否添加换行符
        );
    */
}

void CH_log_use(char *msg, FILE* log_file){// use会使用用户提供的的log文件流指针进行IO操作
    time_t now = time(NULL); // 获取当前时间
    char* CH_ctime = ctime(&now); // 将当前时间转换为字符串
    CH_ctime[strlen(CH_ctime)-1] = '\0'; // 去掉字符串末尾的换行符, 并确保末尾是字符串结束符
    fprintf(logfile, "[%s]: %s%s", CH_ctime, msg, nxt[(msg[strlen(msg)-1] != '\n')+next_line]);// 注释在下方
    // 使用fprintf函数将格式化的字符串写入指定的文件（logfile）
    // 格式化字符串的格式为 "[时间]: 消息内容换行符"
    /*
    fprintf(
        logfile,   指向文件的指针，表示输出目标文件
        "[%s]: %s%s",  格式化字符串，包含三个部分：时间、消息内容、换行符
        CH_ctime,  表示当前时间的字符串，通常由ctime函数生成
        msg,  消息内容，即要记录的主要信息
        nxt[(msg[strlen(msg)-1] != 'n')+next_line] 根据消息内容末尾是否为'n'决定是否添加换行符
        );
    */
}

#endif // 情况为假 跳转到此处结束