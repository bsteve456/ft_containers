#! bin/sh

clang++ -Wall -Werror -Wextra -std=c++98 test_stack/my_stack.cpp -o my_stack
clang++ -Wall -Werror -Wextra -std=c++98 test_stack/true_stack.cpp -o true_stack


./my_stack > my_result
./true_stack > true_result
diff -u my_result true_result > res
if [ -s res  ]
then
	echo "KO, you can see the result in the res file"
else
	echo "OK pass all tests"
	rm res true_stack my_result true_result
fi
