all :
	cc test.c ../get_next_line.c ../get_next_line_utils.c -o mandatory
	valgrind ./mandatory

bonus:
	cc test_bonus.c ../get_next_line_bonus.c ../get_next_line_utils_bonus.c -o bonus
	valgrind ./bonus

phony:
	bonus

clean:
	rm -rf ./bonus ./mandatory