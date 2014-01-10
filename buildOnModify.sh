#!/bin/sh
datestampFormat="%Y%m%d%H%M%S"
lastrun=$(date +$datestampFormat)
inotifywait --exclude '.*\.swp|.*\.o|.*~' \
            --event MODIFY \
            --timefmt $datestampFormat \
            --format %T \
            -q -m -r . |
while read modified; do
    if [ $modified -gt $lastrun ]; then
        lastrun=$(date +$datestampFormat)
        make
    fi
done
