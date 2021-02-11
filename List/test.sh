#! bin/sh

clang++ -Wall -Werror -Wextra -std=c++98 test_list/my_list.cpp -o my_list
clang++ -Wall -Werror -Wextra -std=c++98 test_list/true_list.cpp -o true_list


./my_list > my_result
./true_list > true_result
diff -u my_result true_result > res
if [ -s res  ]
then
	echo "KO, you can see the result in the res file"
else
	echo "OK pass all tests"
	rm res my_list true_list
fi
rm my_result true_result
