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

# Test 8: Command with special characters
echo "Test 8: Special characters in command"
echo "echo 'Special chars: !@#$%^&*()'" | ./hsh

# Test 9: Command with multiple arguments
echo "Test 9: Command with multiple arguments"
echo "echo 'Arg1 Arg2 Arg3'" | ./hsh

# Test 10: Command with quotes
echo "Test 10: Command with single quotes"
echo "echo 'Single quoted argument'" | ./hsh
echo "Test 10: Command with double quotes"
echo "echo \"Double quoted argument\"" | ./hsh

# Test 11: Command with environment variable
echo "Test 11: Command with environment variable"
export TEST_VAR="TestValue"
echo "echo \$TEST_VAR" | ./hsh

# Test 12: Empty command
echo "Test 12: Empty command"
echo "" | ./hsh

# Test 13: Command with relative path
echo "Test 13: Relative path"
echo "./hsh" | ./hsh

# Test 14: Command with trailing spaces
echo "Test 14: Command with trailing spaces"
echo "ls     " | ./hsh

# Test 15: Command with multiple slashes in path
echo "Test 15: Command with multiple slashes in path"
echo "ls ///tmp" | ./hsh

# Test 16: Long command argument
echo "Test 16: Long command argument"
LONG_ARG=$(head -c 1000 </dev/urandom | base64)
echo "echo $LONG_ARG" | ./hsh

# Test 17: Commands with invalid options
echo "Test 17: Commands with invalid options"
echo "ls --invalid-option" | ./hsh

# Test 18: Test execution of a shell script
echo "Test 18: Test execution of a shell script"
echo -e "#!/bin/bash\n echo Script executed" > test_script.sh
chmod +x test_script.sh
echo "./test_script.sh" | ./hsh

echo "All tests completed."

