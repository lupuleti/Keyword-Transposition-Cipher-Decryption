#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char* delete_duplicates(char maria[]){
    int size = strlen(maria);
    for(int index=0;index<size-1; index++){
        for(int jindex=index+1; jindex < size;jindex++){
            if(maria[index] == maria[jindex]){
                for(int kindex=jindex; kindex<size; kindex++)
                    maria[kindex]=maria[kindex+1];
                size--;
            }
        }
    }
    return maria;
}

char* sort_word(char a[])
{
    char t;
    for(int i=0;a[i]!='\0';i++)
        {
            for(int j=i+1;a[j]!='\0';j++)
            {
                if(a[i]>a[j])
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
}

int getIndex (char chr, char keyword[])
{
    int size = strlen(keyword);

    for (int i = 0; i <= size - 1; i++)
        if (keyword[i] == chr)
            return i;

    return 0;
}
bool isItInKey (char c, char keyword[])
{
    for (int i = 0; i <= strlen(keyword); i++)
        if (keyword[i] == c)
            return 1;
    return 0;
}

char decryptedChar (char mapp[][26], char chr)
{
  for (int i = 0; i < 26; i++)
    if (mapp[1][i] == chr)
        return mapp[0][i];
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    char encryption[255][255];
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin.get();
        char keyword[256];
        cin.get(keyword, 256);

        cin.get();
        char cipherText[256];
        cin.get(cipherText, 256);

        delete_duplicates(keyword);

        char sortedKeyword[256];
        strcpy(sortedKeyword,keyword);

        sort_word(sortedKeyword);

        int keywordSize = strlen(sortedKeyword);
        int linesNo;
        if ( 26/keywordSize % 2 == 0)
            linesNo = 26/keywordSize;
        else
            linesNo = 26/keywordSize + 1;

        for (int col = 0; col < keywordSize; col++)
            encryption[0][col] = keyword[col];
        char chr = 65;

        for (int index = 1; index < linesNo; index++)
        {
            for (int jindex = 0; jindex < keywordSize; jindex++)
            {
                if (!isItInKey(chr, keyword))
                    encryption[index][jindex] = chr;

                else
                    jindex--;

                chr++;

                if (chr == 91)
                    break;

            }

            if (chr == 91)
                break;
        }

    char mappedEncryption[2][26];

    chr = 65;

    for (int k = 0; k <= 25; k++)
    {
        mappedEncryption[0][k] = chr;
        chr++;
    }
    int counter1 = 0;
    int counter2 = 0;
    for (int k = 0; k < strlen(keyword); k++)
    {
      int col = getIndex(sortedKeyword[k], keyword);

      for (int line = 0; line < linesNo; line++)
        if (encryption[line][col])
        {
            mappedEncryption[1][line+counter2] = encryption[line][col];
            counter1++;
        }
      counter2 = counter1;
    }


    for (int index = 0; index < strlen(cipherText); index++)
    {
        if (cipherText[index] == 32)
        {
            cout << " ";
        }
        else
        {
            cout << decryptedChar(mappedEncryption, cipherText[index]);
        }
    }

    cout << endl;
    }
    return 0;
}

