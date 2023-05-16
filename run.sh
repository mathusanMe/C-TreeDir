#!/bin/bash

EXEC="program"
OUTPUT="/dev/null"
COMPILE_ALL=false

compile() {
    echo "==================" > $OUTPUT
    echo -e "Compiling...\n" > $OUTPUT

    # Check if the Makefile exists
    if [ ! -f "Makefile" ]; then
        echo "Error: Makefile not found."
        exit 1
    fi

    if [ "$COMPILE_ALL" = true ]; then
        make clean > $OUTPUT
    fi
    make all > $OUTPUT

    echo -e "\nDone compiling." > $OUTPUT
    echo "====================" > $OUTPUT
}

runTests() {
    compile

    echo -e "\n==================" > $OUTPUT
    echo -e "Running tests...\n" > $OUTPUT

    # Check if 'program' exists
    if [ ! -f "$EXEC" ]; then
        echo "Error: $EXEC not found."
        exit 1
    fi

    ./program test

    echo -e "\n====================" > $OUTPUT
}

run() {
    compile

    echo -e "\n==================" > $OUTPUT
    echo -e "Running...\n" > $OUTPUT

    # Check if 'EXEC' exists
    if [ ! -f "$EXEC" ]; then
        echo "Error: $EXEC not found."
        exit 1
    fi

    # Run the main program
    ./program

    echo "==================" > $OUTPUT
}

while getopts ':av' OPTION; do
    case "$OPTION" in
        v)
            OUTPUT="/dev/stdout"
        ;;
        a)
            COMPILE_ALL=true
        ;;
        ?)
            echo "Usage: run.sh [-v] [compile | test]"
            exit 1
        ;;
    esac
done

shift $((OPTIND - 1))

case "$1" in
    "compile")
        compile
    ;;
    "test" | "tests")
        runTests
    ;;
    *)
        run
    ;;
esac

exit 0