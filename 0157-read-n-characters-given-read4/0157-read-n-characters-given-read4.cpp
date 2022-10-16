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
    int read(char *buf, int n) {
       
        int index = 0;
        while(n>0){
            int newIndex=0;
            char buf4[4];
            int v= read4(buf4);
            while(n>0 && newIndex<v){
                buf[index] = buf4[newIndex];
                index++;
                newIndex++;
                n--;
            }
            if(v<4){
                break;
            }
        }
        return index;
    }
};