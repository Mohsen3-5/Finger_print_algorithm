#include <iostream>
#include <string.h>
#include <string>


using namespace std;

int Hashing(string str, int ilk, int son) {
    int sum = 0, taban = 1;
    for (int i = ilk; i < son; i++) {
        sum += int(str[i]) * taban;
        taban = taban * 10;
    }
    return sum % 157;
}
void fingerprint(string str,string str_lookingfor) {
    int sayac = 0, flag = 0;
    int hash_value = Hashing(str_lookingfor, 0, str_lookingfor.length());
    for (int k = str_lookingfor.length(); k < str.length(); k++) {
        int de_karmasi = Hashing(str, sayac, k);
        cout<< str.substr(sayac, k - sayac)<<"  Hash value " << de_karmasi <<endl;
        if (hash_value==de_karmasi){
            cout <<"--------------------------\n" << str_lookingfor << 
                " word found!" <<" Hash value is " << hash_value << endl;
            flag++;
        }
        sayac++;
    }
        if (flag == 0)
            cout << str_lookingfor << " no words found"<<endl;
 
}
int main()
{
    fingerprint("Huzursuz yasam mutlulugun tacı ask sensin", "ask");
}

