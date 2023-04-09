#!/bin/bash

function testName() {
    ./colors.sh blue $1
}

function testPass() {
    ./colors.sh cyan "    - $1"
}

function testFail() {
    ./colors.sh red "    - $1"
}

case $1 in
    name) testName $2; exit  ;;
    passed) testPass $2; exit  ;;
    failed) testFail $2; exit  ;;
esac