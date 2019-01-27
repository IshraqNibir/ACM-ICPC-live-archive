#include <bits/stdc++.h>
#define ll long long
using namespace std;

int hexadecimalToDecimal(string hexVal)
{
    int len = hexVal.length();
    int base = 1;
    int dec_val = 0;
    for (int i=len-1; i>=0; i--)
    {
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;
            base = base * 16;
        }
        else if (hexVal[i]>='A' && hexVal[i]<='F')
        {
            dec_val += (hexVal[i] - 55)*base;
            base = base*16;
        }
    }
    return dec_val;
}

int octalToDecimal(string octal)
{
    int dec_value = 0;
    int len = octal.length();
    int base = 1;
    for (int i=len-1; i>=0; i--) {
        dec_value += (octal[i] - 48)*base;
        base = base * 8;
    }
    return dec_value;
}

int decimalToDecimal(string decimal)
{
    int dec_value = 0;
    int len = decimal.length();
    int base = 1;
    for (int i=len-1; i>=0; i--) {
        dec_value += (decimal[i] - 48)*base;
        base = base * 10;
    }
    return dec_value;
}

int main()
{
    string s;
    int t;
    while (1) {
        cin >> s >> t;
        if(s.length() == 1 && s[0] == '0' && t == 0)
            break;
        int dec_value;
        if (s[0] == '0' && s[1] == 'x') {
            s[1] = '0';
            dec_value = hexadecimalToDecimal(s);
        }
        else if (s[0]=='0') {
            dec_value = octalToDecimal(s);
        }
        else {
            dec_value = decimalToDecimal(s);
        }
        //cout << dec_value << endl;
        string temp;
        int a, b, nmbr = 0;
        for (int i=1; i<=t; i++) {
            cin >> temp >> a;
            if (temp.length() == 1) {
                if (a == dec_value)
                    nmbr++;
                else
                    dec_value = a;
            }
            else if (temp[0] == '+' && temp[1] == '+') {
                if (a == dec_value+1) {
                    dec_value++;
                    nmbr++;
                }
                else
                    dec_value = a;
            }
            else if (temp[1] == '+' && temp[2] == '+') {
                if (a == dec_value) {
                    dec_value++;
                    nmbr++;
                }
                else
                    dec_value = a + 1;
            }
            else if (temp[0] == '-' && temp[1] == '-') {
                if (a == dec_value-1) {
                    dec_value--;
                    nmbr++;
                }
                else
                    dec_value = a;
            }
            else if (temp[1] == '-' && temp[2] == '-') {
                if (a == dec_value) {
                    dec_value--;
                    nmbr++;
                }
                else
                    dec_value = a - 1;
            }
        }
        cout << nmbr <<endl;
    }
    return 0;
}

