export PATH=$PATH:/home/phantom0308/2/timberv/64/bin
riscv64-unknown-elf-gcc -march=rv64g "#1 Demo.c"  -o ./test/"#1 Demo"
riscv64-unknown-elf-gcc -march=rv64g -O0 "#2 Try_to_access_trust_code.c"  -o ./test/"#2 Try_to_access_trust_code"
riscv64-unknown-elf-gcc -march=rv64g "#3 Try_to_access_trust_data.c"  -o ./test/"#3 Try_to_access_trust_data"

echo "Test Demo"
spike pk ./test/"#1 Demo"

echo "========================================"
echo "Test Tag code"
spike pk ./test/"#2 Try_to_access_trust_code"

echo "========================================"
echo "Test Tag data"
spike pk ./test/"#3 Try_to_access_trust_data"
 
