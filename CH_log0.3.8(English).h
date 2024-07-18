/*  -----------------------------------------------
    file info
    file name :: CH_log.h
    version :: 0.3.8
    author :: CHfanzhe
    last update :: China time 2024/7/18 14:16
*///-----------------------------------------------

#ifndef CH_LOG_H // Check if macro :: CH_LOG_H is not defined (defined as false, undefined as true)
// Case :: True
#define CH_LOG_H // Define macro :: CH_LOG_H
    
#include <stdio.h>  // Standard library | Currently used for input and output and file handling
#include <stdlib.h> // Standard library | Used for dynamic memory allocation and string handling
#include <string.h> // Standard library | Used for string handling
#include <time.h>   // Standard library | Used for handling time information

#define version "0.3.8" 
#define author "CHfanzhe"
#define last_update "China time 2024/7/18 14:16"

//data---------------------------------------------------------------------------------
const int next_line_true = 1;
const int next_line_false = 0;

static int next_line = 1; // Define global variable (CH_bool type) next_line as 1 (true), used to save whether a forced line break is needed
static FILE* logfile; // Create file stream pointer for IO operations
static char nxt[3][2] = {"","","\n"}; // Create character table for replacing complex comparison operations

// info---------------------------------------------------------------------------------
int CH_log_info(){
    FILE* infofile = fopen("info.txt", "a"); // Open the info file in write mode, create the file if it does not exist
    if(infofile == NULL){ // Check if the file was opened successfully
        // Case :: True
        fclose(infofile);
        return -1; // Directly return, ending the function here
    }
    time_t now = time(NULL); // Get the current time
    char* CH_ctime = ctime(&now); // Convert the current time to a string
    fprintf(infofile, "\nfile: CH log tool\n"); // Write file information
    fprintf(infofile, "make time: %s", CH_ctime);
    fprintf(infofile, "version: %s\n", version); // Write version information
    fprintf(infofile, "author: %s\n", author); // Write author information
    fprintf(infofile, "last update: %s\n", last_update); // Write last update time information
    fclose(infofile); // Close the file
    return 0;
}

// control-------------------------------------------------------------------------------
void CH_log_close(){ // Simply close the file stream
    fclose(logfile); // Close the file
}

int CH_log_auto_set(){
    logfile = fopen("log.txt", "a"); // Open the log file in write mode, create the file if it does not exist
}

void CH_set_logfile(FILE* fileptr){ // Define function CH_set_log_path prototype is used to set the string path
    logfile = fileptr; // Assign the value of path to log_path, ending the function here
}

void CH_log_next_line_have_to_is(int CHbool){ // Define function CH_next_line_haveto_is prototype is used to force set the value of next_line
    next_line = CHbool; // Assign the value of bool to next_line, ending the function here
}

void CH_change_next_line(){ // Define function CH_change_next_line is used to reverse the value of next_line
    next_line = !next_line; // Reverse the value of next_line, ending the function here
}

void CH_log_partion(){ // Define function CH_log_partion is used to partition the log file
    fprintf(logfile,"\n\n\n"); // Write partition
}

// main----------------------------------------------------------------------------------------------------
void CH_log_ubuild_time(FILE* fileptr){
    time_t now = time(NULL); // Get the current time
    fprintf(fileptr, "%s", ctime(&now)); // Write to the file
}

void CH_log_build_time(){
    time_t now = time(NULL); // Get the current time
    fprintf(logfile, "%s", ctime(&now)); // Write to the file
}

void CH_log_afbuild(char* head,char *msg){
    fprintf(logfile, "[%s]: %s%s", head, msg, nxt[(msg[strlen(msg)-1] != '\n')+next_line]);
    // Custom information and automatic line break
}

void CH_log_afuse(char* head,char *msg, FILE* log_file){
    fprintf(log_file, "[%s]: %s%s", head, msg, nxt[(msg[strlen(msg)-1] != '\n')+next_line]);
    // Custom information and automatic line break
}

void CH_log_fbuild(char* head,char *msg){
    fprintf(logfile, "[%s]: %s\n", head, msg);
    // Custom information
}

void CH_log_fuse(char* head,char *msg, FILE* log_file){
    fprintf(log_file, "[%s]: %s\n", head, msg);
    // Custom information
}

// Functions abandoned due to low efficiency
/*
void CH_log_build(char* msg){ // Build will use the global variable log file stream pointer for IO operations
    time_t now = time(NULL); // Get the current time
    char* CH_ctime = ctime(&now); // Convert the current time to a string
    CH_ctime[strlen(CH_ctime)-1] = '\0'; // Remove the newline character at the end of the string, ensuring the end is a string terminator
    fprintf(logfile, "[%s]: %s%s", CH_ctime, msg, nxt[(msg[strlen(msg)-1] != '\n')+next_line]); // Comment below
    // Use fprintf function to write formatted strings to the specified file (logfile)
    // The format of the formatted string is "[time]: message content newline character"
    fprintf(
        logfile,   Pointer to the file, indicating the output target file
        "[%s]: %s%s",  Formatted string, containing three parts: time, message content, newline character
        CH_ctime,  String representing the current time, usually generated by the ctime function
        msg,  Message content, the main information to be recorded
        nxt[(msg[strlen(msg)-1] != 'n')+next_line] Determine whether to add a newline character based on whether the end of the message content is 'n'
        );
}

void CH_log_use(char *msg, FILE* log_file){ // use will use the log file stream pointer provided by the user for IO operations
    time_t now = time(NULL); // Get the current time
    char* CH_ctime = ctime(&now); // Convert the current time to a string
    CH_ctime[strlen(CH_ctime)-1] = '\0'; // Remove the newline character at the end of the string, ensuring the end is a string terminator
    fprintf(logfile, "[%s]: %s%s", CH_ctime, msg, nxt[(msg[strlen(msg)-1] != '\n')+next_line]); // Comment below
    // Use fprintf function to write formatted strings to the specified file (logfile)
    // The format of the formatted string is "[time]: message content newline character"
    fprintf(
        logfile,   Pointer to the file, indicating the output target file
        "[%s]: %s%s",  Formatted string, containing three parts: time, message content, newline character
        CH_ctime,  String representing the current time, usually generated by the ctime function
        msg,  Message content, the main information to be recorded
        nxt[(msg[strlen(msg)-1] != 'n')+next_line] Determine whether to add a newline character based on whether the end of the message content is 'n'
        );
}
*/

#endif // Case is false, jump to this point to end