#!/bin/bash

EXEC="program"
OUTPUT="&1"
VERBOSE=false
COMPILE_ALL=false

COMPILED=false
VALGRIND=false

compile() {
    if [ "$COMPILED" = true ]; then
        return
    fi

    echo "=================="
    echo -e "Compiling...\n"

    # Check if the Makefile exists
    if [ ! -f "Makefile" ]; then
        echo "Error: Makefile not found."
        exit 1
    fi

    if [ "$COMPILE_ALL" = true ]; then
        make clean
    fi
    make all

    echo -e "\nDone compiling."
    echo "===================="

    COMPILED=true
}

runTests() {

    echo -e "\n=================="
    echo "Running tests..."

    # Check if 'program' exists
    if [ ! -f "$EXEC" ]; then
        echo "Error: $EXEC not found."
        exit 1
    fi

    if [ "$VERBOSE" = true ]; then
        ./program -t -v -o "$OUTPUT"
    else
        ./program -t -o "$OUTPUT"
    fi

    echo "Done running tests."
    echo -e "===================="
}

run() {

    echo -e "\n=================="
    echo  "Running..."

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
        ./program -v -o "$OUTPUT" "$1"
    else
        ./program -o "$OUTPUT" "$1"
    fi

    echo "Done running."
    echo "=================="
}

runWithValgrind() {

    if [ "$VERBOSE" = true ]; then
        valgrind --leak-check=full --show-leak-kinds=all --verbose --error-exitcode=1  ./program -v "$1" -o "$OUTPUT";
    else
        valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1  ./program "$1" -o "$OUTPUT";
    fi
    
    VALGRIND=false
}

while getopts ':avo:' OPTION; do
    case "$OPTION" in
        v)
            VERBOSE=true
        ;;
        a)
            COMPILE_ALL=true
        ;;
        o)
            OUTPUT="$OPTARG"

            if [ -e "$OUTPUT" ]; then
                rm "$OUTPUT"
            fi
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