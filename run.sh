#/bin/bash

compile() {
    echo "Compiling..."

    # Check if 'main.c' exists
    if [ ! -f "main.c" ]; then
        echo "Error: main.c not found."
        exit 1
    fi

    # Compile the main program
    gcc -Wall -o main.out main.c

    echo "Done compiling."
    exit 0
}

run() {
    echo "Running..."

    # Check if 'main.out' exists
    if [ ! -f "main.out" ]; then
        echo "Error: main.out not found."
        exit 1
    fi

    # Check if 'input.txt' exists
    if [ ! -f "input.txt" ]; then
        echo "Error: input.txt not found."
        exit 1
    fi

    # Run the main program
    ./main.out input.txt

    echo "Done running."
    exit 0
}

runTests() {
    echo "Running tests..."

    # Check if 'main.out' exists
    if [ ! -f "main.out" ]; then
        echo "Error: main.out not found."
        exit 1
    fi

    # Check if 'tests' directory exists
    if [ ! -d "tests" ]; then
        echo "Error: tests directory not found."
        exit 1
    fi

    totalTests=$(ls tests/ | grep -E "^input[0-9]+.txt" | wc -l)

    for test in $(ls tests/ | grep -E "^input[0-9]+.txt"); do
        echo "Running test: $test"
        ./main.out $test
    done

    echo "Done running tests."
}

case "$1" in
    "compile")
        compile
    ;;
    "runTests" | "test")
        compileTests
        runTests
    ;;
    *)
        compile && run
    ;;
esac
