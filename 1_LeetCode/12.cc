

/*
12. Integer to Roman
https://leetcode.com/problems/integer-to-roman/

*/

// 2021/02/22
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        
        int q = num / 1000;
        for (int i = 0; i < q; i++) ans += 'M';
        num -= 1000*q;
        
        q = num / 900;
        for (int i = 0; i < q; i++) ans += "CM";
        num -= 900*q;
        
        q = num / 500;
        for (int i = 0; i < q; i++) ans += 'D';
        num -= 500 * q;
        
        q = num / 400;
        for (int i = 0; i < q; i++) ans += "CD";
        num -= 400*q;
        
        q = num / 100;
        for (int i = 0; i < q; i++) ans += "C";
        num -= 100*q;
        
        q = num / 90;
        for (int i = 0; i < q; i++) ans += "XC";
        num -= 90*q;
        
        
        q = num / 50;
        for (int i = 0; i < q; i++) ans += "L";
        num -= 50*q;
        
        
        q = num / 40;
        for (int i = 0; i < q; i++) ans += "XL";
        num -= 40*q;
        
        q = num / 10;
        for (int i = 0; i < q; i++) ans += "X";
        num -= 10*q;
        
        
        q = num / 9;
        for (int i = 0; i < q; i++) ans += "IX";
        num -= 9*q;
        
        q = num / 5;
        for (int i = 0; i < q; i++) ans += "V";
        num -= 5*q;
        
        
        q = num / 4;
        for (int i = 0; i < q; i++) ans += "IV";
        num -= 4*q;
        
        q = num / 3;
        for (int i = 0; i < q; i++) ans += "III";
        num -= 3*q;
        
        q = num / 2;
        for (int i = 0; i < q; i++) ans += "II";
        num -= 2*q;
        
        
        q = num / 1;
        for (int i = 0; i < q; i++) ans += "I";
        num -= q;
        
        return ans;
        
    }
};
