password_check: password_check.c
	gcc password_check.c -o password_check

password_check_ct: password_check_ct.c
	gcc password_check_ct.c -o password_check_ct

run: password_check password_check_ct
	echo "Non constant-time:" && \
	time ./password_check 0123456789 && time ./password_check 1123456789 && \
	echo "Constant-time:" && \
	time ./password_check_ct 0123456789 && time ./password_check_ct 1123456789

clean:
	rm password_check password_check_ct