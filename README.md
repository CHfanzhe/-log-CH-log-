# -log-CH-log-
Machine translation into English

0.3.8
Absolute shit mountain code ( Stinky and long )
I just did some minor optimizations and created it independently.
Function introduction:
  CH_log_close() :: Close the log file
  CH_log_info() :: Creates a file "info.txt" output information
  CH_log_auto_set() :: The default setting of the output path of the log file is "log.txt"
  CH_log_next_line_have_to_is() :: Sets the status of the word wrap to be forced
  CH_change_next_line() :: Like some light switches, press once to switch the state, used to toggle the switch for line wrapping
  CH_log_partion() :: The most wasteful function just writes two blank lines to the log
  Main functions:
  CH_log_build_time() :: Gets and writes to the file time
  CH_log_ubuild_time() :: Same as above, except that the file pointer is provided by the user
  CH_log_afbuild() :: Write custom information and wrap lines
  CH_log_afuse() :: A user-provided file pointer writes custom information and wraps lines
  CH_log_afbuild() :: Write custom information
  CH_log_afuse() :: Write custom information to the user-provided file pointer
To be continued

0.3.8
绝对的屎山代码
我只是做了一些微量的优化, 独立创作。
函数介绍：
  CH_log_close() :: 关闭日志文件
  CH_log_info() :: 创建文件 “info.txt” 输出信息
  CH_log_auto_set() :: 默认设置log文件的输出路径为"log.txt"
  CH_log_next_line_have_to_is() :: 强制设置自动换行的状态
  CH_change_next_line() :: 像一些电灯开关， 按一次就切换一次状态， 用于切换自动换行的开关
  CH_log_partion() :: 最废物的函数 只是向日志写入了两个空行
  主要函数：
  CH_log_build_time() :: 获取并向文件中写入时间
  CH_log_ubuild_time() :: 同上， 只是文件指针是用户提供的
  CH_log_afbuild() :: 写入自定义信息并自动换行
  CH_log_afuse() :: 向用户提供的文件指针写入自定义信息并自动换行
  CH_log_afbuild() :: 写入自定义信息
  CH_log_afuse() :: 向用户提供的文件指针写入自定义信息
未完待续
