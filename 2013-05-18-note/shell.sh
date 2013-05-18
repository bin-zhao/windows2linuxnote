#!/bin/bash  
#===============================================================================
#
#          FILE: shell.sh
# 
#         USAGE: ./shell.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: xiaoxiaoyi (), yisman1991@gmail.com
#  ORGANIZATION: 
#       CREATED: 05/18/2013 01:35:03 PM CST
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error
myvar=abc
echo $myvar
echo "$myvar"
echo "$myvar$myvar"
echo "$myvar $myvar"
