#!/bin/bash

# Define the shell executable
SHELL_EXEC="./hsh"

# Test for Simple Shell 0.1
echo "Running tests for Simple Shell 0.1"

# Test prompt display and command execution
echo "Testing prompt and command execution"
echo "ls" | $SHELL_EXEC > output.txt
echo "cat output.txt" | $SHELL_EXEC
rm output.txt

# Test end of file condition (Ctrl+D)
echo "Testing end of file (Ctrl+D)"
echo "" | $SHELL_EXEC

# Test invalid command
echo "Testing invalid command"
echo "invalid_command" | $SHELL_EXEC

# Test exit command
echo "Testing exit command"
echo "exit" | $SHELL_EXEC

# Test with commands having arguments (Simple Shell 0.2)
echo "Running tests for Simple Shell 0.2"
echo "ls -l" | $SHELL_EXEC
echo "/bin/ls -l" | $SHELL_EXEC

# Test PATH handling (Simple Shell 0.3)
echo "Running tests for Simple Shell 0.3"
echo "ls" | $SHELL_EXEC
echo "which ls" | $SHELL_EXEC

# Test exit built-in (Simple Shell 0.4)
echo "Running tests for Simple Shell 0.4"
echo "exit" | $SHELL_EXEC

# Test env built-in (Simple Shell 1.0)
echo "Running tests for Simple Shell 1.0"
echo "env" | $SHELL_EXEC

# Test custom getline implementation (Simple Shell 0.1.1)
echo "Running tests for Simple Shell 0.1.1"
echo "ls" | $SHELL_EXEC

# Test argument handling for built-in exit (Simple Shell 0.4.1)
echo "Running tests for Simple Shell 0.4.1"
echo "exit 98" | $SHELL_EXEC
echo "echo \$?" | $SHELL_EXEC

# Test setenv and unsetenv (Advanced)
echo "Running tests for setenv and unsetenv"
echo "setenv TEST_VAR test_value" | $SHELL_EXEC
echo "echo \$TEST_VAR" | $SHELL_EXEC
echo "unsetenv TEST_VAR" | $SHELL_EXEC
echo "echo \$TEST_VAR" | $SHELL_EXEC

# Test cd command (Advanced)
echo "Running tests for cd command"
echo "cd /" | $SHELL_EXEC
echo "pwd" | $SHELL_EXEC
echo "cd /tmp" | $SHELL_EXEC
echo "pwd" | $SHELL_EXEC
echo "cd -" | $SHELL_EXEC
echo "pwd" | $SHELL_EXEC

# Test command separator (;) (Advanced)
echo "Running tests for command separator (;)"
echo "ls /var ; ls /tmp" | $SHELL_EXEC

# Test logical operators (&& and ||) (Advanced)
echo "Running tests for logical operators (&& and ||)"
echo "ls /var && ls /tmp" | $SHELL_EXEC
echo "ls /invalid_dir || ls /tmp" | $SHELL_EXEC

# Test alias command (Advanced)
echo "Running tests for alias command"
echo "alias ll='ls -l'" | $SHELL_EXEC
echo "ll" | $SHELL_EXEC

# Test variable replacement ($? and $$) (Advanced)
echo "Running tests for variable replacement"
echo "ls /var" | $SHELL_EXEC
echo "echo \$?" | $SHELL_EXEC
echo "echo \$\$" | $SHELL_EXEC

# Test comments (#) (Advanced)
echo "Running tests for comments (#)"
echo "ls /var # listing /var directory" | $SHELL_EXEC

# Test file input mode (Advanced)
echo "Running tests for file input mode"
echo -e "ls\npwd\nexit" > commands.txt
$SHELL_EXEC commands.txt
rm commands.txt

echo "All tests completed."
