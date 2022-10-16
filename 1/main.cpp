#include <iostream>
#include <cctype>
#include "modBetaCipher.h"
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        modBetaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText)
            cipherText.front() = towlower(cipherText.front());
        decryptedText = cipher.decrypt(cipherText);
        wcout<<L"key="<<key<<endl;
        wcout<<Text<<endl;
        wcout<<cipherText<<endl;
        wcout<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        wcerr<<"Error: "<<e.what()<<endl;
    }
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"ПРОДУКЦИЯ",L"КАЗАХСТАН");
    check(L"КАЗАХСТАН",L"");
    check(L"КАЗАХСТАН",L"КАЗАХСТАН012");
    check(L"К А З А Х С Т А Н",L"ПРОДУКЦИЯ");
    check(L"012",L"ПРОДУКЦИЯ");
}