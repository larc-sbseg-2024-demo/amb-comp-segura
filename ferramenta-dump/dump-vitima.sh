#!/bin/bash

curl http://localhost:5000/autenticar/asilva/sfsdfsdffsdf

#APP_PID=$(pidof fastapi)
APP_PID=$(ps aux | grep vitima | grep -v grep | awk '{print($2)}')
echo "PID de App: $APP_PID"

gcore -a -o dump.bin $APP_PID
