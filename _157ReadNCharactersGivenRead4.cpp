//
// Created by Fangzhou Zhang on 2020/3/24.
//
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char buff[4];
        int res = 0, remain = n;
        while (1) {
            int num_read = read4(buff);

            if (num_read == 0 || remain == 0) break;
            int iter = min(num_read, remain);
            for (int i = 0; i < iter; i++) {
                *buf = buff[i];
                buf++;
                res++;
                remain--;
            }
        }

        return res;
    }

    int read4(char arr[]) {
        return 0;
    }
};
