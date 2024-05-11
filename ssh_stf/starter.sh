#!/bin/bash
# This starter script will ensure that sshd_daemon is present for running 
# and checks  for preconfigs

# stop function is not being added yet...

if [ -f "./sshd_daemon" ];then
    echo "Daemon Starting..."
else
    echo "Daemon is not present!!!"
    exit 1
fi

DAEMON="$PWD/sshd_daemon"
CONFIGFILE="./sshd_config"

function start(){
    "$DAEMON" -f "$CONFIGFILE"
}

while [[ $# -gt 0 ]];do
    case $1 in 
        -s|--start)
            start 
            break;;
        *)
            break;;
    esac
done
