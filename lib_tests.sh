#!/bin/bash
set +x

NAME_COLOR="blue"
SUCCESS_COLOR="cyan"
FAILURE_COLOR="red"

function testName() {
    message=" |___ $*"
    ./colors.sh "$NAME_COLOR" "$message"
}

function testPass() {
    message="    |____ $*"
    ./colors.sh "$SUCCESS_COLOR" "$message"
}

function testFail() {
    message="    |____ $*"
    ./colors.sh "$FAILURE_COLOR" "$message"
}

# Print all arguments except the first one
case $1 in
    name) testName "${*:2}"; exit ;;
    passed) testPass "${*:2}"; exit ;;
    failed) testFail "${*:2}"; exit ;;
esac
