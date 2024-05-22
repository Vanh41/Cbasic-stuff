#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include <math.h>
#include <stdbool.h>

int max(int x,int y){
    if (x>y) return x;
    return y;
}


int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
        int ans = 0;
        int char_count[256] = {0};
        for (int l = 0, r = 0; r < n; r++) {
            char_count[s[r]]++;
            while (char_count[s[r]] > 1) {
                char_count[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
}


int main(){
  char s[1000];
  scanf("%s",s);
  printf("%d",lengthOfLongestSubstring(s));
}