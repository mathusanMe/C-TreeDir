#!/bin/bash
set +x

function format_color() {
    echo -e "\x1B[${1}m ${*:2} \x1B[0m"
}

function black() {
    format_color 30 "$@"
}

function red() {
    format_color 31 "$@"
}

function green() {
    format_color 32 "$@"
}

function yellow() {
    format_color 33 "$@"
}

function blue() {
    format_color 34 "$@"
}

function cyan() {
    format_color 36 "$@"
}

# If the first argument is a color, call the epynomous function with all arguments
case $1 in
    black) "$@"; exit  ;;
    red) "$@"; exit  ;;
    green) "$@"; exit  ;;
    yellow) "$@"; exit  ;;
    blue) "$@"; exit  ;;
    cyan) "$@"; exit ;;
esac