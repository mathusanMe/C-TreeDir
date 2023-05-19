#!/bin/bash

EXEC="program"
OUTPUT="&1"
VERBOSE=false
COMPILE_ALL=false
TO_TEST=false

COMPILED=false
USE_VALGRIND=false

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

    runTestsWithValgrind()

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

    if [ "$USE_VALGRIND" = true ]; then
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
        valgrind --leak-check=full --show-leak-kinds=all --verbose --error-exitcode=1  ./program -v -o "$OUTPUT" "$1";
    else
        valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1  ./program -o "$OUTPUT" "$1";
    fi
}

runTestsWithValgrind() {
    if [ "$VERBOSE" = true ]; then
        valgrind --leak-check=full --show-leak-kinds=all --verbose --error-exitcode=1  ./program -t -v -o "$OUTPUT";
    else
        valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1  ./program -t -o "$OUTPUT";
    fi
}

while getopts ':avVto:' OPTION; do
    case "$OPTION" in
        v)
            VERBOSE=true
        ;;
        a)
            COMPILE_ALL=true
        ;;
        t)
            TO_TEST=true
        ;;
        o)
            OUTPUT="$OPTARG"

            if [ -e "$OUTPUT" ]; then
                rm "$OUTPUT"
            fi
        ;;
        V)
            USE_VALGRIND=true
        ;;
        ?)
            echo "Usage: run.sh [-vato] [valgrind] [files...]"
            exit 1
        ;;
    esac
done

shift $((OPTIND - 1))

compile

if [ "$TO_TEST" = true ]; then
    runTests
fi

for arg in "$@"; do
    case "$arg" in
        *)
            run $arg
            exit 1
    esac
done

exit 0