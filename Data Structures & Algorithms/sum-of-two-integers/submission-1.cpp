class Solution {
public:
    int getSum(int a, int b) {
        int32_t a_ = a;
        int32_t b_ = b;

        int mask = 1;
        int carry = 0;
        int res = 0;
        for (size_t i = 0; i < 32; i += 1) {
            cout << "it " << i << endl;
            int a_res = a_ & mask;
            int b_res = b_ & mask;

            /* Current bit to 1 and carry */
            if (a_res && b_res && carry) {
                res = res | mask;
                cout << "all three high; bit set to 1\n";
                carry = 1;
            }
            /* Set current bit to 0 and carry */
            else if (a_res && b_res || ((a_res || b_res) && carry)) {
                carry = 1;
            } 
            /* Set current bit to 1 and no carry */
            else if (a_res || b_res || carry) {
                cout << "one high; bit set to 1\n";
                res = res | mask;
                carry = 0;
            } 
            /* Set current bit to 0 */
            else {
                carry = 0;
            }
            mask = (mask << 1);
        }
        return res;
    }
};
