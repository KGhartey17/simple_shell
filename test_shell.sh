#!/bin/bash

# Running Simple Shell Tests

# Test 1: Basic Command
echo "Test 1: /bin/ls"
echo "/bin/ls" | ./hsh

# Test 2: Command without full path
echo "Test 2: ls"
echo "ls" | ./hsh

# Test 3: Command with Arguments
echo "Test 3: ls -l /tmp"
echo "ls -l /tmp" | ./hsh

# Test 4: Echo Command
echo "Test 4: echo Hello, World!"
echo "echo Hello, World!" | ./hsh

# Test 5: Invalid Command
echo "Test 5: nonexistentcommand"
echo "nonexistentcommand" | ./hsh

# Completion Message
echo "All tests completed."

