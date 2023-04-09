#!/bin/bash
set +x

NAME_COLOR="blue"
SUCCESS_COLOR="cyan"
FAILURE_COLOR="red"

function testName() {
    ./colors.sh $NAME_COLOR $@
}

function testPass() {
    ./colors.sh $SUCCESS_COLOR "    - $@"
}

function testFail() {
    ./colors.sh $FAILURE_COLOR "    - $@"
}

# Print all arguments except the first one
case $1 in
    name) testName ${@:2}; exit  ;;
    passed) testPass ${@:2}; exit  ;;
    failed) testFail ${@:2}; exit  ;;
esac