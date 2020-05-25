def createMatrix(row, col, val=0):
    mat = []
    while len(mat)<row:
        m = []
        while len(m)<col:
            m.append(val)
        mat.append(m)
    return mat

def printMatrix(mat, index=0):
    for i in range(index, len(mat)):
        for j in range(index, len(mat[i])):
            print(mat[i][j], end=" ")
        print()


def kill(x,y, dev, dev_pos):
    mat = createMatrix(13, 13)
    xi_r, xi_c, og_r, og_c, ze_r, ze_c;

    for i in range(3):
        if(dev[i]=='X'):
            xi_r = dev_pos[i][0], xi_c = dev_pos[i][1];
        if(dev[i]=='O'):
            og_r = dev_pos[i][0], og_c = dev_pos[i][1];
        if(dev[i]=='Z'):
            ze_r = dev_pos[i][0], ze_c = dev_pos[i][1];

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


def solve():
    # angel
    angel = input()
    y = ord(angel[0])-65+1
    x = int(angel[1:])
    #print(x,y)

    # devils
    dev = list(input().split(','))
    #print(dev)

    # devil's corresponding positions
    dev_pos = list(map(lambda p:(int(p[1:]), ord(p[0])-65+1), input().split(',')))
    #print(dev_pos)

    kill(x,y, dev, dev_pos)


if __name__=='__main__':
    solve()
