#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define ff first
#define ss second
#define ii pair<int, int>

void solve(ii angel, string dev, vector<ii> dev_pos) {
    int mat[13][13];
    memset(mat, 0, sizeof(mat));

    int x = angel.ff, y= angel.ss;
    int xi_r, xi_c, og_r, og_c, ze_r, ze_c;

    for(int i=0; i<3; i++) {
        if(dev[i]=='X') xi_r = dev_pos[i].ff, xi_c = dev_pos[i].ss;
        if(dev[i]=='O') og_r = dev_pos[i].ff, og_c = dev_pos[i].ss;
        if(dev[i]=='Z') ze_r = dev_pos[i].ff, ze_c = dev_pos[i].ss;
    }

    // ZeeSnake mov direction
    bool flag = true, down = true, right = true;

    // movement direction for Angel
    char move;
    if(x==1) move='d';
    else if(x==12) move='u';
    else if(y==1) move='r';
    else move='l';

    for(int i=1; i<=12; i++) {
        // mark as visited
        mat[ze_r][ze_c] = -1;

        // cout<<i<<endl;
        // cout<<move<<endl;
        // cout<<"x:"<<x<<" "<<"y:"<<y<<endl;
        // cout<<"og_r:"<<og_r<<" "<<"og_c:"<<og_c<<endl;
        // cout<<"xi_r:"<<xi_r<<" "<<"xi_c:"<<xi_c<<endl;
        // cout<<"ze_r:"<<ze_r<<" "<<"ze_c:"<<ze_c<<endl;


        // For ZeeSnake
        if(mat[x][y]==-1) {
            char ch = 'A'+y-1;
            cout<<ch<<x<<endl;
            return;
        }

        // moving ZeeSnake

        if(flag) {
            // down/up
            if(ze_r==12) down = false;
            if(ze_r==1) down = true;

            if(down) ze_r++;
            else ze_r--;

            flag = false;
        }
        else {
            // right/left
            if(ze_c==12) right = false;
            if(ze_c==1) right = true;

            if(right) ze_c++;
            else ze_c--;

            flag = true;
        }

        // For xixi
        if(((xi_r%2==xi_c%2) == (x%2==y%2)) && i==xi_r) {
            char ch = 'A'+y-1;
            cout<<ch<<x<<endl;
            return;
        }

        // For Ogre
        if(i==2) {
            bool kill = false;
            if(og_r+1==x && og_c==y) kill = true;
            else if(og_r-1==x && og_c==y) kill = true;
            else if(og_r==x && og_c+1==y) kill = true;
            else if(og_r==x && og_c-1==y) kill = true;
            else if(og_r-1==x && og_c-1==y) kill = true;
            else if(og_r+1==x && og_c+1==y) kill = true;
            else if(og_r+1==x && og_c-1==y) kill = true;
            else if(og_r-1==x && og_c+1==y) kill = true;

            if(kill) {
                char ch = 'A'+y-1;
                cout<<ch<<x<<endl;
                return;
            }
        }
        else if(i==3 && og_r==x && og_c==y) {
            char ch = 'A'+y-1;
            cout<<ch<<x<<endl;
            return;
        }

        // movement direction of Angel
        if(move=='d') x++;
        if(move=='u') x--;
        if(move=='r') y++;
        if(move=='l') y--;
    }

    cout<<"SS"<<endl;
    return;
}

ii get_pos(string s) {
    ii p;
    // K12
    p.ss = s[0] - 65 +1;
    if(s.size()>2) p.ff = (s[1] - 48)*10 + (s[2]-48);
    else p.ff = s[1] - 48;

    return p;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    // Get angel position
    cin>>s;
    // pair<row, col>
    ii angel = get_pos(s);
    //cout<<angel.ff<<" "<<angel.ss<<endl;

    // Get devils
    string devils;
    cin>>s;
    for(int i=0; i<s.size(); i++) if(s[i]!=',') devils.push_back(s[i]);
    //cout<<devils<<endl;


    // Get devils position
    vector<ii> dev_pos;
    string t="";
    cin>>s;
    s += ",";

    for(int i=0; i<s.size(); i++) {
        if(s[i]!=',') t.push_back(s[i]);
        else {
            dev_pos.push_back(get_pos(t));
            t = "";
        }
    }
    // for(int i=0; i<3; i++) {
    //     cout<<dev_pos[i].ff<<" "<<dev_pos[i].ss<<endl;
    // }

    solve(angel, devils, dev_pos);


}










//
