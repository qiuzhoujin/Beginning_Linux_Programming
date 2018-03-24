trap 'echo Exiting: critical variable = $critical_variable' EXIT
echo 'xxx'
critical_variable=yyy
exit 1
