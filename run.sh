#!/bin/bash

EXEC="program"
OUTPUT="stdout"
VERBOSE=false
COMPILE_ALL=false

COMPILED=false
VALGRIND=false

compile() {
    if [ "$COMPILED" = true ]; then
        return
    fi

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

    COMPILED=true
}

runTests() {

    echo -e "\n==================" > $OUTPUT
    echo -e "Running tests...\n" > $OUTPUT

    # Check if 'program' exists
    if [ ! -f "$EXEC" ]; then
        echo "Error: $EXEC not found."
        exit 1
    fi

    if [ "$VERBOSE" = true ]; then
        ./program -t -v -o $OUTPUT
    else
        ./program -t -o $OUTPUT
    fi

    echo -e "\n====================" > $OUTPUT
}

run() {

    echo -e "\n==================" > $OUTPUT
    echo -e "Running...\n" > $OUTPUT

    # Check if 'EXEC' exists
    if [ ! -f "$EXEC" ]; then
        echo "Error: $EXEC not found."
        exit 1
    fi

    if [ "$VALGRIND" = true ]; then
        runWithValgrind $1
        return
    fi

    # Run the main program
    if [ "$VERBOSE" = true ]; then
        ./program -v -o $OUTPUT "$1"
    else
        ./program -o $OUTPUT "$1"
    fi

    echo "==================" > $OUTPUT
}

runWithValgrind() {

    if [ "$VERBOSE" = true ]; then
        valgrind --leak-check=full --show-leak-kinds=all --verbose --error-exitcode=1  ./program -v "$1" -o $OUTPUT;
    else
        valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1  ./program "$1" -o $OUTPUT;
    fi
    
    VALGRIND=false
}

while getopts ':avio' OPTION; do
    case "$OPTION" in
        v)
            VERBOSE=true
        ;;
        a)
            COMPILE_ALL=true
        ;;
        o)
            OUTPUT=$OPTARG
        ;;
        ?)
            echo "Usage: run.sh [-vao] [compile | valgrind | test(s) | r(un)] [files...]"
            exit 1
        ;;
    esac
done

shift $((OPTIND - 1))

compile

for arg in "$@"; do
    case "$arg" in
        "test" | "tests")
            runTests
        ;;
        "valgrind" | "v" | "-v" | "--v")
            VALGRIND=true
        ;;
        *)
            run $arg
            exit 1
    esac
done

exit 0