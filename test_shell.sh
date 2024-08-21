#!/bin/bash

echo "Running Simple Shell Tests"

# Test 1: Basic Command
echo "Test 1: ls"
echo "ls" | ./shell

# Test 2: Command with Arguments
echo "Test 2: ls -l"
echo "ls -l" | ./shell

# Test 3: Command with Multiple Arguments
echo "Test 3: ls -l /home"
echo "ls -l /home" | ./shell

# Test 4: Echo Command
echo "Test 4: echo Hello"
echo "echo Hello, World!" | ./shell

# Test 5: Invalid Command
echo "Test 5: invalidcommand"
echo "invalidcommand" | ./shell

echo "All tests completed."

