#!/bin/bash  
#===============================================================================
#
#          FILE: create_tdnote.sh
# 
#         USAGE: ./create_tdnote.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: xiaoxaioyi (), yisman1991@gmail.com
#  ORGANIZATION: 
#       CREATED: 2013-5-16 20:00:41 中国标准时间
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error


sh ./del_tdnote.sh



# usage: today  
# 今天  
# 比如今天是2010年2月27日，那么结果就是2010-02-27  
today()  
{  
    date +%Y-%m-%d  
}  

echo "当前时间（today）：$(today) 创建目录"  
mkdir "$(today)-note"
cd "$(today)-note"
printf $(today) > note.md 
vim note.md


  

