#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void show_help() {
    freopen("E:\\Software\\open\\help.txt","r",stdin);
    string s;
    while(getline(cin, s))
        cout << s << endl;
}

bool judge_key(string s) {
    return s.find(' ')==string::npos && s!="-e";
}

void deal_val(string &s) {
    s = "\"" + s + "\"";
}

void exec(char *key) {
    freopen("E:\\Software\\open\\config.txt","r",stdin);
    string cmd_key, cmd_val;
    map<string, string> mp;
    int line = 0;
    while(++line) {
        if(getline(cin, cmd_key)==0) {
            break;
        }
        if(getline(cin, cmd_val)==0) {
            cout << "config error: lack of val" << endl;
            return;
        }
        if(judge_key(cmd_key)==0) {
            cout << "config error: incorrect key format in pair " << line << " (" << cmd_key << ")" << endl;
            return;
        }
        deal_val(cmd_val);
        if(mp.count(cmd_key)) {
            cout << "config error: repeated key" << endl;
            return;
        }
        mp[cmd_key] = cmd_val;
    }
    if(mp.count(key)) {
        cout << mp[key].c_str() << endl;
        system(mp[key].c_str());
    } else {
        cout << "No this command key" << endl;
    }
}

int main(int argc, char *argv[]) {
    bool exit_flag = 0;
    if(argc == 1) {
        show_help();
    } else {
        if(strcmp(argv[1], "-e")==0) {
            exit_flag = 1;
        }
        if((exit_flag && argc!=3) || (!exit_flag && argc!=2)) {
            cout << "Incorrect format!" << endl;
        } else {
            cout << "opening..." << endl;
            if(exit_flag) {
                exec(argv[2]);
                system("exit");
            } else {
                exec(argv[1]);
            }
        }
    }
    return 0;
}
