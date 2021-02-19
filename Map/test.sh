#! bin/sh

clang++ -Wall -Werror -Wextra -std=c++98 test_map/my_map.cpp -o my_map
clang++ -Wall -Werror -Wextra -std=c++98 test_map/true_map.cpp -o true_map


./my_map > my_result
./true_map > true_result
diff -u my_result true_result > res
if [ -s res  ]
then
	echo "KO, you can see the result in the res file"
else
	echo "OK pass all tests"
	rm res my_map true_map my_result true_result
fi
