#!/bin/sh
#===============================================================================
#
#          FILE: upload_win2linux.sh
# 
#         USAGE: ./upload_win2linux.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: YOUR NAME (易罗阳), 
#  ORGANIZATION: 
#       CREATED: 2013-5-15 18:14:59 
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

echo "#####################before upload git status#####################b"
git status

echo "#####################git add *#####################b"
git add *

echo "#####################git commit#####################b"
git commit -m "auto upload"

echo "#####################after upload git status#####################b"

git status

git push -u origin master

#touch README.md
#git init
#git add README.md
#git commit -m "first commit"
#git remote add origin git@github.com:xiaoxiaoyi/windows2linuxnote.git
#git push -u origin master
#
