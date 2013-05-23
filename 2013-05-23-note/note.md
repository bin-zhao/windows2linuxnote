##时间:
    2013-05-2
##Q:cygwin 剪贴板
##A:
    on Windows, Cygwin comes with getclip and putclip which do the same job.

    Cygwin comes with special device file called /dev/clipboard:
    echo foobar > /dev/clipboard  # Puts "foobar\n" on the clipboard
    cat /dev/clipboard  # Pastes clipboard to stdout

    to cat text to the Windows clipboard
    putclip < foo.txt
    To pipe to a file whatever text is in the Windows clipboard
    getclip > foo.txt
##Q:cygwin 软件包
##A:
    ftp://ftp.ntu.edu.tw/cygwin/release/
##Q:cygwin apt-cyg
##A:
	Intro
	
	apt-cygisacommand-lineinstallerforCygwinwhichcooperateswithCygwinSetupandusesthesamerepository.Thesyntaxissimilartoapt-get.Usageexamples:
	
	"apt-cyginstall<packagenames>"toinstallpackages
	"apt-cygremove<packagenames>"toremovepackages
	"apt-cygupdate"toupdatesetup.ini
	"apt-cygshow"toshowinstalledpackages
	"apt-cygfind<pattern(s)>"tofindpackagesmatchingpatterns
	"apt-cygdescribe<pattern(s)>"todescribepackagesmatchingpatterns
	"apt-cygpackageof<commandsorfiles>"tolocateparentpackages
	
	Quickstart
	
	Firstinstallsubversionandwgetthroughthestandardcygwinsetupprogram.Thenrunthefollowingcommands:
	
	#svn--forceexporthttp://apt-cyg.googlecode.com/svn/trunk//bin/
	#chmod+x/bin/apt-cyg
	
	useapt-cyg,forexample:
	
	#apt-cyginstallnano
###安装apt-cyg
	wget http://apt-cyg.googlecode.com/svn/trunk/apt-cyg
	chmod +x apt-cyg
	mv apt-cyg /usr/local/bin/
	
###安装包
	apt-cyg install bc

###查找包
	apt-cyg find php

###设置下载站点和缓存目录
	apt-cyg -c /cygdrive/d/downloads/cygwin -m http://mirrors.163.com/cygwin/ find php
	apt-cyg -m ftp://ftp.cygwinports.org/pub/cygwinports find php

##Link
    [apt-cyg](http://zengrong.net/post/1792.htm)

##Q:cygwin octopress
##A:
   http://madeye.me/2011/12/17/setup-octopress-on-windows/ 

##Q:cygwin alias
##A:
    alias less='/bin/less -r'
    alias ls='/bin/ls -F --color=tty --show-control-chars'
##Link:
    http://cygwin.com/cygwin-ug-net/setup-files.html

##Q:cygwin git http
##A:
    Install the ca-certificates package to install those
##Link:
    http://christopherpeplin.com/2013/01/cygwin-git-https/
    
##Q:cygwin ctags
##A:
    copy to bin
##Link:
    [](http://sourceforge.net/projects/ctags/?source=dlp)
