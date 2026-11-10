class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 1 && nums2.empty()) {
            return nums1[0];
        } else if (nums2.size() == 1 && nums1.empty()) {
            return nums2[0];
        } else if (nums2.size() == 1 && nums1.size() == 1) {
            return (static_cast<double>(nums1[0]) + static_cast<double>(nums2[0])) / 2.0;
        }
        int lenOne = nums1.size();
        int lenTwo = nums2.size();
        int i = 0, j = 0;

        double valueOne = 0;
        double valueTwo = 0;

        bool b = false;

        for (int count = 0; count < ((lenOne + lenTwo) / 2) + 1; count++) {
            if (i < lenOne && j < lenTwo) {
                // Take the smaller value
                if (nums1[i] <= nums2[j]) {
                    cout << "num1 is smaller\n";
                    if (!b) {
                        cout << "Update v1\n";
                        valueOne = nums1[i];
                    } else {
                        cout << "Update v2\n";
                        valueTwo = nums1[i];
                    }
                    b = !b;
                    // if ((i + j + 1) % 2 == 0) {
                    //     cout << "v1 = " << nums1[i] << "\n";
                    //     valueOne = nums1[i];
                    // } else {
                    //     cout << "v2 = " << nums1[i] << "\n";
                    //     valueTwo = nums1[i];
                    // }
                    i++;
                } else {
                    cout << "num2 is smaller\n";
                    if (!b) {
                        cout << "Update v1\n";
                        valueOne = nums2[j];
                    } else {
                        cout << "Update v2\n";
                        valueTwo = nums2[j];
                    }
                    b = !b;

                    // if ((i + j + 1) % 2 == 0) {
                    //     cout << "v1 = " << nums2[j] << "\n";
                    //     valueOne = nums2[j];
                    // } else {
                    //     cout << "v2 = " << nums2[j] << "\n";
                    //     valueTwo = nums2[j];
                    // }
                    j++;
                }
            } else if (i < lenOne) {
                cout << "num2 has no more elements\n";
                // Take value from lenOne
                if (!b) {
                    cout << "Update v1\n";
                    valueOne = nums1[i];
                } else {
                    cout << "Update v2\n";
                    valueTwo = nums1[i];
                }
                b = !b;
                // if ((i + j + 1) % 2 == 0) {
                //     cout << "v1 = " << nums1[i] << "\n";
                //     valueOne = nums1[i];
                // } else {
                //     cout << "v2 = " << nums1[i] << "\n";
                //     valueTwo = nums1[i];
                // }
                i++;
            } else if (j < lenTwo) {
                cout << "num1 has no more elements\n";
                // Take value from lenTwo
                if (!b) {
                    cout << "Update v1\n";
                    valueOne = nums2[j];
                } else {
                    cout << "Update v1\n";
                    valueTwo = nums2[j];
                }
                b = !b;
                // if ((i + j + 1) % 2 == 0) {
                //     cout << "v1 = " << nums2[j] << "\n";
                //     valueOne = nums2[j];
                // } else {
                //     cout << "v2 = " << nums2[j] << "\n";
                //     valueTwo = nums2[j];
                // }
                j++;
            }
        }

        cout << "v1 = " << valueOne << endl;
        cout << "v2 = " << valueTwo << endl;
        if ((lenOne + lenTwo) % 2 == 0) {
            return (static_cast<double>(valueOne) + static_cast<double>(valueTwo)) / static_cast<double>(2.0);
        } else {
            // ODD length
            if (!b) {
                return valueTwo;
            } else {
                return valueOne;
            }
        }
    }
};
