
// Method  1: Bit manipulation:
static int count1bits(int a) {
    int count = 0;
    while (a > 0) {
        if (a & 1)
            count++;
        a >>= 1;
    }
    return count;
}
// Method 2: Brian Kerninghan algorithm:
// rightmost set bit is unset -> more efficient in time
static int count1bits(int a) {
    int count = 0;
    while (a > 0) {
        a = (a & (a - 1));
        count++;
    }
    return count;
}
