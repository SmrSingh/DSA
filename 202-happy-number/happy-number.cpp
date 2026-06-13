class Solution {
public:
int squareOfDigits(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}
    bool isHappy(int n) {
      int slow=n;
      int fast=n;
     do {
        slow=squareOfDigits(slow);
        fast=squareOfDigits(fast);
        fast=squareOfDigits(fast);
        
        

      }while(fast!=slow);
      return slow==1;  
    }
};