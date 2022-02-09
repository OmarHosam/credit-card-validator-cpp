#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <regex>

using namespace std;

string ccnumber;

// Returns true if given card number is valid
bool checkLuhn(const string& cardNo)
{
    int nDigits = cardNo.length();

    int nSum = 0, isSecond = false;
    for (int i = nDigits - 1; i >= 0; i--) {

        int d = cardNo[i] - '0';

        if (isSecond == true)
            d = d * 2;

        // We add two digits to handle
        // cases that make two digits after
        // doubling
        nSum += d / 10;
        nSum += d % 10;

        isSecond = !isSecond;
    }
    return (nSum % 10 == 0);
}

string checkProvider(const string& cardnum) {
    if (regex_match(cardnum, regex("^4[0-9]{12}(?:[0-9]{3})?$"))) {
        // then its visa
        return "Visa";
    } else if (regex_match(cardnum, regex("^(5[1-5]|222[1-9]|22[3-9]|2[3-6]|27[01]|2720)[0-9]{0,}$"))) {
        // then its master card
        return "Master card";
    } else if (regex_match(cardnum, regex("^3[47][0-9]{13}$"))) {
        // then its american express
        return "American express";
    } else if (regex_match(cardnum, regex("^3(?:0[0-5]|[68][0-9])[0-9]{11}$"))) {
        // then its diners
        return "Diners Club International";
    } else if (regex_match(cardnum, regex("^6(?:011|5[0-9]{2})[0-9]{12}$"))) {
        // then its Discover
        return "Discover";
    } else if (regex_match(cardnum, regex("^(?:2131|1800|35\\d{3})\\d{11}$"))) {
        // then its JCB
        return "JCB";
    } else {
        return "Unknown";
    }
}

int main() {
    cout << "Enter a credit card number: ";
    getline(cin, ccnumber);
    cout << checkProvider(ccnumber) << endl;
    if(checkLuhn(ccnumber)) {
        cout << "Valid credit card" << endl;
    } else {
        cout << "Invalid credit card" << endl;
    }
    main();
}
