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
    char buff[4];
    int read(char *buf, int n) {
        int res = 0;
        int remain = n;
        while (remain > 0) {
            int buff_size = read4(buff);
            if (buff_size == 0) break;
            int buff_ptr = 0;
            while (buff_ptr < buff_size && remain > 0) {
                *buf++ = buff[buff_ptr++];
                remain--;
                res++;
            }
        }
        return res;
    }

    int read4(char arr[]) {
        return 0;
    }
};
