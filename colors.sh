#!/bin/bash
set +x

function black() {
    echo -e "\x1B[30m $@ \x1B[0m"
}

function red() {
    echo -e "\x1B[31m $@ \x1B[0m"
}

function green() {
    echo -e "\x1B[32m $@ \x1B[0m"
}

function yellow() {
    echo -e "\x1B[33m $@ \x1B[0m"
}

function blue() {
    echo -e "\x1B[34m $@ \x1B[0m"
}

function cyan() {
    echo -e "\x1B[36m $@ \x1B[0m"
}

case $1 in
    black) "$@"; exit  ;;
    red) "$@"; exit  ;;
    green) "$@"; exit  ;;
    yellow) "$@"; exit  ;;
    blue) "$@"; exit  ;;
    cyan) "$@"; exit ;;
esac