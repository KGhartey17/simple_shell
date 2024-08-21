#!/bin/bash

echo "Testing /bin/ls"
echo "/bin/ls" | ./shell

echo "Testing /bin/pwd"
echo "/bin/pwd" | ./shell

echo "Testing invalid command"
echo "/bin/invalidcommand" | ./shell

echo "Testing empty input"
echo "" | ./shell

echo "Testing Ctrl+D (EOF)"
echo "" | ./shell  # Should exit

