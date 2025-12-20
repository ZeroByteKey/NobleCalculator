#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    
    DWORD written, read;
    char n1_buf[8], n2_buf[8], op_buf[8];
    char result_str[32];
    
    // Welcome Message
    char welcome[] = "--- Noble Terminal Calculator --- \n";
    WriteFile(hStdOut, welcome, sizeof(welcome) - 1, &written, NULL);

    // Get First Number
    char prompt1[] = "Enter first digit: ";
    WriteFile(hStdOut, prompt1, sizeof(prompt1) - 1, &written, NULL);
    ReadFile(hStdIn, n1_buf, 8, &read, NULL);
    int num1 = n1_buf[0] - '0'; // ASCII to Int

    // Get Operator
    char promptOp[] = "Enter operator (+, -, *): ";
    WriteFile(hStdOut, promptOp, sizeof(promptOp) - 1, &written, NULL);
    ReadFile(hStdIn, op_buf, 8, &read, NULL);
    char op = op_buf[0];

    // Get Second Number
    char prompt2[] = "Enter second digit: ";
    WriteFile(hStdOut, prompt2, sizeof(prompt2) - 1, &written, NULL);
    ReadFile(hStdIn, n2_buf, 8, &read, NULL);
    int num2 = n2_buf[0] - '0';

    int res = 0;
    if (op == '+') res = num1 + num2;
    else if (op == '-') res = num1 - num2;
    else if (op == '*') res = num1 * num2;
    else {
        char err[] = "Invalid operator!\n";
        WriteFile(hStdOut, err, sizeof(err) - 1, &written, NULL);
        return 1;
    }

    // Print Result
    int len = sprintf(result_str, "Result: %d\n", res);
    WriteFile(hStdOut, result_str, len, &written, NULL);

    return 0;
}