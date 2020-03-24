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
    int buff_ptr = 0;
    int buff_size = 0;
    int read(char *buf, int n) {
        int res = 0;
        int remain = n;
        while (remain > 0) {
            if (buff_size > 0) {
                while (buff_ptr < buff_size && remain > 0) {
                    *buf++ = buff[buff_ptr++];
                    res++;
                    remain--;
                }
                if (buff_ptr == buff_size) {
                    buff_ptr = 0;
                    buff_size = 0;
                }
            } else {
                int num_read = read4(buff);
                if (num_read == 0) break;
                buff_size = num_read;
                while (buff_ptr < buff_size && remain > 0) {
                    *buf++ = buff[buff_ptr++];
                    res++;
                    remain--;
                }
                if (buff_ptr == buff_size) {
                    buff_ptr = 0;
                    buff_size = 0;
                }
            }
        }
        return res;
    }
};
