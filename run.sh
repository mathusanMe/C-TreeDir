#!/bin/bash

EXEC="program"
OUTPUT="&1"
VERBOSE=false
COMPILE_ALL=false
TO_TEST=false

NEW_OUTPUT=false
COMPILED=false
USE_VALGRIND=false

EXIT_STATUS=0

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
    echo -e "Running tests...\n"

    # Check if 'program' exists
    if [ ! -f "$EXEC" ]; then
        echo "Error: $EXEC not found."
        exit 1
    fi

    if [ "$USE_VALGRIND" = true ]; then
        runTestsWithValgrind
    else 
        runTestsWoValgrind
    fi

    echo -e "\nDone running tests."
    echo -e "===================="
}

run() {

    echo -e "\n=================="
    echo -e "Running...\n"

    # Check if 'EXEC' exists
    if [ ! -f "$EXEC" ]; then
        echo "Error: $EXEC not found."
        return
    fi

    if [ "$USE_VALGRIND" = true ]; then
        runWithValgrind $1
    else

        # Run the main program
        if [ "$VERBOSE" = true ]; then
            ./program -v -o "$OUTPUT" "$1" && EXIT_STATUS=0 || EXIT_STATUS=1
        else
            ./program -o "$OUTPUT" "$1" && EXIT_STATUS=0 || EXIT_STATUS=1
        fi
    fi

    echo -e "\nDone running."
    echo "=================="
}

runWithValgrind() {

    if [ "$VERBOSE" = true ]; then
        if [ "$NEW_OUTPUT" = true ]; then
            valgrind --leak-check=full --xml=yes --xml-file=VALGRIND_LOGS.xml --show-leak-kinds=all --verbose --error-exitcode=1  ./program -v -o "$OUTPUT" "$1" && EXIT_STATUS=0 || EXIT_STATUS=1
        else
            valgrind --leak-check=full --xml=yes --xml-file=VALGRIND_LOGS.xml --show-leak-kinds=all --verbose --error-exitcode=1  ./program -v "$1" && EXIT_STATUS=0 || EXIT_STATUS=1
        fi
    else
        if [ "$NEW_OUTPUT" = true ]; then
            valgrind --leak-check=full --xml=yes --xml-file=VALGRIND_LOGS.xml --show-leak-kinds=all --verbose --error-exitcode=1  ./program -o "$OUTPUT" "$1" && EXIT_STATUS=0 || EXIT_STATUS=1
        else
            valgrind --leak-check=full --xml=yes --xml-file=VALGRIND_LOGS.xml --show-leak-kinds=all --error-exitcode=1  ./program "$1" && EXIT_STATUS=0 || EXIT_STATUS=1
        fi
    fi
    
    return 0
}

runTestsWithValgrind() {
    if [ "$VERBOSE" = true ]; then
        if [ "$NEW_OUTPUT" = true ]; then
            valgrind --leak-check=full --xml=yes --xml-file=VALGRIND_LOGS.xml --show-leak-kinds=all --verbose --error-exitcode=1  ./program -t -v -o "$OUTPUT" && EXIT_STATUS=0 || EXIT_STATUS=1
        else
            valgrind --leak-check=full --xml=yes --xml-file=VALGRIND_LOGS.xml --show-leak-kinds=all --verbose --error-exitcode=1  ./program -t -v && EXIT_STATUS=0 || EXIT_STATUS=1
        fi
    else
        if [ "$NEW_OUTPUT" = true ]; then
            valgrind --leak-check=full --xml=yes --xml-file=VALGRIND_LOGS.xml --show-leak-kinds=all --verbose --error-exitcode=1  ./program -t -v -o "$OUTPUT" && EXIT_STATUS=0 || EXIT_STATUS=1
        else
            valgrind --leak-check=full --xml=yes --xml-file=VALGRIND_LOGS.xml --show-leak-kinds=all --error-exitcode=1  ./program -t && EXIT_STATUS=0 || EXIT_STATUS=1
        fi
    fi

    return 0
}

runTestsWoValgrind() {
    if [ "$VERBOSE" = true ]; then 
        if [ "$NEW_OUTPUT" = true ]; then
            ./program -t -v -o "$OUTPUT" && EXIT_STATUS=0 || EXIT_STATUS=1
        else
            ./program -t -v && EXIT_STATUS=0 || EXIT_STATUS=1
        fi
    else 
        if [ "$NEW_OUTPUT" = true ]; then
            ./program -t -o "$OUTPUT" && EXIT_STATUS=0 || EXIT_STATUS=1
        else
            ./program -t && EXIT_STATUS=0 || EXIT_STATUS=1
        fi
    fi
}

while getopts ':abvto:' OPTION; do
    case "$OPTION" in
        b)
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
            NEW_OUTPUT=true

            if [ -e "$OUTPUT" ]; then
                rm "$OUTPUT"
            fi
        ;;
        v)
            USE_VALGRIND=true
        ;;
        ?)
            echo "Usage: run.sh [-abtov] [files...]"
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

exit $EXIT_STATUS