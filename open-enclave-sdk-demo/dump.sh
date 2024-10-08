#!/bin/bash

APP_PID=$(pidof autenticador_host)
echo "PID de App: $APP_PID"

gcore -a -o dump.bin $APP_PID
