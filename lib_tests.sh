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
    none) testName $2; exit  ;;
    true) testPass $2; exit  ;;
    false) testFail $2; exit  ;;
esac