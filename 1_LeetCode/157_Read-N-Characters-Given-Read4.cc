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
        int copied_chars = 0;
        int read_chars = 4;
        
        char buf4[4];
        
        while (copied_chars < n && read_chars == 4){
            
            read_chars = read4(buf4);
            
            for (int i = 0; i < read_chars; i++){
                if (copied_chars == n) return n;
                
                buf[copied_chars] = buf4[i];
                copied_chars++;
            }
        }
        
        return copied_chars;
    }
};
