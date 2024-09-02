#!/bin/bash

# Check if the path to the C file is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 path/to/cfile.c"
    exit 1
fi

CFILE="$1"
BINARY_NAME="program.out"
BINARIES_DIR="./binarias"

# Create the binarias directory if it does not exist
if [ ! -d "$BINARIES_DIR" ]; then
    mkdir -p "$BINARIES_DIR"
fi
g++ "$CFILE" -o "$BINARIES_DIR/$BINARY_NAME"

if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

# Execute the compiled binary and show the output
"$BINARIES_DIR/$BINARY_NAME"
# rm "$BINARIES_DIR/$BINARY_NAME"
