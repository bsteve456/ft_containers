#! bin/sh

clang++ -Wall -Werror -Wextra -std=c++98 test_queue/my_queue.cpp -o my_queue
clang++ -Wall -Werror -Wextra -std=c++98 test_queue/true_queue.cpp -o true_queue


./my_queue > my_result
./true_queue > true_result
diff -u my_result true_result > res
if [ -s res  ]
then
	echo "KO, you can see the result in the res file"
else
	echo "OK pass all tests"
	rm res my_queue true_queue my_result true_result
fi
