/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int index4= 0;
    char buff4[4];
    int n4 = 0;
    int read(char *buf, int n) {
        int i = 0;
        while(i<n){
            if(index4<n4){
                buf[i++]=buff4[index4++];
            }else {
                n4 = read4(buff4);
                index4=0;
            }
            if(n4==0) break;
        }
        return i;
    }
    
};