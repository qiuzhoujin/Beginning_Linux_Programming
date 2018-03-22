unset foo
#echo ${foo:-bar}
echo ${foo:=bar}
echo $foo

foo=fud
echo ${foo:-bar}

foo=/usr/bin/X11/startx
echo ${foo#*/}
echo ${foo##*/}

bar=/usr/local/etc/local/networks
echo ${bar%local*}
echo ${bar%%local*}

echo $foo
echo $bar

exit 0
