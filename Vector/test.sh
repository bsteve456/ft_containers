#! bin/sh

clang++ -Wall -Werror -Wextra -std=c++98 test_vector/my_vector.cpp -o my_vector
clang++ -Wall -Werror -Wextra -std=c++98 test_vector/true_vector.cpp -o true_vector


./my_vector > my_result
./true_vector > true_result
diff -u my_result true_result > res
if [ -s res  ]
then
	echo "KO, you can see the result in the res file"
else
	echo "OK pass all tests"
	rm res my_list true_list my_result true_result
fi
