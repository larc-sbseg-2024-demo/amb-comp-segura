#!/bin/bash

APP_PID=$(pidof occlum-run)
echo "PID de App: $APP_PID"

gcore -a -o dump.bin $APP_PID
