class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t newResult = 0;

        uint32_t l = pow(2, 31);
        uint32_t r = 1;

        uint32_t lPtr = 31;
        uint32_t rPtr = 0;

        uint32_t shiftAmt = 31;

        while (rPtr < lPtr)
        {
            uint32_t leftBit  = n & l;
            cout << "l is " << std::bitset<32>(l) << "\n";
            uint32_t rightBit = n & r;
            cout << "r is " << std::bitset<32>(r) << "\n";

            newResult |= (leftBit >> shiftAmt);
            newResult |= (rightBit << shiftAmt);

            l = l >> 1;
            r = r << 1;

            shiftAmt = shiftAmt - 2;
            lPtr--;
            rPtr++;
            cout << "New result after iteration " << rPtr << " " << std::bitset<32>(newResult) << "\n";
        }

        return newResult;
    }
};
