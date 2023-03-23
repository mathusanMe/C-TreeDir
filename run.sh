#/bin/bash

compile() {
    echo "Compiling..."

    # Check if 'Makefile' exists
    if [ ! -f "Makefile" ]; then
        echo "Error: Makefile not found."
        exit 1
    fi

    # Remove all the object files
    make clean

    # Compile the main program
    make all 1>logs 2> logs_error.err

    echo "Done compiling."
    exit 0
}

run() {
    echo "Running..."

    # Check if 'main' exists
    if [ ! -f "main" ]; then
        echo "Error: main not found."
        exit 1
    fi

    # Check if 'input.txt' exists
    # And run the main program
    if [ -f "input.txt" ]; then
        ./main input.txt
    else 
        ./main
    fi

    echo "Done running."
    exit 0
}

runTests() {
    echo "Running tests..."

    # Check if 'main' exists
    if [ ! -f "main" ]; then
        echo "Error: main not found."
        exit 1
    fi

    # Check if 'tests' directory exists
    if [ ! -d "tests" ]; then
        echo "Error: tests directory not found."
        exit 1
    fi

    tests=$(ls tests/ | grep -E "^input-([a-z]|[A-Z])-[0-9][0-9]+.txt")
    totalTests=$(echo $tests | wc -l)

    for test in $tests; do
        echo "\n/======= $test ======/"
        ./main tests/$test
        echo "/===== END $test ====/\n"
    done

    echo "Done running tests."
}

case "$1" in
    "compile")
        compile
    ;;
    "run")
        run
    ;;
    "runTests" | "test" | "tests")
        runTests
    ;;
    *)
        compile && run
    ;;
esac
