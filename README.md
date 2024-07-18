# -log-CH-log-
0.3.8
屎山代码？
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
