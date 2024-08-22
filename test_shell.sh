#!/bin/bash

echo "Running Simple Shell Tests"

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

# Test 6: Check PATH handling for nonexistent command
echo "Test 6: Check PATH handling for nonexistent command"
echo "echo $PATH"
echo "echo nonexistentcommand" | ./hsh

# Test 7: Verify no fork for nonexistent command
echo "Test 7: No fork for nonexistent command"
echo "nonexistentcommand" | ./hsh

# Test 8: Special characters in command
echo "Test 8: Special characters in command"
echo "echo '!@#$%^&*()'" | ./hsh

# Test 9: Command with multiple arguments
echo "Test 9: Command with multiple arguments"
echo "echo Arg1 Arg2 Arg3" | ./hsh

# Test 10: Command with single quotes
echo "Test 10: Command with single quotes"
echo "echo 'Single quoted argument'" | ./hsh

# Test 11: Command with double quotes
echo "Test 11: Command with double quotes"
echo "echo \"Double quoted argument\"" | ./hsh

# Test 12: Command with environment variable
echo "Test 12: Command with environment variable"
export TEST_VAR="TestValue"
echo "echo \$TEST_VAR" | ./hsh

# Test 13: Empty command
echo "Test 13: Empty command"
echo "" | ./hsh

# Test 14: Relative path
echo "Test 14: Relative path"
echo "./some_relative_command" | ./hsh

# Test 15: Command with trailing spaces
echo "Test 15: Command with trailing spaces"
echo "echo 'Trailing spaces     '" | ./hsh

# Test 16: Command with multiple slashes in path
echo "Test 16: Command with multiple slashes in path"
echo "echo /tmp/////somepath/////file" | ./hsh

# Test 17: Long command argument
echo "Test 17: Long command argument"
echo "echo $(head -c 1024 < /dev/urandom)" | ./hsh

# Test 18: Commands with invalid options
echo "Test 18: Commands with invalid options"
echo "ls --invalid-option" | ./hsh

# Test 19: Test execution of a shell script
echo "Test 19: Test execution of a shell script"
echo "echo 'Script executed' > test_script.sh"
echo "chmod +x test_script.sh"
echo "./test_script.sh" | ./hsh

# Test 20: Test exit command
echo "Test 20: Test exit command"
echo "exit" | ./hsh

echo "All tests completed."

