#include <iostream>
#include <string>
#define MAXNUM 200
using namespace std;
char op1[MAXNUM];
char op2[MAXNUM];
char result[MAXNUM * 4];
char tmpA[10][MAXNUM*2];
char reminder[MAXNUM] = "";
void GetTheOpr() {
    // input A
    string a, b;
    cin >> a;
    cin >> b;
    strcpy(op1, a.c_str());
    strcpy(op2, b.c_str());
}
void ADD(char *op1, char *op2) {
    int c = 0; // carry
    result[strlen(op1)] = '\0';
    int j = strlen(op2) - 1;
    if(strlen(op1) >= strlen(op2)) {
        for(int i = strlen(op1) - 1; i >= 0; i--) {
            int tmp = op1[i] - '0' + c;
            if(j >= 0) {
                tmp += op2[j] - '0';
            }
            if(tmp > 9) {
                result[i] = tmp - 10 + '0';
                c = 1;
            } else {
                result[i] = tmp + '0';
                c = 0;
            }
            j--;
        }
        if(c == 1) {
            for(int i = strlen(op1); i >= 0; i--) {
                result[i+1] = result[i];
            }
            result[0] = '1';
        }
        
    } else {
        ADD(op2, op1);
    }
}
void SUB(char *op1, char *op2) {
    int borrow = 0;
    if(strcmp(op1, op2) == 0) {
        strcpy(result, "0");
    } else if(strlen(op1) > strlen(op2) || strlen(op1) == strlen(op2) && strcmp(op1, op2) > 0) {
        result[strlen(op1)] = '\0';
        int j = strlen(op2) - 1;
        for(int i = strlen(op1) - 1; i >= 0; i--) {
            int tmp = op1[i] - '0' - borrow;
            if(j >= 0) {
                tmp -= op2[j] - '0';
            }
            if(tmp < 0) {
                result[i] = tmp + 10 + '0';
                borrow = 1;
            } else {
                result[i] = tmp + '0';
                borrow = 0;
            }
            j--;
        }
        while(result[0] == '0') {
            for(int i = 0; i < strlen(op1); i++) {
                result[i] = result[i+1];
            }
        }
        // cout << result << endl;
    } else {
        cout << "-";
        SUB(op2, op1);
    }
}
void MUL(char *op1, char *op2) {
    char tmp[MAXNUM * 2];
    // char tmpA[10][MAXNUM*2];
    strcpy(tmpA[0], "0");
    for(int i = 1; i < 10; i++) {
        ADD(tmpA[i-1], op1);
        strcpy(tmpA[i], result);
    }
    strcpy(result, "0");
    for(int j = 0; j < strlen(op2); j++) {
        if(op2[j] != '0') {
            strcpy(tmp, tmpA[op2[j]-'0']);
            for(int i = 0; i < strlen(op2)-j-1;i++) {
                strcat(tmp, "0");
            }
            ADD(result, tmp);
        }
    }
}
bool Equal(char *a, char *b) {
    if(strlen(a) > strlen(b) || strlen(a) == strlen(b) && strcmp(a, b) > 0) {
        return true;
    } else {
        return false;
    }
}
void DIV(char *op1, char *op2) {
    
    char tmp[2] = "0";
    char quotient[MAXNUM] = "";
    int possible = 0;
    strcpy(tmpA[0], "0");
    for(int i = 1; i < 10; i++) {
        ADD(tmpA[i-1], op2);
        strcpy(tmpA[i], result);
    }
    for(int i = 0; i < strlen(op1); i++) {
        tmp[0] = op1[i];
        strcat(reminder, tmp);
        possible = 1;
        while(possible != 10 && !Equal(tmpA[possible],reminder)) {
            possible++;
        }
        tmp[0] = possible -1 + '0';
        if(tmp[0] != '0' || quotient[0] != '\0') {
            strcat(quotient, tmp);
        }
        SUB(reminder, tmpA[possible-1]);
        strcpy(reminder, result);
        if(reminder[0] == '0') {
            reminder[0] = '\0';
        }
    }
    if(quotient[0] == '\0') {
        strcpy(quotient, "0");
    }
    if(reminder[0] == '\0') {
        strcpy(reminder, "0");
    }
    strcpy(result, quotient);
}
int main() {
	GetTheOpr();
	
	ADD(op1, op2);
    cout << result << endl;
	SUB(op1, op2);
	cout << result << endl;
	MUL(op1, op2);
    cout << result << endl;
	DIV(op1, op2);
    cout << result << endl;
    cout << reminder << endl;
    system("pause");
	return 0;
}