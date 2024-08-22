#!/bin/bash

echo "Running Simple Shell Tests for PATH Handling"

# Test 1: Command with full path
echo "Test 1: /bin/ls"
echo "/bin/ls" | ./hsh

# Test 2: Command found in PATH
echo "Test 2: ls"
echo "ls" | ./hsh

# Test 3: Command with arguments
echo "Test 3: ls -l /tmp"
echo "ls -l /tmp" | ./hsh

# Test 4: Echo command
echo "Test 4: echo Hello, World!"
echo "echo Hello, World!" | ./hsh

# Test 5: Nonexistent command
echo "Test 5: nonexistentcommand"
echo "nonexistentcommand" | ./hsh

# Test 6: Command with a PATH that does not include the command
echo "Test 6: Check PATH handling for nonexistent command"
echo "echo $PATH"
echo "echo nonexistentcommand" | ./hsh

# Test 7: Verify no fork for nonexistent command
echo "Test 7: No fork for nonexistent command"
echo "nonexistentcommand" | ./hsh

echo "All tests completed."

