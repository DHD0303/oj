#include<stdio.h>
#include<string.h>
#include <algorithm>
#include<stdbool.h>

using namespace std;

char s[10020];//�����ַ��� 
int a[26];//�洢ÿ����ĸ�����ֵ�λ�� 

struct arr{
	char ch[30];
}m[10010]; //sort�����޷��Զ�ά����������������˺þã������ýṹ�� �� ���������洢���������Ӵ� 

void cpy(int n, char str[], char str1[]) {
    int i;
    for(i=0; i<n; i++) {
        str[i] = str1[i];
    }
    str[i] = '\0';
    return;
}//��str1λ�ø���n���ַ���str�� 

void init(void) {
	for(int i=0; i<26; i++) {
		a[i] = -1;
	}

	return;
}//��a������г�ʼ�� 

bool cmp(struct arr a, struct arr b) {
    int h = strcmp(a.ch, b.ch);
    if( h < 0 ) {
        return true;
    } else {
        return false;
    }
}//Ϊsort�����ṩ������� 

int main(void) {
    int coun, i, len, maxn, h;//counΪ����ɨ����ִ����ȣ� maxnΪ��ɨ������ִ�����󳤶ȣ� hΪ���������ִ�������   
    while( scanf("%s", s) != EOF ) {
        len = strlen(s);
        init();
        h = maxn = coun = 0;
        for(i=0; i<len; i++) { // ɨ��һ��; 
            if( a[s[i]-'a'] < (i-coun) ) {//iΪ��ǰλ�ã� i-coun Ϊ����ɨ���Ӵ��Ŀ�ʼλ�� 
                a[s[i]-'a'] = i; //���ǰһ�θ��ַ��������Ӵ���ʼλ��֮ǰ�� ��û���ظ��� ����a���飻 
                coun++;//����ɨ���Ӵ����ȼ�һ 
            } else {
                if(coun > maxn) {
                	maxn = coun;
                    h = 0;
                    cpy(coun, m[h++].ch, (s+i-coun));
                } else if(coun == maxn) {
                    cpy(coun, m[h++].ch, (s+i-coun));
                }
                coun = i - a[s[i] -'a'];//coun����Ϊ�ظ��ַ���һ������ǰ�ַ��ľ��� 
                a[s[i]-'a'] = i;//����a���� 
            }
        }
        if(coun > maxn) {
        	maxn = coun;
            h = 0;
            cpy(coun, m[h++].ch, (s+i-coun));
        } else if(coun == maxn) {
            cpy(coun, m[h++].ch, (s+i-coun));
        }//�ظ�����  ��ֹ������coun>maxnȴͨ��48�е��ж϶��޷�����else 
        sort(m, m+h, cmp);
        printf("%d\n", maxn);
        printf("%s\n", m[0].ch);
        for(i=1; i<h; i++) {
            if( strcmp(m[i].ch, m[i-1].ch) ) {
                printf("%s\n", m[i].ch);
            }
        }
    }

    return 0;
}
