#!/bin/bash  
#===============================================================================
#
#          FILE: del_tdnote.sh
# 
#         USAGE: ./del_tdnote.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: xiaoxaioyi (), yisman1991@gmail.com
#  ORGANIZATION: 
#       CREATED: 2013-5-16 20:13:30 中国标准时间
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

# usage: today  
# 今天  
# 比如今天是2010年2月27日，那么结果就是2010-02-27  
today()  
{  
    date +%Y-%m-%d  
}  

rm -rf "$(today)-note"



