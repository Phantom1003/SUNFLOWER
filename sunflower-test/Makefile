CC:=riscv64-unknown-elf-gcc
PWD:=$(shell pwd)
DEST_DIR:=$(RISCV)/bin/
DEST_TEST_DIR:=$(PWD)/test/

all: \#1\ Demo \#2\ Try_to_access_trust_code \#3\ Try_to_access_trust_data \#4\ Try_to_access_trust_data2

\#1\ Demo: \#1\ Demo.c
	python translate.py "$<"
	$(CC) -march=rv64g "$@_s.c" -o "$(DEST_DIR)$@"
	$(CC) -march=rv64g "$@_s.c" -o "$(DEST_TEST_DIR)$@"
	riscv64-unknown-elf-objdump -d "$(DEST_DIR)$@" > "$(DEST_TEST_DIR)$@_binary"
	mv "$@_s.c" "$(DEST_TEST_DIR)"
	#rm "$@_s.c"
	
\#2\ Try_to_access_trust_code: \#2\ Try_to_access_trust_code.c
	python translate.py "$<"
	$(CC) -march=rv64g "$@_s.c" -o "$(DEST_DIR)$@"
	$(CC) -march=rv64g "$@_s.c" -o "$(DEST_TEST_DIR)$@"
	riscv64-unknown-elf-objdump -d "$(DEST_DIR)$@" > "$(DEST_TEST_DIR)$@_binary"
	mv "$@_s.c" "$(DEST_TEST_DIR)"
	#rm "$@_s.c"	

\#3\ Try_to_access_trust_data: \#3\ Try_to_access_trust_data.c
	python translate.py "$<"
	$(CC) -march=rv64g "$@_s.c" -o "$(DEST_DIR)$@"
	$(CC) -march=rv64g "$@_s.c" -o "$(DEST_TEST_DIR)$@"
	riscv64-unknown-elf-objdump -d "$(DEST_DIR)$@" > "$(DEST_TEST_DIR)$@_binary"
	mv "$@_s.c" "$(DEST_TEST_DIR)"
	#rm "$@_s.c"

\#4\ Try_to_access_trust_data2: \#4\ Try_to_access_trust_data2.c
	python translate.py "$<"
	$(CC) -march=rv64g "$@_s.c" -o "$(DEST_DIR)$@"
	$(CC) -march=rv64g "$@_s.c" -o "$(DEST_TEST_DIR)$@"
	riscv64-unknown-elf-objdump -d "$(DEST_DIR)$@" > "$(DEST_TEST_DIR)$@_binary"
	mv "$@_s.c" "$(DEST_TEST_DIR)"
	#rm "$@_s.c"
	
.PHONY:\#1\ Demo \#2\ Try_to_access_trust_code \#3\ Try_to_access_trust_data \#4\ Try_to_access_trust_data2
