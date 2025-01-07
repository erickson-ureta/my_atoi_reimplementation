#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int my_atoi(const char *num)
{
    if (!num)
    {
        return 0;
    }

    int value = 0;
    int negative_mult = 1;
    bool started_parsing = false;

    const char *c = &num[0];
    while (*c != '\0')
    {
        if (*c == '-' && !started_parsing)
        {
            negative_mult = -1;
            started_parsing = true;
        }
        else if (*c == '+' && !started_parsing)
        {
            started_parsing = true;
        }
        else if (*c >= 48 && *c <= 57)
        {
            value *= 10;
            value += ((int) *c - 48);
            started_parsing = true;
        }
        else if (*c == ' ' && started_parsing)
        {
            break;
        }
        else if (*c != ' ')
        {
            value = 0;
            break;
        }
        c++;
    }

    return value * negative_mult;
}

bool run_my_atoi_test_case(const char *input, int expected_val, bool print_pass)
{
    int res = my_atoi(input);
    if (res == expected_val)
    {
        if (print_pass)
        {
            printf("========\n");
            printf("[PASS] Test case: \"%s\"\n", input);
        }

        return true;
    }
    else
    {
        printf("========\n");
        printf("[FAIL] Test case: \"%s\"\n", input);
        printf("  Expected return value: %d\n", expected_val);
        printf("  Actual return value: %d\n", res);

        return false;
    }
}

int main()
{
    for (int i = -100000000; i <= 100000000; i++)
    {
        char i_str[12];
        sprintf(i_str, "%d", i);
        run_my_atoi_test_case(i_str, i, false);
    }

    run_my_atoi_test_case("1234", 1234, true);
    run_my_atoi_test_case("-1234", -1234, true);
    run_my_atoi_test_case("+1234", 1234, true);
    run_my_atoi_test_case("      +1234", 1234, true);
    run_my_atoi_test_case("      -1234", -1234, true);
    run_my_atoi_test_case("1234   ", 1234, true);
    run_my_atoi_test_case("-1234   ", -1234, true);
    run_my_atoi_test_case("      1234   ", 1234, true);
    run_my_atoi_test_case("      -1234   ", -1234, true);
    run_my_atoi_test_case("abc", 0, true);
    run_my_atoi_test_case("!#!U", 0, true);
    run_my_atoi_test_case(NULL, 0, true);
    run_my_atoi_test_case("123abc", 0, true);
    run_my_atoi_test_case("abc123", 0, true);
    run_my_atoi_test_case("", 0, true);
    run_my_atoi_test_case("2147483647", 2147483647, true);
    run_my_atoi_test_case("+2147483647", 2147483647, true);
    run_my_atoi_test_case("-2147483648", -2147483648, true);
    run_my_atoi_test_case("2147483648", -2147483648, true); // Int overflow
    run_my_atoi_test_case("+2147483648", -2147483648, true); // Int overfllow
    run_my_atoi_test_case("-2147483649", 2147483647, true); // Int underflow
    run_my_atoi_test_case("1234 44124", 1234, true);
    run_my_atoi_test_case("+1234 44124", 1234, true);
    run_my_atoi_test_case("-1234 44124", -1234, true);
    run_my_atoi_test_case("    1234 44124", 1234, true);
    run_my_atoi_test_case("    +1234 44124", 1234, true);
    run_my_atoi_test_case("    -1234 44124", -1234, true);
    run_my_atoi_test_case("    1234abc 44124", 0, true);
    run_my_atoi_test_case("    +1234abc 44124", 0, true);
    run_my_atoi_test_case("    -1234abc 44124", 0, true);

    return 0;
}
