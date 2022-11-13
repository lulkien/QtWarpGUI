#!/usr/bin/bash

echo $0

if [ ! -e "/usr/bin/lrelease" ]; then
    echo "Cannot find lrelease. Exit"
    exit
fi

lrelease ../res/translations/ts/*.ts
mv ../res/translations/ts/*.qm ../res/translations/qm
