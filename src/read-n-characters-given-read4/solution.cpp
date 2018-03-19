// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
  public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
      char last[4];
      if (!n) return n;
      int count = 0;
      int i = 0;
      for (i = 0; i < n - 4; i += 4) {
        count += read4(buf + i);
      }
      int rc = read4(last);
      for (int c = 0; i < n && c < rc; i++, c++) {
        buf[i] = last[c];
        count++;
      }
      return count;
    }
};
