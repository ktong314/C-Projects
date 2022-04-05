#include <iostream>
#include <map>
#include <list>
#include <stack>
#include <vector>
#include "Parse.h"


using namespace std;
vector<string> total;
vector<string> operators;
vector<int> numbers;

map<string, int> map1;

void displayText(void){
    read_next_token();
    cout << next_token();
}

void pushVector(void){
    operators.push_back(next_token());
    do{
        read_next_token();
        if(next_token_type == SYMBOL){
            string x = next_token();
            if (x == "!" || x == "~"){
                read_next_token();
                if(x == "~"){
                    int asd = token_number_value * -1;
                    numbers.push_back(asd);
                    total.push_back("0");
                }
                else if (x == "!"){
                    if (token_number_value == 0) {
                        numbers.push_back(1);
                        total.push_back("0");
                    } else {
                        numbers.push_back(0);
                        total.push_back("0");
                    }
                }
            } else {
                operators.push_back(next_token());
                total.push_back(next_token());
            }
        }
        else if(next_token_type == NUMBER){
            numbers.push_back(token_number_value);
            total.push_back("0");
        }
        else if(next_token_type == NAME){
            numbers.push_back(map1[next_token()]);
            total.push_back("0");
        }
    }while(numbers.size() != operators.size() + 1);
}


int Solve(string symbol, int y, int x){
    int result;
    if (symbol == "+"){
        result = x + y;
    } else if (symbol == "-"){
        result = x - y;
    } else if (symbol == "*"){
        result = x * y;
    } else if(symbol == "/"){
        result = x / y;
    } else if(symbol == "%") {
        result = x % y;
    } else if (symbol == "<"){
        result = x < y;
    } else if (symbol == ">"){
        result = x > y;
    } else if (symbol == "=="){
        result = x == y;
    } else if (symbol == "!="){
        result = x != y;
    } else if (symbol == "&&"){
        result = x && y;
    } else if (symbol == "||"){
        result = x || y;
    }
    return result;
}

int OperateVector(void){
    int result;
    for (auto i = operators.rbegin(); i != operators.rend(); ++i){
        auto x = numbers.rbegin();
        int counter = 0;
        int temp = 0;
        for (auto z = total.rbegin(); z != total.rend(); ++z){
            if(*z != "0"){
                break;
            }
            counter++;
        }
        if(counter > 2){
            temp = *x;
            numbers.insert(numbers.begin(),temp);
            numbers.pop_back();
            x = numbers.rbegin();
        }
        int num1 = *x;
        numbers.pop_back();
        x = numbers.rbegin();
        int num2 = *x;
        numbers.pop_back();
        result = Solve(*i, num1, num2);
        numbers.insert(numbers.begin(),result);
    }
    return result;
}


//make another function called varOperate

void clearVector(void){
    numbers.clear();
    operators.clear();
    total.clear();
}

void displayOutput(void){
    read_next_token();
    if(next_token_type == NUMBER){
        cout << token_number_value;
    }
    else if(next_token_type == SYMBOL){
        string x = next_token();
        if (x == "!") {
            read_next_token();
            if (token_number_value == 0) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        else if(x == "~"){
            read_next_token();
            cout << token_number_value * -1;
        } else {
            pushVector();
            cout << OperateVector();
            clearVector();
        }
    }
    else if(next_token_type == NAME){
        cout << map1[next_token()];
    }
}

void run(void){
    string command = "";
    while(next_token_type != END){
        read_next_token();
        if(next_token_type == KEYWORD){
            command = next_token();
            if (command == "text"){
                displayText();
            }
            else if (command == "output"){
                displayOutput();
            }
            else if (command == "var"){
                read_next_token();
                string variable = next_token();
                map<string, int>::iterator it = map1.find(variable);
                if (it != map1.end()){
                    cout << "variable " << variable << " incorrectly re-initialized" << endl;
                }
                read_next_token();
                if(next_token_type == SYMBOL){
                    pushVector();
                    map1[variable] = OperateVector();
                    clearVector();
                }
                else if (next_token_type == NUMBER){
                    int value = token_number_value;
                    map1[variable] = value;
                }
            }
            else if (command == "set"){
                read_next_token();
                string variable = next_token();
                map<string, int>::iterator it = map1.find(variable);
                if (it == map1.end()){
                    cout << "variable " << variable << " not declared" << endl;
                }
                read_next_token();
                if(next_token_type == SYMBOL){
                    pushVector();
                    map1[variable] = OperateVector();
                    clearVector();
                }
                else if (next_token_type == NUMBER){
                    int value = token_number_value;
                    map1[variable] = value;
                }
            }
        }
    }
    next_token_type = INVALID;
    map1.clear();
}

int main() {
/*

    set_input("test_grader.blip");
    run();
*/

    cout << endl << endl << "Test 1" << endl;
    set_input("test1.blip");
    run();

    cout << endl << endl << "Test 2" << endl;
    set_input("test2.blip");
    run();

    cout << endl << endl << "Test 3" << endl;
    set_input("test3.blip");
    run();

    cout << endl << endl << "Test 4" << endl;
    set_input("test4.blip");
    run();


}