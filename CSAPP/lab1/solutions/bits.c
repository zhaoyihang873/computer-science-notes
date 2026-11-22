/*
 * CS:APP 3e Data Lab self-study reference implementations.
 * These functions follow the operator rules and machine model in ../bits.c.
 */

int bitXor(int x, int y)
{
    return ~(x & y) & ~(~x & ~y);
}

int tmin(void)
{
    return 1 << 31;
}

int isTmax(int x)
{
    int successor = x + 1;

    return !(successor ^ ~x) & !!successor;
}

int allOddBits(int x)
{
    int byte_mask = 0xAA;
    int half_mask = byte_mask | (byte_mask << 8);
    int odd_mask = half_mask | (half_mask << 16);

    return !((x & odd_mask) ^ odd_mask);
}

int negate(int x)
{
    return ~x + 1;
}

int isAsciiDigit(int x)
{
    int high_matches = !((x >> 4) ^ 3);
    int digit = x & 0xF;
    int low_fits = !((digit + 6) >> 4);

    return high_matches & low_fits;
}

int conditional(int x, int y, int z)
{
    int truth = !!x;
    int choose_y = ~truth + 1;

    return (choose_y & y) | (~choose_y & z);
}

int isLessOrEqual(int x, int y)
{
    int x_negative = (x >> 31) & 1;
    int y_negative = (y >> 31) & 1;
    int signs_differ = x_negative ^ y_negative;
    int value_mask = ~(1 << 31);
    int difference = (y & value_mask) + ~(x & value_mask) + 1;

    return (signs_differ & x_negative) | (!signs_differ & !(difference >> 31));
}

int logicalNeg(int x)
{
    int negated = ~x + 1;

    return ((x | negated) >> 31) + 1;
}

int howManyBits(int x)
{
    int bits = x ^ (x >> 31);
    int upper16;
    int upper8;
    int upper4;
    int upper2;
    int upper1;

    upper16 = !!(bits >> 16) << 4;
    bits = bits >> upper16;
    upper8 = !!(bits >> 8) << 3;
    bits = bits >> upper8;
    upper4 = !!(bits >> 4) << 2;
    bits = bits >> upper4;
    upper2 = !!(bits >> 2) << 1;
    bits = bits >> upper2;
    upper1 = !!(bits >> 1);
    bits = bits >> upper1;

    return upper16 + upper8 + upper4 + upper2 + upper1 + bits + 1;
}

unsigned floatScale2(unsigned uf)
{
    unsigned sign = uf & 0x80000000u;
    unsigned exponent = (uf >> 23) & 0xFFu;
    unsigned fraction = uf & 0x7FFFFFu;

    if (exponent == 0xFFu)
        return uf;
    if (exponent == 0)
        return sign | (fraction << 1);
    if (exponent == 0xFEu)
        return sign | 0x7F800000u;
    return uf + (1u << 23);
}

int floatFloat2Int(unsigned uf)
{
    int exponent = (uf >> 23) & 0xFFu;
    int power = exponent - 127;
    unsigned significand = (uf & 0x7FFFFFu) | 0x800000u;
    int magnitude;

    if (power < 0)
        return 0;
    if (power > 30)
        return 0x80000000u;

    if (power >= 23)
        magnitude = significand << (power - 23);
    else
        magnitude = significand >> (23 - power);

    if (uf >> 31)
        return -magnitude;
    return magnitude;
}

unsigned floatPower2(int x)
{
    if (x > 127)
        return 0x7F800000u;
    if (x >= -126)
        return (x + 127) << 23;
    if (x < -149)
        return 0;
    return 1u << (x + 149);
}
